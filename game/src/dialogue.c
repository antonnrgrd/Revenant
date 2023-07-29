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
  manager->next_char_offset = (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2 ;
  manager->prev_char_offset = 0;
  manager->set_offset = 0;
  mvwprintw(gs->logs[DIALOGUE_LOG], 1,(gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) / 3,"Talking to: ");
  char npc_id[10];
  chdir("/usr/lib/revenant_files/npc_name_files/");
  sprintf(npc_id, "%d", manager->npc_id);
  FILE *fp_2 = fopen(npc_id, "r");
  char c_2 = fgetc(fp_2);
  int curr_name_offset = (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) / 3 + 11;
  while(c_2 != EOF){
    mvwprintw(gs->logs[DIALOGUE_LOG], 1, curr_name_offset, "%c", c_2);
  c_2 = fgetc(fp_2);
  curr_name_offset++;
  }
  fclose(fp_2);
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
  int current_col = 3;
  top_panel(gs->panels[DIALOGUE_LOG]);
  int num_lines = 0;
  char c = fgetc(fp);
  int processed_bytes;
  int byte_offset;
  int num_bytes = dia_compute_num_bytes(fp);
  while( c != EOF && current_col < gs->num_cols -1){
	  int char_offset = 1;
	  /*Printing the characters one by one is most likely infinitely more ineffecient that printing lines at a time
	   but coming up with a more clever scheme that always prints a line that is at most as long as the screen width
	   and formats everything neatly appears to be way more complex logic so doing this character by character will have to do*/
	  while(char_offset < (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 1 && c != EOF ){
	    //	    byte_offset++;
	    if(c == LF){
	      /*No idea why we have to set the offset to 0 here to get it to format properly, presumably because the line feed behaves differently than a whitespace when it comes to how it affects formatting? In any case, we have to set the offset to 0 instead of 1 to get it to print properly and force it to move down the the next line (in ncurses logic)*/
	      char_offset = 0;
	      current_col++;
	      //if(){

	      //}
	    }
	    /*I actually don't know if the two cases for encountering whitespace could be merged somehow, but in any case, these two else if cases handle the logic when the first or the last character is a whitespace, in which case we skip printing it and optionally reset the character position*/
	    else if(c == SPACE && char_offset == 1){
	      /*Again, no idea why i have to change offset to 0 instead of the usual 1 to get it to format properly, but that's how it is*/
	      char_offset = 0;
	    }
	    /*
	      I really don't think you can format the text properly when the last character is a whitespace, because no matter what, it is gonna look ugly. THis is because if you skip printing the newline, the alternatively it remove a whitespace and just print the next character which will look ugly. You can only skip the redundandt whitespace if it is the first character
	    else if(c == SPACE && char_offset == (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) -2 ){
	      printf("true");
	      char_offset--;
	    }
	    */
	    else{
	      mvwprintw(gs->logs[DIALOGUE_LOG], current_col,char_offset, "%c", c);
	    }
	    c = fgetc(fp);
	    char_offset++;
	    byte_offset++;
	    }
	  char_offset = 1;
	  current_col++;

    num_lines++;
  }
   UPDATE_PANEL_INFO();
    while(1){
      int ch = getch();
      if(ch == 'q'){
	hide_panel(gs->panels[DIALOGUE_LOG]);
	UPDATE_PANEL_INFO();
	return;
      }
      else if(ch == KEY_DOWN){
	dia_reddraw_dialogue_scroll(manager, gs, fp,manager->next_char_offset);
	manager->next_char_offset = DIA_SAFE_INCREMENT_NEXT(manager,gs,num_bytes);
	/*
	  The previous and next fp offset are somewhat askew. It is not until
	  we move beyond the first line that we need to keep track of what the previous line is.
	  until then, the previous offset is 1 and this is what we keep track of
	*/
	manager->set_offset++;
	if(manager->set_offset >= 2){
	  manager->prev_char_offset = DIA_SAFE_INCREMENT_PREV(manager,gs,num_bytes);
	}
      }
      else if(ch == KEY_UP){
	dia_reddraw_dialogue_scroll(manager, gs, fp,manager->prev_char_offset);
	manager->next_char_offset = DIA_SAFE_DECREMENT_NEXT(manager,gs);
	manager->prev_char_offset = DIA_SAFE_DECREMENT_PREV(manager,gs);
	if(manager->set_offset > 0){
	  manager->set_offset --;
	}
      }
    }
}
Dialogue_Manager *dia_init_dialogue_manager(int dialogue_folder_id, int initial_dialogue_id, int npc_id){
  Dialogue_Manager *manager = malloc(sizeof(Dialogue_Manager));
  manager->dialogue_folder_id;
  manager->initial_dialogue_id;
 return manager;
}

void dia_reddraw_dialogue_scroll(Dialogue_Manager *manager, Game_State *gs, FILE *fp, int offset){
  int curr_name_offset = (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) / 3 + 11;
  chdir("/usr/lib/revenant_files/npc_name_files/");
  char npc_id[10];
  sprintf(npc_id, "%d", manager->npc_id);
  FILE *fp_2 = fopen(npc_id, "r");
  char c_2 = fgetc(fp_2);
  fseek(fp, offset, SEEK_SET);
  wclear(gs->logs[DIALOGUE_LOG]);
  DIA_DRAW_DIALOGUE_BORDER(gs->logs[DIALOGUE_LOG],gs);
  mvwprintw(gs->logs[DIALOGUE_LOG], 1,(gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) / 3,"Talking to: ");
  while(c_2 != EOF){
    mvwprintw(gs->logs[DIALOGUE_LOG], 1, curr_name_offset, "%c", c_2);
  c_2 = fgetc(fp_2);
  curr_name_offset++;
  }
  fclose(fp_2);
  int current_col = 3;
  char c = fgetc(fp);
  while(c != EOF && current_col < gs->num_cols -1){
    int char_offset = 1;
    while(char_offset < (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 1 && c != EOF ){
      if(c == LF){
	  char_offset = 0;
	  current_col++;
	}
	else if(c == SPACE && char_offset == 1){
	  char_offset = 0;
	}
	else{
	  mvwprintw(gs->logs[DIALOGUE_LOG], current_col,char_offset, "%c", c);
	}
      c = fgetc(fp);
      char_offset++;
    }
    char_offset = 1;
    current_col++;
  }
  UPDATE_PANEL_INFO();
}

int dia_compute_num_bytes(FILE *fp){
  int found_bytes = 1;
  char ch = fgetc(fp);
  while(ch != EOF){
    ch = fgetc(fp);
    found_bytes++;
  }
  fseek(fp, 1, SEEK_SET);
  return found_bytes;
}

/*
int dia_redraw_text_scroll(WINDOW *w,FILE *fp, int byte_offset){
  werase(w);
  fseek(fp, byte_offset, SEEK_SET);
  char ch = fgetc(fp);
  int current_col = 3;
  int new_byte_offset =;
  while(ch != EOF && current_col < gs->num_cols -1){
    fbytes++;
    int char_pos = 0;
    // while( line[char_pos] != '\0'  &&  current_col < gs->num_cols -1){
	  int char_offset = 1;
	  have to do
	  while(char_offset < (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 1 && c != EOF ){
	    byte_offset++;
	    if(c == LF){
	   
	      char_offset = 0;
	      current_col++;
	    }
	   	    else if(c == SPACE && char_offset == 1){
	     
	      char_offset = 0;
	    }
	    else{
	      mvwprintw(gs->logs[DIALOGUE_LOG], current_col,char_offset, "%c", c);
	    }
	    c = fgetc(fp);
	    char_offset++;
	    }
	  char_offset = 1;
	  current_col++;
    num_lines++;
  }
  UPDATE_PANEL_INFO();
}
*/
