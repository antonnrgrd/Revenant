/*This file is part of Revenant.
Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
Revenant  is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */
#ifndef GENERIC_MACROS
#define GENERIC_MACROS
#include <stdlib.h>
#define YES 0
#define NO 1
#define END_TURN 0
#define CONTINUE_TURN 1
#define FREE_NULL(ptr){\
    free(ptr);					\
    (ptr) = NULL;				\
}
#define MAX(num_1, num_2) num_1 > num_2 ? num_1 : num_2
#define MIN(num_1, num_2) num_1 < num_2 ? num_1 : num_2
#define LF 10
#define SPACE 32
#define NEWLINE 13
// Some errors are not an unexpected game state but rather occur at the os level, for these kind of errors
//we want in addition to get the stderror
#define L_WRITE_OS_LEVEL_ERROR(msg){			\
    endwin();						\
    fprintf(stderr,"The game encountered the following unrecoverable OS-level issue and was forced to terminate:\n%s\nPlease note down what you were doing when you saw this message and hand over the log file at /var/log/revenant.log", msg); \
    perror("In addition, see the message that comes after the colon for further hints as to what went wrong"); \
   exit(EXIT_FAILURE); \
  }
#endif
