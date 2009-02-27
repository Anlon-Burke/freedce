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
#ifndef _COMSOC_WIN32_H
#define _COMSOC_WIN32_H	1
/*
**
**  NAME:
**
**      comsoc_win32.h
**
**  FACILITY:
**
**      Remote Procedure Call (RPC) 
**
**  ABSTRACT:
**
**  The platform-specific portion of the internal network "socket" object
**  interface.  See abstract in "comsoc.h" for details.
**
**  For BSD 4.3 & 4.4 systems.  
**
*/

#ifndef _DCE_PROTOTYPE_
#include <dce/dce.h>
#endif

#if defined(__osf__) || defined(__OSF__) 
# include <sys/time.h>
#endif

/*
 * A handle to a socket.  The implementation of this type is considered
 * to be private to this package.
 */

typedef int rpc_socket_t;                       /* a UNIX socket handle */

/*
 * A public function for comparing two socket handles.
 */

#define RPC_SOCKET_IS_EQUAL(s1, s2)             (s1 == s2)


/*
 * This package's error type and values.  The implementation of this
 * type is considered to be private to this package.
 */

typedef int rpc_socket_error_t;                 /* a UNIX errno */

#include <comnaf.h>
#include <ipnaf.h>

/*
 * The maximum number of iov elements which can be sent through
 * sendmsg is MSG_IOVLEN-1.
 */
#define RPC_C_MAX_IOVEC_LEN ( MSG_MAXIOVLEN - 1)

/*
 * The maximum number of connections which can be queued on a socket.
 */
#define RPC_C_LISTEN_BACKLOG SOMAXCONN

/*
 * Public error constants and functions for comparing errors.
 * The _ETOI_ (error-to-int) function converts a socket error to a simple
 * integer value that can be used in error mesages.
 */

#define RPC_C_SOCKET_OK           0             /* a successful error value */
#define RPC_C_SOCKET_EWOULDBLOCK  WSAEWOULDBLOCK   /* operation would block */
#define RPC_C_SOCKET_EINTR        WSAEINTR         /* operation was interrupted */
#define RPC_C_SOCKET_EIO          EIO           /* I/O error */
#define RPC_C_SOCKET_EADDRINUSE   WSAEADDRINUSE    /* address was in use (see bind) */
#define RPC_C_SOCKET_ECONNRESET   WSAECONNRESET    /* connection reset by peer */
#define RPC_C_SOCKET_ETIMEDOUT    WSAETIMEDOUT     /* connection request timed out*/
#define RPC_C_SOCKET_ECONNREFUSED WSAECONNREFUSED  /* connection request refused */
#define RPC_C_SOCKET_ENOTSOCK     WSAENOTSOCK      /* descriptor was not a socket */
#define RPC_C_SOCKET_ENETUNREACH  WSAENETUNREACH   /* network is unreachable*/
#define RPC_C_SOCKET_ENOSPC       ENOSPC        /* no local or remote resources */
#define RPC_C_SOCKET_ENETDOWN     WSAENETDOWN      /* network is down */
#define RPC_C_SOCKET_ETOOMANYREFS WSAETOOMANYREFS  /* too many remote connections */
#define RPC_C_SOCKET_ESRCH        ESRCH         /* remote endpoint not found */
#define RPC_C_SOCKET_EHOSTDOWN    WSAEHOSTDOWN     /* remote host is down */
#define RPC_C_SOCKET_EHOSTUNREACH WSAEHOSTUNREACH  /* remote host is unreachable */
#define RPC_C_SOCKET_ECONNABORTED WSAECONNABORTED  /* local host aborted connect */
#define RPC_C_SOCKET_ECONNRESET   WSAECONNRESET    /* remote host reset connection */
#define RPC_C_SOCKET_ENETRESET    WSAENETRESET     /* remote host crashed */
#define RPC_C_SOCKET_ENOEXEC      ENOEXEC       /* invalid endpoint format for remote */
#define RPC_C_SOCKET_EACCESS      WSAEACCES        /* access control information */
                                                /* invalid at remote node */
#define RPC_C_SOCKET_EPIPE        EPIPE         /* a write on a pipe */
                                                /* or socket for which there */
                                                /* is no process to */
                                                /* read the data. */
#define RPC_C_SOCKET_EAGAIN       EAGAIN        /* no more processes */
#define RPC_C_SOCKET_EALREADY     EALREADY      /* operation already */
                                                /* in progress */
#define RPC_C_SOCKET_EDEADLK      EDEADLK       /* resource deadlock */
                                                /* would occur */
