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


#ifndef GENERATE
#define GENERATE
#include <ncurses.h>
#include "gameinfo.h"
#include "rng.h"
#include "item.h"
#define GENERATE_CONSUMABLE 1
#define GENERATE_REAGENT 2
#define GENERATE_ARMOR 3
#define GENERATE_WEAPON 4
#define PLACE_MERCHANT(game_state,merchant, global_x,global_y)(game_state)
extern const char *alphabet;

Game_World *g_generate_game_world(int width, int height);

Item_Holder *g_generate_item(Mersienne_Twister *twister); 

U_Hashtable *g_generate_merchant_inventory(int min_amount, int max_amount, Mersienne_Twister *twister);

void g_generate_merchant();
#endif

