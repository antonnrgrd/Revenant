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
#include "cuckoohash.h"
#include "generate.h"
#include "game_state.h"
#include "move_handler.h"
#include "tiles.h"
#include <time.h>
#define DELAY 30000
//#define OUTERLOOP(x,y) for(int i = 0; i < x; i++ )
//#define INNERLOOP(x,y)OUTERLOOP(x,y)for(int j = 0; j < y; j++ )
int main(int argc, char *argv[]){
  printf("%d", 10/3);
  
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
  // printf("%d", c->position.local_y);
  endwin();
  
}
