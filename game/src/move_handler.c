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


  

void mv_check_move_handler(int global_x, int global_y, int local_x, int local_y, Creature *c,Game_State *game_state){
  /* Before we check the response value from the character, we first need to be assert that position we are trying to make the move to is within bounds of the current zone's dimensionality to avoid invalid index lookups in the game world's tiles (whether negative or too large index values)  */
  if( (global_x < game_state->current_zone->width  && global_y < game_state->current_zone->height) && (global_x > -1  && global_y > -1 )  ){
    int response = numerical_responses[game_state->current_zone->tiles[global_y][global_x].content[0]];
     (*move_response_handler[response])(global_x,global_y,local_x,local_y,c,game_state);
  }
}


void (*move_response_handler[4])(int global_x, int global_y, int local_x, int local_y, Creature *c,Game_State *game_state) =  {move_response_move_character,move_response_halt_character,move_response_loot_item,move_response_attack_target};

  void move_response_move_character(int global_x, int global_y, int local_x, int local_y, Creature *c,Game_State *game_state){
    game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
    c->position.global_x = global_x;
    c->position.global_y = global_y;
    if(local_y  <  0){
      c->position.local_y = DEFAULT_MAX_Y - 1;
      REDRAW_MAP(c,game_state->current_zone, c->position.global_x,c->position.global_y,x_max, y_max);
    }

    else if(local_y  >  DEFAULT_MAX_Y - 1){
      c->position.local_y = 0;
      REDRAW_MAP(c,game_state->current_zone, c->position.global_x,c->position.global_y,x_max, y_max);
      
    }

    else if(local_x  <  DEFAULT_MAX_INFOBAR_WIDTH){
      c->position.local_x = DEFAULT_MAX_X - 1;
      REDRAW_MAP(c,game_state->current_zone, c->position.global_x,c->position.global_y,x_max, y_max);
    }

    else if(local_x  >  DEFAULT_MAX_X - 1){
      c->position.local_x = DEFAULT_MAX_INFOBAR_WIDTH;
      REDRAW_MAP(c,game_state->current_zone, c->position.global_x,c->position.global_y,x_max, y_max);
    }
    else{
      
  mvprintw(c->position.local_y,c->position.local_x, c->standing_on);
  c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
  mvprintw(local_y,local_x,c->representation);
  c->position.local_x = local_x;
  c->position.local_y = local_y;
  move(c->position.local_y,c->position.local_x);
    }
    
    
  
 
}

void move_response_halt_character(int global_x, int global_y,int local_x, int local_y, Creature *c,Game_State *game_state){
  ;
}




  

void move_response_loot_item(int global_x, int global_y,int local_x, int local_y, Creature *c,Game_State *game_state){

  /*Bug is somewhere in these lines before we ask for user input. Removing either the stndard move operation OR the print seems to fix it */

  c->position.global_x = global_x;
  c->position.global_y = global_y;
  mvprintw(c->position.local_y,c->position.local_x, c->standing_on);
  c->standing_on[0] =  mvinch(local_y,local_x);
  mvprintw(local_y,local_x,c->representation);
  c->position.local_x = local_x;
  c->position.local_y = local_y;
  move(c->position.local_y,c->position.local_x);
  
  
  move_response_move_character(global_x, global_y, local_x,local_y,c,game_state);
    
    mvprintw(0,0, "%s%s%s%d%s", "Pickup ", game_state->current_zone->tiles[global_y][global_x].entry->item_holder->item->name, " amount: ", game_state->current_zone->tiles[global_y][global_x].entry->item_holder->amount, " ? [y/n/a/d]");  
  
  int response;
  int result;
  response = getch();
  switch(response){
  case Y:
    result = inv_add_item(game_state->current_zone->tiles[global_y][global_x].entry->item_holder, c->instance.character->inventory, c);
    Item *i = game_state->current_zone->tiles[global_y][global_x].entry->item_holder->item;
    if(result == SUCCESS_ADDITION){
      move(0,0);
      clrtoeol();
      move(c->position.local_y,c->position.local_x);
      mvprintw(0,0, "%s", "Item(s) successfully added to inventory");
      Entry *next_in_pile = game_state->current_zone->tiles[global_y][global_x].entry->next_entry;
      free(game_state->current_zone->tiles[global_y][global_x].entry);
      if(next_in_pile != NULL){
	game_state->current_zone->tiles[global_y][global_x].entry = next_in_pile;
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


void move_response_attack_target(int global_x, int global_y,int local_x, int local_y, Creature *c,Game_State *game_state){

  //((rand() % (21 - 1 + 1) + 1)) + c->attributes.dexterity >= ((Creature *)current_zone->tiles[global_y][global_x].foe)->attributes.dexterity
   
  if  (1){

    ((Creature *)game_state->current_zone->tiles[global_y][global_x].foe)->curr_health = ((Creature *)game_state->current_zone->tiles[global_y][global_x].foe)->curr_health-10;
      
    /*  mvprintw(DEFAULT_MAX_Y,0, "%s%s%s%d%s", "You damage ", c_retrieve_creature_name((Creature *)current_zone->tiles[global_y][global_x].foe) , " for ", 10, " damage");
      UPDATE_EVENT_LOG()
    */
      move(c->position.local_y,c->position.local_x);
    if (((Creature *)game_state->current_zone->tiles[global_y][global_x].foe)->curr_health <= 0){
      c_cleanup_creature(c,game_state->current_zone);
      // If a creature runs out of health, mark it for deletion s.t when we next go through all the creatures that are to act, we see that it is dead and can therefore be free'd and removed from the list of active creatures  
      c->marked_for_deletion = YES;
      
    }
  }
  
} 

