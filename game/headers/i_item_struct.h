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


#ifndef ITEM_STRUCT
#define ITEM_STRUCT

#include <stdlib.h>
#include "strings.h"
#include "m_modifier.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <ncurses.h>
#define PRINT_ITEM 0
  
typedef enum I_Material{carbon_fiber,plastic,clay,leather,gold,silver,custom,granite,marble,flint,iron,bronze,steel,mithril,adamantite,runite,titanium,laser,plasma,matterbane}I_Material;
typedef enum I_Variant{one_hand, two_hand}I_Variant;
typedef enum I_I_Weapon_Group{mele,ranged}I_Weapon_Group;
typedef enum I_Type{normal,magical}I_Type;
typedef enum I_Quality_Level{poor,adequate,good,great,excellent,masterful,epic,legendary,artefact}I_Quality_Level;
//typedef enum Enchantment_Level{low,medium,high,very_high,epic,legendary,artefact}Enchantment_Level;
#define I_NUM_EQUIPMENT_SLOTS 9
typedef enum I_Worn_In{head_slot,neck_slot,finger_slot,torso_slot,legs_slot,back_slot,mainhand_slot,offhand_slot, feet_slot}I_Worn_In;
typedef enum I_Item_Kind{reagent,consumable,weapon,armor}I_Item_Kind;
typedef enum {cooking,smithing,fishing,herb,computer}I_Reagent_Kind;
typedef enum {sword,mace,axe}I_Weapon_Kind;
typedef enum {helmet, hat, mask, chestplate,robe,chainmail,leggings, trousers, ring,boots }I_Equipment_Kind;
typedef enum {very_light, light, medium, heavy,very_heavy}I_Equipment_Classification;
typedef struct{
  int id;
  I_Reagent_Kind reagent_kind;
}I_Reagent;
typedef struct{
  int id;
  int hp_change;
}I_Consumable;
typedef struct I_Armor{
  I_Quality_Level quality;
  uint64_t armor;
  I_Worn_In slot; //in which item slot will the item be worn in
  I_Material material;
  uint16_t skill;
  I_Equipment_Kind armor_type;
  I_Equipment_Classification weight_classification;
}I_Armor;

typedef struct I_Weapon{
  I_Quality_Level quality;
  I_Variant variant;
  I_Material material;
  I_Weapon_Group group;
  uint64_t dmg;
  I_Weapon_Kind kind;
  I_Worn_In slot;
}I_Weapon;

typedef union Equipment{
  I_Armor *armor;
  I_Weapon *weapon;
}I_Equipment; 


typedef struct I_Item{
  int id;
  void *item_specific_info;
  char representation[2];
  char standing_on[2];
  uint32_t value;
  I_Item_Kind kind;
  float weight;
  uint8_t quest_item; //an unsigned int to specify if an item is a quest item and an id to specify
  uint8_t quest_id;   //which quest it belongs to.
}I_Item;

typedef struct I_Item_Holder{ //a struct for an item and how many of that item currently is in the inventory
  I_Item *item;
  int amount;
}I_Item_Holder;

/*
#define I_COPY_ITEM_HOLDER(source_item,target_item,amount_copied) source_item = malloc(sizeof(Item));  \
  source_item->id = target_item->item->id; \
  source_item->representation[0] = target_item->item->representation[0]; \
  source_item->standing_on[0] = target_item->item->standing_on[0]; \
  source_item->value = target_item->item->value; \
  source_item->kind = target_item->item->kind; \
  source_item->weight = target_item->item->weight; \
  source_item->quest_item = target_item->item->quest_item; \
  (*i_item_holder_copy_handler[source_item->kind])(source_item,target_item);
*/



#endif


