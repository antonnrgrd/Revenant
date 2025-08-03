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
#define GENERATE_CONSUMABLE 1
#define GENERATE_REAGENT 2
#define GENERATE_ARMOR 3
#define GENERATE_WEAPON 4

#include "ir_information_reader.h"
#include <ncurses.h>
#include "gameinfo.h"
#include "rng_rng.h"
#include "i_item_struct.h"
#include "dia_dialogue.h"
#include <sqlite3.h>
#define PLACE_MERCHANT(game_state,merchant, global_x,global_y)(game_state)
extern const char *alphabet;

Game_World *g_generate_game_world(int width, int height);

I_Item_Holder *g_generate_item(Rng_Mersienne_Twister *twister); 

U_Hashtable *g_generate_merchant_inventory(int min_amount, int max_amount, Rng_Mersienne_Twister *twister);

void g_generate_trader(int global_x, int global_y ,Rng_Mersienne_Twister *twister, Game_State *gs);

void g_generate_dialogue(int global_x, int global_y,int dialogue_folder_id, int initial_dialogue_id,int npc_id, Game_State *gs);

//A variant that hard codes the generated items for debugging and testing
U_Hashtable *g_generate_merchant_inventory_hardcoded_items(Rng_Mersienne_Twister *twister);

void g_generate_database_tables(sqlite3 *db, Game_State *gs);

void g_generate_database_contents(sqlite3 *db);

void g_generate_all_database_content(sqlite3 *db, Game_State *gs);

void g_generate_entire_game_state(Game_State *gs);
#endif

