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
#ifndef ITEM
#define ITEM
#include "dialogue.h"
#include "modifier.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
typedef enum Material{carbon_fiber,plastic,clay,leather,gold,silver,custom,granite,marble,flint,iron,bronze,steel,mithril,adamantite,runite,titanium,laser,plasma,matterbane}Material;
typedef enum Variant{one_hand, two_hand}Variant;
typedef enum Wkind{mele,ranged}Wkind;
typedef enum Type{normal,magical}Type;
typedef enum Quality_Level{poor,adequate,medium,high,very_high,epic,legendary,artefact}Quality_Level;
//typedef enum Enchantment_Level{low,medium,high,very_high,epic,legendary,artefact}Enchantment_Level;
typedef enum Worn_In{head,neck,finger,torso,legs,back,hand,hand_w}Worn_in;
typedef enum Equipment_Kind{armor, weaponry}Equipment_Kind;
typedef enum Item_Kind{interactable,valuable,reagent,consumable,equippable}Item_Kind;
typedef enum Reagent_Kind{cooking,smithing,fishing,herb,computer}Reagent_Kind;
typedef enum Mele_Weapon_Kind{sword,mace,axe}Mele_Weapon_Kind;

typedef struct Armor{
  uint64_t armor;
  Worn_in slot; //in which item slot will the item be worn in
  Material material;
  uint16_t skill;
}Armor;

typedef struct Weapon{
  Quality_Level quality;
  Variant variant;
  Material material;
  Wkind kind;
  uint64_t dmg;
  uint16_t skill;//what crafting level is required to make it
  Mele_Weapon_Kind type;
}Weapon;

typedef struct Reagent{
  Variant variant;
  float weight;
  uint32_t value;
  Reagent_Kind kind;
}Reagent;

typedef struct Consumable{
  uint32_t healing;
  float weight;
  uint16_t skill;
}Consumable;

typedef union Equipment{
  Armor *armor;
  Weapon *weapon;
  Equipment_Kind kind;
}Equipment; 

typedef union Specifier{
  Equipment equipment;
  Reagent *reagent;
  Consumable *consumable;
}Specifier;

typedef struct Item{
  Specifier specifier;
  char *name;
  char *representation;
  uint32_t value;
  char *description;
  Item_Kind kind;
  float weight;
  uint8_t quest_item; //an unsigned int to specify if an item is a quest item and an id to specify
  uint8_t quest_id;   //which quest it belongs to.
}Item;

typedef struct Item_Holder{ //a struct for an item and how many of that item currently is in the inventory
  Item *item;
  unsigned amount;
}Item_Holder;

void i_swap_pointers(Item_Holder *i,Item_Holder *j);

Item *i_make_mele_weapon(Quality_Level q, Material material, Variant v,Mele_Weapon_Kind kind);

Item *i_make_consumable(char *name, char *description,uint32_t healing, uint32_t value, float weight, uint16_t skill);

Item *i_make_armor(Quality_Level q, Material material, Worn_in w);
Consumable *i_gen_consumable(uint32_t healing, uint32_t value, float weight, uint16_t skill);

Reagent *i_gen_reagent(Variant variant,float weight,uint32_t value,Reagent_Kind kind);

Weapon *i_gen_mele_weapon(Quality_Level q,Variant variant,Material material,Wkind kind,uint16_t skill,Mele_Weapon_Kind k);
Armor *i_gen_armor();
//Consumable *i_create_consumable(char *name, char *description);

//Item *i_create_item(char *name, char *description,Item_Kind kind);

char *i_mele_weapon_name(Quality_Level q, Material material, Variant v, Mele_Weapon_Kind kind);
char *i_consumable_name();
char *i_armor_name(Quality_Level q, Material material, Worn_in w);
char *i_reagent_name();
char *i_material_name(Material material);
char *i_variant_name(Variant v);
char *i_quality_name(Quality_Level q);
Item *i_make_armor(Quality_Level q, Material material, Worn_in w);
Item *i_make_weapon(Quality_Level q, Material material, Variant v);

void i_armor_info(Item *i);
void i_mele_weapon_info(Item *i);
Item *i_make_weapon_or_shield(Equipment_Kind k,Material material, Variant v, Worn_in w,Quality_Level q,Mele_Weapon_Kind kind);

void i_free_item(Item *i);
void i_free_interactable(Item *i);
void i_free_valuable(Item *i);
void i_free_reagent(Item *i);
void i_free_consumable(Item *i);
void i_free_equippable(Item *i);
Item *i_copy_item(Item *i);
void (*free_item_handler[5])();

Item *i_copy_item(Item *i);

void i_copy_interactable(Item *i, Item *j);
void i_copy_valuable(Item *i, Item *j);
void i_copy_reagent(Item *i, Item *j);
void i_copy_consumable(Item *i, Item *j);
void i_copy_equippable(Item *i, Item *j);
void i_copy_reagent(Item *i, Item *j);

void (*copy_item_handler[5])();
#endif
