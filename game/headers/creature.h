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
#ifndef CREATURE
#define CREATURE
#include <inttypes.h>
#include "strings.h"
#include "u_hash.h"
#include <ncurses.h>
#include "placeholder.h"
#include "tiles.h"
typedef enum Creature_Kind{animal, humanoid,cyborg,mechanical,mathematical,vegetative,player_character}Creature_Kind;
typedef enum Environment{cavern,forest,aquatic,plains,mountain}Environment;
typedef enum Disposition{friendly,hostile, territorial,neutral,passive,undefined}Disposition;
typedef enum Styling{land,flying,burrowing,diving}Styling;
typedef enum Limb_Kind{hhead,ttorso,aarm,lleg,ttail,wwing,hhand,ffoot,tthroat,tappendage,ffinn,ggill,noone}Limb_Kind;
typedef enum Limb_Status{bleeding,healthy,infected,disabled,frozen,poisons}Limb_Status;
typedef enum Status{immobile,poisoned,haemorrhaging,unconscious,frostbit}Status;
typedef enum Animal_ID{short_nosed_bear,elk,}Animal_ID;
typedef struct Limb{
  Limb_Kind kind;
  Limb_Status status;
  int durability;
  int damage;
}Limb;

typedef struct Color{
  /* will be defined by the constants in ncurses i.e COLOR_RED, COLOR_CYAN etc. */
  unsigned primary_color:4;
  /* extra parameters to vary color intensity */
  unsigned second_color:10;
  unsigned third_color:10;
  unsigned fourth_color:10;
}Color;
typedef struct Attributes{
  uint32_t stamina;
  uint32_t strength;
  uint32_t dexterity;
  uint32_t luck;
  uint32_t charisma;
  uint32_t intelligence;
  uint32_t wisdom;
}Attributes;
/*As a side note i choose the scheme of animal definitions as the specifications of the stats a creature should have and animal instances as the actually initialized structs since C apparenty doesn't allow you to declare AND initialize a pointer at compile time. Instead, what you must do is declare a pointer and then instantiate with something that is NOT a pointer */
typedef struct Animal_Definition{ // Anything ending with an Definitions is an array that defines the stats of a given creature of a given type
  char *name;
  char *description;
  float weight;
  float height;
  float width;
  Attributes attributes;
  Limb head;
  Limb torso;
  Limb l_arm;
  Limb r_arm;
  Limb l_leg;
  Limb r_leg;
  Limb tail;
  Color color;
}Animal_Definition;

typedef struct Humanoid_Definition{ 
  char *name;
  char *description;
  float weight;
  float height;
  Material head_m;
  Material neck_m;
  Material finger_m;
  Material torso_m;
  Material legs_m;
  Material main_hand_m;
  Variant main_hand_variant;
  Mele_Weapon_Kind mele_weapon_kind;
  Material off_hand_m;
  Material back_m;
  Attributes attributes;
  Limb head;
  Limb torso;
  Limb l_arm;
  Limb r_arm;
  Limb l_leg;
  Limb r_leg;
  Limb l_wing;
  Limb r_wing;
  Limb tail;
  Quality_Level equipment_quality;
  Equipment_Kind secondary_kind; // a specifier that specifies whether the offhand is a weapon or something else
  Mele_Weapon_Kind secondary_weapon_kind; // in the case that their offhand is a weapon, use this, if not, let it be some arbitrary value
}Humanoid_Definition;


typedef struct Humanoid_Instance{ 
  Item *head_wear;
  Item *torso_wear;
  Item *legs_wear;
  Item *main_hand_wear;
  Item *off_hand_wear;
  Item *neck_wear;
  Item *back_wear;
  Item *finger_wear;
  Limb *head;
  Limb *torso;
  Limb *l_arm;
  Limb *r_arm;
  Limb *l_leg;
  Limb *r_leg;
  Limb *tail;
}Humanoid_Instance;

typedef struct Animal_Instance{ // Anything ending with an Instance is intended to be the actual instantiations of a given creature type
  Limb *head;
  Limb *torso;
  Limb *l_arm;
  Limb *r_arm;
  Limb *l_leg;
  Limb *r_leg;
  Limb *tail;
}Animal_Instance;



typedef struct Dragon_Kind{
  char *name;
  char *description;
  Attributes *attributes;
  Limb *tail;
  Limb *hhhead;
  Limb *torso;
  Limb *throat;
  Limb *left_wing;
  Limb *right_wing;
  Limb *l_foreleg;
  Limb *r_foreleg;
  Limb *l_hindleg;
  Limb *r_hindleg;
  Limb *l_forehand;
  Limb *r_forehand;
  Limb *l_hindhand;
  Limb *r_hindhand;
  Limb *l_forefoot;
  Limb *r_forefoot;
  Limb *l_hindfoot;
  Limb *r_hindfoot;
}Dragon_Kind;

typedef struct Humanoid{
  char *description;
  Limb *head;
  Limb *torso;
  Limb *throat;
  Limb *l_leg;
  Limb *r_leg;
  Limb *l_foot;
  Limb *r_foot;
  Limb *l_hand;
  Limb *r_hand;
  Limb *l_arm;
  Limb *r_arm;
  Item *headgear;
  Item *chestgear;
  Item *leggear;
  Item *backgear;
  Item *mainhand;
  Item *offhand;
}Humanoid;

typedef struct Player_Character{
  char *description;
  Limb *head;
  Limb *torso;
  Limb *throat;
  Limb *l_leg;
  Limb *r_leg;
  Limb *l_foot;
  Limb *r_foot;
  Limb *l_hand;
  Limb *r_hand;
  Limb *l_arm;
  Limb *r_arm;
  Item *headgear;
  Item *chestgear;
  Item *leggear;
  Item *backgear;
  Item *mainhand;
  Item *offhand;
  U_Hashtable *inventory;
}Player_Character;
 

typedef union Creature_Instance{
  Humanoid_Instance *humanoid;
   Animal_Instance *animal;
  Player_Character *character;
}Creature_Instance;

typedef struct Creature{
  float weight;
  float height;
  Creature_Kind species;
  Disposition disposition;
  Attributes *attributes;
  uint32_t max_health;
  uint32_t curr_health;
  char *name;
  char *description;
  float max_carry;
  float current_carry;
  Creature_Instance instance;
  char *representation;
  Color *color;
  Position position;
  char *standing_on;
  int flip:1;
}Creature;


extern Animal_Definition animal_definitions[];
extern Humanoid_Definition humanoid_definitions[];


Attributes *c_generate_attributes(uint32_t stamina,uint32_t strength,uint32_t dexterity,uint32_t luck,uint32_t charisma,uint32_t intelligence,uint32_t wisdom);

Limb *c_generate_limb(Limb_Kind kind, int durability, int damage);

Creature *c_generate_creature(Creature_Kind kind, int id,unsigned x,unsigned y);

Animal_Instance *c_generate_animal_instance(Animal_Definition d);

Attributes *c_gen_attributes(Attributes src);

void c_free_(Animal_Instance *a);


Humanoid_Instance *c_generate_humanoid_instance(Humanoid_Definition d);
//Humanoid_Instance *c_generate_humanoid_instance(Humanoid_Definition d);


void c_initialize_animal_inf(Creature *c, int id);

void c_initialize_humanoid_inf(Creature *c, int id);

Creature *c_generate_creature(Creature_Kind kind, int id, unsigned x, unsigned y);

void (*creature_initializer[6])(Creature *c, int id);

Color *c_copy_color(Color color);

Creature *c_random_player(int y, int x ,Game_World *world);
#endif
