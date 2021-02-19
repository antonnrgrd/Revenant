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


Attributes *c_generate_attributes(uint32_t stamina,uint32_t strength,uint32_t dexterity,uint32_t luck,uint32_t charisma,uint32_t intelligence,uint32_t wisdom){
  Attributes *a = malloc(sizeof(Attributes));
  a->stamina = stamina;
  a->strength = strength;
  a->dexterity = dexterity;
  a->luck = luck;
  a->charisma = charisma;
  a->intelligence = intelligence;
  a->wisdom = wisdom;
  return a;
}


extern  Animal_Definition animal_definitions[] = {{"Short-faced bear","A large brown bear. It has a disproportionately short face",900,3.4,1.5 , {12,12,12,12,12,12,12}, {hhead,healthy, 100, 100},{ttorso,healthy, 100, 100}, {lleg,healthy, 100, 100}, {lleg,healthy, 100, 100}, {lleg,healthy, 100, 100}, {lleg,healthy, 100, 100}, {ttail,healthy, 100, 100}, {COLOR_RED, 0,0,0}}};

extern Humanoid_Definition humanoid_definitions[] = {{"Bandit", "A bandit looking to steal rob and murder you", 65,1.65, iron,iron,iron, leather, leather, steel, one_hand, sword,steel, leather, {15,15,15,15,15,15,15}, {hhead, healthy, 14, 15},{ttorso, healthy, 18, 21},{aarm, healthy, 14, 15} , {aarm, healthy, 14, 15}, {lleg, healthy, 14, 15}, {lleg, healthy, 14, 15},{noone, healthy, 14, 15},{noone, healthy, 14, 15},{noone, healthy, 14, 15}, medium, weaponry, axe}};

Attributes *c_gen_attributes(Attributes src ){
  Attributes *dst = malloc(sizeof(Attributes));
  dst->stamina = src.stamina;
  dst->strength = src.strength;
  dst->dexterity = src.dexterity;
  dst->luck = src.luck;
  dst->charisma = src.charisma;
  dst->intelligence = src.intelligence;
  dst->wisdom = src.wisdom;
  return dst;
}



//given a animal definition, return the corresponding instance
Animal_Instance *c_generate_animal_instance(Animal_Definition d){
  Animal_Instance *animal = malloc(sizeof(Animal_Instance));
  animal->head = malloc(sizeof(Limb));
  animal->torso = malloc(sizeof(Limb));
  if(d.tail.kind != noone){
    animal->tail = malloc(sizeof(Limb));
    animal->tail->kind = ttail;
  animal->tail->status=healthy;
  animal->tail->durability=d.tail.durability;
  animal->tail->damage=d.tail.damage;
  }
  if(d.l_arm.kind != noone){
  animal->l_arm = malloc(sizeof(Limb));
  animal->l_arm->kind = aarm;
  animal->l_arm->status=healthy;
  animal->l_arm->durability=d.tail.durability;
  animal->l_arm->damage=d.l_arm.damage;
  animal->r_arm = malloc(sizeof(Limb));
  animal->r_arm->kind = aarm;
  animal->r_arm->status=healthy;
  animal->r_arm->durability=d.r_arm.durability;
  animal->r_arm->damage=d.r_arm.damage;
  }
  if(d.l_leg.kind != noone){
  animal->l_leg = malloc(sizeof(Limb));
  animal->l_leg->kind = lleg;
  animal->l_leg->status=healthy;
  animal->l_leg->durability=d.l_leg.durability;
  animal->l_leg->damage=d.l_leg.damage;
  animal->r_leg = malloc(sizeof(Limb));
  animal->r_leg->kind = lleg;
  animal->r_leg->status=healthy;
  animal->r_leg->durability=d.r_leg.durability;
  animal->r_leg->damage=d.r_leg.damage;
  }
  
  return animal;
}
//anything with a free, frees up a creature instance of the named type
void c_free_animal(Animal_Instance *a){
  free(a->head);
  free(a->torso);
  if(a->tail != NULL){
    free(a->tail);
  }
  if(a->l_arm != NULL){
    free(a->l_arm);
    free(a->r_arm);
  }
  if(a->l_leg != NULL){
    free(a->l_leg);
    free(a->r_leg);
  }
  free(animal);
}

void c_generate_monster_animal(Creature *c, int id){

}


