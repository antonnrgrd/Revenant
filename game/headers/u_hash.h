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
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>
#include "item.h"
#define BFP 18446744073709551615ULL //an enormous prime (by 64-bit standards)
#define BFP_2 10089886811898868001ULL


typedef struct Entry{
  unsigned long long key;
  void *value;
  struct Entry *next_entry;
}Entry;

typedef struct U_Hashtable{
  int size;
  Entry **entries;
  unsigned long long a;
  unsigned long long b;
}U_Hashtable;

typedef struct Entry_Pairs{ // If a lookup with modification is ever needed, we will need parent-child anyways so might as well have functions return exactly that
  Entry *parent;
  Entry *child;
  unsigned long long offset;
}Entry_Pairs;

Entry_Pairs uh_find_entry_pairs(U_Hashtable *hashtable,char *name);

Entry *uh_create_entry_item();

void uh_free_entry(unsigned long long key);

U_Hashtable *uh_init_table(int size);

void uh_destroy_table_simple(U_Hashtable *hashtable);

Entry *uh_lookup(U_Hashtable *hashtable,unsigned long long key);

int uh_rand_num(int range);

int uh_rand_num_z(int range);

void uh_force_insert(Entry *entry, int index, U_Hashtable *hashtable);

void uh_print(U_Hashtable *hashtable);

void uh_add_int_entry(unsigned long long key, int value, U_Hashtable *hashtable);

void uh_add_string_entry(int key, char *value, U_Hashtable *hashtable);

void uh_add_float_entry(int key, float value , U_Hashtable *hashtable);

Entry *uh_create_entry_item(Item *i, unsigned long long key);


void uh_add_item_entry(Item *i, U_Hashtable *hashtable);

Entry *uh_lookup_item(U_Hashtable *hashtable,char *name);

Entry *uh_create_entry(unsigned long long key);

void *uh_destroy_entry(U_Hashtable *hashtable,unsigned long long key);

Entry *uh_create_entry_item_holder(Item *i, unsigned long long amount);
#endif
