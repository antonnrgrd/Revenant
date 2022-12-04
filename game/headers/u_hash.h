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
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>
#include "item.h"
#include "rng.h"
#include "strings.h"
#define BFP 18446744073709551615ULL //an enormous prime (by 64-bit standards)
#define BFP_2 10089886811898868001ULL
#define NOT_DELETED 0
#define DELETED 1
#define NOT_ONE
#define ONE

#define GET_AVAILABLE(amount, available)(amount>available? available:amount)
#define U_HASH_ITEM_NONEQ(item_holder,table)({unsigned long long hash; char *filepath  = I_GET_FILEPATH(item_holder->item); hash = ir_hash_string(filepath, "name",table); free(filepath); hash;})
#define U_HAS_ITEM_WEAPON(item_holder,table)({unsigned long long hash; hash = u_hash(1,table, quality_name_modifier[((struct Weapon*)item_holder->item->item_specific_info)->quality]); hash;})
#define U_HAS_ITEM_ARMOR(item_holder,table)({unsigned long long hash; hash = u_hash(1, table,quality_name_modifier[((struct Armor*)item_holder->item->item_specific_info)->quality]); hash;})
#define U_HASH_ITEM_EQUIPPABLE(item_holder,table) item_holder->item->kind == weapon ? U_HAS_ITEM_WEAPON(item_holder,table) : U_HAS_ITEM_ARMOR(item_holder,table)
#define U_HASH_ITEM(item_holder,table) item_holder->item->kind != weapon && item_holder->item->kind != armor ? U_HASH_ITEM_NONEQ(item_holder,table) : U_HASH_ITEM_EQUIPPABLE(item_holder,table)
//Just a highly specialized structure that holds a reference to an item and how much weight there is to be subtracted from the player's
//carry weight and a flag that indicated if we deleted it from inventory 
typedef struct Item_Weight{
  Item *item;
  float weight_loss;
  int deleted;
}Item_Weight;

typedef struct Entry{
  Item_Holder *item_holder;
  struct Entry *next_entry;
}Entry;



typedef struct Entry_Pairs{ // If a lookup with modification is ever needed, we will need parent-child anyways so might as well have functions return exactly that
  Entry *parent;
  Entry *child;
  unsigned long long offset;
}Entry_Pairs;

typedef struct U_Hashtable{
  int size;
  int item_count;
  Entry **entries;
  unsigned long long a;
  unsigned long long b;
  int money;
}U_Hashtable;

unsigned long long u_hash(int char_count,U_Hashtable *table,char *strings, ...);

U_Hashtable *u_initialize_hashtable(int initial_size,Mersienne_Twister *twister);

void u_add_item(Item_Holder *item, int amount,U_Hashtable *table);

Item_Weight u_remove_item(Item_Holder *item, int amount, U_Hashtable *table,int free_item_if_removed);


char *u_readin_char(char *file_path, char *variable);

#define U_GET_ITEMNAME_CONSUMABLE(item)({char *name = NULL; char *bfr = malloc(sizeof(char) * (strlen("/usr/lib/revenant_files/item_files/consumable_files/")) + 5); sprintf(bfr,"/usr/lib/revenant_files/item_files/consumable_files/%d",item->id); name = u_readin_char(bfr,"name"); free(bfr); name;  })
#define U_GET_ITEMNAME_REAGENT(item)({char *name = NULL; char *bfr = malloc(sizeof(char) * (strlen("/usr/lib/revenant_files/item_files/reagent_files/")) + 5); sprintf(bfr,"/usr/lib/revenant_files/item_files/reagent_files/%d",item->id); name = u_readin_char(bfr,"name"); free(bfr); name; })
#define U_GET_ITEMNAME_NONEQUIPPABLE(item)(item->kind == reagent ? (U_GET_ITEMNAME_REAGENT(item)) : (U_GET_ITEMNAME_CONSUMABLE(item)))



//#define U_DECIDE_FILEPATH(item)({char *file_path; item->kind == reagent ? (file_path = malloc(sizeof(char) * strlen("/usr/lib/revenant_files/item_files/reagent_files/") +5); sprintf(file_path,"/usr/lib/revenant_files/item_files/reagent_files/%d",item->id);) :(file_path = malloc(sizeof(char) * strlen("/usr/lib/revenant_files/item_files/reagent_files/") +5); sprintf(file_path,"/usr/lib/revenant_files/item_files/reagent_files/%d",item->id);) file_path;  })

#endif



