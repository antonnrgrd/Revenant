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


#ifndef GAMEINFO
#define GAMEINFO
#include "game_state_struct.h"
#include "gameinfo_struct.h"

extern int numerical_responses[256];

#define GAMEINFO_PLACE_TRADER(trader, global_x,global_y, gamle_world) gs->current_zone->tiles[global_y][global_x].foe = trader; gs->current_zone->tiles[global_y][global_x].content[0] = 't';

void gm_free_game_world(Game_World *current_zone);
void gm_free_tile(Game_State *gs,Tile *tile);
#endif


