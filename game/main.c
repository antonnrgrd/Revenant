/*This file is part of Revenant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
,,,
Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */
#include "dialogue.h"
#include "u_hash.h"
#include "creature.h"
#include "u_hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ncurses.h>
#include <curses.h>
#include "inventory.h" 
#include "item.h"
#include "strings.h"
#include "modifier.h"
#include "generate.h"
#include "game_state.h"
#include "move_handler.h"
#include "tiles.h"
#include <time.h>
#define DELAY 30000

int main(int argc, char *argv[]){
  Game_World *game_world = g_generate_game_world(1000,1000);
  Creature *c = c_random_player(5,3, game_world);
  Item *first_loot = i_make_mele_weapon(poor, steel,one_hand, sword);
  Item *second_loot = i_make_mele_weapon(legendary, granite,one_hand, mace);
  Item *third_loot = i_make_mele_weapon(high,silver, two_hand, axe);
  
  U_Hashtable *inventory = u_initalize_hashtable(7);
  u_print_inventory(inventory);
  Item_Holder *first_loot_ = i_make_item_holder(first_loot,3);
  Item_Holder *second_loot_ = i_make_item_holder(second_loot,3);
  Item_Holder *third_loot_ = i_make_item_holder(third_loot,3);

  inv_add_item(first_loot_, inventory,c);
  inv_add_item(second_loot_, inventory,c);
  inv_add_item(third_loot_, inventory,c);
  
  /*
  initscr();
  start_color();    
  Game_World *game_world = g_generate_game_world(1000,1000);
  Creature *c = c_random_player(5,3, game_world);
  initscr();
  start_color();
  noecho();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  srand(time(NULL));
  raw();
  game_loop(c, game_world);
  endwin();
  */
}
