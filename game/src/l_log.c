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

#include "l_log.h"
void l_write_log(char *bfr, char *msg , char *debug_lvl, char *fpath){
  time_t now;
  time(&now);
  sprintf(bfr, "%s: %s - %s", ctime(&now), debug_lvl, msg);
  FILE *fp = fopen(DEFAULT_LOGGING_FILE, "a");
  fprintf(fp,bfr);
  fclose(fp);
  if(debug_lvl == L_ERR){
    endwin();
    exit(1);
    printf(bfr);
  }
}
