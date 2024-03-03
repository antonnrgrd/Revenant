/*This file is part of Revnant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar.  If not, see <https://www.gnu.org/licenses/>. */


#ifndef DIALOGUE
#define DIALOGUE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include "strings.h"
#include "ingame_msg.h"
#include "generic_macros.h"
#include "game_state_struct.h"
#include "screen_constants.h"
#include "db_reader.h"
#define END_DIALOGUE 0
#define CONTINUE_DIALOGUE 1
#define NO_NEXT_DIALOGUE_ID -1
#define NO_SKILLCHECK -1
#define NO_SKILL_ID -1
#define NULL_AMOUNT_DIALOGUE_OPTIONS -1


//
/*For exiting the dialogue, returning control to the game world*/
#define DIA_EXIT_DIALOGUE_MANAGER(manager){\
  manager->next_char_offset = 0; \
  manager->prev_char_offset = 0; \
  manager->set_offset = NO;	 \
  manager->reached_eof = NO;	 \
}

/*For continuing to the next dialogue screen, ensuring we start with a clean plate*/
#define DIA_RESET_DIALOGUE_MANAGER_INFO(manager){\
    FREE_NULL(manager->saved_prev_offsets);	 \
    manager->next_char_offset = 0;		 \
    manager->prev_char_offset = 0;		 \
    manager->num_dialogue_options = 0;		 \
    manager->current_dialogue_id = 0;		 \
    manager->current_saved_offset_index = 0;	 \
    manager->encountered_double_lf = NO;	 \
    manager->set_offset = NO;			 \
    manager->reached_eof = NO;			 \
    manager->single_page_file = NO;		 \
}

typedef struct {
  /*the id of the folder we should look in for the dialogue files*/
  int dialogue_folder_id;
  /*The id of the initial dialogue file the player should see upon engaging conversation*/
  int initial_dialogue_id;
  /**/
  int npc_id;
  int num_dialogue_options;
  int current_dialogue_id;
  int next_char_offset;
  int prev_char_offset;
  int *saved_prev_offsets;
  int current_saved_offset_index;
  int encountered_double_lf;
  int set_offset;
  /*Note: if using single bit, bit-packed values, you need to use an unsigned int. If you use a regular signed int, you need at least two bits worth, in order to be able to differentiate between positive and negative numbers, otherwise, you get unusual behavior */
  unsigned int reached_eof : 1;
  /*In the event that the text file fits into a single window, we need to keep extra track of this to avoid unecessarily updating the next and prev char offsets. I don't know if we already store sufficient logic to check this but at this point i am too lazy and have spendt too much time to bother coming up with a more clever solution */
  unsigned int single_page_file : 1;
}Dialogue_Manager;

typedef struct{
  short set_next_offset;
  short set_prev_offset;
}Offset_Changes;

/*Normally, we'd be content using the box function to draw a border around the wndow, but we want an ultra specific bordering set, you we have to do it manually */
#define DIA_DRAW_DIALOGUE_BORDER(dialogue_screen,gs) mvwhline(dialogue_screen, 0, 0, 0, (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) -1); mvwhline(dialogue_screen, 2, 1, 0, (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) -2 ); mvwvline(dialogue_screen, 0, 0, 0, gs->num_cols); mvwvline(dialogue_screen, 1, (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) -1, 0, gs->num_cols);  mvwaddch(dialogue_screen,0, 0, ACS_ULCORNER); mvwaddch(dialogue_screen,0, (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) -1, ACS_URCORNER);

#define DIA_SET_OFFSET(offset, dia_manager) dia_manager->set_offset == NO ? dia_manager->next_char_offset = offset : ;

/*No fucking idea why, but the decrement substracts an offset of 4 too many, so we offset this by adding 4. No idea if this is by how macro evaluted the expression or what. I fucking hate this so much*/
#define DIA_SAFE_DECREMENT_NEXT(manager,gs) (manager->next_char_offset - (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2) <= 0 ? (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2  : (manager->next_char_offset - (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2) + 4

#define DIA_SAFE_INCREMENT_NEXT(manager,gs,maximum_bytes) manager->next_char_offset + (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) >= maximum_bytes ? maximum_bytes - (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) : (manager->next_char_offset + (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2)


#define DIA_SAFE_DECREMENT_PREV(manager,gs) (manager->prev_char_offset - (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2) <= 0 ? manager->prev_char_offset = 0 : (manager->prev_char_offset - (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2) + 4

#define DIA_SAFE_INCREMENT_PREV(manager,gs,maximum_bytes) manager->prev_char_offset + (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) >= maximum_bytes ? maximum_bytes - (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) : (manager->prev_char_offset + (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) -2)

void dia_loop_dialogue(Dialogue_Manager *manager, Game_State *gs);

int dia_compute_num_bytes(FILE *fp);
Dialogue_Manager *dia_init_dialogue_manager(int dialogue_folder_id, int initial_dialogue_id, int npc_id, Game_State *gs);

int dia_redraw_text_scroll(Dialogue_Manager *manager, Game_State *gs, FILE *fp, int offset);

void dia_print_char_at_offset(FILE *fp, int offset);

void dia_print_char_at_offset_times(FILE *fp, int times);

void dia_safe_find_next_offset(Dialogue_Manager *manager, Game_State *gs, int maximum_bytes);

Offset_Changes dia_reddraw_dialogue_scroll(Dialogue_Manager *manager, Game_State *gs, FILE *fp, int offset, int direction);

dia_find_next_nonlf_char(FILE *fp,Dialogue_Manager *manager,char currchar, int start_offset, int current_offset);

int dia_offset_in_list(int offset, Dialogue_Manager *manager);

extern int (*dia_selected_dialogue_response_handler[2])(Dialogue_Manager *manager);
int dia_selected_dialogue_quit(Dialogue_Manager *manager);
int dia_selected_dialogue_advance_dialogue(Dialogue_Manager *manager);
FILE *dia_extract_next_dialogue_window_info(Game_State *gs, Selected_Dialogue_Qresult selected_dialogue_info, FILE *current_dialogue);
#endif

