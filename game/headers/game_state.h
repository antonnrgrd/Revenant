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
#include "move_handler.h"
#include "linked_list.h"
#include "creature_behavior.h"
#define INIT_GAME_STATE(game_state)
#define UPDATE_STATE(game_state) ll_iter_list_as_creature(game_state->player,game_state->current_zone,game_state->active_creatures);
/*A macro that initalizes the game state's action log's events that have occured's ordering. We iterate 0-99 because our pad is 100 y coords long and we add 0 char to i to convert it to a char*/
#define INIT_ACTION_LOG(pad) for(int i = 0; i < 100; i++)waddch(i, 0, i + '0');
/* */
#dfine DISPLAY_ACTION_LOG
/*The main struct that will encapsulate all information about the game currently present */
typedef struct Game_State{
  Creature *player;
  Game_World *current_zone;
  Linked_List *active_creatures;
  WINDOW *action_log;
}Game_State;

Game_State *gs_create_game_state(Creature *player, Game_World *world,Linked_List *active_creatures);


void game_loop(Game_State *gamestate);

void ll_iter_list_as_creature(Linked_List *list, Game_World *current_zone);

void gs_print_foes(Game_State *game_state);
#endif
