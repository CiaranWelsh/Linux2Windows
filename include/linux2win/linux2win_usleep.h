#ifndef LINUX2WIN_USLEEP_H
#define LINUX2WIN_USLEEP_H

#include "linux2win_config.h"


#ifdef HAVE_USLEEP_H
#   include <usleep.h>
#else

#   include "linux2win/_usleep.h"

#endif


#endif //LINUX2WIN_USLEEP_H