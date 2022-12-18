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
 
#include "game_state.h"
#include "move_handler.h"
#include "creature.h"

void ll_iter_list_as_creature(Linked_List *list, Game_State *game_state){
  /*We have to keep track of where we are in the position of the linked ist
because depending on where we are in the list, we have to perform different steps to remove the node */
  int i = 0;
  Node *current_node = list->initial_node;
  Node *previous = current_node;
  // printf("%d", ((struct Creature *)current_node->value)->marked_for_deletion);
  while(current_node != NULL) {
    //If a creature has been marked for deletion, it is dead and should therefore be firstly removed from the lsit of creature's that gets to act because it is dead and secondly, the creature itself is freed. We do not free the intercal contained structures of the creatures itself because they are already free'd whenever it is detected that a creature has died.
    if(((struct Creature *)current_node->value)->marked_for_deletion == YES){
      if(i == 0){
	  Node *to_be_freed = current_node;
	  list->initial_node = current_node->next;
	  previous = current_node->next;
	  current_node = current_node->next;
	  //Apparently, free-ing a pointer is not enough to make it null
	  //You have to explicitly set it to be so i.e you can free a pointer
	  //but will still on null checks come up as non-null, so we need
	  //to set it to null here
	  free(to_be_freed);
	  to_be_freed = NULL;	  
       }

      else if(i > 0 && current_node->next == NULL){
	/*Unsure why i need to set both pointers null, in theory, setting either (the pointer to the last node in the list) hould do, but
	 if both aren't set to null, there are race conditions that can result in seg faults*/
	previous->next = NULL; 
	free(current_node);
	current_node = NULL;
      }
      else{
	Node *to_be_freed = current_node;
	previous->next = current_node->next;
	current_node = current_node->next;
	free(to_be_freed);
	to_be_freed = NULL;
      }
      i++;
    }  
    else{
      while(((struct Creature *)current_node->value)->curr_ap > 0 ){
	cb_act( (struct Creature *)current_node->value, game_state);
      }
      ((struct Creature *)current_node->value)->curr_ap = ((struct Creature *)current_node->value)->max_ap;
      i++;
            
     previous = current_node;
    current_node = current_node->next;
    }
  }
}

void gs_print_foes(Game_State *game_state){
  Node *current_node = game_state->active_creatures->initial_node;
  // TBD:consider only creatures within range of the player 
  while(current_node != NULL) {
    mvwprintw(game_state->logs[MAIN_SCREEN], ((struct Creature *)current_node->value)->position.local_y,((struct Creature *)current_node->value)->position.local_x,((struct Creature *)current_node->value)->representation);
    current_node = current_node->next;
  }
}


Game_State *gs_create_game_state(Game_World *game_world){


  
  
  Game_State *state = malloc(sizeof(Game_State));
  state->twister = rng_generate_twister();
  state->player = c_random_player(20,3, game_world,state->twister);
 

  //Creature *opponent = c_generate_creature(animal,0,20,4, game_world,state->player);
    Creature *opponent = ir_readin_creature("/usr/lib/revenant_files/creature_files/0",20,4,game_world,state->player);
    //    Creature *opponent_2 = ir_readin_creature("/usr/lib/revenant_files/creature_files/0",20,5,game_world,state->player); 
  /*
  Creature *opponent2 = c_generate_creature(animal,0,21,4, game_world,state->player);
  Creature *opponent3 = c_generate_creature(animal,0,22,4, game_world,state->player);
  Creature *opponent4 = c_generate_creature(animal,0,23,4, game_world,state->player);
  */
    opponent->behavior = attacking;
    //   opponent_2->behavior = attacking;
  /*
  opponent2->behavior = pursuing;
  opponent3->behavior = pursuing;
  opponent4->behavior = pursuing;
  */
  Linked_List *ll = ll_initialize_linked_list();
   ll_prepend_node_creature(ll,opponent);
   // ll_prepend_node_creature(ll,opponent_2);
  /*
  ll_prepend_node_creature(ll,opponent2);
  
  ll_prepend_node_creature(ll,opponent3);
  ll_prepend_node_creature(ll,opponent4);
  */
  /*
  APPEND_NODE_CREATURE(ll,opponent);
  APPEND_NODE_CREATURE(ll,opponent2);
  //  APPEND_NODE_CREATURE(ll,opponent2);
  // APPEND_NODE_CREATURE(ll,opponent3);
  //APPEND_NODE_CREATURE(ll,opponent4);
  */
  state->current_zone = game_world;
  state->active_creatures = ll;
  //It may seem redundant to make a screen that basically takes up the entire stdscr, but this is because unlike windows managed by panels, stdscr does not take into consideration the contents of other
  // windows. Therefore, if the contents of stdscr overlaps the contents of a window, stdscr will overwrite/take precedence of the contents of said window. To achieve the desired windows browsing effect,
  //we are made to make a new panel-managed window that will act as stdscr 
  state->logs[MAIN_SCREEN]  = newwin(0,0,0,0);
  state->logs[EVENT_LOG] = newwin(LOG_Y_SIZE,LOG_X_SIZE,LOG_START_Y,LOG_START_X);
  state->logs[INVENTORY_LOG] = newwin(LOG_Y_SIZE,LOG_X_SIZE,LOG_START_Y,LOG_START_X);
  state->logs[TRADING_LOG] = newwin(LOG_Y_SIZE,LOG_X_SIZE,LOG_START_Y,LOG_START_X);
  
  MSG_ENABLE_SCROLLING(state->logs[TRADING_LOG]);
  
  state->panels[EVENT_LOG] = new_panel(state->logs[EVENT_LOG]);
  state->panels[MAIN_SCREEN] = new_panel(state->logs[MAIN_SCREEN]);
  state->panels[INVENTORY_LOG] = new_panel(state->logs[INVENTORY_LOG]);
  state->panels[TRADING_LOG] = new_panel(state->logs[TRADING_LOG]);
  
  box(state->logs[EVENT_LOG],0,0);
  box(state->logs[INVENTORY_LOG],0,0);

  INIT_EVENT_LOG(state->logs[EVENT_LOG]);

    
  top_panel(state->panels[MAIN_SCREEN]);
   
  update_panels();
  doupdate();

  return state;
 
}

 
