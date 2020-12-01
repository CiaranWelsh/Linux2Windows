//
// Created by Ciaran on 01/12/2020.
//

#ifndef SAMTOOLS_CMAKE_LINUX2WIN_REGEX_H
#define SAMTOOLS_CMAKE_LINUX2WIN_REGEX_H

#include "linux2win_config.h"

#ifdef HAVE_REGEX_H
#include <regex.h>
#endif

#ifdef HAVE_REGEX
#include <regex>
#endif

#endif //SAMTOOLS_CMAKE_LINUX2WIN_REGEX_H
