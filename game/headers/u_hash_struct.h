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

#ifndef UHASH_STRUCT
#define UHASH_STRUCT
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>
#include "rng_rng.h"
#include "strings.h"
#include "i_item.h"
#define U_BFP 18446744073709551615ULL //an enormous prime (by 64-bit standards)
#define U_BFP_2 10089886811898868001ULL
#define U_NOT_DELETED 0
#define U_DELETED 1
#define U_NOT_ONE
#define U_ONE

//Just a highly specialized structure that holds a reference to an item and how much weight there is to be subtracted from the player's
//carry weight and a flag that indicated if we deleted it from inventory 
typedef struct{
  I_Item_Holder *item_h;
  float weight_loss;
  int deleted;
}U_Item_Weight;

typedef struct U_Entry{
  I_Item_Holder *item_holder;
  struct U_Entry *next_entry;
}U_Entry;



typedef struct{ // If a lookup with modification is ever needed, we will need parent-child anyways so might as well have functions return exactly that
  U_Entry *parent;
  U_Entry *child;
  unsigned long long offset;
}U_Entry_Pairs;

typedef struct U_Hashtable{
  int size;
  int item_count;
  U_Entry **entries;
  unsigned long long a;
  unsigned long long b;
  int money;
}U_Hashtable;


#endif



