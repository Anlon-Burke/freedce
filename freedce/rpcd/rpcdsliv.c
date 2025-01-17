/*
 * 
 * (c) Copyright 1989 OPEN SOFTWARE FOUNDATION, INC.
 * (c) Copyright 1989 HEWLETT-PACKARD COMPANY
 * (c) Copyright 1989 DIGITAL EQUIPMENT CORPORATION
 * To anyone who acknowledges that this file is provided "AS IS"
 * without any express or implied warranty:
 *                 permission to use, copy, modify, and distribute this
 * file for any purpose is hereby granted without fee, provided that
 * the above copyright notices and this notice appears in all source
 * code copies, and that none of the names of Open Software
 * Foundation, Inc., Hewlett-Packard Company, or Digital Equipment
 * Corporation be used in advertising or publicity pertaining to
 * distribution of the software without specific, written prior
 * permission.  Neither Open Software Foundation, Inc., Hewlett-
 * Packard Company, nor Digital Equipment Corporation makes any
 * representations about the suitability of this software for any
 * purpose.
 * 
 */
/*
 */
/*
**
**  NAME:
**
**      rpcdsliv.c
**
**  FACILITY:
**
**      RPC Daemon
**
**  ABSTRACT:
**
**      RPCD  Server Liveness Module.  Tasks to periodically ping servers
**      which are registered in the endpoint database and mark them for
**      deletion from the database if they do not respond.  One task
**      also purges entries which are marked as deleted and which have 
**      no read references to them.
**      
**
**
*/

#ifdef HAVE_OS_WIN32
typedef int pid_t;
#endif

#include <commonp.h>
#include <com.h>

#include <dce/ep.h>     /* derived from ep.idl */
#include <dsm.h>        /* derived from dsm.idl */

#include <rpcdp.h>
#include <rpcddb.h>
#include <rpcdepdbp.h>
#include <rpcdutil.h>


#define slive_c_long_wait   (15*60) /* 15 minutes */
#define slive_c_short_wait  (1*60)  /* 1 minute */

/*  RPC comm timeout for ping of a "good" server
 *  (ie. a server which has been communicating)
 */
#define slive_c_short_comm_timeout          3

/*  Number of consecutive failures to communicate with a server
 *  before it is deemed to be dead and is removed from the database  
 */
#define slive_c_max_server_not_listening    20   


INTERNAL void sliv_task1
    _DCE_PROTOTYPE_((
        void    *arg
    ));

INTERNAL void sliv_task2
    _DCE_PROTOTYPE_((
        void    *arg
    ));

INTERNAL boolean32 ping_server
    _DCE_PROTOTYPE_((
        db_entry_t      *entp,
        unsigned32      timeout,
        error_status_t  *status
    ));



/*  Start server alive tasks and init condition variable
 *  used by task1 to tell task2 that it should aggressively
 *  ping a server
 *
 *  NB: this routine must be called after the db locks have been
 *  inited
 */
PRIVATE void sliv_init(h, status)
struct db       *h;
error_status_t  *status;
{
    sys_pthread_cond_init(&h->sliv_task2_cv, &sys_pthread_condattr_default);

    sys_pthread_create(&h->sliv_task1_h, &sys_pthread_attr_default, 
            (void*) sliv_task1, (void *) h);

    sys_pthread_create(&h->sliv_task2_h, &sys_pthread_attr_default, 
            (void*) sliv_task2, (void *) h);
    *status = error_status_ok;
}

/*  Task1 runs a few times an hour 
 *  It purges entries which are marked as deleted and
 *      have no read references to them.
 *  It also pings servers which have been reachable.
 *  If a server becomes not reachable, its destiny is passed
 *  off to Task2 which pings it more frequently and will
 *  mark it for deletion if it isn't reachable after 
 *  slive_c_max_server_not_listening consecutive tries.
 */

#ifdef HAVE_OS_WIN32
struct timeval;
extern int win32_gettimeofday(struct timeval *tp, void *unused);
#endif

INTERNAL void sliv_task1(arg)
void    *arg;
{
#define slive_c_max_deletes 5

    struct db       *h;
    struct timeval  now;
    unsigned32      ndeletes;
    db_lists_t      *lp,
                    *lp_next;
    db_entry_t      *entp;
    boolean32       server_listening;
    error_status_t  status;

#ifdef PTHREAD_CANCEL_DEFAULT_ON
    sys_pthread_setcancel(CANCEL_ON);
#endif

    h = (struct db *) arg;

#ifdef HAVE_OS_WIN32
    win32_gettimeofday(&now, NULL);
#else
    gettimeofday(&now, (struct timezone *) 0);
#endif

    while (true)
    {    
        ru_sleep_until(&now, slive_c_long_wait);

#ifdef HAVE_OS_WIN32
	win32_gettimeofday(&now, NULL);
#else
        gettimeofday(&now, (struct timezone *) 0);
#endif

        db_lock(h);
                    
        ndeletes = 0;
        for (lp = db_list_first(&h->lists_mgmt, db_c_entry_list, NULL);
                lp != NULL; lp = lp_next)
        { 
            /*
             *  Point to next entry in list now because
             *  may delete this entry and remove it from
             *  list
             */
            lp_next = db_list_next(db_c_entry_list, lp);

            entp = (db_entry_t *) lp;

            /*  If have done lots of deletes 
             *  unlock db for a while so more
             *  important things can happen
             */
            if (ndeletes > slive_c_max_deletes)
            {
                ndeletes = 0;
                entp->read_nrefs++;
                db_unlock(h);

                ru_sleep(60);

                db_lock(h);
                entp->read_nrefs--;
            }

            if (entp->delete_flag) 
            {
                if (entp->read_nrefs == 0)
                {
                    epdb_delete_entry(h, entp, &status);
                    ndeletes++;

                    if (dflag)
                        printf("sliv_task1 deleting server\n");
                }
            }
            else
            if (entp->ncomm_fails == 0)
            {
                entp->read_nrefs++;
                db_unlock(h);

                sys_pthread_testcancel();

                server_listening = ping_server(entp, slive_c_short_comm_timeout, &status);

                db_lock(h);
                entp->read_nrefs--;

                if (!server_listening)
                {
                    entp->ncomm_fails++;
                    sys_pthread_cond_signal(&h->sliv_task2_cv);
                }
            }

        }   /* end entry list loop */

        db_unlock(h);
    }
}

