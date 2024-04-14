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

#ifndef UHASH
#define UHASH
#include "u_hash_struct.h"
#define U_GET_AVAILABLE(amount, available)(amount>available? available:amount)
#define U_HASH_ITEM_NONEQ(item_holder,table)({unsigned long long hash; char *filepath  = I_GET_FILEPATH(item_holder->item); hash = ir_hash_string(filepath, "name",table); free(filepath); hash;})
#define U_HAS_ITEM_WEAPON(item_holder,table)({unsigned long long hash; hash = u_hash(2,table, m_quality_name_modifier[(( I_Weapon*)item_holder->item->item_specific_info)->quality] , m_material_name_modifier[(( I_Weapon*)item_holder->item->item_specific_info)->material] , m_handed_modifier[(( I_Weapon*)item_holder->item->item_specific_info)->variant], m_mele_weapon_name_modifier[(( I_Weapon*)item_holder->item->item_specific_info)->kind] ); hash;})
#define U_HAS_ITEM_ARMOR(item_holder,table)({unsigned long long hash; hash = u_hash(1, table,m_quality_name_modifier[(( I_Armor*)item_holder->item->item_specific_info)->quality]); hash;})
#define U_HASH_ITEM_EQUIPPABLE(item_holder,table) item_holder->item->kind == weapon ? U_HAS_ITEM_WEAPON(item_holder,table) : U_HAS_ITEM_ARMOR(item_holder,table)
#define U_HASH_ITEM(item_holder,table) item_holder->item->kind != weapon && item_holder->item->kind != armor ? U_HASH_ITEM_NONEQ(item_holder,table) : U_HASH_ITEM_EQUIPPABLE(item_holder,table)

unsigned long long u_hash(int char_count,U_Hashtable *table,char *strings, ...);

U_Hashtable *u_initialize_hashtable(int initial_size,Rng_Mersienne_Twister *twister);

void u_add_item(I_Item_Holder *item, int amount,U_Hashtable *table);

U_Item_Weight u_remove_item(I_Item_Holder *item, int amount, U_Hashtable *table);


char *u_readin_char(char *file_path, char *variable);

#define U_GET_ITEMNAME_CONSUMABLE(item)({char *name = NULL; char *bfr = malloc(sizeof(char) * (strlen("/usr/lib/revenant_files/item_files/consumable_files/")) + 5); sprintf(bfr,"/usr/lib/revenant_files/item_files/consumable_files/%d",item->id); name = u_readin_char(bfr,"name"); free(bfr); name;  })
#define U_GET_ITEMNAME_REAGENT(item)({char *name = NULL; char *bfr = malloc(sizeof(char) * (strlen("/usr/lib/revenant_files/item_files/reagent_files/")) + 5); sprintf(bfr,"/usr/lib/revenant_files/item_files/reagent_files/%d",item->id); name = u_readin_char(bfr,"name"); free(bfr); name; })
#define U_GET_ITEMNAME_NONEQUIPPABLE(item)(item->kind == reagent ? (U_GET_ITEMNAME_REAGENT(item)) : (U_GET_ITEMNAME_CONSUMABLE(item)))

//#define U_DECIDE_FILEPATH(item)({char *file_path; item->kind == reagent ? (file_path = malloc(sizeof(char) * strlen("/usr/lib/revenant_files/item_files/reagent_files/") +5); sprintf(file_path,"/usr/lib/revenant_files/item_files/reagent_files/%d",item->id);) :(file_path = malloc(sizeof(char) * strlen("/usr/lib/revenant_files/item_files/reagent_files/") +5); sprintf(file_path,"/usr/lib/revenant_files/item_files/reagent_files/%d",item->id);) file_path;  })

#endif
