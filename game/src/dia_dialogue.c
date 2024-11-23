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

#include "dia_dialogue.h"
#include "l_log.h"
void dia_loop_dialogue(Dia_Dialogue_Manager *manager, Game_State *gs){
  
  dia_draw_npc_name(manager, gs);
  
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
  top_panel(gs->panels[DIALOGUE_LOG]);
  int num_lines = 0;
  char c = fgetc(fp);
  int processed_bytes;
  int byte_offset;
  int num_bytes = dia_compute_num_bytes(fp);
  dia_draw_dialogue_screen(manager,gs,fp);
    UPDATE_PANEL_INFO();
    while(1){
      int ch = getch();
      if(ch == 'q'){
	hide_panel(gs->panels[DIALOGUE_LOG]);
	UPDATE_PANEL_INFO();
	return;
      }
      else if(ch == KEY_DOWN && manager->single_page_file == NO){
	manager->expected_char_offset = DIA_SAFE_INCREMENT_NEXT(manager,gs,num_bytes,manager->expected_char_offset);
	manager->current_char_offset = dia_recompute_char_offset_forwards(manager,gs,num_bytes,fp);//DIA_SAFE_INCREMENT_NEXT(manager,gs,num_bytes);
	dia_draw_dialogue_screen(manager,gs,fp);
      }
      else if(ch == KEY_UP && manager->single_page_file == NO){
	manager->expected_char_offset = DIA_SAFE_DECREMENT_NEXT(manager,gs,manager->expected_char_offset);
	manager->current_char_offset = dia_recompute_char_offset_backwards(manager, gs, fp);
	dia_draw_dialogue_screen(manager,gs,fp);
	manager->reached_eof = NO;
      }
      else if(isdigit(ch) == 0){
	if(ch - '0' < manager->num_dialogue_options){
	  Dbr_Selected_Dialogue_Qresult selected_dialogue_qresult = dbr_get_dialogue_response(gs,manager,ch - '0');
	  if(selected_dialogue_qresult.selected_dialogue_consequence == DIA_CONTINUE_DIALOGUE){
	    DIA_RESET_DIALOGUE_MANAGER_INFO(manager);
	    dia_extract_next_dialogue_window_info(gs,selected_dialogue_qresult,fp);
	  }
	  else{
	    DIA_EXIT_DIALOGUE_MANAGER(manager);
	  }
	}
      }
    }
}
Dia_Dialogue_Manager *dia_init_dialogue_manager(int dialogue_folder_id, int initial_dialogue_id, int npc_id, Game_State *gs){
  Dia_Dialogue_Manager *manager = malloc(sizeof(Dia_Dialogue_Manager));
  manager->dialogue_folder_id;
  manager->initial_dialogue_id;
  manager->reached_eof = NO;
  manager->single_page_file = NO;
 return manager;
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
/*
int dia_offset_in_list(int offset, Dia_Dialogue_Manager *manager){
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
*/
int (*dia_selected_dialogue_response_handler[2])(Dia_Dialogue_Manager *manager) = {dia_selected_dialogue_advance_dialogue,dia_selected_dialogue_quit};

int dia_selected_dialogue_quit(Dia_Dialogue_Manager *manager){

}

int dia_selected_dialogue_advance_dialogue(Dia_Dialogue_Manager *manager){
  DIA_RESET_DIALOGUE_MANAGER_INFO(manager);
}

FILE *dia_extract_next_dialogue_window_info(Game_State *gs, Dbr_Selected_Dialogue_Qresult selected_dialogue_qresult, FILE *current_dialogue){
  fclose(current_dialogue);
  sprintf(gs->bfr, "%d", selected_dialogue_qresult.next_dialogue_id);
  FILE *new_dialogue_file = fopen(gs->bfr, "r");
  return new_dialogue_file;
}

void dia_draw_npc_name(Dia_Dialogue_Manager *manager, Game_State *gs){
  mvwprintw(gs->logs[DIALOGUE_LOG], 1,(gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) / 3,"Talking to: ");
  char npc_id[10];
  chdir("/usr/lib/revenant_files/npc_name_files/");
  sprintf(npc_id, "%d", manager->npc_id);
  FILE *fp = fopen(npc_id, "r");
  char c = fgetc(fp);
  int curr_name_offset = (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) / 3 + 11;
  while(c != EOF){
    mvwprintw(gs->logs[DIALOGUE_LOG], 1, curr_name_offset, "%c", c);
  c = fgetc(fp);
  curr_name_offset++;
  }
  fclose(fp);
}

void dia_draw_dialogue_screen(Dia_Dialogue_Manager *manager, Game_State *gs, FILE *dialogue_file){
  fseek(dialogue_file, manager->current_char_offset, SEEK_SET);
  char c = fgetc(dialogue_file);
  int current_col = 3;
  int num_lfs = 0;
  while(c != EOF && current_col < gs->num_cols -1){
    int char_offset = 1;
    while(char_offset < (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 1 && c != EOF ){
      if(c == LF){
	num_lfs++;
	DIA_PRINT_NEWLINE(current_col, char_offset,gs);
	char_offset = 0;
	current_col++;
      }
       else{
	 mvwprintw(gs->logs[DIALOGUE_LOG], current_col,char_offset, "%c", c);
       }
      c = fgetc(dialogue_file);
      char_offset++;
      if(c == EOF){
	manager->current_char_offset = 0;
	manager->reached_eof = YES;
	manager->single_page_file = YES;
      }
    }
    char_offset = 1;
    current_col++;
  }
  //printf("num lfs: %d", num_lfs);
  DIA_DRAW_DIALOGUE_BORDER(gs->logs[DIALOGUE_LOG],gs);
  UPDATE_PANEL_INFO();
}

extern inline int dia_recompute_char_offset_forwards(Dia_Dialogue_Manager *manager, Game_State *gs, int maximum_bytes, FILE *dialogue_file){
  int next_current_char_offset;
  fseek(dialogue_file, manager->current_char_offset, SEEK_SET);
  char c = fgetc(dialogue_file);
  for(int char_offset = 1; char_offset < ((gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 1); char_offset++){
    if(c == LF){
      fseek(dialogue_file, manager->current_char_offset+(char_offset+2), SEEK_SET);
      if(c == LF){
	//printf("%d"," Updating special case ",manager->current_char_offset + char_offset);
	return manager->current_char_offset + char_offset;
      }
    }
    c = fgetc(dialogue_file);
  }
  //printf("%d" " updating normally ", DIA_SAFE_INCREMENT_NEXT(manager,gs,maximum_bytes, manager->current_char_offset));
  next_current_char_offset = DIA_SAFE_INCREMENT_NEXT(manager,gs,maximum_bytes, manager->current_char_offset);
  return next_current_char_offset;
}

extern inline int dia_recompute_char_offset_backwards(Dia_Dialogue_Manager *manager, Game_State *gs, FILE *dialogue_file){
  int next_current_char_offset;
  fseek(dialogue_file, manager->current_char_offset-1, SEEK_SET);
  char c_1 = fgetc(dialogue_file);
  fseek(dialogue_file, manager->current_char_offset-2, SEEK_SET);
  char c_2 = fgetc(dialogue_file);
  fseek(dialogue_file, manager->current_char_offset-3, SEEK_SET);
  char c_3 = fgetc(dialogue_file);
  if(c_1 == LF && c_2 == LF){
    return manager->current_char_offset-1;
  }
  else if(c_1 == LF && c_2 != LF){
    next_current_char_offset = manager->current_char_offset-2;
    while(next_current_char_offset % ((gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2) != 0){
      next_current_char_offset--;
      fseek(dialogue_file, next_current_char_offset, SEEK_SET);
      char c = fgetc(dialogue_file);
      if(c == LF){
	return manager->current_char_offset-2;;
      }
    }
    printf("print true");
    int difference = manager->expected_char_offset - manager->current_char_offset;
    return manager->current_char_offset - difference;
  }
  next_current_char_offset = DIA_SAFE_DECREMENT_NEXT(manager,gs, manager->current_char_offset);
  return next_current_char_offset;
}
