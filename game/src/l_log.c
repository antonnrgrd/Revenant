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
void l_add_metadata_to_msg(char *msg, char *debug_lvl){
  time_t now;
  time(&now);
  //prepend hyphen padding
  msg = s_append_to_string(msg, " - ");
  //prepend debug level
  msg = s_append_to_string(msg, debug_lvl);
  //prepend timestmap
  msg = s_append_to_string(msg, ctime(&now));

  return msg;
}
// Assumes msg to be written is already defined and has sufficient space for prepending the timestamp + debugging lvl.
void l_write_log(char *msg , char *debug_lvl, char *fpath){

  char *msg_with_metadata = l_add_metadata_to_msg(msg,debug_lvl);
  FILE *fp = fopen(DEFAULT_LOGGING_FILE, "a");
  fprintf(fp,msg_with_metadata);
  fclose(fp);
  if(debug_lvl == L_ERR){
    endwin();
    exit(1);
    printf(bfr);
  }
}


