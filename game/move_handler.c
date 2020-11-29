/*This file is part of Revenant.
a
Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */

#include "move_handler.h"
#include "tiles.h"
  //  mvprintw(max_y, max_x ,world->tiles[x][y].content);
  

void mv_check_move_handler(int x, int y, Creature *c,Game_World *current_zone){
  char tile = mvinch(y,x);
  int response = numerical_responses[tile];
  (*move_response_handler[response])(x,y,c,current_zone);
}


void (*move_response_handler[2])(int x, int y, Creature *c,Game_World *current_zone) =  {move_response_move_character,move_response_halt_character};

  void move_response_move_character(int x, int y, Creature *c,Game_World *current_zone){
  mvprintw(c->position.local_y,c->position.local_x, c->standing_on);
  c->standing_on[0] = mvinch(y,x);
  mvprintw(y,x,c->representation);
  c->position.global_x = x;
  c->position.global_y = y;
  c->position.local_x = x;
  c->position.local_y = y;
  move(c->position.local_y,c->position.local_x);
  int y_max;
  int x_max;
  getmaxyx(stdscr, y_max, x_max);
  if(c->position.local_y  <  0){
    c->position.local_y = y_max -1 ;
    REDRAW_MAP(c,current_zone, c->position.global_x,c->position.global_y,x_max, y_max);
    SPAWN_AT(c,x,y);
      }
  if(c->position.local_x < 0){
    c->position.local_x = x_max -1;
    REDRAW_MAP(c,current_zone, c->position.global_x,c->position.global_y,x_max, y_max);
    SPAWN_AT(c,x,y);
  }

  if(c->position.local_y > y_max - 1){
    c->position.local_y = 0;
    //   printf("%d%s%d%s", c->position.local_y, " ", c->position.local_x, "\n");
    REDRAW_MAP(c,current_zone, c->position.global_x,c->position.global_y,x_max, y_max);
    SPAWN_AT(c,20,20);
  }

  if(c->position.local_x > x_max - 1){
    c->position.local_x = 0;
    REDRAW_MAP(c,current_zone, c->position.global_x,c->position.global_y,x_max, y_max);
    SPAWN_AT(c,20,20);
  }

}

void move_response_halt_character(int x, int y, Creature *c,Game_World *current_zone){
  ;
}


/*
void move_response_move_character(int x, int y, Creature *c, unsigned coordinate_flag){
  if(coordinate_flag == MOVE_X){
    c->x = x;
    c->y = y;
  }

  else{
    c->y = y;
    c->x = x;
  }
  
}

void move_response_halt_character(int x, int y, Creature *c, unsigned coordinate_flag){
  ;
}

*/