Humanoid_Instance *c_generate_humanoid_instance(Humanoid_Definition d){
Humanoid_Instance *humanoid = malloc(sizeof(Humanoid_Instance));
  humanoid->head = malloc(sizeof(Limb));
  humanoid->torso = malloc(sizeof(Limb));
  if(d.tail.kind != noone){
    humanoid->tail = malloc(sizeof(Limb));
    humanoid->tail->kind = ttail;
  humanoid->tail->status=healthy;
  humanoid->tail->durability=d.tail.durability;
  humanoid->tail->damage=d.tail.damage;
  }
  if(d.l_arm.kind != noone){
  humanoid->l_arm = malloc(sizeof(Limb));
  humanoid->l_arm->kind = aarm;
  humanoid->l_arm->status=healthy;
  humanoid->l_arm->durability=d.tail.durability;
  humanoid->l_arm->damage=d.l_arm.damage;
  humanoid->r_arm = malloc(sizeof(Limb));
  humanoid->r_arm->kind = aarm;
  humanoid->r_arm->status=healthy;
  humanoid->r_arm->durability=d.r_arm.durability;
  humanoid->r_arm->damage=d.r_arm.damage;
  }
  if(d.l_leg.kind != noone){
  humanoid->l_leg = malloc(sizeof(Limb));
  humanoid->l_leg->kind = lleg;
  humanoid->l_leg->status=healthy;
  humanoid->l_leg->durability=d.l_leg.durability;
  humanoid->l_leg->damage=d.l_leg.damage;
  humanoid->r_leg = malloc(sizeof(Limb));
  humanoid->r_leg->kind = lleg;
  humanoid->r_leg->status=healthy;
  humanoid->r_leg->durability=d.r_leg.durability;
  humanoid->r_leg->damage=d.r_leg.damage;
  }
  humanoid->head_wear = i_make_armor(d.equipment_quality,d.head_m,head);
  humanoid->torso_wear = i_make_armor(d.equipment_quality,d.torso_m,torso);
  humanoid->legs_wear = i_make_armor(d.equipment_quality,d.legs_m,legs);
  humanoid->main_hand_wear = i_make_mele_weapon(d.equipment_quality,d.main_hand_m, d.main_hand_variant, d.mele_weapon_kind);
  humanoid->off_hand_wear = i_make_weapon_or_shield(d.secondary_kind,d.off_hand_m, d.main_hand_variant,hand_w, d.equipment_quality, d.secondary_weapon_kind);
  humanoid->back_wear = i_make_armor(d.equipment_quality,d.back_m,back);
  humanoid->neck_wear = i_make_armor(d.equipment_quality,d.neck_m,neck);
  humanoid->finger_wear = i_make_armor(d.equipment_quality,d.finger_m,finger);
  return humanoid;
}


void c_initialize_animal_inf(Creature *c,int id){
  Animal_Definition d = animal_definitions[id];
  c->name = s_create_text(d.name);
  c->description = s_create_text(d.description);
  c->attributes = c_gen_attributes(d.attributes);
  c->weight = d.weight;
  c->height = d.height;
  c->instance.animal = c_generate_animal_instance(d);
  c->representation = malloc(sizeof(char));
  c->representation[0] = 'a';
  c->color = c_copy_color(d.color);
}

void c_initialize_humanoid_inf(Creature *c, int id){
  Humanoid_Definition d = humanoid_definitions[id];
  c->name = s_create_text(d.name);
  c->description = s_create_text(d.description);
  c->attributes = c_gen_attributes(d.attributes);
  c->weight = d.weight;
  c->height = d.height;
  c->representation[0] = 'h';
  c->instance.humanoid = c_generate_humanoid_instance(d);
}

Creature *c_generate_creature(Creature_Kind kind, int id,unsigned x,unsigned y){
  Creature *c = malloc(sizeof(Creature));
  creature_initializer[kind](c,id);
  c->position.global_x=x;
  c->position.global_y=y;
  c->position.local_x=x;
  c->position.local_y=y;
  return c;
}

Color *c_copy_color(Color color){
  Color *c = malloc(sizeof(Color));
  c->primary_color = color.primary_color;
  c->second_color = color.second_color;
  c->third_color = color.third_color;
  c->fourth_color = color.fourth_color;
  return c;
}
/* A tester function to help test cases */
Creature *c_random_player(int y, int x,Game_World *world){
  Creature *c = malloc(sizeof(Creature));
  c->standing_on = malloc(sizeof(char));
  c->weight = 80.5;
  c->height = 1.80;
  c->species = humanoid;
  c->max_carry = 5000.0;
  c->current_carry = 0.0;
  c->disposition = undefined;
  c->attributes = malloc(sizeof(Attributes));
  c->name = s_create_text("maranax");
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
  return c;
}
