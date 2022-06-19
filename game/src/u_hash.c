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
#include "screen_constants.h"
unsigned long long u_hash(int char_count,U_Hashtable *table, char *strings, ...){
  return((table->a * s_uint_from_string(char_count,strings) + table->b) % BFP) % table->size;
}
 
U_Hashtable *u_initialize_hashtable(int initial_size,Mersienne_Twister *twister){
  U_Hashtable *table = malloc(sizeof(U_Hashtable));
  table->size = initial_size;
  table->item_count = 0;
  table->entries =  malloc(sizeof(Entry *) * initial_size);
  table->equipment_list = malloc(sizeof(Item *) * NUM_EQUIPMENT_SLOTS);
  table->a = GEN_VALUE_RANGE(1,BFP,twister);
  table->b = GEN_VALUE_RANGE(0,BFP,twister);
  return table;
}

void u_add_item(Item_Holder *item, int amount,U_Hashtable *table){
  

  unsigned long long index = U_HASH_ITEM(item,table);
    //Item already present in inventory 
//Maybe delete item at this point, maybe not since we might not use it after adding to inventory??
  
  
  //It's very important that we put parenthesis around the two last conditions because otherwise the logical short circuiting of the first statement won't kick into effect for
  // some reason, thus checking the second condition, potentially accessing a null pointer value, which woud cause a segmentation fault
  //Zero, in the case of strcmp means "True"
  if(table->entries[index] != NULL && (table->entries[index]->item_holder->item->kind == item->item->kind && (HAS_SAME_NAME(table->entries[index]->item_holder, item)) == 0)){
     table->entries[index]->item_holder->amount += amount;    
  }
  else if(table->entries[index] == NULL){
    table->entries[index] = malloc(sizeof(Entry));
     table->entries[index]->item_holder = item;
     table->item_count++;
     //printf("%s", "Second case, \n");
  }
  //   else it must be that table->entries[index] != NULL && (table->entries[index]->item_holder->item->kind == item->item->kind && HAS_SAME_NAME(table->entries[index]->item_holder, item) == 0)  
   else{
     //     printf("%s", "Third case, \n");
    if(table->entries[index]->next_entry == NULL){
      table->entries[index]->next_entry = malloc(sizeof(Entry));
      table->entries[index]->next_entry->item_holder = item;
      table->item_count++;
      return;
      
    }
    
    Entry *current_entry = table->entries[index]->next_entry;
    while(current_entry->next_entry != NULL){
      if(HAS_SAME_NAME(current_entry->item_holder, item) == 0){
	current_entry->item_holder->amount += amount;
	return;
      }
      current_entry = current_entry->next_entry;
    }
    current_entry->next_entry = malloc(sizeof(Entry));
    current_entry->next_entry->item_holder = item;
    table->item_count++;
  }

}


Item_Weight u_remove_item(Item_Holder *item, int amount, U_Hashtable *table, int free_item_if_removed){
  unsigned long long index = U_HASH_ITEM(item,table);
  Item_Weight item_weight;

  // If the item we are looking for is at the top-level, then assert if we are removing all occurences of the items and act correspondingly
  // Unsure why but we have to wrap the HAS_SAME_NAME macro in parenthesis in this case, but not for item insert for it to actually return a value 
  if(table->entries[index] != NULL && (table->entries[index]->item_holder->item->kind == item->item->kind && (HAS_SAME_NAME(table->entries[index]->item_holder, item)) == 0)){
    if(amount >= table->entries[index]->item_holder->amount){
      if(free_item_if_removed == YES){
	i_free_item(table->entries[index]->item_holder->item);
      }
      else{
	item_weight.item = table->entries[index]->item_holder->item;
      }
      item_weight.item = table->entries[index]->item_holder->item;
      item_weight.weight_loss = (table->entries[index]->item_holder->amount * table->entries[index]->item_holder->item->weight);
      item_weight.deleted = DELETED;
      free(table->entries[index]->item_holder);
      Entry *replacement = table->entries[index]->next_entry;
      free(table->entries[index]);
      table->entries[index] = replacement;
      return item_weight;
    }
    else{
      table->entries[index]->item_holder->amount -= amount;
      item_weight.item = table->entries[index]->item_holder->item;
      item_weight.weight_loss = (amount * table->entries[index]->item_holder->item->weight);
      item_weight.deleted = NOT_DELETED;
      return item_weight;
    }
  }

  
  
    
  
  // If the item was not found at the top-level, start the search in the chained sequence of items and act accordingly, depending on whether we remove all occurences of said item 
  if(table->entries[index] != NULL && (table->entries[index]->item_holder->item->kind == item->item->kind && (HAS_SAME_NAME(table->entries[index]->item_holder, item)) == 1)){

    Entry *previous_entry = table->entries[index];
    Entry *current_entry = table->entries[index]->next_entry;
    while(current_entry->next_entry != NULL){
      if(current_entry->item_holder->item->kind == item->item->kind && HAS_SAME_NAME(current_entry->item_holder, item) == 0){
	if(amount >= current_entry->item_holder->amount)
	  if(free_item_if_removed == YES){
	    i_free_item(table->entries[index]->item_holder->item);
	  }
	  else{
	    item_weight.item = table->entries[index]->item_holder->item;
	  }
	  item_weight.item = table->entries[index]->item_holder->item;
	  item_weight.weight_loss = (current_entry->item_holder->amount * current_entry->item_holder->item->weight);
	  item_weight.deleted = DELETED;
	  previous_entry->next_entry = current_entry->next_entry;
	  free(current_entry->item_holder);
	  free(current_entry);
	  return item_weight;
       }
      else{
	table->entries[index]->item_holder->amount -= amount;
	item_weight.item = table->entries[index]->item_holder->item;
	item_weight.weight_loss = (amount * current_entry->item_holder->item->weight);
	item_weight.deleted = NOT_DELETED;
	return item_weight;
       }
      previous_entry = current_entry;
      current_entry = current_entry->next_entry;
      }
    // A safety guard more than anything else, if all else fails, we found no item and we stand to lose no weight 
  item_weight.weight_loss = 0;
  item_weight.item = NULL;
  return item_weight;
  }
}
  








