//
// Created by Ciaran on 01/12/2020.
//

#ifndef SAMTOOLS_CMAKE_LINUX2WIN_ERROR_H
#define SAMTOOLS_CMAKE_LINUX2WIN_ERROR_H

#ifdef _MSC_VER
#   include <errors.h>
#else
#   include <err.h>
#   include <errno.h>
#   include <error.h>
#endif

#endif //SAMTOOLS_CMAKE_LINUX2WIN_ERROR_H
