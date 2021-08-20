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
#include "tiles.h"


void c_free_animal(Animal_Instance *a){
  /* remember to free other animal components */
  free(animal);
}

/*
void c_generate_monster_animal(int id){
  c_initialize_animal_inf(c,id);
  return;
}
*/




void c_initialize_animal_inf(Creature *c,int id){
  Animal_Definition d = animal_definitions[id];
  COPY_ATTRIBUTE_INFORMATION(c->attributes, d.attributes);
  c->weight = d.weight;
  c->height = d.height;
  c->representation = malloc(sizeof(char));
  c->representation[0] = 'a';
  c_initialize_animal_body(c, d.body_type);
}

void c_initialize_humanoid_inf(Creature *c, int id){
  Humanoid_Definition d = humanoid_definitions[id];
  c->weight = d.weight;
  c->height = d.height;
  c->representation[0] = 'h';
  // c->instance.humanoid = c_generate_humanoid_instance(d);
}

Creature *c_generate_creature(Creature_Kind kind, int id,unsigned x,unsigned y,Game_World *world){
  Creature *c = malloc(sizeof(Creature));
  creature_initializer[kind](c,id);
  c->position.global_x=x;
  c->position.global_y=y;
  c->position.local_x=x;
  c->position.local_y=y;
  c->species = kind;
  c->standing_on = malloc(sizeof(char));
  c->standing_on[0] = world->tiles[c->position.global_y][c->position.global_x].content[0];
  c->has_moved_around_vertically = 0;
  c->has_moved_around_horizontally = 0;
  return c;
}

/*
Color *c_copy_color(Color color){
  Color *c = malloc(sizeof(Color));
  c->primary_color = color.primary_color;
  c->second_color = color.second_color;
  c->third_color = color.third_color;
  c->fourth_color = color.fourth_color;
  return c;
}
*/
/* A tester function to help test cases */
Creature *c_random_player(int x, int y,Game_World *world){
  Creature *c = malloc(sizeof(Creature));
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
  c->instance.character = malloc(sizeof(Player_Character));
  c->instance.character->inventory = u_initialize_hashtable(10);
  return c;
  
}

void c_initialize_animal_body(Creature *c, body_type body_type){
    if(body_type == animal_quad ){
      c->body.animal_body = malloc(sizeof(Animal_Body));
}
}
extern  Animal_Definition animal_definitions[] = {{0 ,"Short-faced bear","A large brown bear. It has a disproportionately short face",900,3.4,1.5 , {12,12,12,12,12,12,12}, {COLOR_RED, 0,0,0}, {.animal_body = {{hhead,healthy,100, 100},{ttorso,healthy,100, 100},{aarm,healthy,100, 100},{hhead,healthy,100, 100},{lleg,healthy,100, 100},{lleg,healthy,100, 100},{ttail,healthy,100, 100}}},roaming, animal_quad}};

extern Humanoid_Definition humanoid_definitions[] = {{"Bandit", "A bandit looking to steal rob and murder you", 65,1.65, iron,iron,iron, leather, leather, steel, one_hand, sword,steel, leather, {15,15,15,15,15,15,15}, {hhead, healthy, 14, 15},{ttorso, healthy, 18, 21},{aarm, healthy, 14, 15} , {aarm, healthy, 14, 15}, {lleg, healthy, 14, 15}, {lleg, healthy, 14, 15},{noone, healthy, 14, 15},{noone, healthy, 14, 15},{noone, healthy, 14, 15}, medium, weaponry, axe}};

void (*creature_initializer[1])(Creature *c, int id) = { c_initialize_animal_inf};
