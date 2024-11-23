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



#include "cb_creature_behavior.h"
#include "c_creature.h"
#include "u_hash.h"
#include <stdlib.h>
#include <stdint.h>
#include <ncurses.h>
#include <curses.h>
#include "inv_inventory.h" 
#include "i_item.h"
#include "strings.h"
#include "gameinfo.h"
#include "m_modifier.h"
#include "generate.h"
#include "game_state.h"
#include "gameinfo.h"
#include <time.h>
#include "u_hash.h"
#include "state_manager.h"
#include "msg_ingame_msg.h"
#include "game_state_struct.h"
#include "rng_rng.h"
#include "ir_information_reader.h"
#include "dia_dialogue.h"
int main(int argc, char *argv[]){
  
  initscr();
 start_color();   
   Game_World *game_world = g_generate_game_world(1000,1000);
  Game_State *gs =  gs_create_game_state(game_world);
  ((C_Player_Info *)gs->player->additional_info)->inventory = g_generate_merchant_inventory(3,3,gs->twister);
  noecho();
  curs_set(FALSE);
   keypad(stdscr, TRUE);
    srand(time(NULL));
  raw();  
  game_loop(gs);
  endwin();  
}
  
 
 
