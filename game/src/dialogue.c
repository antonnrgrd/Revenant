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
  //  printf("%d", (manager->next_char_offset + (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2));
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
	      /* 
		 Another programmer's sidenote: I initially tried some scheme to trim redundant whitespace that occured in the beginning and                 end of lines. However, this caused issues when scrolling, where the scheme for finding the next offset behaved inconsistenly, namely we would have off by one character character issues, where we would jump to +1 position too high. In the end, i gave and let them be. Besides, less has the same issue, so why should i bother?
	       */
	    }
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
	//printf(" offset wer are using  %d ",manager->next_char_offset);
	Offset_Changes offset_changes = dia_reddraw_dialogue_scroll(manager, gs, fp,manager->next_char_offset, KEY_DOWN);
	if(offset_changes.set_next_offset == NO){
	manager->next_char_offset = DIA_SAFE_INCREMENT_NEXT(manager,gs,num_bytes);
	}
	/*
	  The previous and next fp offset are somewhat askew. It is not until
	  we move beyond the first line that we need to keep track of what the previous line is.
	  until then, the previous offset is 1 and this is what we keep track of
	*/
	manager->set_offset++;
	if(manager->set_offset >= 2){
	  if(offset_changes.set_prev_offset == NO){
	  manager->prev_char_offset = DIA_SAFE_INCREMENT_PREV(manager,gs,num_bytes);
	  }
	}
      }
      else if(ch == KEY_UP){
	manager->reached_eof = NO;
        Offset_Changes offset_changes = dia_reddraw_dialogue_scroll(manager, gs, fp,manager->prev_char_offset, KEY_UP);
	manager->next_char_offset = DIA_SAFE_DECREMENT_NEXT(manager,gs);
	if(offset_changes.set_prev_offset == NO){
	manager->prev_char_offset = DIA_SAFE_DECREMENT_PREV(manager,gs);
	}
	if(manager->set_offset > 0){
	  manager->set_offset --;
	 }
      }
      //printf(" %d ", manager->prev_char_offset % ((gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2 ) );
      // printf();
      
    }
}
Dialogue_Manager *dia_init_dialogue_manager(int dialogue_folder_id, int initial_dialogue_id, int npc_id, Game_State *gs){
  Dialogue_Manager *manager = malloc(sizeof(Dialogue_Manager));
  manager->dialogue_folder_id;
  manager->initial_dialogue_id;
  manager->saved_prev_offsets = NULL;
  manager->current_saved_offset_index = -1;
  manager->encountered_double_lf = 0;
  manager->reached_eof = NO;
 return manager;
}

