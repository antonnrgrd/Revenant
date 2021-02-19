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
#define BFP 18446744073709551615ULL //an enormous prime (by 64-bit standards)
#define BFP_2 10089886811898868001ULL
#define NOT_DELETED 0
#define DELETED 1
#define NOT_ONE
#define ONE
#define GET_AVAILABLE(amount, available){amount>available? available:amount }
/*Just a highly specialized structure that holds a reference to an item and how much weight there is to be subtracted from the player's
carry weight and a flag that indicated if we deleted it from inventory */
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
}U_Hashtable;

unsigned long long u_hash(char *name,U_Hashtable *table);

unsigned long long generate_value(unsigned long long min, unsigned long long max);

U_Hashtable *u_initalize_hashtable(int initial_size);

void u_add_item(Item_Holder *item, int amount,U_Hashtable *table);

Item_Weight u_remove_item(char *name,int amount,U_Hashtable *table);

void u_print_inventory(U_Hashtable *inventory);
#endif
