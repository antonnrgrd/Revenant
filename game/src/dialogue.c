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
  while(c != EOF && current_col < gs->num_cols -1){
    int char_pos = 0;
    // while( line[char_pos] != '\0'  && */ current_col < gs->num_cols -1){
	  int char_offset = 1;
	  /*Printing the characters one by one is most likely infinitely more ineffecient that printing lines at a time
	   but coming up with a more clever scheme that always prints a line that is at most as long as the screen width
	   and formats everything neatly appears to be way more complex logic so doing this character by character will have to do*/
	  while(char_offset < (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 1 && c != EOF ){
	    if(c == LF){
	      /*No idea why we have to set the offset to 0 here to get it to format properly, presumably because the line feed behaves differently than a whitespace when it comes to how it affects formatting? In any case, we have to set the offset to 0 instead of 1 to get it to print properly and force it to move down the the next line (in ncurses logic)*/
	      char_offset = 0;
	      current_col++;
	    }
	    /*I actually don't know if the two cases for encountering whitespace could be merged somehow, but in any case, these two else if cases handle the logic when the first or the last character is a whitespace, in which case we skip printing it and optionally reset the character position*/
	    else if(c == SPACE && char_offset == 1){
	      /*Again, no idea whu i have to change */
	      char_offset = 0;
	    }
	    else if(c == SPACE && char_offset == (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) -1 ){
	      /*We substract from the current number of printed characters, allowing the next non whitespace character to be printed there instead if the last character one the current line is a whitespace*/
	      char_offset--;
	    }
	    else{
	      mvwprintw(gs->logs[DIALOGUE_LOG], current_col,char_offset, "%c", c);
	    }
	    c = fgetc(fp);
	    //char_pos++;
	    char_offset++;
	    }
	  char_offset = 1;
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
