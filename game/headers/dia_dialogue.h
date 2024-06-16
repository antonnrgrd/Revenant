/*This file is part of Revnant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */


#ifndef DIALOGUE
#define DIALOGUE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include "strings.h"
#include "msg_ingame_msg.h"
#include "generic_macros.h"
#include "game_state_struct.h"
#include "screen_constants.h"
#include "dbr_db_reader.h"
#include "dia_dialogue_struct.h"


#define DIA_PRINT_NEWLINE(current_col_offset,char_offset,gs)for(int row_offset = char_offset; row_offset < ((gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 1) ;  row_offset++) mvwprintw(gs->logs[DIALOGUE_LOG], current_col,row_offset, " ");
/*For exiting the dialogue, returning control to the game world*/
#define DIA_EXIT_DIALOGUE_MANAGER(manager){\
  manager->current_char_offset = 0; \
  manager->reached_eof = NO;	 \
  manager->expected_char_offset = 0;		\
}

/*For continuing to the next dialogue screen, ensuring we start with a clean plate*/
#define DIA_RESET_DIALOGUE_MANAGER_INFO(manager){\
    manager->current_char_offset = 0;		 \
    manager->num_dialogue_options = 0;		 \
    manager->current_dialogue_id = 0;		 \
    manager->reached_eof = NO;			 \
    manager->single_page_file = NO;		 \
    manager->expected_char_offset = 0;		 \
}





/*Normally, we'd be content using the box function to draw a border around the wndow, but we want an ultra specific bordering set, you we have to do it manually */
#define DIA_DRAW_DIALOGUE_BORDER(dia_dialogue_screen,gs) mvwhline(dia_dialogue_screen, 0, 0, 0, (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) -1); mvwhline(dia_dialogue_screen, 2, 1, 0, (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) -2 ); mvwvline(dia_dialogue_screen, 0, 0, 0, gs->num_cols); mvwvline(dia_dialogue_screen, 1, (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) -1, 0, gs->num_cols);  mvwaddch(dia_dialogue_screen,0, 0, ACS_ULCORNER); mvwaddch(dia_dialogue_screen,0, (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) -1, ACS_URCORNER);

#define DIA_SET_OFFSET(offset, dia_dia_manager) dia_manager->set_offset == NO ? dia_manager->current_char_offset = offset : ;

/*No fucking idea why, but the decrement substracts an offset of 4 too many, so we offset this by adding 4. No idea if this is by how macro evaluted the expression or what. I fucking hate this so much*/
#define DIA_SAFE_DECREMENT_NEXT(manager,gs) (manager->current_char_offset - (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2) <= 0 ? (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2  : (manager->current_char_offset - (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2) + 4

#define DIA_SAFE_INCREMENT_NEXT(manager,gs,maximum_bytes) manager->current_char_offset + (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) >= maximum_bytes ? maximum_bytes - (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) : (manager->current_char_offset + (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2)

void dia_loop_dialogue(Dia_Dialogue_Manager *manager, Game_State *gs);

int dia_compute_num_bytes(FILE *fp);
Dia_Dialogue_Manager *dia_init_dialogue_manager(int dialogue_folder_id, int initial_dialogue_id, int npc_id, Game_State *gs);

int dia_redraw_text_scroll(Dia_Dialogue_Manager *manager, Game_State *gs, FILE *fp, int offset);

void dia_print_char_at_offset(FILE *fp, int offset);

void dia_print_char_at_offset_times(FILE *fp, int times);

void dia_safe_find_next_offset(Dia_Dialogue_Manager *manager, Game_State *gs, int maximum_bytes);

Dia_Offset_Changes dia_reddraw_dialogue_scroll(Dia_Dialogue_Manager *manager, Game_State *gs, FILE *fp, int offset, int direction);

dia_find_next_nonlf_char(FILE *fp,Dia_Dialogue_Manager *manager,char currchar, int start_offset, int current_offset);

int dia_offset_in_list(int offset, Dia_Dialogue_Manager *manager);

extern int (*dia_selected_dialogue_response_handler[2])(Dia_Dialogue_Manager *manager);
int dia_selected_dialogue_quit(Dia_Dialogue_Manager *manager);
int dia_selected_dialogue_advance_dialogue(Dia_Dialogue_Manager *manager);
FILE *dia_extract_next_dialogue_window_info(Game_State *gs, Dbr_Selected_Dialogue_Qresult selected_dialogue_info, FILE *current_dialogue);

void dia_redraw_dialogue_screen(Dia_Dialogue_Manager *manager, Game_State *gs, FILE *dialogue_file);

void dia_draw_npc_name(Dia_Dialogue_Manager *manager, Game_State *gs);

extern inline int dia_recompute_char_offset_forwards(Dia_Dialogue_Manager *manager, Game_State *gs, int maximum_bytes, FILE *dialogue_file);

extern inline int dia_recompute_char_offset_backwards(Dia_Dialogue_Manager *manager, Game_State *gs, FILE *dialogue_file);
#endif

