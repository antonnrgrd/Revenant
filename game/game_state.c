/*This file is part of Revenant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
,
You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */
#include "game_state.h"
#include "move_handler.h"
#include "creature.h"



void game_loop(Creature *c, Game_World *current_zone){
  int ch;
  int rows;
  int cols;
  getmaxyx(stdscr, cols,rows);
  REDRAW_MAP(c,current_zone, c->position.global_x,c->position.global_y,rows, cols);
  //SPAWN_AT(c,current_zone,c->position.local_x, c->position.local_y);
  refresh();
  while(1){
    refresh(); 
    ch = getch();
    switch(ch){
    case KEY_UP:
      mv_check_move_handler(c->position.global_x, c->position.global_y-1,c->position.local_x, c->position.local_y-1, c,current_zone);
      break;
    case KEY_DOWN:
      mv_check_move_handler(c->position.global_x, c->position.global_y+1,c->position.local_x, c->position.local_y+1, c,current_zone);      
      break;
    case KEY_LEFT:
      mv_check_move_handler(c->position.global_x-1,c->position.global_y ,c->position.local_x-1, c->position.local_y,c,current_zone);
      break;
    case KEY_RIGHT:
      mv_check_move_handler(c->position.global_x+1, c->position.global_y ,c->position.local_x+1, c->position.local_y, c,current_zone);
      break;
    case 'q':
      return;
      break;
    case 's':
      c->position.local_y = 10;
      c->position.local_x = 20;
      mvprintw(10,20, c->representation);
      c->standing_on[0] = mvinch(10,20);
      move(10,20);
      break;
    default:
      break;
    }
  }
}

