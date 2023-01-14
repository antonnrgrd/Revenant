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

int mv_check_move_handler(int global_x, int global_y, int local_x, int local_y, Creature *c,Game_State *game_state){
  // Before we check the response value from the character, we first need to be assert that position we are trying to make the move to is within bounds of the current zone's dimensionality to avoid invalid index lookups in the game world's tiles (whether negative or too large index values)
  if( (global_x < game_state->current_zone->width  && global_y < game_state->current_zone->height) && (global_x > -1  && global_y > -1 )  ){
    int response = numerical_responses[game_state->current_zone->tiles[global_y][global_x].content[0]];
    return (*move_response_handler[response])(global_x,global_y,local_x,local_y,c,game_state);
  }
  else{
    return CONTINUE_TURN;
  }
}


int (*move_response_handler[5])(int global_x, int global_y, int local_x, int local_y, Creature *c,Game_State *game_state) =  {move_response_move_character,move_response_halt_character,move_response_loot_item, move_response_attack_target , move_response_initiate_trade };

  int move_response_move_character(int global_x, int global_y, int local_x, int local_y, Creature *c,Game_State *game_state){
    game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
    c->position.global_x = global_x;
    c->position.global_y = global_y;
    if(local_y  <  0){
      c->position.local_y = DEFAULT_MAX_Y - 1;
      REDRAW_MAP(c,game_state->current_zone,game_state->logs[MAIN_SCREEN], c->position.global_x,c->position.global_y,x_max, y_max);
    }

    else if(local_y  >  DEFAULT_MAX_Y - 1){
      c->position.local_y = 0;
      REDRAW_MAP(c,game_state->current_zone,game_state->logs[MAIN_SCREEN], c->position.global_x,c->position.global_y,x_max, y_max);
      
    }

    else if(local_x  <  DEFAULT_MAX_INFOBAR_WIDTH){
      c->position.local_x = DEFAULT_MAX_X - 1;
      REDRAW_MAP(c,game_state->current_zone,game_state->logs[MAIN_SCREEN], c->position.global_x,c->position.global_y,x_max, y_max);
    }

    else if(local_x  >  DEFAULT_MAX_X - 1){
      c->position.local_x = DEFAULT_MAX_INFOBAR_WIDTH;
      REDRAW_MAP(c,game_state->current_zone,game_state->logs[MAIN_SCREEN], c->position.global_x,c->position.global_y,x_max, y_max);
    }
    else{
      
  mvwprintw(game_state->logs[MAIN_SCREEN],c->position.local_y,c->position.local_x, c->standing_on);
  c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
  mvwprintw(game_state->logs[MAIN_SCREEN],local_y,local_x,c->representation);
  c->position.local_x = local_x;
  c->position.local_y = local_y;
  move(c->position.local_y,c->position.local_x);
    }
    
   c->curr_ap--;
  ;
  if(c->curr_ap == 0){
    return END_TURN;
  }
  else{
    return CONTINUE_TURN;
  } 
}

int move_response_halt_character(int global_x, int global_y,int local_x, int local_y, Creature *c,Game_State *game_state){
  c->curr_ap--;
  ;
  if(c->curr_ap == 0){
    return END_TURN;
  }
  else{
    return CONTINUE_TURN;
  }
}

/*Ignore the fact that the message is not visible on screen until the creature dies because at some point you will rewrite the game to use the entire terminal, but for now, keep in mind you won't see that you are damaging your target until it is dead. oddly enough, it is visible in the event log.*/

int move_response_attack_target(int global_x, int global_y,int local_x, int local_y, Creature *c,Game_State *game_state){
  if  (1){
    CLEAR_MSG_LINE();
      ir_print_damage_to_creature(game_state, game_state->player, ((Creature *)game_state->current_zone->tiles[global_y][global_x].foe));
    msg_update_event_log(game_state);
      move(c->position.local_y,c->position.local_x);
     
    if (((Creature *)game_state->current_zone->tiles[global_y][global_x].foe)->curr_health <= 0){
      mvwprintw(game_state->logs[MAIN_SCREEN],game_state,((Creature *)game_state->current_zone->tiles[global_y][global_x].foe)->position.local_y,((Creature *)game_state->current_zone->tiles[global_y][global_x].foe)->position.local_x,((Creature *)game_state->current_zone->tiles[global_y][global_x].foe)->standing_on);
           game_state->current_zone->tiles[global_y][global_x].content[0] = ((Creature *)game_state->current_zone->tiles[global_y][global_x].foe)->standing_on[0];
	   // c_cleanup_creature(c,game_state->current_zone);
      
      // If a creature runs out of health, mark it for deletion s.t when we next go through all the creatures that are to act, we see that it is dead and can therefore be free'd and removed from the list of active creatures  
	         ((Creature *)game_state->current_zone->tiles[global_y][global_x].foe)->marked_for_deletion = YES;
    }
  }
  c->curr_ap--;
  if(c->curr_ap == 0){
    return END_TURN;
  }
  else{
    return CONTINUE_TURN;
  }
} 



  

int move_response_loot_item(int global_x, int global_y,int local_x, int local_y, Creature *c,Game_State *game_state){
  
  c->position.global_x = global_x;
  c->position.global_y = global_y;
  mvwprintw(game_state->logs[MAIN_SCREEN],c->position.local_y,c->position.local_x, c->standing_on);
  c->standing_on[0] =  mvinch(local_y,local_x);
  mvwprintw(game_state->logs[MAIN_SCREEN],local_y,local_x,c->representation);
  c->position.local_x = local_x;
  c->position.local_y = local_y;
  move(c->position.local_y,c->position.local_x);
    
  move_response_move_character(global_x, global_y, local_x,local_y,c,game_state);
  MSG_ITEM_PICKUP(game_state,game_state->current_zone->tiles[global_y][global_x].entry->item_holder);
  /*    
mvwprintw(game_state->logs[MAIN_SCREEN],0,0, "%s%s%s%d%s", "Pickup ", i_derive_item_name[game_state->current_zone->tiles[global_y][global_x].entry->item_holder->item->kind], " amount: ", game_state->current_zone->tiles[global_y][global_x].entry->item_holder->amount, " ? [y/n/a/d]");  
  */
  int response;
  int result;
  response = getch();
  switch(response){
   case 'y':
    result = inv_add_item(game_state->current_zone->tiles[global_y][global_x].entry->item_holder, (struct U_Hashtable *)c->additional_info, c);
    Item *i = game_state->current_zone->tiles[global_y][global_x].entry->item_holder->item;
    if(result == SUCCESS_ADDITION){
      move(0,0);
      clrtoeol();
      move(c->position.local_y,c->position.local_x);
      mvwprintw(game_state->logs[MAIN_SCREEN],0,0, "%s", "Item(s) successfully added to inventory");
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
      mvwprintw(game_state->logs[MAIN_SCREEN],0,0, "%s", "You cannot carry that many");
      move(c->position.local_y,c->position.local_x);
    }
    break;
  case 'n':
   move(0,0);
    clrtoeol();
    move(c->position.local_y,c->position.local_x);
    break;
  case 'a':
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
  c->curr_ap--;
  ;
  if(c->curr_ap == 0){
    return END_TURN;
  }
  else{
    return CONTINUE_TURN;
  }
 }



int move_response_initiate_trade(int global_x, int global_y,int local_x, int local_y, Creature *c,Game_State *game_state){
  msg_trading_session(global_x,global_y,game_state);
}


