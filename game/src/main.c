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
#include "placeholder.h"
#include "modifier.h"
#include "generate.h"
#include "game_state.h"
#include "tiles.h"
#include <time.h>
//can be removed 
#include <sys/ioctl.h>
int main(int argc, char *argv[]){
  /*
  Game_World *game_world = g_generate_game_world(1000,1000);
  Creature *c = c_random_player(5,3, game_world);
  
  
  
  
  
  u_print_inventory(inventory);
  
  
  Item_Holder *third_loot_ = i_make_item_holder(third_loot,3);

  inv_add_item(first_loot_, inventory,c);
  inv_add_item(second_loot_, inventory,c);
  inv_add_item(third_loot_, inventory,c);
  u_print_inventory(inventory);
  u_remove_item(second_loot->name,1,inventory);
  u_print_inventory(inventory);
  */
  /*
  struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
    return 0;
  */

  /*
  Game_World *game_world = g_generate_game_world(1000,1000);
  Creature *c = c_random_player(13,13, game_world);
  inv_add_item(first_loot_,c->instance.character->inventory,c);
  */
  Item *second_loot = i_make_mele_weapon(legendary, granite,one_hand, mace);
  Item_Holder *second_loot_ = i_make_item_holder(second_loot,3);
  initscr();
  start_color();    
  Game_World *game_world = g_generate_game_world(1000,1000);
  Creature *c = c_random_player(13,13, game_world);
  initscr();
  start_color();
  noecho();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  srand(time(NULL));
  raw();
  SPAWN_ITEM(game_world,second_loot_,15,15)
  game_loop(c, game_world);
  endwin();
  
  

  
}