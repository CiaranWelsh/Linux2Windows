cmake_minimum_required(VERSION 3.18)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)
set(PROJECT_VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

project(Linux2Windows VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 14)

include(CheckSymbolExists)
include(CheckCXXSymbolExists)
include(CheckLibraryExists)
include(CheckIncludeFile)
include(CheckIncludeFileCXX)
include(CheckFunctionExists)
include(CheckTypeSize)
include(GNUInstallDirs)

# put all runtime targets (exe and dll) into bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

# put libraries into lib
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)

# archives
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)

##########################################################################################
#   Defines for config.h.in
#
#/* Define to 1 if you have the unistd. This way is preferable to #ifdef _WIN32 because
# _WIN32 is also defined on WSL. */
check_include_file(unistd.h HAVE_UNISTD_H)

# check to see if we have sys/time.h
check_include_file(sys/time.h HAVE_SYS_TIME_H)

# check to see if we have getopt
check_include_file(getopt.h HAVE_GETOPT_H)

# check to see if we have usleep
check_function_exists(usleep HAVE_USLEEP_H)

# on linux we have include strings while windows its string (no 's')
check_include_file(string.h HAVE_STRING)
check_include_file(strings.h HAVE_STRINGS)

# Check whether we have dirent.h
check_include_file(dirent.h HAVE_DIRENT_H)

# Check whether we have dlfcn.h
check_include_file(dlfcn.h HAVE_DLFCN_H)

# check to see if ssize_t exists. On linux yes, windows no.
check_type_size(ssize_t SSIZE_T LANGUAGE C)

# Check whether we have regex.h
check_include_file(regex.h REGEX_H) # linux

# Check whether we have regex
check_include_file(regex REGEX) # win

# Check whether we have strings.h
check_include_file(strings.h HAVE_STRINGS_H)

# Check whether we have string.h
check_include_file(string.h HAVE_STRING_H)

#/* check if we have pipe C function
check_function_exists(pipe HAVE_PIPE)

#/* check if we have popen C function
check_function_exists(popen HAVE_POPEN)

#/* check if we have pclose C function
check_function_exists(pcose HAVE_CLOSE)

configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/linux2win_config.h.in"
        "${CMAKE_CURRENT_BINARY_DIR}/linux2win_config.h"
)


# define an interface target that propagates include directories to
#   other targets
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/include/linux2win/*")
MESSAGE(STATUS "SOURCES ${SOURCES}")
add_library(linux2win STATIC ${SOURCES})

set_target_properties(linux2win PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(linux2win PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
        "$<INSTALL_INTERFACE:include>"
        )

install(TARGETS linux2win )





