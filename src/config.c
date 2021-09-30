/*
  Xiphos, a UCI chess engine
  Copyright (C) 2018, 2019 Milos Tatarevic

  (With additions from Marc-Philippe Huget)

  Xiphos is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Xiphos is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void getNbCores() {

    long nprocs = -1;
    long nprocs_max = -1;

    #ifdef _WIN32
        #ifndef _SC_NPROCESSORS_ONLN
            SYSTEM_INFO info;
            GetSystemInfo(&info);
            #define sysconf(a) info.dwNumberOfProcessors
            #define _SC_NPROCESSORS_ONLN
        #endif
    #endif

    #ifdef _SC_NPROCESSORS_ONLN
        nprocs = sysconf(_SC_NPROCESSORS_ONLN);
        if (nprocs < 1) {
            fprintf(stderr, "Could not determine number of CPUs online:\n%s\n", 
            strerror (errno));
            exit (EXIT_FAILURE);
        }
  
        nprocs_max = sysconf(_SC_NPROCESSORS_CONF);
        if (nprocs_max < 1) {
            fprintf(stderr, "Could not determine number of CPUs configured:\n%s\n", 
            strerror (errno));
            exit (EXIT_FAILURE);
        }
  
        printf ("%ld of %ld processors online\n",nprocs, nprocs_max);
        exit (EXIT_SUCCESS);
    #else
        fprintf(stderr, "Could not determine number of CPUs");
        exit (EXIT_FAILURE);
    #endif


}