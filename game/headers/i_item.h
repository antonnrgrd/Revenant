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
#include "i_item_struct.h"
#define I_COPY_ITEM_HOLDER(source_item,target_item,amount_copied) source_item = malloc(sizeof(I_Item_Holder));  \
  source_item->item = malloc(sizeof(I_Item)); \
  source_item->item->id = target_item->item->id; \
  source_item->amount = amount_copied; \
  source_item->item->representation[0] = target_item->item->representation[0]; \
  source_item->item->standing_on[0] = target_item->item->standing_on[0]; \
  source_item->item->value = target_item->item->value; \
  source_item->item->kind = target_item->item->kind; \
  source_item->item->weight = target_item->item->weight; \
  source_item->item->quest_item = target_item->item->quest_item; \
  (*i_item_holder_copy_handler[source_item->item->kind])(source_item,target_item);


#define I_FREE_ITEM_HOLDER(item_holder) \
  (*i_free_item_handler[item_holder->item->kind])(item_holder);	\
  free(item_holder->item); \
  free(item_holder); \
  item_holder = NULL; \


I_Item_Holder *i_make_item_holder(I_Item *item, unsigned amount);
void i_swap_pointers(I_Item_Holder *i,I_Item_Holder *j);

I_Item *i_make_mele_weapon(I_Quality_Level q, I_Material material, I_Variant v,I_Weapon_Kind weapon_kind);

I_Item *i_make_consumable(char *name, char *description,uint32_t healing, uint32_t value, float weight, uint16_t skill);

I_Armor *i_gen_armor(I_Quality_Level q, I_Material material,I_Equipment_Kind armor_type);
I_Consumable *i_gen_consumable(uint32_t healing, uint32_t value, float weight, uint16_t skill);

I_Reagent *i_gen_reagent(I_Variant variant,float weight,uint32_t value,I_Reagent_Kind kind);

I_Weapon *i_gen_weapon(I_Quality_Level q,I_Variant variant,I_Material material,I_Weapon_Group group,I_Weapon_Kind k);
I_Item *i_make_armor(I_Quality_Level q, I_Material material, I_Equipment_Kind armor_type);
I_Consumable *i_create_consumable(char *name, char *description);

I_Item *i_create_item(char *name, char *description,I_Item_Kind kind);

char *i_mele_weapon_name(I_Quality_Level q, I_Material material, I_Variant v, I_Weapon_Kind kind);
char *i_consumable_name();
char *i_reagent_name();
char *i_material_name(I_Material material);
char *i_variant_name(I_Variant v);
char *i_quality_name(I_Quality_Level q);
I_Item *i_make_weapon(I_Quality_Level q, I_Material material, I_Variant v);

void i_free_weapon(I_Item *item);
void i_free_reagent(I_Item *item);
void i_free_consumable(I_Item *item);
I_Item *i_copy_item(I_Item_Holder *item);



extern void (*copy_item_handler[5])(I_Item *i);


extern void (*i_print_item_name_handler[3])(I_Item *i);

extern inline void i_derive_item_name(I_Item *i,char *bfr);

void i_print_reagent_name(I_Item *i, WINDOW *inv_screen,int x, int y);
void i_print_consumable_name(I_Item *i, WINDOW *inv_screen,int x, int y);
void i_print_equippable_name(I_Item *i, WINDOW *inv_screen,int x, int y);

/*
#define HAS_ITEM_NAME_WEAPON(source_item_holder, target_item_holder)({int is_equal = 0; const char *source_item_holder_quality = quality_name_modifier[((struct Weapon *)source_item_holder->item->item_specific_info)->quality]; const char *source_item_holder_material = material_name_modifier[((struct Weapon *)source_item_holder->item->item_specific_info)->material]; const char *source_item_holder_handed_modifier = handed_modifier[((struct Weapon *)source_item_holder->item->item_specific_info)->variant]; const char *source_item_holder_kind_modifier = mele_weapon_name_modifier[((struct Weapon *)source_item_holder->item->item_specific_info)->kind]; const char *target_item_holder_quality = quality_name_modifier[((struct Weapon *)target_item_holder->item->item_specific_info)->quality]; const char *target_item_holder_material = material_name_modifier[((struct Weapon *)target_item_holder->item->item_specific_info)->material]; const char *target_item_holder_handed_modifier = handed_modifier[((struct Weapon *)target_item_holder->item->item_specific_info)->variant]; const char *target_item_holder_kind_modifier = mele_weapon_name_modifier[((struct Weapon *)target_item_holder->item->item_specific_info)->kind]; is_equal = (strcmp(source_item_holder_quality,target_item_holder_quality)  |  strcmp(source_item_holder_material, target_item_holder_material)  | strcmp(source_item_holder_handed_modifier,target_item_holder_handed_modifier)  | strcmp(source_item_holder_kind_modifier,target_item_holder_kind_modifier)); is_equal;})
*/
#define HAS_ITEM_NAME_WEAPON(source_item_holder, target_item_holder)((( I_Weapon *)source_item_holder->item->item_specific_info)->quality == (( I_Weapon *)target_item_holder->item->item_specific_info)->quality && (( I_Weapon *)source_item_holder->item->item_specific_info)->material == (( I_Weapon *)target_item_holder->item->item_specific_info)->material && (( I_Weapon *)source_item_holder->item->item_specific_info)->variant == (( I_Weapon *)target_item_holder->item->item_specific_info)->variant && (( I_Weapon *)source_item_holder->item->item_specific_info)->kind == (( I_Weapon *)target_item_holder->item->item_specific_info)->kind ? 0 : 1)


