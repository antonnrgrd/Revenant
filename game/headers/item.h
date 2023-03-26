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
#define PRINT_ITEM 0
#define I_COPY_ITEM_HOLDER(source_item,target_item) Item_Holder *item_holder = malloc(sizeof(Item_Holder)); \
  item_holder->item = malloc(sizeof(Item)); \
  item_holder->item->id = item->item->id; \
  item_holder->item->representation = malloc(sizeof(char)); \
  strcpy(item_holder->item->representation,item->item->representation); \
  item_holder->item->standing_on = malloc(sizeof(char)); \
  strcpy(item_holder->item->standing_on,item->item->standing_on); \
  item_holder->item->value = item->item->value; \
  item_holder->item->kind = item->item->kind; \
  item_holder->item->weight = item->item->weight; \
  item_holder->item->quest_item = item->item->quest_item; \
  (*i_item_holder_copy_handler[item_holder->item->kind])(item_holder);

#define I_FREE_ITEM_HOLDER(item_holder) \
  (*i_free_item_handler[item_holder->item->kind])(item_holder); \
  free(item_holder->item->representation);			\
    free(item_holder->item->standing_on);			\
  free(item_holder->item);					\
  free(item_holder);						\
  item_holder = NULL;

  
typedef enum Material{carbon_fiber,plastic,clay,leather,gold,silver,custom,granite,marble,flint,iron,bronze,steel,mithril,adamantite,runite,titanium,laser,plasma,matterbane}Material;
typedef enum Variant{one_hand, two_hand}Variant;
typedef enum Weapon_Group{mele,ranged}Weapon_Group;
typedef enum Type{normal,magical}Type;
typedef enum Quality_Level{poor,adequate,good,great,excellent,masterful,epic,legendary,artefact}Quality_Level;
//typedef enum Enchantment_Level{low,medium,high,very_high,epic,legendary,artefact}Enchantment_Level;
#define NUM_EQUIPMENT_SLOTS 9
typedef enum Worn_In{head_slot,neck_slot,finger_slot,torso_slot,legs_slot,back_slot,mainhand_slot,offhand_slot, feet_slot}Worn_in;
typedef enum Item_Kind{reagent,consumable,weapon,armor}Item_Kind;
typedef enum Reagent_Kind{cooking,smithing,fishing,herb,computer}Reagent_Kind;
typedef enum Weapon_Kind{sword,mace,axe}Weapon_Kind;
typedef enum {helmet, hat, mask, chestplate,robe,chainmail,leggings, trousers, ring,boots }Equipment_Kind;
typedef enum {very_light, light, medium, heavy,very_heavy}Equipment_Classification;
typedef struct{
  int id;
  Reagent_Kind reagent_kind;
}Reagent;
typedef struct{
  int id;
  int hp_change;
}Consumable;
typedef struct Armor{
  Quality_Level quality;
  uint64_t armor;
  Worn_in slot; //in which item slot will the item be worn in
  Material material;
  uint16_t skill;
  Equipment_Kind armor_type;
  Equipment_Classification weight_classification;
}Armor;

typedef struct Weapon{
  Quality_Level quality;
  Variant variant;
  Material material;
  Weapon_Group group;
  uint64_t dmg;
  Weapon_Kind kind;
  Worn_in slot;
}Weapon;

typedef union Equipment{
  Armor *armor;
  Weapon *weapon;
}Equipment; 


typedef struct Item{
  int id;
  void *item_specific_info;
  char *representation;
  char *standing_on;
  uint32_t value;
  Item_Kind kind;
  float weight;
  uint8_t quest_item; //an unsigned int to specify if an item is a quest item and an id to specify
  uint8_t quest_id;   //which quest it belongs to.
}Item;

typedef struct Item_Holder{ //a struct for an item and how many of that item currently is in the inventory
  Item *item;
  int amount;
}Item_Holder;


Item_Holder *i_make_item_holder(Item *item, unsigned amount);
void i_swap_pointers(Item_Holder *i,Item_Holder *j);

Item *i_make_mele_weapon(Quality_Level q, Material material, Variant v,Weapon_Kind weapon_kind);

Item *i_make_consumable(char *name, char *description,uint32_t healing, uint32_t value, float weight, uint16_t skill);

Armor *i_gen_armor(Quality_Level q, Material material,Equipment_Kind armor_type);
Consumable *i_gen_consumable(uint32_t healing, uint32_t value, float weight, uint16_t skill);

Reagent *i_gen_reagent(Variant variant,float weight,uint32_t value,Reagent_Kind kind);

Weapon *i_gen_weapon(Quality_Level q,Variant variant,Material material,Weapon_Group group,Weapon_Kind k);
Item *i_make_armor(Quality_Level q, Material material, Equipment_Kind armor_type);
Consumable *i_create_consumable(char *name, char *description);

Item *i_create_item(char *name, char *description,Item_Kind kind);

char *i_mele_weapon_name(Quality_Level q, Material material, Variant v, Weapon_Kind kind);
char *i_consumable_name();
char *i_reagent_name();
char *i_material_name(Material material);
char *i_variant_name(Variant v);
char *i_quality_name(Quality_Level q);
Item *i_make_weapon(Quality_Level q, Material material, Variant v);

void i_free_weapon(Item_Holder *item);
void i_free_reagent(Item_Holder *item);
void i_free_consumable(Item_Holder *item);
Item *i_copy_item(Item_Holder *item);



extern void (*copy_item_handler[5])(Item *i);


extern void (*i_print_item_name_handler[3])(Item *i);

extern inline void i_derive_item_name(Item *i,char *bfr);