#define RPC_C_SOCKET_EINPROGRESS  WSAEINPROGRESS   /* operation now in */
                                                /* progress */
#define RPC_C_SOCKET_EISCONN      WSAEISCONN       /* socket is already */
                                                /* connected */

/*
 * A macro to determine if an socket error can be recovered from by
 * retrying.
 */
#define RPC_SOCKET_ERR_IS_BLOCKING(s) \
    ((s == RPC_C_SOCKET_EAGAIN) || (s == RPC_C_SOCKET_EWOULDBLOCK) || (s == RPC_C_SOCKET_EINPROGRESS) || \
     (s == RPC_C_SOCKET_EALREADY) || (s == RPC_C_SOCKET_EDEADLK))

#define RPC_SOCKET_ERR_EQ(serr, e)  ((serr) == e)

#define RPC_SOCKET_IS_ERR(serr)     (! RPC_SOCKET_ERR_EQ(serr, RPC_C_SOCKET_OK))

#define RPC_SOCKET_ETOI(serr)       (serr)

/*
 * Macros to paper over the difference between the 4.4bsd and 4.3bsd
 * socket API.
 *
 * The layout of a 4.4 struct sockaddr includes a 1 byte "length" field
 * which used to be one of the bytes of the "family" field.  (The "family"
 * field is now 1 byte instead of 2 bytes.)  4.4 provides binary
 * compatibility with applications compiled with a 4.3 sockaddr definition
 * by inferring a default length when the supplied length is zero.  Source
 * compatibility is blown however (if _SOCKADDR_LEN is #define'd) --
 * applications that assign only to the "family" field will leave the
 * "length" field possibly non-zero.
 *
 * Note that RPC's "sockaddr_t" is always defined to contains only a
 * family.  (We defined "rpc_addr_t" to be a struct that contains a length
 * and a sockaddr rather than mucking with the sockaddr itself.)  We
 * assumed that "sockaddr_t" and "struct sockaddr" are the same.  At
 * 4.4, this assumption caused problems.  We use RPC_SOCKET_FIX_ADDRLEN
 * at various opportunities to make sure sockaddrs' length is zero and
 * that makes the problems go away.
 *
 * RPC_SOCKET_FIX_ADDRLEN takes an "rpc_addr_p_t" (or "rpc_ip_addr_p_t")
 * as input.  The complicated casting (as opposed to simply setting
 * ".sa_len" to zero) is to ensure that the right thing happens regardless
 * of the integer endian-ness of the system).
 *
 * RPC_SOCKET_INIT_MGRHDR deals with the differences in the field names of
 * the "struct msghdr" data type between 4.3 and 4.4.
 */

#define _SOCKADDR_LEN
	
#ifdef _SOCKADDR_LEN

  #define RPC_SOCKET_FIX_ADDRLEN(addrp) ( \
      ((struct sockaddr *) &(addrp)->sa)->sa_family = \
              ((struct sockaddr *) &(addrp)->sa)->sa_family \
  )

#define RPC_SOCKET_INIT_MSGHDR(msgp) ( \
    (msgp)->msg_control         = NULL, \
    (msgp)->msg_controllen      = 0, \
    (msgp)->msg_flags           = 0 \
)

#else

#define RPC_SOCKET_FIX_ADDRLEN(addrp)

#define RPC_SOCKET_INIT_MSGHDR(msgp) ( \
    (msgp)->msg_accrights       = NULL, \
    (msgp)->msg_accrightslen    = 0 \
)

#endif /* _SOCKADDR_LEN */

extern void RPC_SOCKET_SENDMSG(
	rpc_socket_t sock,
	rpc_socket_iovec_p_t iovp,
	int iovlen,
	rpc_addr_p_t addrp,
	volatile int *ccp,
  	volatile rpc_socket_error_t *serrp
		);
extern void RPC_SOCKET_RECVFROM
(
    rpc_socket_t        sock,
    byte_p_t            buf,        /* buf for rcvd data */
    int                 buflen,        /* len of above buf */
    rpc_addr_p_t        from,       /* addr of sender */
    volatile int                 *ccp,        /* returned number of bytes actually rcvd */
	 volatile rpc_socket_error_t *serrp
);
extern void RPC_SOCKET_RECVMSG
(
    rpc_socket_t        sock,
    rpc_socket_iovec_p_t iovp,       /* array of bufs for rcvd data */
    int                 iovlen,    /* number of bufs */
    rpc_addr_p_t        addrp,       /* addr of sender */
    volatile int                 *ccp,        /* returned number of bytes actually rcvd */
	 volatile rpc_socket_error_t *serrp
);

#endif /* _COMSOC_WIN32_H */
