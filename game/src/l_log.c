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
char *l_add_metadata_to_msg(char *msg, char *debug_lvl){
  //prepend hyphen padding
  msg = s_append_to_string(msg, " - ");
  //prepend debug level
  msg = s_append_to_string(msg, debug_lvl);
  //prepend a formatting colon
  msg = s_append_to_string(msg, ": ");
  //prepend timestmap
  time_t now;
  time(&now);
  //Annoyingly, the timestamp ends with a newline. We need to have this removed first.
  msg = s_append_to_string(msg, s_replace_all_char_occurences(ctime(&now), '\n', SPACE));
  return msg;
}
// Assumes msg to be written is already defined and has sufficient space for prepending the timestamp + debugging lvl.
void l_write_log(char *msg , char *debug_lvl, int verbosity_flag){

  char *msg_with_metadata = l_add_metadata_to_msg(msg,debug_lvl);
  FILE *fp = fopen(DEFAULT_LOGGING_FILE, "a");
  if(fp == NULL){
    endwin();
    perror("Error when trying to access the log file for writing, see the message that comes after the colon for a hint as to what's the issue");
    exit(EXIT_FAILURE);
  }
  fprintf(fp,msg_with_metadata);
  //Hacky, but ensures we never have to consider adding newlines to the messages directly
  fprintf(fp,"\n");
  fclose(fp);
  if(verbosity_flag == L_LOG_VERBOSELY && strcmp(debug_lvl,L_ERR) != YES){
    printf(msg);
  }
  if(strcmp(debug_lvl,L_ERR) == YES){
    // Note - it is important to call endwin first to get the desired behavior
    endwin();
    fprintf(stderr,"The game encountered the following unrecoverable issue and was forced to terminate:\n%s\nPlease note down what you were doing when you saw this message and hand over the log file at /var/log/revenant.log", msg);
    exit(EXIT_FAILURE);
  }
}


