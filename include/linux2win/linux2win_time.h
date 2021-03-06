#ifndef LINUX2WIN_TIME_H
#define LINUX2WIN_TIME_H

#include "linux2win_config.h"


#ifdef HAVE_SYS_TIME_H
#   include <time.h>
#   include <sys/time.h>
#else
#   include "linux2win/_time.h"
#endif


#endif //LINUX2WIN_TIME_H