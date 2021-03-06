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

#include "move_handler.h"
#include "tiles.h"
  //  mvprintw(max_y, max_x ,world->tiles[x][y].content);
  

void mv_check_move_handler(int global_x, int global_y, int local_x, int local_y, Creature *c,Game_World *current_zone){
  char tile = mvinch(local_y,local_x);
  int response = numerical_responses[tile];
  
  (*move_response_handler[response])(global_x,global_y,local_x,local_y,c,current_zone);
}


void (*move_response_handler[2])(int global_x, int global_y, int local_x, int local_y, Creature *c,Game_World *current_zone) =  {move_response_move_character,move_response_halt_character};

  void move_response_move_character(int global_x, int global_y, int local_x, int local_y, Creature *c,Game_World *current_zone){
    int y_max;
    int x_max;
    getmaxyx(stdscr, y_max, x_max);
    c->position.global_x = global_x;
    c->position.global_y = global_y;
    if(local_y  <  0){
      c->position.local_y = y_max-1;
      c->position.local_x = local_x;
      REDRAW_MAP(c,current_zone, c->position.global_x,c->position.global_y,x_max, y_max);
      c->standing_on[0] = mvinch(local_y,local_x);
      mvprintw(local_y,local_x,c->representation);
      move(c->position.local_y,c->position.local_x);
      
    }

    else if(local_y  >  y_max - 1){
      c->position.local_y = 0;
      c->position.local_x = local_x;
      REDRAW_MAP(c,current_zone, c->position.global_x,c->position.global_y,x_max, y_max);
      c->standing_on[0] = mvinch(local_y,local_x);
      mvprintw(local_y,local_x,c->representation);
      move(c->position.local_y,c->position.local_x);
    }

    else if(local_x  <  0){
      c->position.local_y = x_max - 1;
      REDRAW_MAP(c,current_zone, c->position.global_x,c->position.global_y,x_max, y_max);
    }

    else if(local_x  >  x_max - 1){
      c->position.local_x = 0;
      REDRAW_MAP(c,current_zone, c->position.global_x,c->position.global_y,x_max, y_max);
    }
    else{
      
      /* current_zone->tiles[global_y][global_x].content[0] = c->standing_on[0];*/
       mvprintw(c->position.local_y,c->position.local_x, c->standing_on);
    c->standing_on[0] = mvinch(local_y,local_x);
  /*  current_zone->tiles[global_y][global_x].content[0] = c->representation[0]; */
  mvprintw(local_y,local_x,c->representation);
  c->position.global_x = global_x;
  c->position.local_x = local_x;
  c->position.local_y = local_y;
  move(c->position.local_y,c->position.local_x);
    }
    
    
  
 
}

void move_response_halt_character(int global_x, int global_y,int local_x, int local_y, Creature *c,Game_World *current_zone){
  ;
}
void redraw_map(Creature *c, Game_World *world, int x, int y, int max_x, int max_y){
  for(int i = 0; i < max_y  && i+y < (world->height);  i++){
    for(int j = 0; j < max_x  && j+x < (world->width);  j++){
      mvprintw(i,j,(world->tiles[(c->position.global_y - (c->position.local_y))+i][(c->position.global_x - (c->position.local_x))+j].content));
    }
  }
}

void gw_add_to_pile(Item_Holder *item, Entry *item_pile){
  Entry *current_entry = item_pile;
  if(current_entry == NULL ){
    current_entry = malloc(sizeof(Entry));
    current_entry->item_holder = item;
    return;
  }
  while(current_entry->next_entry != NULL){
    current_entry = current_entry->next_entry;
  }
  current_entry->next_entry = malloc(sizeof(Entry));
  current_entry->next_entry = item;
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