#define HAS_ITEM_NAME_ARMOR(source_item_holder, target_item_holder)({int is_equal; const char *source_item_holder_quality = m_quality_name_modifier[(( I_Armor *)source_item_holder->item->item_specific_info)->quality]; const char *source_item_holder_material = m_material_name_modifier[(( I_Armor *)source_item_holder->item->item_specific_info)->material]; const char *source_item_holder_armor_type = m_equipment_type_modifier[(( I_Armor *)source_item_holder->item->item_specific_info)->armor_type]; char *target_item_holder_quality = m_quality_name_modifier[(( I_Armor *)target_item_holder->item->item_specific_info)->quality]; const char *target_item_holder_material = m_material_name_modifier[(( I_Armor *)target_item_holder->item->item_specific_info)->material]; const char *target_item_holder_armor_type = m_equipment_type_modifier[(( I_Armor *)target_item_holder->item->item_specific_info)->armor_type]; is_equal = (strcmp(source_item_holder_quality,target_item_holder_quality) | strcmp(source_item_holder_material,target_item_holder_material) | strcmp(source_item_holder_armor_type,target_item_holder_armor_type) ); is_equal;})

#define HAS_ITEM_NAME_EQ(source_item_holder, target_item_holder) target_item_holder->item->kind == weapon ? HAS_ITEM_NAME_WEAPON(source_item_holder, target_item_holder) :  HAS_ITEM_NAME_ARMOR(source_item_holder, target_item_holder)
#define HAS_ITEM_NAME_NONEQ(source_item_holder,target_item_holder)source_item_holder->item->kind == target_item_holder->item->kind && source_item_holder->item->id == target_item_holder->item->id ? 0 : 1
#define HAS_SAME_NAME(source_item_holder,target_item_holder)target_item_holder->item->kind == weapon || target_item_holder->item->kind == armor ? HAS_ITEM_NAME_EQ(source_item_holder,target_item_holder) : HAS_ITEM_NAME_NONEQ(source_item_holder,item)
/*if the items are of a different type, we can trivially conlclude that they are not the same*/
#define HAS_SAME_NAME_TRIVIAL(source_item_holder,target_item_holder) source_item_holder->item->kind != target_item_holder->item->kind ? 1 : HAS_SAME_NAME(source_item_holder,target_item_holder)

#define I_GET_FILEPATH_REAGNET(item)({char *file_path; file_path = malloc(sizeof(char) * strlen("/usr/lib/revenant_files/item_files/reagent_files/") +5); sprintf(file_path,"/usr/lib/revenant_files/item_files/reagent_files/%d",item->id); file_path;})

#define I_GET_FILEPATH_CONSUMABLE(item)({char *file_path; file_path = malloc(sizeof(char) * strlen("/usr/lib/revenant_files/item_files/reagent_files/") +5); sprintf(file_path,"/usr/lib/revenant_files/item_files/consumable_files/%d",item->id); file_path;})
  

#define I_GET_FILEPATH(item)(item->kind == reagent ? (I_GET_FILEPATH_REAGNET(item)) : (I_GET_FILEPATH_CONSUMABLE(item)))

extern void (*i_item_holder_copy_handler[4])(I_Item_Holder *source_item,I_Item_Holder *target_item);
extern void (*i_free_item_specific_info_handler[4])(I_Item *item);


void i_copy_reagent(I_Item_Holder *source_item,I_Item_Holder *target_item);

void i_copy_consumable(I_Item_Holder *source_item,I_Item_Holder *target_item);

void i_copy_weapon(I_Item_Holder *source_item,I_Item_Holder *target_item);

void i_copy_armor(I_Item_Holder *source_item,I_Item_Holder *target_item);

void i_free_item_holder(I_Item_Holder *item_holder);
/*19-01-2025 verified it frees all data */
#define I_FREE_ITEM(item){					       \
    (*i_free_item_specific_info_handler[item->kind])(item);	       \
    FREE_NULL(item);						       \
  }
#endif
