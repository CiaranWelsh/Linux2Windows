
#ifndef _UNISTD_H
#define _UNISTD_H

/* This is intended as a drop-in replacement for unistd.h on Windows.
 * Please add functionality as neeeded.
 * https://stackoverflow.com/a/826027/1202830
 * https://stackoverflow.com/questions/341817/is-there-a-replacement-for-unistd-h-for-windows-visual-c
 */

#include <stdlib.h>
#include <io.h>

#include "_getopt.h"
#include <process.h> /* for getpid() and the exec..() family */
#include <direct.h> /* for _getcwd() and _chdir() */

#define srandom srand
#define random rand

/* Values for the second argument to access.
   These may be OR'd together.  */
#define R_OK    4       /* Test for read permission.  */
#define W_OK    2       /* Test for write permission.  */
//#define   X_OK    1       /* execute permission - unsupported in windows*/
#define F_OK    0       /* Test for existence.  */

#define access _access
#define dup2 _dup2
#define execve _execve
#define ftruncate _chsize
#define unlink _unlink
#define fileno _fileno
#define getcwd _getcwd
#define chdir _chdir
#define isatty _isatty
#define lseek _lseek
/* read, write, and close are NOT being #defined here, because while there are file handle specific versions for Windows, they probably don't work for sockets. You need to look at your app and consider whether to call e.g. closesocket(). */

#ifdef _WIN64
#   define ssize_t __int64
#   define SSIZE_MAX _I64_MAX
#else
#   define SSIZE_MAX LONG_MAX
#   define ssize_t long
#endif

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#ifndef HAVE_STDINT_H
/**
 * should be in some equivalent to <sys/types.h> */
 * note that sometimes stdint.h is or isn't available on windows
 * which is why we have this in a #ifndef macro. Could be c++ standard dependent?
 */
typedef __int8            int8_t;
typedef __int16           int16_t;
typedef __int32           int32_t;
typedef __int64           int64_t;
typedef unsigned __int8   uint8_t;
typedef unsigned __int16  uint16_t;
typedef unsigned __int32  uint32_t;
typedef unsigned __int64  uint64_t;
#endif
#endif //HTSLIB_CMAKE__UNISTD_H
