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
 */

/*
 *  OSF DCE Version 1.0 
 */

/*
**
**  NAME:
**
**      dsm_unix.c
**
**  FACILITY:
**
**      Data Storage Manager (DSM)
**
**  ABSTRACT:
**
**  The module contains any UNIX specific routines necessary for the DSM.
**
**
*/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "dsm_p.h"      /* private include file */
#include <stdio.h>
#include <unistd.h>

/*
 *  dsm__flush_file (fd)
 *
 *  Synchronize the memory representation of the file with the disk
 *  representation.
 *
 *  Returns 0 if successful, -1 if error occurred.
 */
public int dsm__flush_file (fd)
#ifdef HAVE_OS_WIN32
int fd __attribute__((__unused__));
#else
int fd;
#endif
{
#ifdef HAVE_OS_WIN32
    return 0;
#else
    return (fsync(fd));
#endif
} 

/*
 *  dsm__lock_file (fd)
 *
 *  Locks the given open fd such that other DSM instances will not be able 
 *  to open it (to lock it).  File locking varies from system to system; 
 *  currently BSD and SYS5 are supported.
 */

public void dsm__lock_file (fd, st)
#ifdef HAVE_OS_WIN32
int fd __attribute__((__unused__));
#else
int fd;
#endif
error_status_t *st;
{
#ifdef HAVE_OS_WIN32
    (*st) = status_ok;
#else
    int result;

#ifdef BSD
    result = flock(fd, (LOCK_EX|LOCK_NB));
#else
    struct flock    farg;

    farg.l_type   = F_WRLCK;
    farg.l_whence = 0;
    farg.l_start  = 0;
    farg.l_len    = 0;
    farg.l_pid    = getpid();
    result = fcntl(fd, F_SETLK, &farg);
#endif

    if (result == -1) {
        if (errno == EWOULDBLOCK)
            (*st) = dsm_err_file_busy;
        else
            (*st) = dsm_err_file_io_error;
    }
    else (*st) = status_ok;
#endif
} 

