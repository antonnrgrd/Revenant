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

#ifndef L_LOG
#define L_LOG
#include "l_log_struct.h"
char *l_add_metadata_to_msg(char *msg, char *debug_lvl);
void l_write_log(char *msg, char *debug_lvl, int verbosity_flag);
#define L_WRITE_OS_LEVEL_ERROR(bfr){ \
    perror("Game encountered an unrecoverable OS-level error. See the message after the colon for a hint as to what the issue is:"); \
    l_write_log(bfr, L_ERROR);						\
  }
#endif
