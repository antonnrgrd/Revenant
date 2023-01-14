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
  for(int i = 0; i < initial_size; i++){
    table->entries[i] = NULL;
  }
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

  
  if(table->entries[index] != NULL && (table->entries[index]->item_holder->item->kind == item->item->kind && (HAS_SAME_NAME_TRIVIAL(table->entries[index]->item_holder, item)) == 0)){
     table->entries[index]->item_holder->amount += amount;    
  }

  else if(table->entries[index] == NULL){
     table->entries[index] = malloc(sizeof(Entry));
     table->entries[index]->item_holder = item;
     table->entries[index]->next_entry = NULL;
     table->item_count++;
     //printf("%s", "Second case, \n");
  }
  //   else it must be that table->entries[index] != NULL && (table->entries[index]->item_holder->item->kind == item->item->kind && HAS_SAME_NAME_TRIVIAL(table->entries[index]->item_holder, item) == 0)  
   else{
     //      printf("%s", "Third case of u_add_item ");
    if(table->entries[index]->next_entry == NULL){
      //printf("%s", " and next entry is null ");
      table->entries[index]->next_entry = malloc(sizeof(Entry));
      table->entries[index]->next_entry->item_holder = item;
      table->entries[index]->next_entry->next_entry = NULL;
      table->item_count++;
      return;
      
    }
     
    Entry *current_entry = table->entries[index]->next_entry;
    while(current_entry->next_entry != NULL){
      if((HAS_SAME_NAME_TRIVIAL(current_entry->item_holder, item)) == 0){
	current_entry->item_holder->amount += amount;
	return;
      }
      current_entry = current_entry->next_entry;
    }
    current_entry->next_entry = malloc(sizeof(Entry));
    current_entry->next_entry->item_holder = item;
    current_entry->next_entry->next_entry = NULL;
    table->item_count++;
  }
}


Item_Weight u_remove_item(Item_Holder *item, int amount, U_Hashtable *table, int free_item_if_removed){
  unsigned long long index = U_HASH_ITEM(item,table);
  // if(((struct Weapon *)item->item->item_specific_info)->material == bronze){
  //printf("%s%llu", " " , index);
  //}
  Item_Weight item_weight;
  // If the item we are looking for is at the top-level, then assert if we are removing all occurences of the items and act correspondingly
  // Unsure why but we have to wrap the HAS_SAME_NAME_TRIVIAL macro in parenthesis in this case, but not for item insert for it to actually return a value 
  if(table->entries[index] != NULL && (table->entries[index]->item_holder->item->kind == item->item->kind  && (HAS_SAME_NAME_TRIVIAL(table->entries[index]->item_holder, item)) == 0)){
    //    printf("%s", " first case ");
    if(amount >= table->entries[index]->item_holder->amount){
      if(free_item_if_removed == YES){
	i_free_item(table->entries[index]->item_holder->item);
	free(table->entries[index]->item_holder);
	free(table->entries[index]);
	table->entries[index] = NULL;
      }
      else{   
      item_weight.item = table->entries[index]->item_holder->item;
      item_weight.weight_loss = (table->entries[index]->item_holder->amount * table->entries[index]->item_holder->item->weight);
      item_weight.deleted = DELETED;
      Entry *tmp = table->entries[index];      
      Entry *replacement = table->entries[index]->next_entry;
      table->entries[index] = replacement;
      free(tmp);
      return item_weight;
      }
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
  //strcmp returns 0 iff the strings are equal, otherwise it returns a nonzero value, so we have to check if the return value is nonzero to see if we have to go through the Entry
  //chain
  else if(table->entries[index] != NULL && (table->entries[index]->item_holder->item->kind == item->item->kind && (HAS_SAME_NAME_TRIVIAL(table->entries[index]->item_holder, item)) != 0)){
    //    int i = HAS_SAME_NAME_TRIVIAL(table->entries[index]->item_holder, item);
    //    printf("%s%d", " second case of removal", i);
    //    printf("%s",material_name_modifier[((struct Weapon *)table->entries[index]->item_holder->item->item_specific_info)->material]);
    Entry *previous_entry = table->entries[index];
    Entry *current_entry = table->entries[index]->next_entry;
    //Edge case of when the immedediately next entry was the item we were looking for
    if(current_entry->item_holder->item->kind == item->item->kind && (HAS_SAME_NAME_TRIVIAL(current_entry->item_holder, item)) == 0){
       if(amount >= current_entry->item_holder->amount){
      if(free_item_if_removed == YES){
	i_free_item(current_entry->item_holder->item);
	free(current_entry->item_holder);
	free(current_entry);
      }
      else{   
      item_weight.item = current_entry->item_holder->item;
      item_weight.weight_loss = (current_entry->item_holder->amount * current_entry->item_holder->item->weight);
      item_weight.deleted = DELETED;
      Entry *replacement = current_entry->next_entry;
      previous_entry->next_entry = replacement;
      return item_weight;
      }
    }
    else{
      current_entry->item_holder->amount -= amount;
      item_weight.item = current_entry->item_holder->item;
      item_weight.weight_loss = (amount * current_entry->item_holder->item->weight);
      item_weight.deleted = NOT_DELETED;
      return item_weight;
     }
    }
    else{
    while(current_entry->next_entry != NULL){
      //  printf("%s", " checking ");
      if(current_entry->item_holder->item->kind == item->item->kind && (HAS_SAME_NAME_TRIVIAL(current_entry->item_holder, item)) == 0){
	//	printf("%s", " found item to remove ");
	if(amount >= current_entry->item_holder->amount){	  
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
      }
      previous_entry = current_entry;
      current_entry = current_entry->next_entry;
      }
    }
  
  }
    // A safety guard more than anything else, if all else fails, we found no item and we stand to lose no weight 
  item_weight.weight_loss = 0;
  item_weight.item = NULL;
  return item_weight;
}
  




/*
char *faku(){
  char *val = malloc(sizeof(char));
  return val;
}
*/



char *faku(){
  char *val = "abc";
  return val;
}
