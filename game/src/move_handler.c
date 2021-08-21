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

  

void mv_check_move_handler(int global_x, int global_y, int local_x, int local_y, Creature *c,Game_World *current_zone){
  //printf("%d%s%d", global_x," " ,global_y);
  //return;
  
  if( (global_x < current_zone->width  && global_y < current_zone->height) && (global_x > -1  && global_y > -1 )  ){
    int response = numerical_responses[current_zone->tiles[global_y][global_x].content[0]];
     (*move_response_handler[response])(global_x,global_y,local_x,local_y,c,current_zone);
  }
}


void (*move_response_handler[3])(int global_x, int global_y, int local_x, int local_y, Creature *c,Game_World *current_zone) =  {move_response_move_character,move_response_halt_character,move_response_loot_item};

  void move_response_move_character(int global_x, int global_y, int local_x, int local_y, Creature *c,Game_World *current_zone){  
    c->position.global_x = global_x;
    c->position.global_y = global_y;
    if(local_y  <  0){
      c->position.local_y = DEFAULT_MAX_Y - 1;
      REDRAW_MAP(c,current_zone, c->position.global_x,c->position.global_y,x_max, y_max);
      c->standing_on[0] = mvinch(local_y,local_x);
      move(c->position.local_y,c->position.local_x);
      
    }

    else if(local_y  >  DEFAULT_MAX_Y - 1){
     
      c->position.local_y = 1;
      REDRAW_MAP(c,current_zone, c->position.global_x,c->position.global_y,x_max, y_max);
      
    }

    else if(local_x  <  DEFAULT_MAX_INFOBAR_WIDTH){
      c->position.local_x = DEFAULT_MAX_X - 1;
      REDRAW_MAP(c,current_zone, c->position.global_x,c->position.global_y,x_max, y_max);
    }

    else if(local_x  >  DEFAULT_MAX_X - 1){
      c->position.local_x = DEFAULT_MAX_INFOBAR_WIDTH;
      REDRAW_MAP(c,current_zone, c->position.global_x,c->position.global_y,x_max, y_max);
    }
    else{
      
  mvprintw(c->position.local_y,c->position.local_x, c->standing_on);
  c->standing_on[0] = mvinch(local_y,local_x);
  mvprintw(local_y,local_x,c->representation);
  c->position.local_x = local_x;
  c->position.local_y = local_y;
  move(c->position.local_y,c->position.local_x);
    }
    
    
  
 
}

void move_response_halt_character(int global_x, int global_y,int local_x, int local_y, Creature *c,Game_World *current_zone){
  ;
}




  

void move_response_loot_item(int global_x, int global_y,int local_x, int local_y, Creature *c,Game_World *current_zone){

  /*Bug is somewhere in these lines before we ask for user input. Removing either the stndard move operation OR the print seems to fix it */

  c->position.global_x = global_x;
  c->position.global_y = global_y;
  mvprintw(c->position.local_y,c->position.local_x, c->standing_on);
  c->standing_on[0] =  mvinch(local_y,local_x);
  mvprintw(local_y,local_x,c->representation);
  c->position.local_x = local_x;
  c->position.local_y = local_y;
  move(c->position.local_y,c->position.local_x);
  
  
  move_response_move_character(global_x, global_y, local_x,local_y,c,current_zone);
    
    mvprintw(0,0, "%s%s%s%d%s", "Pickup ", current_zone->tiles[global_y][global_x].entry->item_holder->item->name, " amount: ", current_zone->tiles[global_y][global_x].entry->item_holder->amount, " ? [y/n/a/d]");  
  
  int response;
  int result;
  response = getch();
  switch(response){
  case Y:
    result = inv_add_item(current_zone->tiles[global_y][global_x].entry->item_holder, c->instance.character->inventory, c);
    Item *i = current_zone->tiles[global_y][global_x].entry->item_holder->item;
    if(result == SUCCESS_ADDITION){
      move(0,0);
      clrtoeol();
      move(c->position.local_y,c->position.local_x);
      mvprintw(0,0, "%s", "Item(s) successfully added to inventory");
      Entry *next_in_pile = current_zone->tiles[global_y][global_x].entry->next_entry;
      free(current_zone->tiles[global_y][global_x].entry);
      if(next_in_pile != NULL){
	current_zone->tiles[global_y][global_x].entry = next_in_pile;
	c->standing_on[0] = next_in_pile->item_holder->item->representation[0];
      }
      else{
	c->standing_on[0] = i->standing_on[0];
      }
    }
    else{
      move(0,0);
      clrtoeol();
      mvprintw(0,0, "%s", "You cannot carry that many");
      move(c->position.local_y,c->position.local_x);
    }
    break;
  case N:
    move(0,0);
    clrtoeol();
    move(c->position.local_y,c->position.local_x);
    break;
  case A:
    move(0,0);
    clrtoeol();
    move(c->position.local_y,c->position.local_x);
    break;
  default:
    move(0,0);
    clrtoeol();
    move(c->position.local_y,c->position.local_x);
    break;
  }
 }
  

