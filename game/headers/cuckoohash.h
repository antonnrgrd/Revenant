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
#ifndef CUCKOO_HASH
#define CUCKOO_HASH
#define ZERO 0
#define NONZERO 0
#include "u_hash.h"
typedef struct Cuckoo_Hash_Table{
  unsigned long long first_a;
  unsigned long long first_b;
  unsigned long long second_a;
  unsigned long long second_b;
  unsigned cur_elements;
  unsigned max_elements;
  Item_Holder **entries;
}Cuckoo_T;


typedef struct C_Entry{
  unsigned long long key;
  void *value;
}C_entry;


unsigned generate_value(unsigned long long min, unsigned long long max);

void insert_item(Item_Holder *item,Cuckoo_T *table);

void remove_item(char *name, unsigned amount);

unsigned long long first_offset(unsigned long long key, Cuckoo_T *table );

unsigned long long second_offset(unsigned long long key, Cuckoo_T *table );

Cuckoo_T *generate_table(unsigned size);

Cuckoo_T *rehash_table(Cuckoo_T *table,unsigned size);

void c_insert_item(Cuckoo_T *table, Item_Holder *i);
#endif
