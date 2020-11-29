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

#ifndef INVENTORY
#define INVENTORY
#define DELETION 0
#define NONDELETION 1
#include "u_hash.h"
#include "creature.h"
#include "cuckoohash.h"


typedef struct Item_Msg{ //a struct for an item and how many of that item currently is in the inventory
  Item *item;
  unsigned flag;
}Item_Msg;


extern const char* inventory_response[];

void inv_move_items(Cuckoo_T *from_table,Cuckoo_T *to_table, unsigned amount, char *item);

void inv_add_item(Cuckoo_T *table, unsigned amount, Item_Msg msg);

Item_Msg inv_remove_item(Cuckoo_T *table,char *name, unsigned amount);

void inv_equip_item(Item *i);

void inv_equip_item_from_inv(char *name);

Cuckoo_T *reshash(Cuckoo_T *table);

#endif
