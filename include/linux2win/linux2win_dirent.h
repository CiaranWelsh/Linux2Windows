
/*
 * Dirent interface for Microsoft Visual Studio
 *
 * Copyright (C) 2006-2012 Toni Ronkko
 * This file is part of dirent.  Dirent may be freely distributed
 * under the MIT license.  For all details and documentation, see
 * https://github.com/tronkko/dirent
 */
#ifndef DIRENT_H
#define DIRENT_H

#ifdef HAVE_DIRENT_H
#   include <dirent.h"
#else

#   include "linux2win/_dirent.h"

#endif

#endif
#endif /*DIRENT_H*/