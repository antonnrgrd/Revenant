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

void ll_iter_list_as_creature(Linked_List *list, Game_World *current_zone){
  Node *current_node = list->initial_node;
  Node *previous = current_node;
  while(current_node != NULL) {
    /*If a creature has been marked for deletion, it is dead and should therefore be firstly removed from the lsit of creature's that gets to act because it is dead and secondly, the creature itself is freed. We do not free the intercal contained structures of the creatures itself because they are already free'd whenever it is detected that a creature has died.*/
    if( ((struct Creature *)current_node->value)->marked_for_deletion == YES){
      free((struct Creature *)current_node->value);
      current_node->value = NULL;
    }
    else{
    cb_act( (struct Creature *)current_node->value, ((struct Creature *)current_node->value)->target, current_zone);
    previous = current_node;
    current_node = current_node->next;
    }
  }
}

void gs_print_foes(Game_State *game_state){
  Node *current_node = game_state->active_creatures->initial_node;
  /* TBD:consider only creatures within range of the player */
  while(current_node != NULL) {
    mvprintw( ((struct Creature *)current_node->value)->position.local_y,((struct Creature *)current_node->value)->position.local_x,((struct Creature *)current_node->value)->representation);
    current_node = current_node->next;
  }
}



Game_State *gs_create_game_state(Creature *player, Game_World *world,Linked_List *active_creatures){
  Game_State *state = malloc(sizeof(Game_State));
  state->player = player;
  state->current_zone = world;
  state->active_creatures = active_creatures;
  state->action_log = new_panel(stdscr);
  INIT_LOG_SCREEN(state->action_log);
  /*We don't call */
  return state;
}