void i_print_reagent_name(Item *i, WINDOW *inv_screen,int x, int y);
void i_print_consumable_name(Item *i, WINDOW *inv_screen,int x, int y);
void i_print_equippable_name(Item *i, WINDOW *inv_screen,int x, int y);

#define HAS_ITEM_NAME_WEAPON(source_item_holder, target_item_holder)({int is_equal = 0; const char *source_item_holder_quality = quality_name_modifier[((struct Weapon *)source_item_holder->item->item_specific_info)->quality]; const char *source_item_holder_material = material_name_modifier[((struct Weapon *)source_item_holder->item->item_specific_info)->material]; const char *source_item_holder_handed_modifier = handed_modifier[((struct Weapon *)source_item_holder->item->item_specific_info)->variant]; const char *source_item_holder_kind_modifier = mele_weapon_name_modifier[((struct Weapon *)source_item_holder->item->item_specific_info)->kind]; const char *target_item_holder_quality = quality_name_modifier[((struct Weapon *)target_item_holder->item->item_specific_info)->quality]; const char *target_item_holder_material = material_name_modifier[((struct Weapon *)target_item_holder->item->item_specific_info)->material]; const char *target_item_holder_handed_modifier = handed_modifier[((struct Weapon *)target_item_holder->item->item_specific_info)->variant]; const char *target_item_holder_kind_modifier = mele_weapon_name_modifier[((struct Weapon *)target_item_holder->item->item_specific_info)->kind]; is_equal = (strcmp(source_item_holder_quality,target_item_holder_quality)  |  strcmp(source_item_holder_material, target_item_holder_material)  | strcmp(source_item_holder_handed_modifier,target_item_holder_handed_modifier)  | strcmp(source_item_holder_kind_modifier,target_item_holder_kind_modifier));/* printf(" cmps: %d %d %d %d", strcmp(source_item_holder_quality,target_item_holder_quality) , strcmp(source_item_holder_material, target_item_holder_material), strcmp(source_item_holder_handed_modifier,target_item_holder_handed_modifier), strcmp(source_item_holder_kind_modifier,target_item_holder_kind_modifier)  );*/ is_equal;})
#define HAS_ITEM_NAME_ARMOR(source_item_holder, target_item_holder)({int is_equal; const char *source_item_holder_quality = quality_name_modifier[((struct Armor *)source_item_holder->item->item_specific_info)->quality]; const char *source_item_holder_material = material_name_modifier[((struct Armor *)source_item_holder->item->item_specific_info)->material]; const char *source_item_holder_armor_type = equipment_type_modifier[((struct Armor *)source_item_holder->item->item_specific_info)->armor_type]; char *target_item_holder_quality = quality_name_modifier[((struct Armor *)target_item_holder->item->item_specific_info)->quality]; const char *target_item_holder_material = material_name_modifier[((struct Armor *)target_item_holder->item->item_specific_info)->material]; const char *target_item_holder_armor_type = equipment_type_modifier[((struct Armor *)target_item_holder->item->item_specific_info)->armor_type]; is_equal = (strcmp(source_item_holder_quality,target_item_holder_quality) | strcmp(source_item_holder_material,target_item_holder_material) | strcmp(source_item_holder_armor_type,target_item_holder_armor_type) ); is_equal;})

#define HAS_ITEM_NAME_EQ(source_item_holder, target_item_holder) target_item_holder->item->kind == weapon ? HAS_ITEM_NAME_WEAPON(source_item_holder, target_item_holder) :  HAS_ITEM_NAME_ARMOR(source_item_holder, target_item_holder)
#define HAS_ITEM_NAME_NONEQ(source_item_holder,target_item_holder)source_item_holder->item->kind == target_item_holder->item->kind && source_item_holder->item->id == target_item_holder->item->id ? 0 : 1
#define HAS_SAME_NAME(source_item_holder,target_item_holder)target_item_holder->item->kind == weapon || target_item_holder->item->kind == armor ? HAS_ITEM_NAME_EQ(source_item_holder,target_item_holder) : HAS_ITEM_NAME_NONEQ(source_item_holder,item)
/*if the items are of a different type, we can trivially conlclude that they are not the same*/
#define HAS_SAME_NAME_TRIVIAL(source_item_holder,target_item_holder) source_item_holder->item->kind != target_item_holder->item->kind ? 1 : HAS_SAME_NAME(source_item_holder,target_item_holder)

#define I_GET_FILEPATH_REAGNET(item)({char *file_path; file_path = malloc(sizeof(char) * strlen("/usr/lib/revenant_files/item_files/reagent_files/") +5); sprintf(file_path,"/usr/lib/revenant_files/item_files/reagent_files/%d",item->id); file_path;})

#define I_GET_FILEPATH_CONSUMABLE(item)({char *file_path; file_path = malloc(sizeof(char) * strlen("/usr/lib/revenant_files/item_files/reagent_files/") +5); sprintf(file_path,"/usr/lib/revenant_files/item_files/consumable_files/%d",item->id); file_path;})
  

#define I_GET_FILEPATH(item)(item->kind == reagent ? (I_GET_FILEPATH_REAGNET(item)) : (I_GET_FILEPATH_CONSUMABLE(item)))

extern void (*i_item_holder_copy_handler[4])(Item_Holder *source_item,Item_Holder *target_item);
extern void (*i_free_item_handler[4])(Item_Holder *item);
void i_copy_reagent(Item_Holder *source_item,Item_Holder *target_item);

void i_copy_consumable(Item_Holder *source_item,Item_Holder *target_item);

void i_copy_weapon(Item_Holder *source_item,Item_Holder *target_item);

void i_copy_armor(Item_Holder *source_item,Item_Holder *target_item);
//Item_Holder *i_readin_reagent(char *reagent_file_path);

#endif