Offset_Changes dia_reddraw_dialogue_scroll(Dialogue_Manager *manager, Game_State *gs, FILE *fp, int offset, int direction){
  Offset_Changes offset_changes;
  offset_changes.set_next_offset = NO;
  offset_changes.set_prev_offset = NO;
  int curr_name_offset = (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) / 3 + 11;
  chdir("/usr/lib/revenant_files/npc_name_files/");
  char npc_id[10];
  sprintf(npc_id, "%d", manager->npc_id);
  FILE *fp_2 = fopen(npc_id, "r");
  char c_2 = fgetc(fp_2);
  fseek(fp, offset-2, SEEK_SET);
  char c1 = fgetc(fp);
  /*Case when the line we start at is a newline i.e the first char is a LF and we are one the way down on the scroll
*/
  if(c1 == LF  && direction == KEY_DOWN){
    manager->prev_char_offset = offset-2;//;-= ((gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2);
    offset_changes.set_prev_offset = YES;
    /*We have to check if we have already reached EOF when scanning for chars because this logic cannot keep track of the fact that we have not moved to the next line from the last line scroll i.e we are at the the same line as the last time we moved down, with the first char being a LF. Otherwise, we will continuously increment the saved offset index beyond the actual indexes.*/
    if(manager->reached_eof == NO){
    manager->current_saved_offset_index++;
    }
    //printf(" After incrementing, index is %d ",manager->current_saved_offset_index);
    //printf("case 1");
  }
  /*The opposite case i.e when the next line, when scrolling upwards, is a newline*/
  else if(c1 == LF  && direction == KEY_UP){
    manager->prev_char_offset = offset -2;
    offset_changes.set_prev_offset = YES;
    //printf("case 2");
  }

  /*Case when the second previous line was a newline, when scrolling downwards*/
  if (direction == KEY_DOWN){
    fseek(fp, offset - ( (((gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2)) +1), SEEK_SET);
    char myc = fgetc(fp);
    if(myc == LF){
      manager->prev_char_offset = offset -  ( (((gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2)));
      offset_changes.set_prev_offset = YES;
      //printf("case 3");
    }
  }
  
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
  int current_offset = offset;
  
  if(c == LF && direction == KEY_UP){
    /*Future note to self. For some reason, there are a few cases wheere the next_char_offset is computed incorrectly, when hitting this case. To say that i have spendt a LOT of time trying to fix this issue is an understatement. I have therefore decided to let it be for now, since it seems so rare that this happens.*/
    manager->prev_char_offset = manager->saved_prev_offsets[manager->current_saved_offset_index];
      if(manager->current_saved_offset_index > -1){
	manager->current_saved_offset_index --;
	//printf(" After decrementing, index is %d ",manager->current_saved_offset_index);
      }
    offset_changes.set_prev_offset = YES;
    /*If we are scrolling upwards and first character is a LF, skip printing it as it causes inconsistent formatting of the text*/
    c = fgetc(fp);
  }
  while(c != EOF && current_col < gs->num_cols -1){
    int char_offset = 1;
    while(char_offset < (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 1 && c != EOF ){
      if(c == LF){
	/*
	  God this is so fucking asinine. Usually, when scrolling through dialogue, the correct way to update the the next offset would be to       add the length of the dialogue screen to the offset to correctly start printing from the next line, but provided the current line you        are reading ends with a life feed, the correct way to get the next offset it is offset where you encountered the linefeef + one for some reason, getting the next offset the usual way does not work. God how fucking stupid that is.
	*/
	if(current_col == 3 && direction == KEY_DOWN){
	  //printf("case 5");
	  if(char_offset > 1){
	    if(dia_offset_in_list(offset, manager) == NO){
	      manager->encountered_double_lf++;
	      manager->saved_prev_offsets = realloc(manager->saved_prev_offsets,sizeof(int) * manager->encountered_double_lf);
	      manager->saved_prev_offsets[manager->encountered_double_lf-1] = offset;
	    }
	    //manager->current_saved_offset_index++;
	    //printf(" offset is now: %d ",manager->current_saved_offset_index);
	  }
	  manager->next_char_offset = current_offset + 1;
	  offset_changes.set_next_offset = YES;
	}
	else if (current_col == 4 && direction == KEY_UP){
	  //printf("case 7");
	  manager->next_char_offset = (manager->next_char_offset + (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2) - char_offset;
	  offset_changes.set_next_offset = YES;
	  
	}
	  char_offset = 0;
	  current_col++;
	}
	else{
	  mvwprintw(gs->logs[DIALOGUE_LOG], current_col,char_offset, "%c", c);
	}
      c = fgetc(fp);
      if(c == EOF){
	offset_changes.set_next_offset = YES;
	manager->reached_eof = YES;
      }
      char_offset++;
      current_offset++;
    }
    char_offset = 1;
    current_col++;
  }
  UPDATE_PANEL_INFO();
  return offset_changes;
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



void dia_print_char_at_offset(FILE *fp, int offset){
  fseek(fp, 0, SEEK_SET);
  char ch = fgetc(fp);
  for(int i = 0; i < 5; i++ ){
    printf("%c", ch);
    ch = fgetc(fp);
  }
  fseek(fp, 0, SEEK_SET);
}

int dia_offset_in_list(int offset, Dialogue_Manager *manager){
  if(manager->saved_prev_offsets == NULL){
    return NO;
  }
  else{
    for(int i = 0; i < manager->encountered_double_lf; i++){
      if(manager->saved_prev_offsets[i] == offset){
	return YES;
      }
   }
    return NO;
  }
}
