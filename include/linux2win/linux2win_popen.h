//
// Created by Ciaran on 01/12/2020.
//

#ifndef SAMTOOLS_CMAKE_LINUX2WIN_POPEN_H
#define SAMTOOLS_CMAKE_LINUX2WIN_POPEN_H

#ifdef HAVE_PIPE
inline int _pipe(int fildes[2], unsigned psize, int textmode) {
   return pipe(fildes);
}
#endif

#ifdef HAVE_POPEN
inline FILE* _popen(const char* command, const char* type) {
   return popen(command, type);
}
#endif

#ifdef HAVE_PCLOSE
inline void _pclose(FILE* file) {
   pclose(file);
}
#endif

#endif

#endif //SAMTOOLS_CMAKE_LINUX2WIN_POPEN_H
