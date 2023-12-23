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
#include "err_handler.h"
#include <stdio.h>
#include <time.h>

char *err_get_timestamp()
void err_append_err(char *err){
  FILE *err_log = fopen("/usr/lib/revenant_files/misc_files/err.log", "a");
  while(fgets(err, sizeof(err), err_log)) {
        fprintf(err_log, "%s", buffer);
    }
  fclose(err_log);
}
