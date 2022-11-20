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


void c_initialize_animal_inf(Creature *c,int id){
  Animal_Definition d = animal_definitions[id];
  COPY_ATTRIBUTE_INFORMATION(c->attributes, d.attributes);
  c->weight = d.weight;
  c->height = d.height;
  c->limb_count = d.limb_count;
  c->limbs = malloc(sizeof(Limb) * c->limb_count);
  memcpy(c->limbs, d.limbs, (sizeof(Limb) * c->limb_count));
  c->representation = malloc(sizeof(char));
  // We use strcpy instead of assigning the 0th index to be it's char represenation because for some reason, it started printing garbage when using that method to assign its creaturetype representation
  //,explaining the difference in how the ascii represenation for the player and creature is handled
  strcpy(c->representation, "a");
}

void c_initialize_humanoid_inf(Creature *c, int id){
  //  Humanoid_Definition d = humanoid_definitions[id];
  //  c->weight = d.weight;
  // c->height = d.height;
  c->representation[0] = 'h';
  // c->instance.humanoid = c_generate_humanoid_instance(d);
}

Creature *c_generate_creature(Creature_Kind kind, int id,unsigned x,unsigned y,Game_World *world,Creature *target){
  Creature *c = malloc(sizeof(Creature));
  creature_initializer[kind](c,id);
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
  c->standing_on = malloc(sizeof(char));
  c->standing_on[0] = world->tiles[c->position.global_y][c->position.global_x].content[0];
  world->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
  world->tiles[c->position.global_y][c->position.global_x].foe = c;
  c->has_moved_around_vertically = 0;
  c->has_moved_around_horizontally = 0;
  c->marked_for_deletion = NO;
  return c;
}


// A tester function to help test cases 
Creature *c_random_player(int x, int y,Game_World *world, Mersienne_Twister *twister){
  Creature *c = malloc(sizeof(Creature));
  c->curr_ap = 1;
  c->max_ap = 1;
  c->standing_on = malloc(sizeof(char));
  c->weight = 80.5;
  c->height = 1.80;
  c->species = humanoid;
  c->max_carry = 5000.0;
  c->current_carry = 0.0;
  c->disposition = undefined;
  c->position.global_x = x;
  c->position.global_y = y;
  if(x <= world->max_x-1){
    c->position.local_x = x;
  }
  else{
    if(world->max_x % 2 == 0){
      c->position.local_x = world->max_x/2;
    }
    else{
      c->position.local_x = (world->max_x - 1)/2;
    }
  }
  if(y <= world->max_y-1){
    c->position.local_y = y;
  }
  else{
    if(world->max_x % 2 == 0){
      c->position.local_x = world->max_x/2;
    }
    else{
      c->position.local_x = (world->max_x - 1)/2;
    }
  }
  


  c->representation = malloc(sizeof(char));
  c->representation[0] = '@';
  c->color = malloc(sizeof(Color));
  c->standing_on[0] = ' ';
  U_Hashtable *inventory = u_initialize_hashtable(10,twister);
  Player_Info *player_info = malloc(sizeof(Player_Info));
  player_info->equipment_list = malloc(sizeof(Item *) * NUM_EQUIPMENT_SLOTS);
  player_info->inventory = inventory;
  c->additional_info = player_info;
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


extern  Animal_Definition animal_definitions[] = {{"Short-faced bear","A large brown bear. It has a disproportionately short face",900,3.4,1.5 , {12,12,12,12,12,12,12}, {COLOR_RED, 0,0,0},6,  {{{head,healthy,100, 100},{torso,healthy,100, 100},{arm,healthy,100, 100},{arm,healthy,100, 100},{leg,healthy,100, 100},{leg,healthy,100, 100},{tail,healthy,100, 100}}},roaming}};


						  

//extern Humanoid_Definition humanoid_definitions[] = {{"Bandit", "A bandit looking to steal rob and murder you", 65,1.65, iron,iron,iron, leather, leather, steel, one_hand, sword,steel, leather, {15,15,15,15,15,15,15}, {head, healthy, 14, 15},{torso, healthy, 18, 21},{arm, healthy, 14, 15} , {arm, healthy, 14, 15}, {leg, healthy, 14, 15}, {leg, healthy, 14, 15},{noone, healthy, 14, 15},{noone, healthy, 14, 15},{noone, healthy, 14, 15}, medium, weaponry, axe}};


void (*creature_initializer[1])(Creature *c, int id) = { c_initialize_animal_inf};

char *c_retrieve_creature_name(Creature *c){
  switch(c->species){
  case animal:
    return animal_definitions[c->id].name;
  default:
    return "Undef";
  }
}


