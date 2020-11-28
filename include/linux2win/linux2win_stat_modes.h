//
// Created by Ciaran on 28/11/2020.
//

#ifndef BCFTOOLS_CMAKE_LINUX2WIN_STAT_MODES_H
#define BCFTOOLS_CMAKE_LINUX2WIN_STAT_MODES_H

#include "linux2win_config.h"

#ifndef __S_ISUID
#   define	__S_ISUID	04000	/* Set user ID on execution.  */
#endif

#ifndef __S_ISGID
#   define	__S_ISGID	02000	/* Set group ID on execution.  */
#endif

#ifndef __S_ISVTX
#   define	__S_ISVTX	01000	/* Save swapped text after use (sticky).  */
#endif

#ifndef __S_IREAD
#   define	__S_IREAD	0400	/* Read by owner.  */
#endif

#ifndef __S_IWRITE
#   define	__S_IWRITE	0200	/* Write by owner.  */
#endif

#ifndef __S_IEXEC
#   define	__S_IEXEC	0100	/* Execute by owner.  */
#endif

// defintions from msvc's sys\stat.h
#ifndef S_IRUSR
#   define S_IRUSR 0400
#endif

#ifndef S_IWUSR
#   define S_IWUSR 0200
#endif

#ifndef S_IXUSR
#   define S_IXUSR 0100
#endif

#ifndef S_IRGRP
#   define S_IRGRP (S_IRUSR >> 3)
#endif

#ifndef S_IROTH
#   define S_IROTH (S_IRGRP >> 3)
#endif

#ifndef S_IXGRP
#   define	S_IXGRP	(S_IXUSR >> 3)
#endif

#ifndef S_IXOTH
#   define	S_IXOTH	(S_IXGRP >> 3)
#endif

#ifndef S_IRWXG
#   define S_IRWXG	(S_IRWXU >> 3)
#endif

#ifndef S_IRWXU
#   define S_IRWXU	(__S_IREAD|__S_IWRITE|__S_IEXEC)
#endif

#endif //BCFTOOLS_CMAKE_LINUX2WIN_STAT_MODES_H
