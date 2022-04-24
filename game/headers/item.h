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

#include <stdlib.h>
#include "strings.h"
#include "modifier.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <ncurses.h>
typedef enum Material{carbon_fiber,plastic,clay,leather,gold,silver,custom,granite,marble,flint,iron,bronze,steel,mithril,adamantite,runite,titanium,laser,plasma,matterbane}Material;
typedef enum Variant{one_hand, two_hand}Variant;
typedef enum Weapon_Group{mele,ranged}Weapon_Group;
typedef enum Type{normal,magical}Type;
typedef enum Quality_Level{poor,adequate,medium,high,very_high,epic,legendary,artefact}Quality_Level;
//typedef enum Enchantment_Level{low,medium,high,very_high,epic,legendary,artefact}Enchantment_Level;
typedef enum Worn_In{head_slot,neck_slot,finger_slot,torso_slot,leg_slot,back_slot,hand_slot}Worn_in;
typedef enum Item_Kind{reagent,consumable,weapon,armor}Item_Kind;
typedef enum Reagent_Kind{cooking,smithing,fishing,herb,computer}Reagent_Kind;
typedef enum Weapon_Kind{sword,mace,axe}Weapon_Kind;
typedef struct{
  int id;
  char *name;
  float weight;
}Reagent_Definition;
typedef struct{
  int id;
  char *name;
  int hp_change;
  float weight;
}Consumable_Definition;
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
  Weapon_Group kind;
  uint64_t dmg;
  Weapon_Kind type;
}Weapon;

typedef struct Reagent{
  float weight;
  uint32_t value;
  Reagent_Kind kind;
}Reagent;

typedef struct Consumable{
  uint32_t healing;
  uint16_t skill;
}Consumable;

typedef union Equipment{
  Armor *armor;
  Weapon *weapon;
}Equipment; 


typedef struct Item{
  int is_quest_item:1;
  void *item_specific_info;
  char *representation;
  char *standing_on;
  uint32_t value;
  char *description;
  Item_Kind kind;
  float weight;
  uint8_t quest_item; //an unsigned int to specify if an item is a quest item and an id to specify
  uint8_t quest_id;   //which quest it belongs to.
  int id;
}Item;

typedef struct Item_Holder{ //a struct for an item and how many of that item currently is in the inventory
  Item *item;
  unsigned amount;
}Item_Holder;


Item_Holder *i_make_item_holder(Item *item, unsigned amount);
void i_swap_pointers(Item_Holder *i,Item_Holder *j);

Item *i_make_mele_weapon(Quality_Level q, Material material, Variant v,Weapon_Kind kind);

Item *i_make_consumable(char *name, char *description,uint32_t healing, uint32_t value, float weight, uint16_t skill);

Item *i_make_armor(Quality_Level q, Material material, Worn_in w);
Consumable *i_gen_consumable(uint32_t healing, uint32_t value, float weight, uint16_t skill);

Reagent *i_gen_reagent(Variant variant,float weight,uint32_t value,Reagent_Kind kind);

Weapon *i_gen_weapon(Quality_Level q,Variant variant,Material material,Weapon_Group kind,Weapon_Kind k);
Armor *i_gen_armor();
Consumable *i_create_consumable(char *name, char *description);

Item *i_create_item(char *name, char *description,Item_Kind kind);

char *i_mele_weapon_name(Quality_Level q, Material material, Variant v, Weapon_Kind kind);
char *i_consumable_name();
char *i_armor_name(Quality_Level q, Material material, Worn_in w);
char *i_reagent_name();
char *i_material_name(Material material);
char *i_variant_name(Variant v);
char *i_quality_name(Quality_Level q);
Item *i_make_armor(Quality_Level q, Material material, Worn_in w);
Item *i_make_weapon(Quality_Level q, Material material, Variant v);

void i_free_item(Item *i);
void i_free_interactable(Item *i);
void i_free_valuable(Item *i);
void i_free_reagent(Item *i);
void i_free_consumable(Item *i);
void i_free_equippable(Item *i);
Item *i_copy_item(Item *i);


Item *i_copy_item(Item *i);

void i_copy_interactable(Item *i, Item *j);
void i_copy_valuable(Item *i, Item *j);
void i_copy_reagent(Item *i, Item *j);
void i_copy_consumable(Item *i, Item *j);
void i_copy_equippable(Item *i, Item *j);
void i_copy_reagent(Item *i, Item *j);

extern void (*copy_item_handler[5])(Item *i);
extern void (*free_item_handler[5])(Item *i);

extern Reagent_Definition reagent_definitions[];
extern Consumable_Definition consumable_definitions[];

extern void (*i_print_item_name_handler[3])(Item *i);

extern char* (*i_derive_item_name[3])(Item *i);

char *i_derive_item_name_reagent(Item *i);
char *i_derive_item_name_consumable(Item *i);
char *i_derive_item_name_equipment(Item *i);

void i_print_reagent_name(Item *i, WINDOW *inv_screen,int x, int y);
void i_print_consumable_name(Item *i, WINDOW *inv_screen,int x, int y);
void i_print_equippable_name(Item *i, WINDOW *inv_screen,int x, int y);

#define HAS_ITEM_NAME_WEAPON(source_item, target_item) char *source_item_quality = quality_name_modifier[((struct Weapon *)source_item->item_specific_info)->quality]; char *source_item_material = material_name_modifier[((struct Weapon *)source_item->item_specific_info)->material]; char *source_item_handed_modifer = handed_modifier[((struct Weapon *)source_item->item_specific_info)->variant]; char * source_item_type_modifer = mele_weapon_name_modifier[((struct Weapon *)source_item->item_specific_info)->type]; char *target_item_quality = quality_name_modifier[((struct Weapon *)target_item->item_specific_info)->quality]; char *target_item_material = material_name_modifier[((struct Weapon *)target_item->item_specific_info)->material]; char target_item_handed_modifer = handed_modifier[((struct Weapon *)target_item->item_specific_info)->variant]; char *target_item_type_modifer = mele_weapon_name_modifier[((struct Weapon *)target_item->item_specific_info)->type]; int res = (strcmp(source_item_quality,target_item_quality) & strcmp(source_item_material, target_item_material) & strcmp(source_item_handed_modifer,target_item_handed_modifer) & strcmp(source_item_type_modifer,target_item_type_modifer) );
#define HAS_ITEM_NAME_ARMOR(source_item, target_item)
#define HAS_ITEM_NAME_EQ(source_item, target_item)
#define HAS_ITEM_NAME_NONEQ(source_item,item) char *source_item_name = i_derive_item_name[source_item->kind]; char *target_item_name i_derive_item_name[target_item->kind]; strcmp(source_item_name, target_item_name);
#define HAS_SAME_NAME(source_item,item) item->kind == weapon || item->kind == armor ? HAS_ITEM_NAME_EQ(source_item,item) : HAS_ITEM_NAME_NONEQ(source_item,item)
#endif


