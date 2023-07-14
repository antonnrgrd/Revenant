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
  /*the id of the file we should look in*/
  int dialogue_folder_id;
  int initial_dialogue_id;
  int **dialogue_id_options;  
}Dialogue_Manager;

/*Normally, we'd be content using the box function to draw a border around the wndow, but we want an ultra specific bordering set, you we have to do it manually */
#define DIA_DRAW_DIALOGUE_BORDER(dialogue_screen,gs) mvwhline(dialogue_screen, 0, 0, 0, gs->num_rows-3); mvwvline(dialogue_screen, 0, 0, 0, gs->num_cols); mvwaddch(dialogue_screen,0, 0, ACS_ULCORNER); mvwhline(dialogue_screen, 1, 1, 0, gs->num_rows-3); mvwvline(dialogue_screen, 0, gs->num_rows-2, 0, 1);

void dia_loop_dialogue(Dialogue_Manager *manager, Game_State *gs);

Dialogue_Manager *dia_init_dialogue_manager(int dialogue_folder_id, int initial_dialogue_id);

#endif