INTERNAL void sliv_task2(arg)
void    *arg;
{
    struct db       *h;
    struct timeval  now;
    struct timespec waketime;
    unsigned32      waitsecs;
    boolean32       have_db_lock;
    db_lists_t      *lp;
    db_entry_t      *entp;
    boolean32       server_listening;
    error_status_t  status;

	DO_NOT_CLOBBER(waitsecs);
	DO_NOT_CLOBBER(have_db_lock);
	 
#ifdef PTHREAD_CANCEL_DEFAULT_ON
    sys_pthread_setcancel(CANCEL_ON);
#endif

    h = (struct db *) arg;

    /*  let other init stuff get done */
    ru_sleep(180);      

#ifdef HAVE_OS_WIN32
    win32_gettimeofday(&now, NULL);
#else
    gettimeofday(&now, (struct timezone *) 0);
#endif
    waitsecs = slive_c_long_wait;

    db_lock(h);
    have_db_lock = true;

    TRY
    {
        while (true)
        {
			  int __istat;
            waketime.tv_sec = now.tv_sec + waitsecs + 1;
            waketime.tv_nsec = 0;
    
            /*  release lock and wait for task2 event or timeout or cancel
             */
				
				do	{
					__istat = sys_pthread_cond_timedwait(&h->sliv_task2_cv, &h->lock, &waketime);
				} while(__istat == EINTR);
    
            /*  have lock now
             */
    
#ifdef HAVE_OS_WIN32
	    win32_gettimeofday(&now, NULL);
#else
            gettimeofday(&now, (struct timezone *) 0);
#endif
            waitsecs = slive_c_long_wait;   /* so far no bad servers */
    
            for (lp = db_list_first(&h->lists_mgmt, db_c_entry_list, NULL);
                    lp != NULL; lp = db_list_next(db_c_entry_list, lp))
            { 
                entp = (db_entry_t *) lp;
    
                if ((entp->ncomm_fails > 0) && (!entp->delete_flag))
                {
                    entp->read_nrefs++;
                    have_db_lock = false;
                    db_unlock(h);
    
                    sys_pthread_testcancel();
    
                    server_listening = ping_server(entp, rpc_c_binding_default_timeout, &status);
    
                    db_lock(h);
                    have_db_lock = true;
                    entp->read_nrefs--;
    
                    if (!server_listening)
                    {   
                        waitsecs = slive_c_short_wait;
                        entp->ncomm_fails++;
                        if (entp->ncomm_fails >= slive_c_max_server_not_listening)
                        {    
                            /*  Haven't communicated with server for
                             *  slive_c_max_server_not_listening consecutive tries
                             *  so mark entry as deleted in memory and on disk.
                             *  Task1 will actually purge entry from database
                             *  (it needs to do some extra bookkeeping so let's
                             *  keep that in one place)
                             */
                            entp->delete_flag = true;
                            db_update_entry(h, entp, &status);
                            if (dflag)
                                printf("sliv_task2 marking server for deletion\n");
                        }
                    }
                    else
                    {
                        entp->ncomm_fails = 0;
                    }
                }
            } /* end entry list loop */
        } /* end while loop */

    }   /* TRY */
    CATCH_ALL
    {
        /*  received cancel or some other exception.
         *  just unlock database and exit task
         */
        if (have_db_lock) 
            db_unlock(h);
        RERAISE;
    }
    ENDTRY
}

INTERNAL boolean32 ping_server(entp, timeout, status)
db_entry_t      *entp;
unsigned32      timeout;
error_status_t  *status;
{
    rpc_binding_handle_t    binding_h;
    boolean32               is_listening;
    error_status_t          tmp_st;

    rpc_tower_to_binding(entp->tower.tower_octet_string, &binding_h, status);
    if (! STATUS_OK(status)) return(true);      /* what to do? */

    if (timeout != rpc_c_binding_default_timeout)
    {
        rpc_mgmt_set_com_timeout(binding_h, timeout, status);
    }

    is_listening = rpc_mgmt_is_server_listening(binding_h, status);

    rpc_binding_free(&binding_h, &tmp_st);

    return(is_listening);
}


