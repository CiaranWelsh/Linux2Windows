cmake_minimum_required(VERSION 3.18)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)
set(PROJECT_VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

project(Linux2Windows VERSION ${PROJECT_VERSION})

# this should be set by the top level project!
#set(CMAKE_CXX_STANDARD 14)

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

# check if pid_t exists. Linux yes, windows no.
check_symbol_exists(pid_t "sys/types.h" HAVE_PID_T)

# Check if we have stdint.h
check_include_file(stdint.h HAVE_STDINT_H)

message(STATUS "HAVE_STDINT_H ${HAVE_STDINT_H}")
configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/linux2win_config.h.in"
        "${CMAKE_CURRENT_BINARY_DIR}/linux2win_config.h"
)


# define an interface target that propagates include directories to
#   other targets

set(
        SOURCES
        include/linux2win/linux2win_dirent.h
        include/linux2win/linux2win_dlfcn.h
        include/linux2win/linux2win_getopt.h
        include/linux2win/linux2win_mkstemp.h
        include/linux2win/linux2win_popen.h
        include/linux2win/linux2win_regex.h
        include/linux2win/linux2win_stat_modes.h
        include/linux2win/linux2win_strings.h
        include/linux2win/linux2win_time.h
        include/linux2win/linux2win_unistd.h
        include/linux2win/linux2win_usleep.h
        include/linux2win/linux2win_error.h
)

if (NOT HAVE_DIRENT)
    set(SOURCES ${SOURCES} include/linux2win/_dirent.h)
endif()

if (NOT HAVE_DLFCN)
    set(SOURCES ${SOURCES} include/linux2win/_dlfcn.h src/_dlfcn.c)
endif()

if (NOT HAVE_GETOPT)
    set(SOURCES ${SOURCES} include/linux2win/_getopt.h src/_getopt.c)
endif()

if (NOT HAVE_TIME)
    set(SOURCES ${SOURCES} include/linux2win/_time.h src/_time.c)
endif()

if (NOT HAVE_UNISTD)
    set(SOURCES ${SOURCES} include/linux2win/_unistd.h)
endif()

if (NOT HAVE_USLEEP)
    set(SOURCES ${SOURCES} include/linux2win/_usleep.h src/_usleep.c)
endif()

MESSAGE(STATUS "SOURCES ${SOURCES}")
add_library(linux2win STATIC ${SOURCES})

set_target_properties(linux2win PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(linux2win PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
        "$<INSTALL_INTERFACE:include>"
        )

install(TARGETS linux2win )





