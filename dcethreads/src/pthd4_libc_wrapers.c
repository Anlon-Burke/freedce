// vim: ts=4 sw=4 expandtab:
/**************************************************************************
 *
 * DCE Threads Compatibility Library for Linux
 *
 * A DCE Threads emulation layer ontop of Pthreads on Linux.
 *
 **************************************************************************
 * Maintainer:                    Loic Domaigne <LoicWorks@gmx.net>
 *-------------------------------------------------------------------------
 *
 * This module provides wrappers around well known system calls like
 * open(2), close(2) etc. in order to define DCE wrappers for D4 call
 * semantic.
 *
 * This module has been inspired from the original pthd4_libc_wrapers.c
 * of Jim Doyle / Miroslaw Dobrzanski-Neumann. However it has been
 * rewritten from scratch to make it portable accross GNU/Linux system
 * (present and future).
 *
 * Special Thanks to Roland McGrath <roland@redhat.com> for his tips
 * that make this modules so portable within GNU/Linux system.
 *
 ****************************************************************************
 * Change Log
 *---------------------------------------------------------------------------
 *
 * 2003.05.03: loic
 *   Handled Single Unix Specification prototype for sendXXX/recvXXX
 *   functions.
 *
 * 2004.12.06: loic
 *   rewrite entirely pthd4_libc_wrapers.c module
 *
 ****************************************************************************
 * COPYRIGHT NOTICE
 *---------------------------------------------------------------------------
 *
 * This software derives from source from several other implementations
 * and efforts to support DCE Threads including:
 *
 *    OSF/DCE V1.1 Public Domain RPC Release
 *    Michael T. Peterson's PCthreads package and DCE RPC port
 *    Andrew Sandoval's port of DCE RPC to Linux
 *
 * This DCE Threads package is provided under the GNU General Public
 * License. The interfaces to Exceptions and Threads were taken
 * from the header files of the OSF DCE V1.1 RPC Public Domain Release
 *
 * Contributors to this package include:
 *
 *  Jim Doyle                   <jrd@bu.edu>
 *  John Rousseau               <rousseau@world.std.com>
 *  Andrew Sandoval             <sandoval@perigee.net>
 *  Michael T. Peterson         <mtp@big.aa.net>
 *  Miroslaw Dobrzanski-Neumann <mirek-dn@freenet.de>
 *
 *****************************************************************************/

#include "dce/dcethreads_conf.h"

static char rcsid [] __attribute__((__unused__)) = "$Id: pthd4_libc_wrapers.c,v 1.4 2009/02/27 19:14:07 lkcl Exp $";

#ifdef HAVE_OS_WIN32
#include </usr/i586-mingw32msvc/include/pthread.h>    /* Import platform win32 threads*/
#else
#include </usr/include/pthread.h>          /* Import platform LinuxThreads */
#endif

#include "pthread_dce_atfork.h"

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <stdarg.h>

#include <dlfcn.h>
#include <errno.h>
#include <poll.h>
#include <sys/select.h>
#include <time.h>
#include <unistd.h>

#include "pthd4_cancel.h"

#ifndef PIC
const int __dcethread_provide_wrappers = 0;
#endif


/*############################################################################
 *NON CANCELABLE SYSTEM CALLS
 *############################################################################

 *The following define a wrapper for the system calls that are NOT cancelable
 *in the DCEthread semantic, but are in Pthreads. The list of non-cancelable
 *system calls in DCE is:

 *  close(2)
 *  creat(2)
 *  fnctl(2)
 *  fsync(2)
 *  lseek(2)
 *  msync(2)
 *  open(2)
 *  pause(2)
 *  system(3)
 *  tcdrain(3)
 *  wait(2)
 *  waitpid(2)
 *
 *  For those system calls, a wrapper is defined in order to provide the
 *  DCEthreads semantics instead of the Pthreads semantic.

--- NOTE -------------------------------------------------------------------

 *Some of the functions listed above are normally async-signal-safe, but
 *the wrapper use non-async-signal-safe functions like pthread_setcanceltype(3)
 *or dlsym(3).

 *However, this _might_ be a non-issue on GNU/Linux system.

*/

