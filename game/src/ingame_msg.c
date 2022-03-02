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


#include "ingame_msg.h"
#include "game_state.h"
void msg_show_log(Game_State *gs, int panel_index){
  top_panel(gs->panels[panel_index]);
  // We defer the refreshing of screen contents of the panels until
  // we actually want to see them, because if we refresh them immedately upon manipulating it conflicts
  //with the contents of the main screen. update_panels + doupdate does this for us so no need to call wfrefresh
  update_panels(); 
  doupdate();
  int ch;
  while (1){
    ch = getch();
    if (ch == 'q'){
      hide_panel(gs->panels[panel_index]);
      update_panels();
      doupdate();
      return;
    }
  }
}
 
int msg_find_log_position(Game_State *gs){
  char *line_contents = malloc(MAX_MSG_LENGTH * sizeof(char));
  for(int i = 3; i< 13; i++){
      mvwinnstr(gs->logs[EVENT_LOG], i,23,line_contents,MAX_MSG_LENGTH-1);
      //printf("%d%s", line_contents[0], " ");
      //      printf("%d",s_only_whitespace(line_contents));
      if(s_only_whitespace(line_contents) == 1){
	free(line_contents);
	return i;
      }
  }
  //printf("%s",line_contents);  
  free(line_contents);
  return -1;
}
  
void msg_update_event_log(Game_State *gs){
  char *msg_bfr = malloc(MAX_MSG_LENGTH * sizeof(char));
  mvwinnstr(gs->logs[MAIN_SCREEN], DEFAULT_MAX_Y,0,msg_bfr,MAX_MSG_LENGTH-1);
  int free_log_position = msg_find_log_position(gs);
  // printf("%d%s",free_log_position, " ");
  if(free_log_position != -1){
    if(free_log_position < 12){
      UPDATE_ADD_TO_LOG(gs,position,msg_bfr,12);
    }
    else{
      //We change the offset where print if the found y position is 13 because the offset position is 2 digits and so we counter that by increasing the offst
      UPDATE_ADD_TO_LOG(gs,position,msg_bfr,14);
    }
  }
  else{
    UPDATE_PUSH_ADD_TO_LOG(gs,msg_bfr);
   }
}
 
 
 
