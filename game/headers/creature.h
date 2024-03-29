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
#include "gameinfo.h"
#include "creature_macros.h"
#include "rng.h"
#include "screen_constants.h"
#include "game_state_struct.h"
#define COPY_LIMB(creature_limb, source_limb){\
  creature_limb.kind = source_limb.kind; \
  creature_limb.status = healthy; \
  creature_limb.kind = source_limb.kind; \
  creature_limb.durability = source_limb.durability; \
  creature_limb.damage = source_limb.damage; \
    };

#define COPY_ATTRIBUTE_INFORMATION(creature_attributes, creature_information_attributes){ \
  creature_attributes.stamina =  creature_information_attributes.stamina; \
  creature_attributes.strength =  creature_information_attributes.strength; \
  creature_attributes.dexterity =  creature_information_attributes.dexterity; \
  creature_attributes.luck =  creature_information_attributes.luck; \
  creature_attributes.charisma =  creature_information_attributes.charisma; \
  creature_attributes.intelligence =  creature_information_attributes.intelligence; \
  creature_attributes.wisdom =  creature_information_attributes.intelligence; \
  }

typedef enum Creature_Kind{animal, humanoid,cyborg,mechanical,mathematical,vegetative,player_character}Creature_Kind;
typedef enum Environment{cavern,forest,aquatic,plains,mountain}Environment;
typedef enum Disposition{friendly,hostile, territorial,neutral,passive,undefined}Disposition;
typedef enum Styling{land,flying,burrowing,diving}Styling;
typedef enum Limb_Kind{head,torso,arm,leg,tail,wing,hand,foot,throat,appendage,finn,gill,noone}Limb_Kind;
typedef enum Limb_Status{healthy,bleeding,infected,disabled,frozen,poisons}Limb_Status;
typedef enum Status{immobile,poisoned,haemorrhaging,unconscious,frostbit}Status;
typedef enum Animal_ID{short_nosed_bear,elk,}Animal_ID;
typedef enum behavior{idle, roaming, pursuing, attacking}behavior;
typedef enum attack_type{biting, clawing, charging, headbutting}attack_type;
typedef enum{paw}limb_subtype;
typedef struct Limb{
  Limb_Kind kind;
  Limb_Status status;
  int durability;
  int damage;  
}Limb;

typedef struct{
   Item **equipment_list;
   U_Hashtable *inventory;
}Player_Info;

typedef struct Color{
  // will be defined by the constants in ncurses i.e COLOR_RED, COLOR_CYAN etc. 
  unsigned primary_color:4;
// extra parameters to vary color intensity 
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
//As a side note i choose the scheme of animal definitions as the specifications of the stats a creature should have and animal instances as the actually initialized structs since C apparenty doesn't allow you to declare AND initialize a pointer at compile time. Instead, what you must do is declare a pointer and then instantiate with something that is NOT a pointer 
typedef struct Animal_Definition{ // Anything ending with an Definitions is an array that defines the stats of a given creature of a given type
  char *name;
  char *description;
  float weight;
  float height;
  float width;
  Attributes attributes;
  Color color;
  behavior behavior;
  int limb_count;
  Limb *limbs;
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
  //  Mele_Weapon_Kind mele_weapon_kind;
  Material off_hand_m;
  Material back_m;
  Attributes attributes;
  Quality_Level equipment_quality;
  //  Mele_Weapon_Kind secondary_weapon_kind;  in the case that their offhand is a weapon, use this, if not, let it be some arbitrary value
  behavior behavior;
}Humanoid_Definition;


typedef struct Creature{
  int id;
  unsigned int limb_count:10;
  Limb *limbs;
  float weight;
  float height;
  Creature_Kind species;
  Disposition disposition;
  Attributes attributes;
  uint32_t max_health;
  uint32_t curr_health;
  float max_carry;
  float current_carry;
  // A generic placeholder for any kind of additional info that is highly dependent on the specific creature type
  void *additional_info;
  char representation[2];
  Color *color;
  Position position;
  char standing_on[2];
  int marked_for_deletion : 1 ;
  int target_is_within_bound:1;
  behavior behavior;
  behavior default_behavior;
  struct Creature *target;
  unsigned int has_moved_around_vertically:1;
  unsigned int has_moved_around_horizontally:1;
  unsigned int curr_ap:10;
  unsigned int max_ap:10;
  unsigned preferred_attack_type;
  int alive : 1;
  int status_flags;
}Creature;



extern void (*c_free_creature_body_type[1])(Creature *c);
void c_free_animal(Creature *c);



Creature *c_generate_creature(Creature_Kind kind, int id,unsigned x,unsigned y,Game_World *world,Creature *target);



void c_initialize_humanoid_inf(Creature *c, int id);


Color *c_copy_color(Color color);

Creature *c_random_player(int y, int x ,Game_State *gs, Game_World *gw);

void c_compute_relative_coords(Creature *creature, Creature *player);

void c_cleanup_creature(Creature *c,Game_World *world);
 char  *c_retrieve_creature_name(Creature *c);

char *creature_attack_bodytype_quad(Creature *c,Mersienne_Twister *twister);
#endif


