/*This file is part of Revenant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */


#include "dialogue.h"

void dia_loop_dialogue(Dialogue_Manager *manager, Game_State *gs){

  chdir("/usr/lib/revenant_files/dialogue_files");
  char dialogue_folder[10];
  char dialogue_id[10];
  sprintf(dialogue_folder, "%d", manager->dialogue_folder_id);
  chdir(dialogue_folder);
  sprintf(dialogue_id, "%d", manager->initial_dialogue_id);
  FILE *fp = fopen(dialogue_id, "r");
  if(fp == NULL){
    return;
  }
  char * line = NULL;
  size_t len = 0;
  int current_col = 1;
  top_panel(gs->panels[DIALOGUE_LOG]);
  int num_lines = 0;
  //while((getline(&line, &len, fp)) != -1 ){
  char c = fgetc(fp);
  while(c != EOF && c != '�' && current_col < gs->num_cols -1){
    int char_pos = 0;
    // while( line[char_pos] != '\0'  && */ current_col < gs->num_cols -1){
	  int printed_chars = 0;
	  /*Printing the characters one by one is most likely infinitely more ineffecient that printing lines at a time
	   but coming up with a more clever scheme that always prints a line that is at most as long as the screen width
	   and formats everything neatly appears to be way more complex logic so doing this character by character will have to do*/
	  while(printed_chars < (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2 && c != EOF ){
	    if(c == LF){
	      printed_chars = 0;
	      current_col++;
	    }
	    else{
	      mvwprintw(gs->logs[DIALOGUE_LOG], current_col,printed_chars+1, "%c", c /*line[char_pos] */);
	    }
	    c = fgetc(fp);
	    //char_pos++;
	    printed_chars++;
	    }
	  printed_chars = 0;
	  current_col++;
	  //}
    num_lines++;
    //}
  }
   UPDATE_PANEL_INFO();
    while(1){
      int ch = getch();
      if(ch == 'q'){
	hide_panel(gs->panels[DIALOGUE_LOG]);
	UPDATE_PANEL_INFO();
	return;
      }
    }
}

Dialogue_Manager *dia_init_dialogue_manager(int dialogue_folder_id, int initial_dialogue_id){
  Dialogue_Manager *manager = malloc(sizeof(Dialogue_Manager));
  manager->dialogue_folder_id;
  manager->initial_dialogue_id;
 return manager;
}
