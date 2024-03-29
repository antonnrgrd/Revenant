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


#include "creature.h"
#include "item.h"
#include "move_handler.h"
 
void c_free_creature(Creature *c){
  free(c->representation);
  free(c->standing_on);
  // We do not free the Creature struct itself because when a creature dies, we mark it for deletion and later on, when going through all active creatures and we see that it is marked for deletion, we remove it from the list of active creatures and only then, can we safely remove. Otherwise, we will have a segementation fault because we pass a null pointer as an argument for the creature behavior function.
}

void c_cleanup_creature(Creature *c,Game_World *world ){
  c_free_creature(c);
}

void (*c_free_creature_body_type[1])(Creature *c) = {};

void c_initialize_humanoid_inf(Creature *c, int id){
  //  Humanoid_Definition d = humanoid_definitions[id];
  //  c->weight = d.weight;
  // c->height = d.height;
  //  c->representation = 'h';
  // c->instance.humanoid = c_generate_humanoid_instance(d);
}

Creature *c_generate_creature(Creature_Kind kind, int id,unsigned x,unsigned y,Game_World *world,Creature *target){
  Creature *c = malloc(sizeof(Creature));

  c->position.global_x=x;
  c->position.global_y=y;
  c->curr_ap = 1;
  c->max_ap = 1;
  // Because the assignment of local coordinates can be rather arbitrary, as the local coordinates can be anything relative to the POV, we arbitarily assign to be roughly centered 
  
  c_compute_relative_coords(c, target);
 
  c->curr_health = 10;

  c->target=target;
  
  c->species = kind;
  c->id = id;
  //  c->standing_on = malloc(sizeof(char));
  c->standing_on[0] = world->tiles[c->position.global_y][c->position.global_x].content[0];
  world->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
  world->tiles[c->position.global_y][c->position.global_x].foe = c;
  c->has_moved_around_vertically = 0;
  c->has_moved_around_horizontally = 0;
  c->marked_for_deletion = NO;
  return c;
}


// A tester function to help test cases 
Creature *c_random_player(int x, int y,Game_State *gs, Game_World *gw){
  Creature *c = malloc(sizeof(Creature));
  c->curr_ap = 1;
  c->max_ap = 1;
  //c->standing_on = malloc(sizeof(char));
  c->weight = 80.5;
  c->height = 1.80;
  c->species = player_character;
  c->max_carry = 5000.0;
  c->current_carry = 0.0;
  c->curr_health = 5000;
  c->disposition = undefined;
  c->position.global_x = x;
  c->position.global_y = y;
  if(x + (DEFAULT_MAX_INFOBAR_WIDTH  - 1 ) <= gs->num_cols-1){
    c->position.local_x = x  + (DEFAULT_MAX_INFOBAR_WIDTH  - 1 ); 
  }
  else{
    if (gw->width % gs->num_cols == 0){
      c->position.local_x = gs->num_cols-1;
    }
    else{
      /*We subtract 1 to account for the fact that positions are 0-indexed*/
      c->position.local_x = (gw->width % gs->num_cols) - 1 + (DEFAULT_MAX_X  - 1 );
    }
  }
  if(y <= gs->num_rows-1){
    c->position.local_y = y;
  }
  else{
    if (gw->height % gs->num_rows == 0){
      c->position.local_y = gs->num_rows-1;
    }
    else{
      /*We subtract 1 to account for the fact that positions are 0-indexed*/
      c->position.local_y = gw->height % gs->num_rows - 1;
    }
  }
  
  // printf("local x: %d, local y: %d, global x: %d, global_y: %d, expr: %d", c->position.local_x, c->position.local_y, c->position.global_x, c->position.global_y,(x  + (DEFAULT_MAX_INFOBAR_WIDTH  - 1 )));

  //c->representation = malloc(sizeof(char));
  c->representation[0] = '@';
  c->color = malloc(sizeof(Color));
  c->standing_on[0] = ' ';
  U_Hashtable *inventory = u_initialize_hashtable(10,gs->twister);
  Player_Info *player_info = malloc(sizeof(Player_Info));
  player_info->equipment_list = malloc(sizeof(Item *) * NUM_EQUIPMENT_SLOTS);
  player_info->inventory = inventory;
  c->additional_info = player_info;
  c->marked_for_deletion = NO;
  (((Player_Info * )c->additional_info)->inventory)->money = 10000;
  c->max_carry = 0;
  return c;

}


// In order to understand why we compute the coordinates as we do when the distance ebtween player and creature exceeds the scrren boundaries, refer to the game manual
void c_compute_relative_coords(Creature *creature, Creature *player){
  if(creature->position.global_x > player->position.global_x){
    if(player->position.local_x + (creature->position.global_x - player->position.global_x) < DEFAULT_MAX_X ){
    creature->position.local_x = (player->position.local_x + (creature->position.global_x - player->position.global_x));
    }
    else{
      
      creature->position.local_x =  DEFAULT_MAX_INFOBAR_WIDTH + ((creature->position.global_x - SET_TO_MIN_X(player)) % (((DEFAULT_MAX_X -1) - DEFAULT_MAX_INFOBAR_WIDTH) + 1)); 
    }
  }
  else{
  if((player->position.local_x - (player->position.global_x - creature->position.global_x)) >= DEFAULT_MAX_INFOBAR_WIDTH ){
  creature->position.local_x = player->position.local_x - (player->position.global_x - creature->position.global_x);
    }
    else{
      creature->position.local_x = ((DEFAULT_MAX_X -1) - (((SET_TO_MAX_X(player)) - creature->position.global_x ) % (((DEFAULT_MAX_X -1) - DEFAULT_MAX_INFOBAR_WIDTH) + 1)));
    }
  }
  
  if(creature->position.global_y > player->position.global_y){
  if(player->position.local_y + (creature->position.global_y - player->position.global_y ) < DEFAULT_MAX_Y ){
  creature->position.local_y = player->position.local_y + (creature->position.global_y - player->position.global_y);
    }
  
    else{
      creature->position.local_y = DEFAULT_MIN_Y + ((creature->position.global_y - SET_TO_MIN_Y(player) ) % (( (DEFAULT_MAX_Y -1) - DEFAULT_MIN_Y)+1));
    }
  }
  
  else{
  if(player->position.local_y - (player->position.global_y - creature->position.global_y) >= DEFAULT_MIN_Y ){
  creature->position.local_y = player->position.local_y - (player->position.global_y - creature->position.global_y);
    }
    else{
      
      creature->position.local_y = (DEFAULT_MAX_Y-1) -  ((SET_TO_MAX_Y(player) - creature->position.global_y ) % (((DEFAULT_MAX_Y -1) - DEFAULT_MIN_Y)+1));
    }
  }
}






