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


#ifndef CREATURE_STRUCT
#define CREATURE_STRUCT
#include <inttypes.h>
#include "strings.h"
#include "u_hash.h"
#include <ncurses.h>
#include "gameinfo.h"
#include "creature_macros.h"
#include "rng_rng.h"
#include "screen_constants.h"
#include "game_state_struct.h"
#include "i_item_struct.h"
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

typedef enum {animal, humanoid,cyborg,mechanical,mathematical,vegetative,player_character}C_Creature_Kind;
typedef enum {cavern,forest,aquatic,plains,mountain}C_Environment;
typedef enum {friendly,hostile, territorial,neutral,passive,undefined}C_Disposition;
typedef enum {land,flying,burrowing,diving}C_Styling;
typedef enum {head,torso,arm,leg,tail,wing,hand,foot,throat,appendage,finn,gill,noone}C_Limb_Kind;
typedef enum {healthy,bleeding,infected,disabled,frozen,poisons}C_Limb_Status;
typedef enum {immobile,poisoned,haemorrhaging,unconscious,frostbit}C_Status;
typedef enum {short_nosed_bear,elk,}C_Animal_ID;
typedef enum {idle, roaming, pursuing, attacking}C_Behavior;
typedef enum {biting, clawing, charging, headbutting}C_Attack_Type;
typedef enum{paw}limb_subtype;
typedef struct{
  C_Limb_Kind kind;
  C_Limb_Status status;
  int durability;
  int damage;  
}C_Limb;

typedef struct{
   I_Item **equipment_list;
   U_Hashtable *inventory;
}C_Player_Info;

typedef struct Color{
  // will be defined by the constants in ncurses i.e COLOR_RED, COLOR_CYAN etc. 
  unsigned primary_color:4;
// extra parameters to vary color intensity 
  unsigned second_color:10;
  unsigned third_color:10;
  unsigned fourth_color:10;
}C_Color;
typedef struct C_Attributes{
  uint32_t stamina;
  uint32_t strength;
  uint32_t dexterity;
  uint32_t luck;
  uint32_t charisma;
  uint32_t intelligence;
  uint32_t wisdom;
}C_Attributes;
//As a side note i choose the scheme of animal definitions as the specifications of the stats a creature should have and animal instances as the actually initialized structs since C apparenty doesn't allow you to declare AND initialize a pointer at compile time. Instead, what you must do is declare a pointer and then instantiate with something that is NOT a pointer 
typedef struct Animal_Definition{ // Anything ending with an Definitions is an array that defines the stats of a given creature of a given type
  char *name;
  char *description;
  float weight;
  float height;
  float width;
  C_Attributes attributes;
  C_Color color;
  C_Behavior behavior;
  int limb_count;
  C_Limb *limbs;
}C_Animal_Definition;

typedef struct Humanoid_Definition{
  char *name;
  char *description;
  float weight;
  float height;
  I_Material head_m;
  I_Material neck_m;
  I_Material finger_m;
  I_Material torso_m;
  I_Material legs_m;
  I_Material main_hand_m;
  I_Variant main_hand_variant;
  //  Mele_Weapon_Kind mele_weapon_kind;
  I_Material off_hand_m;
  I_Material back_m;
  C_Attributes attributes;
  I_Quality_Level equipment_quality;
  //  Mele_Weapon_Kind secondary_weapon_kind;  in the case that their offhand is a weapon, use this, if not, let it be some arbitrary value
  C_Behavior behavior;
}C_Humanoid_Definition;

// Code's sidenote. When mixing typedef and recursive structs, one needs a fair bit of care. Because the struct is recursively defined,
// the name of the struct must be defined, when recursively defining it. So for example
//
// typedef struct {
//  struct my_struct; <----- not valid as name is not defined
//   } my_struct;
//
//  typedef struct somestruct {
//    struct mystruct; <-------- not valid as struct is named as somestruct and and typedef is not completed yet.
//     } mystruct;
//
//
//
//
//
//


typedef struct C_Creature{
  int id;
  unsigned int limb_count:10;
  C_Limb *limbs;
  float weight;
  float height;
  C_Creature_Kind creature_type;
  C_Disposition disposition;
  C_Attributes attributes;
  uint32_t max_health;
  uint32_t curr_health;
  float max_carry;
  float current_carry;
  // A generic placeholder for any kind of additional info that is highly dependent on the specific creature type
  void *additional_info;
  char representation[2];
  C_Color *color;
  Position position;
  char standing_on[2];
  int marked_for_deletion : 1 ;
  int target_is_within_bound:1;
  C_Behavior behavior;
  C_Behavior default_behavior;
  struct C_Creature *target;
  unsigned int has_moved_around_vertically:1;
  unsigned int has_moved_around_horizontally:1;
  unsigned int curr_ap:10;
  unsigned int max_ap:10;
  unsigned preferred_attack_type;
  int alive : 1;
  int status_flags;
}C_Creature;




char *c_creature_attack_bodytype_quad(C_Creature *c,Rng_Mersienne_Twister *twister);
#endif


