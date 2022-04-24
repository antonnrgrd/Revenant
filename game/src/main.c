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
#include "gameinfo.h"
#include "modifier.h"
#include "generate.h"
#include "game_state.h"
#include "gameinfo.h"
#include <time.h>
#include "creature_behavior.h"
#include "state_manager.h"
#include "ingame_msg.h"
#include "game_state_struct.h"
#include "rng.h"
int main(int argc, char *argv[]){
   
  //  Item *weapon = i_make_mele_weapon(epic,one_hand,steel,sword);
  // printf("%s", i_derive_item_name_equipment(weapon));
    
  initscr();
  start_color();
  Game_World *game_world = g_generate_game_world(1000,1000);
 
  Creature *opponent = c_generate_creature(animal,0,20,4, game_world, game_world->player);
  Linked_List *ll = ll_initialize_linked_list();
  APPEND_NODE_CREATURE(ll,opponent);
  Game_State *game_state = gs_create_game_state(game_world,ll);
   
   
  opponent->target = game_state->player;
  opponent->behavior=attacking;
  initscr();
  start_color();
  noecho();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  srand(time(NULL));
  raw();
   
  game_loop(game_state);
  endwin();

}
  
 
 
