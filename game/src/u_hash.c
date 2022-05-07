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

unsigned long long u_hash(int char_count,U_Hashtable *table, char *strings, ...){
  return((table->a * s_uint_from_string(char_count,strings) + table->b) % BFP) % table->size;
}

U_Hashtable *u_initialize_hashtable(int initial_size,Mersienne_Twister *twister){
  U_Hashtable *table = malloc(sizeof(U_Hashtable));
  table->size = initial_size;
  table->item_count = 0;
  table->entries =  malloc(sizeof(Entry *) * initial_size);

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
  if(table->entries[index] != NULL && (table->entries[index]->item_holder->item->kind == item->item->kind && HAS_SAME_NAME(table->entries[index]->item_holder, item) == 0)){
     table->entries[index]->item_holder->amount += amount;
     printf("%s", "First case, \n");
     
    
  }
  else if(table->entries[index] == NULL){
    table->entries[index] = malloc(sizeof(Entry));
     table->entries[index]->item_holder = item;
     printf("%s", "Second case, \n");
  }
  //   else it must be that table->entries[index] != NULL && (table->entries[index]->item_holder->item->kind == item->item->kind && HAS_SAME_NAME(table->entries[index]->item_holder, item) == 0)  
   else{
     printf("%s", "Third case, \n");
    if(table->entries[index]->next_entry == NULL){
      table->entries[index]->next_entry = malloc(sizeof(Entry));
      table->entries[index]->next_entry->item_holder = item;
      return;
      
    }
    
    Entry *current_entry = table->entries[index]->next_entry;
    while(current_entry->next_entry != NULL){
      if(HAS_SAME_NAME(current_entry->item_holder, item) == 1){
	current_entry->item_holder->amount += amount;
	return;
      }
      current_entry = current_entry->next_entry;
    }
    current_entry->next_entry = malloc(sizeof(Entry));
    current_entry->next_entry->item_holder = item;
  }

}

Item_Weight u_remove_item(int argcount,int amount,U_Hashtable *table, char *item_name){
  unsigned long long index = u_hash(amount, table,item_name);
  Item_Weight item_weight;
  // If the item we are looking for is at the top-level, then assert if we are removing all occurences of the items and act correspondingly 
  if(table->entries[index] != NULL && i_derive_item_name[table->entries[index]->item_holder->item->kind]  == item_name){
    if(amount >= table->entries[index]->item_holder->amount){
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
  if(table->entries[index] != NULL && i_derive_item_name[table->entries[index]->item_holder->item->kind] != item_name){
    Entry *previous_entry = table->entries[index];
    Entry *current_entry = table->entries[index]->next_entry;
    while(current_entry->next_entry != NULL){
      if((current_entry->item_holder->item) == item_name){
	if(amount >= current_entry->item_holder->amount)
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
  
 

void u_print_inventory(U_Hashtable *inventory){ /*
  for(int i = 0; i < 7; i++){
    if(inventory->entries[i] != NULL){
      printf("%s%d%s", "Item found at index: ", i, "\n");
     Entry  *current_entry = inventory->entries[i];
      while(current_entry != NULL){
	printf("%s%s%s%d%s", "The item is: ", current_entry->item_holder->item->name, " Of which you have in amount: ",current_entry->item_holder->amount ,  "\n");
	current_entry = current_entry->next_entry;
      }
    }
    } */
}