/****************************************************************************
 * NON_CANCELABLE_SYSCALL- wrapper to define non cancelable syscalls        *
 ****************************************************************************
 *                                                                          *
 * this macro define the wrapper of system calls in such a way that         *
 * cancellation is disabled.                                                *
 *                                                                          *
 * to be used with syscall having a fixed number of arguments               *
 ****************************************************************************/

#define NON_CANCELABLE_SYSCALL(res_type, name, param_list, params)    \
                                                                      \
  res_type                                                            \
  name param_list                                                     \
  {                                                                   \
    res_type result;                                                  \
    int      old_cancel_state;                                        \
    res_type (*glibc_function) param_list;                            \
                                                                      \
    glibc_function = dlsym(RTLD_NEXT, #name);                         \
    pthread_setcancelstate (PTHREAD_CANCEL_DISABLE, &old_cancel_state); \
    result = glibc_function params;                                   \
    pthread_setcancelstate (old_cancel_state, NULL);                  \
    return result;                                                    \
  }                                                                   \



/****************************************************************************
 * NON_CANCELABLE_SYSCALL_VA- wrapper to define non cancelable syscalls     *
 ****************************************************************************
 *                                                                          *
 * idem as NON_CANCELABLE_SYSCALL but for system calls with a variable      *
 * number of arguments.                                                     *
 ****************************************************************************/

#define NON_CANCELABLE_SYSCALL_VA(res_type, name, param_list, params, last_arg) \
  res_type                                                            \
  name param_list                                                     \
  {                                                                   \
    va_list  ap;                                                      \
    res_type result;                                                  \
    int      old_cancel_state;                                        \
    res_type (*glibc_function) param_list;                            \
                                                                      \
    glibc_function = dlsym(RTLD_NEXT, #name);                         \
    pthread_setcancelstate (PTHREAD_CANCEL_DISABLE, &old_cancel_state); \
    va_start (ap, last_arg);                                          \
    result = glibc_function params;                                   \
    va_end (ap);                                                      \
    pthread_setcancelstate (old_cancel_state, NULL);                  \
    return result;                                                    \
  }                                                                   \

/*============================================================================*/


/*--------------------------------------------------------*
 * close(2)                                               *
 *--------------------------------------------------------*/
NON_CANCELABLE_SYSCALL (int, close, (int fd), (fd));


/*--------------------------------------------------------*
 * creat(2)                                               *
 *--------------------------------------------------------*/
NON_CANCELABLE_SYSCALL (int, creat,
            (const char*pathname, mode_t mode),
            (pathname, mode)
            );


/*--------------------------------------------------------*
 * fcntl(2)                                               *
 *--------------------------------------------------------*/
NON_CANCELABLE_SYSCALL_VA (int, fcntl,
               (int fd, int cmd, ...),
               (fd, cmd, va_arg (ap, long int)),
               cmd
               );


/*--------------------------------------------------------*
 * fsync(2)                                               *
 *--------------------------------------------------------*/
NON_CANCELABLE_SYSCALL (int, fsync, (int fd), (fd));


/*--------------------------------------------------------*
 * lseek(2)                                               *
 *--------------------------------------------------------*/
NON_CANCELABLE_SYSCALL (off_t, lseek,
            (int fd, off_t offset, int whence),
            (fd, offset, whence)
            );


/*--------------------------------------------------------*
 * msync(2)                                               *
 *--------------------------------------------------------*/
NON_CANCELABLE_SYSCALL (off_t, msync,
            (__ptr_t addr, size_t length, int flags),
            (addr, length, flags)
            );


/*--------------------------------------------------------*
 * open(2)                                                *
 *--------------------------------------------------------*/
NON_CANCELABLE_SYSCALL_VA (int, open,
               (const char *pathname, int flags, ...),
               (pathname, flags, va_arg (ap, mode_t)),
               flags
               );


/*--------------------------------------------------------*
 * pause(2)                                               *
 *--------------------------------------------------------*/
NON_CANCELABLE_SYSCALL (int, pause, (void), ());


/*--------------------------------------------------------*
 * system(3)                                              *
 *--------------------------------------------------------*/
NON_CANCELABLE_SYSCALL (int, system, (const char *line), (line));


/*--------------------------------------------------------*
 * wait(2)                                                *
 *--------------------------------------------------------*/
NON_CANCELABLE_SYSCALL (pid_t, wait, (int* status), (status));


/*--------------------------------------------------------*
 * wapid(2)                                               *
 *--------------------------------------------------------*/
NON_CANCELABLE_SYSCALL (pid_t, waitpid,
            (pid_t pid, int *status, int options),
            (pid, status, options)
            );




/*############################################################################
 * CANCELABLE SYSTEM CALLS
 *############################################################################
 *
 *The following define a wrapper for the system calls that are cancelable
 *in the DCEthread semantic. The list of the system calls are:
 *
 *    nanosleep(2)
 *    read(2)
 *    write(2)
 *    accept(2)
 *    connect(2)
 *    recv(2)
 *    recvfrom(2)
 *    recvmsg(2)
 *    send(2)
 *    sendmsg(2)
 *    sendto(2)
 *    select(2)
 *    poll(2)
 *
 *It happens that these system calls are exactly CP in Pthreads.
 *However, in some older glibc, there weren't true CP. This is exactly
 *when the wrappers below are needed.
 *
 *In newer glibc, the corresponding glibc functions are not wrapped, since
 *the they are true CP.
 *
 *--- NOTE --------------------------------------------------------------------
 *
 *Some of the functions listed above are normally async-signal-safe, but
 *the wrapper use non-async-signal-safe functions like pthread_testcancel(3)
 *or dlsym(3).
 *
 *However, this _might_ be a non-issue on GNU/Linux system.

*/

#if USE_CANCELATION_WRAPPER

/*
 * With the own cancel implementation, cancels are posted and delivered by
 * dcethreads itself (pthd4_cancel.c).  A thread that waits in one of the
 * calls below must then be woken up by the wake-up signal: the wrappers
 * wait with ppoll()/pselect(), which unblock that signal only for the
 * duration of the wait, and do the real call once the descriptor is
 * ready.  Only such waits are cancellation points; calls that cannot
 * block (non-blocking descriptors, sends) are not.  Threads without DCE
 * cancel state, and the NPTL mode, keep the plain behavior.
 */

/* Look up the libc function once and cache it in *cache. */
static void *
real_function (void **cache, const char *name)
{
  if (*cache == NULL)
    *cache = dlsym (RTLD_NEXT, name);
  return *cache;
}

#define REAL_FUNCTION(name) \
  ((__typeof__ (real_##name)) real_function ((void **) &real_##name, #name))

/* The DCE cancel state if the own implementation applies, else NULL. */
static pthd4_cancel_state_t *
own_cancel_state (void)
{
  pthd4_cancel_state_t *s = pthd4__cancel_peek ();
  return pthd4__own_cancel ? s : NULL;
}

static int
fd_is_blocking (int fd)
{
  int flags = fcntl (fd, F_GETFL);
  return flags != -1 && !(flags & O_NONBLOCK);
}

/*
 * Wait until fd is ready for "events".  Returns 0 when ready, -1 with
 * errno set on an error; delivers a cancel.
 */
static int
wait_fd (pthd4_cancel_state_t *s, int fd, short events)
{
  struct pollfd pfd;
  int r;

  pfd.fd = fd;
  pfd.events = events;
  pfd.revents = 0;
  r = pthd4__wait (s, &pfd, 1, NULL);
  if (r == PTHD4_WAIT_CANCEL)
    pthd4__raise_cancel ();
  return r > 0 ? 0 : -1;
}


/****************************************************************************
 * CANCELABLE_SYSCALL- wrapper for the sending calls                        *
 ****************************************************************************
 *                                                                          *
 * In NPTL mode they are cancellation points before and after the call.     *
 * With the own cancel implementation they are no cancellation points: the  *
 * RPC runtime sends on non-blocking sockets and only expects cancels at    *
 * its own waits, which are enclosed in TRY blocks; a cancel raised in the  *
 * middle of a send would escape into the stub.                             *
 ****************************************************************************/

#define CANCELABLE_SYSCALL(res_type, name, param_list, params)      \
                                              \
  static res_type (*real_##name) param_list;  \
                                              \
  res_type                                    \
  name param_list                             \
  {                                           \
    res_type result;                          \
                                              \
    if (own_cancel_state () != NULL)          \
      return REAL_FUNCTION (name) params;     \
                                              \
    pthread_testcancel ();                    \
    result = REAL_FUNCTION (name) params;     \
    pthread_testcancel ();                    \
    return result;                            \
  }                                           \



/*--------------------------------------------------------*
 * nanosleep(2), sleep(3), usleep(3)                      *
 *--------------------------------------------------------*/

static int (*real_nanosleep) (struct timespec const *, struct timespec *);
static unsigned int (*real_sleep) (unsigned int);
static int (*real_usleep) (useconds_t);

/* Sleep as a cancellation point; returns 0, or -1/EINTR with *remaining. */
static int
own_sleep (pthd4_cancel_state_t *s, struct timespec const *requested,
           struct timespec *remaining)
{
  struct timespec now, end, left;
  int r;

  clock_gettime (CLOCK_MONOTONIC, &now);
  end.tv_sec = now.tv_sec + requested->tv_sec;
  end.tv_nsec = now.tv_nsec + requested->tv_nsec;
  if (end.tv_nsec >= 1000000000)
    {
      end.tv_sec++;
      end.tv_nsec -= 1000000000;
    }

  for (;;)
    {
      left.tv_sec = end.tv_sec - now.tv_sec;
      left.tv_nsec = end.tv_nsec - now.tv_nsec;
      if (left.tv_nsec < 0)
        {
          left.tv_sec--;
          left.tv_nsec += 1000000000;
        }
      if (left.tv_sec < 0)
        return 0;

      r = pthd4__wait (s, NULL, 0, &left);
      if (r == PTHD4_WAIT_CANCEL)
        pthd4__raise_cancel ();
      if (r < 0)
        {
          if (remaining != NULL)
            *remaining = left;
          return -1;            /* EINTR from another signal */
        }
      clock_gettime (CLOCK_MONOTONIC, &now);
    }
}

int
nanosleep (struct timespec const *requested_time, struct timespec *remaining)
{
  pthd4_cancel_state_t *s = own_cancel_state ();
  int result;

  if (s != NULL)
    return own_sleep (s, requested_time, remaining);

  pthread_testcancel ();
  result = REAL_FUNCTION (nanosleep) (requested_time, remaining);
  pthread_testcancel ();
  return result;
}

unsigned int
sleep (unsigned int seconds)
{
  pthd4_cancel_state_t *s = own_cancel_state ();
  struct timespec req, rem;

  if (s == NULL)
    return REAL_FUNCTION (sleep) (seconds);

  req.tv_sec = seconds;
  req.tv_nsec = 0;
  if (own_sleep (s, &req, &rem) == 0)
    return 0;
  return rem.tv_sec + (rem.tv_nsec > 0);
}

int
usleep (useconds_t usec)
{
  pthd4_cancel_state_t *s = own_cancel_state ();
  struct timespec req;

  if (s == NULL)
    return REAL_FUNCTION (usleep) (usec);

  req.tv_sec = usec / 1000000;
  req.tv_nsec = (usec % 1000000) * 1000;
  return own_sleep (s, &req, NULL);
}


/*--------------------------------------------------------*
 * read(2)                                                *
 *--------------------------------------------------------*/
static ssize_t (*real_read) (int, void *, size_t);

ssize_t
read (int fd, void *buf, size_t count)
{
  pthd4_cancel_state_t *s = own_cancel_state ();
  ssize_t result;

  if (s != NULL)
    {
      if (fd_is_blocking (fd) && wait_fd (s, fd, POLLIN) != 0)
        return -1;
      return REAL_FUNCTION (read) (fd, buf, count);
    }

  pthread_testcancel ();
  result = REAL_FUNCTION (read) (fd, buf, count);
  pthread_testcancel ();
  return result;
}


/*--------------------------------------------------------*
 * write(2)                                               *
 *--------------------------------------------------------*/
CANCELABLE_SYSCALL (ssize_t,
            write,
            (int fd, const void *buf, size_t n),
            (fd, buf, n)
            );


/*--------------------------------------------------------*
 * accept(2)                                              *
 *--------------------------------------------------------*/
static int (*real_accept) (int, struct sockaddr *, socklen_t *);

int
accept (int fd, struct sockaddr *addr, socklen_t *addr_len)
{
  pthd4_cancel_state_t *s = own_cancel_state ();
  int result;

  if (s != NULL)
    {
      if (fd_is_blocking (fd) && wait_fd (s, fd, POLLIN) != 0)
        return -1;
      return REAL_FUNCTION (accept) (fd, addr, addr_len);
    }

  pthread_testcancel ();
  result = REAL_FUNCTION (accept) (fd, addr, addr_len);
  pthread_testcancel ();
  return result;
}


/*--------------------------------------------------------*
 * connect(2)                                             *
 *--------------------------------------------------------*/
static int (*real_connect) (int, struct sockaddr const *, socklen_t);

int
connect (int fd, struct sockaddr const *addr, socklen_t addrlen)
{
  pthd4_cancel_state_t *s = own_cancel_state ();
  int result, flags, err;
  socklen_t len;

  if (s == NULL)
    {
      pthread_testcancel ();
      result = REAL_FUNCTION (connect) (fd, addr, addrlen);
      pthread_testcancel ();
      return result;
    }
  if ((flags = fcntl (fd, F_GETFL)) == -1 || (flags & O_NONBLOCK))
    return REAL_FUNCTION (connect) (fd, addr, addrlen);

  /* connect without blocking, then wait until the connection is set up */
  if (pthd4__take_cancel (s))
    pthd4__raise_cancel ();
  fcntl (fd, F_SETFL, flags | O_NONBLOCK);
  result = REAL_FUNCTION (connect) (fd, addr, addrlen);
  if (result == 0 || errno != EINPROGRESS)
    {
      err = errno;
      fcntl (fd, F_SETFL, flags);
      errno = err;
      return result;
    }

  for (;;)
    {
      struct pollfd pfd;
      int r;

      pfd.fd = fd;
      pfd.events = POLLOUT;
      pfd.revents = 0;
      r = pthd4__wait (s, &pfd, 1, NULL);
      if (r == PTHD4_WAIT_CANCEL)
        {
          fcntl (fd, F_SETFL, flags);
          pthd4__raise_cancel ();
        }
      if (r > 0)
        break;
      if (errno != EINTR)
        {
          err = errno;
          fcntl (fd, F_SETFL, flags);
          errno = err;
          return -1;
        }
    }

  len = sizeof (err);
  if (getsockopt (fd, SOL_SOCKET, SO_ERROR, &err, &len) == -1)
    err = errno;
  fcntl (fd, F_SETFL, flags);
  if (err != 0)
    {
      errno = err;
      return -1;
    }
  return 0;
}


/*--------------------------------------------------------*
 * select(2)                                              *
 *--------------------------------------------------------*/
static int (*real_select) (int, fd_set *, fd_set *, fd_set *, struct timeval *);

int
select (int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,
        struct timeval *timeout)
{
  pthd4_cancel_state_t *s = own_cancel_state ();
  int result;

  if (s != NULL)
    return pthd4__select (s, nfds, readfds, writefds, exceptfds, timeout);

  pthread_testcancel ();
  result = REAL_FUNCTION (select) (nfds, readfds, writefds, exceptfds, timeout);
  pthread_testcancel ();
  return result;
}


/*--------------------------------------------------------*
 * poll(2)                                                *
 *--------------------------------------------------------*/
static int (*real_poll) (struct pollfd *, nfds_t, int);

int
poll (struct pollfd *fds, nfds_t nfds, int timeout)
{
  pthd4_cancel_state_t *s = own_cancel_state ();
  struct timespec ts;
  int result;

  if (s != NULL)
    {
      if (timeout >= 0)
        {
          ts.tv_sec = timeout / 1000;
          ts.tv_nsec = (timeout % 1000) * 1000000L;
        }
      result = pthd4__wait (s, fds, nfds, timeout >= 0 ? &ts : NULL);
      if (result == PTHD4_WAIT_CANCEL)
        pthd4__raise_cancel ();
      return result;
    }

  pthread_testcancel ();
  result = REAL_FUNCTION (poll) (fds, nfds, timeout);
  pthread_testcancel ();
  return result;
}


/*
 * For the networking API, we use the Single Unix Specification or the
 * BSD proto depending on the environment
 */

#ifdef _BSD_SOURCE
/*-----------------------------------------*
 * use BSD prototype                       *
 *-----------------------------------------*/
#define net_type ssize_t
#else
/*-----------------------------------------*
 * use Single Unix Specification prototype *
 *-----------------------------------------*/
#define net_type ssize_t
#endif


/*
 * recv(2), recvfrom(2), recvmsg(2): wait until the socket is readable,
 * then receive without blocking (unless MSG_WAITALL was asked for).
 */
#define OWN_RECV(s, fd, flags, call)                                \
  do                                                                \
    {                                                               \
      net_type r_;                                                  \
      int blocking_ = fd_is_blocking (fd);                          \
      for (;;)                                                      \
        {                                                           \
          if (blocking_ && wait_fd (s, fd, POLLIN) != 0)            \
            return -1;                                              \
          r_ = call;                                                \
          if (r_ >= 0 || !blocking_ || (flags & MSG_WAITALL)        \
              || (errno != EAGAIN && errno != EWOULDBLOCK))         \
            break;                                                  \
        }                                                           \
      return r_;                                                    \
    }                                                               \
  while (0)

/*--------------------------------------------------------*
 * recv(2)                                                *
 *--------------------------------------------------------*/
static net_type (*real_recv) (int, __ptr_t, size_t, int);

net_type
recv (int fd, __ptr_t buf, size_t n, int flags)
{
  pthd4_cancel_state_t *s = own_cancel_state ();
  net_type result;

  if (s != NULL)
    OWN_RECV (s, fd, flags,
              REAL_FUNCTION (recv) (fd, buf, n,
                                    (flags & MSG_WAITALL) ? flags
                                    : flags | MSG_DONTWAIT));

  pthread_testcancel ();
  result = REAL_FUNCTION (recv) (fd, buf, n, flags);
  pthread_testcancel ();
  return result;
}

/*--------------------------------------------------------*
 * recvfrom(2)                                            *
 *--------------------------------------------------------*/
static net_type (*real_recvfrom) (int, void *__restrict, size_t, int,
                                  __SOCKADDR_ARG, socklen_t *__restrict);

net_type
recvfrom (int fd, void *__restrict buf, size_t n, int flags,
          __SOCKADDR_ARG addr, socklen_t *__restrict addr_len)
{
  pthd4_cancel_state_t *s = own_cancel_state ();
  net_type result;

  if (s != NULL)
    OWN_RECV (s, fd, flags,
              REAL_FUNCTION (recvfrom) (fd, buf, n,
                                        (flags & MSG_WAITALL) ? flags
                                        : flags | MSG_DONTWAIT,
                                        addr, addr_len));

  pthread_testcancel ();
  result = REAL_FUNCTION (recvfrom) (fd, buf, n, flags, addr, addr_len);
  pthread_testcancel ();
  return result;
}

/*--------------------------------------------------------*
 * recvmsg(2)                                            *
 *--------------------------------------------------------*/
static net_type (*real_recvmsg) (int, struct msghdr *, int);

net_type
recvmsg (int fd, struct msghdr *message, int flags)
{
  pthd4_cancel_state_t *s = own_cancel_state ();
  net_type result;

  if (s != NULL)
    OWN_RECV (s, fd, flags,
              REAL_FUNCTION (recvmsg) (fd, message,
                                       (flags & MSG_WAITALL) ? flags
                                       : flags | MSG_DONTWAIT));

  pthread_testcancel ();
  result = REAL_FUNCTION (recvmsg) (fd, message, flags);
  pthread_testcancel ();
  return result;
}


/*--------------------------------------------------------*
 * send(2)                                                *
 *--------------------------------------------------------*/
CANCELABLE_SYSCALL (net_type, send,
            (int fd, const __ptr_t buf, size_t n, int flags),
            (fd, buf, n, flags)
            );


/*--------------------------------------------------------*
 * sendmsg(2)                                             *
 *--------------------------------------------------------*/
CANCELABLE_SYSCALL (net_type, sendmsg,
            (int fd, const struct msghdr *message, int flags),
            (fd, message, flags)
            );


/*--------------------------------------------------------*
 * sendto(2)                                              *
 *--------------------------------------------------------*/
CANCELABLE_SYSCALL (net_type, sendto,
            (int fd, const __ptr_t buf, size_t n,
             int flags, struct sockaddr const *addr,
             socklen_t addr_len
             ),
            (fd, buf, n, flags, addr, addr_len)
            );


/*--------------------------------------------------------*
 * __poll_chk, __read_chk, __recv_chk, __recvfrom_chk     *
 *--------------------------------------------------------*
 * With _FORTIFY_SOURCE (the default of many distributions *
 * at -O2) glibc's headers turn a call on a buffer of      *
 * known size into these checking variants, which go to    *
 * libc directly and would bypass the wrappers above.  Do  *
 * the same check and call the wrapper.                    *
 *--------------------------------------------------------*/
extern void __chk_fail (void) __attribute__ ((__noreturn__));

int
__poll_chk (struct pollfd *fds, nfds_t nfds, int timeout, size_t fdslen)
{
  if (fdslen / sizeof (*fds) < nfds)
    __chk_fail ();
  return poll (fds, nfds, timeout);
}

ssize_t
__read_chk (int fd, void *buf, size_t nbytes, size_t buflen)
{
  if (nbytes > buflen)
    __chk_fail ();
  return read (fd, buf, nbytes);
}

ssize_t
__recv_chk (int fd, void *buf, size_t n, size_t buflen, int flags)
{
  if (n > buflen)
    __chk_fail ();
  return recv (fd, buf, n, flags);
}

ssize_t
__recvfrom_chk (int fd, void *__restrict buf, size_t n, size_t buflen,
                int flags, __SOCKADDR_ARG addr, socklen_t *__restrict addr_len)
{
  if (n > buflen)
    __chk_fail ();
  return recvfrom (fd, buf, n, flags, addr, addr_len);
}


#endif /* USE_CANCEL_WRAPPER */



/****************************************************************************
 * pthd4_wrapper_pthread_atfork- wrapper for pthread_atfork()               *
 ****************************************************************************
 *                                                                          *
 * This wrapper for pthread_atfork(3thr) is provided for binary             *
 * compatibility with Pthreads. Notice however that there is no             *
 * pthread_atfork(3thr) in D4.                                              *
 *                                                                          *
 ***************************************************************************/
int
pthd4_wrapper_pthread_atfork __P ((fork_handler_7_t pre,
                   fork_handler_7_t parent,
                   fork_handler_7_t child))
{
  struct atfork_cb_t cb;
  cb.draft4        = !!0;
  cb.cb.fh7.pre    = pre;
  cb.cb.fh7.parent = parent;
  cb.cb.fh7.child  = child;
  return pthd4_pthread_atfork(&cb);
}
