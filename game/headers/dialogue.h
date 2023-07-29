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
typedef struct {
  /*the id of the folder we should look in for the dialogue files*/
  int dialogue_folder_id;
  /*The id of the initial dialogue file the player should see upon engaging conversation*/
  int initial_dialogue_id;
  /**/
  int npc_id;
  int **dialogue_id_options;
  int next_char_offset;
  int prev_char_offset;
  int set_offset;
}Dialogue_Manager;

/*Normally, we'd be content using the box function to draw a border around the wndow, but we want an ultra specific bordering set, you we have to do it manually */
#define DIA_DRAW_DIALOGUE_BORDER(dialogue_screen,gs) mvwhline(dialogue_screen, 0, 0, 0, (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) -1); mvwhline(dialogue_screen, 2, 1, 0, (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) -2 ); mvwvline(dialogue_screen, 0, 0, 0, gs->num_cols); mvwvline(dialogue_screen, 1, (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) -1, 0, gs->num_cols);  mvwaddch(dialogue_screen,0, 0, ACS_ULCORNER); mvwaddch(dialogue_screen,0, (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) -1, ACS_URCORNER);

#define DIA_SET_OFFSET(offset, dia_manager) dia_manager->set_offset == NO ? dia_manager->next_char_offset = offset : ;

#define DIA_SAFE_DECREMENT_NEXT(manager,gs) manager->next_char_offset - (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) <= 0 ? 0 : (manager->next_char_offset - (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2)

#define DIA_SAFE_INCREMENT_NEXT(manager,gs,maximum_bytes) manager->next_char_offset + (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) >= maximum_bytes ? maximum_bytes - (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) : (manager->next_char_offset + (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2)


#define DIA_SAFE_DECREMENT_PREV(manager,gs) manager->prev_char_offset - (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) <= 0 ? manager->prev_char_offset = 0 : (manager->prev_char_offset - (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) - 2)

#define DIA_SAFE_INCREMENT_PREV(manager,gs,maximum_bytes) manager->prev_char_offset + (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) >= maximum_bytes ? maximum_bytes - (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) : (manager->prev_char_offset + (gs->num_rows - DEFAULT_MAX_INFOBAR_WIDTH) -2)

void dia_loop_dialogue(Dialogue_Manager *manager, Game_State *gs);

int dia_compute_num_bytes(FILE *fp);
Dialogue_Manager *dia_init_dialogue_manager(int dialogue_folder_id, int initial_dialogue_id, int npc_id);

int dia_redraw_text_scroll(Dialogue_Manager *manager, Game_State *gs, FILE *fp, int offset);
#endif

