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

#ifndef GAME_STATE
#define GAME_STATE
#include "mv_move_handler.h"
#include "ll_linked_list.h"
#include "cb_creature_behavior.h"
#include "game_state_struct.h"
#include "generic_macros.h"
#include "ir_information_reader.h"
#define INIT_GAME_STATE(game_state)
#define GS_PLACE_MERCHANT(hashtable)
#define UPDATE_STATE(game_state) ll_iter_list_as_creature(game_state->player,game_state->current_zone,game_state->active_creatures);
/*
Unlike the other fields which we can initiaize from the inside of the creation of the Game_State struct, we have to create a Game_World struct, THEN pass it as an argument and assign it as the value
for the Game_world field for the Game_State. I suspect this is because how the values of max_x and max_y in the Game_World are affected by calls of the getmaxyx function, which are somehow not initialized from the gatmaxyx function call when creating the Game_World struct from inside of the create_game_state struct. Attempting to create the  Game_World struct from inside the function will cause seg fault, so this is how it has to be done.
*/
Game_State *gs_create_game_state(Game_World *game_world);


void gs_iter_list_as_creature(Ll_Linked_List *list, Game_State *game_state);

void gs_print_foes(Game_State *game_state);

void gs_recompute_creature_local_coords(Ll_Linked_List *list);

void gs_update_screen_resize(Game_State *gs);

void gs_free_game_state(Game_State *gs);
#endif

