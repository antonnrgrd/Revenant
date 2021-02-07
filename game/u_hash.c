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
#include "u_hash.h"
#include "strings.h"
#include "inventory.h"

unsigned long long u_hash(char *name,U_Hashtable *table){
  return((table->a * s_uint_from_string(name) + table->b) % BFP) % table->size;
}

U_Hashtable *u_initalize_hashtable(int inital_size){
  U_Hashtable *table = malloc(sizeof(U_Hashtable));
  table->size = initial_size;
  table->item_count = 0;
  table->entries = initial_size * malloc(sizeof(Entry *));
  
  return table;
}

void u_add_item(Item_holder *item, int amount,U_Hashtable *table){
  unsigned long long index = u_hash(item->item->name, table);
  /*Item already present in inventory 
Maybe delete item at this point, maybe not since we might not use it after adding to inventory??
*/
  if(table->entries[index] != NULL && table->entries[index]->item_holder->item->name == item->item->name){
    table->entries[index]->item_holder->amount += amount;
  }
  if(table->entries[index] == NULL){
    table->entries[index] = malloc(sizeof(Entry));
    table->entries[index]->item_holder = malloc(sizeof(Item_Holder));
    table->entries[index]->item_holder->amount = amount;
  }
  if(table->entries[index] != NULL && table->entries[index]->item_holder->item->name != item->name){
    Entry *current_entry = table->entries[index]->next_entry;
    while(current_entry->next_entry != NULL){
      if(table->entries[index]->item_holder->item->name == item->name){
	table->entries[index]->item_holder->amount += amount;
	return;
      }
    }
    table->entries[index]->next_entry = malloc(sizeof(Entry));
    table->entries[index]->next_entry->item_holder = malloc(sizeof(Item_Holder));
    table->entries[index]->next_entry->item_holder->item = item;
    table->entries[index]->next_entry->item_holder->amount = amount;
  }
}

Item_Weight u_remove_item(char *name,int amount,U_Hashtable *table){
  unsigned long long index = u_hash(name, table);
  Item_Weight item_weight;
  /* If the item we are looking for is at the top-level, then assert if we are removing all occurences of the items and act correspondingly */
  if(table->entries[index] != NULL && table->entries[index]->item_holder->item->name == name){
    if(amount => table->entries[index]->item_holder->amount){
      item_weight.item = table->entries[index]->item_holder.item;
      item_weight.weight = (amount * item_holder.item->weight);
      item_weight.deleted = DELETED;
      free(table->entries[index]->item_holder);
      Entry *replacement = table->entries[index]->next_entry
      free(table->entries[index]);
      table->entries[index] = replacement;
      return item_weight;
    }
    else{
      table->entries[index]->item_holder->amount -= amount;
      item_weight.item = table->entries[index]->item_holder.item;
      item_weight.weight = (amount * item_holder.item->weight);
      item_weight.deleted = NOT_DELETED;
      return item_weight;
    }
  }
  /*If the item was not found at the top-level, start the search in the chained sequence of items and act accordingly, depending on whether we remove all occurences of said item */
  if(table->entries[index] != NULL && table->entries[index]->item_holder->item->name != name){
    Entry *previous_entry = table->entries[index];
    Entry *current_entry = table->entries[index]->next_entry;
    while(current_entry->next_entry != NULL){
      if(current_entry->item_holder->item->name == item->name){
	if(amount => current_entry->item_holder->amount)
	  item_weight.item = table->entries[index]->item_holder.item;
	  item_weight.weight = (amount * item_holder.item->weight);
	  item_weight.deleted = DELETED;
	  previous_entry->next_entry = current_entry->next_entry;
	  free(current_entry->item_holder);
	  free(current_entry);
	  return item_weight;
       }
      else{
	table->entries[index]->item_holder->amount -= amount;
	item_weight.item = table->entries[index]->item_holder.item;
	item_weight.weight = (amount * item_holder.item->weight);
	item_weight.deleted = NOT_DELETED;
	return item_weight;
       }
      previous_entry = current_entry;
      current_entry = current->next_entry;
      }
    }
  }
/*A safety guard more than anything else, if all else fails, we found no item and we stand to lose no weight */
  item_holder.weight = 0;
  item_holder.item = NULL;
}
