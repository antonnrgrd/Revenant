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
  // printf(" on add index is: %llu ",index);
    //Item already present in inventory 
//Maybe delete item at this point, maybe not since we might not use it after adding to inventory??
     
  //It's very important that we put parenthesis around the two last conditions because otherwise the logical short circuiting of the first statement won't kick into effect for
  // some reason, thus checking the second condition, potentially accessing a null pointer value, which woud cause a segmentation fault
  //Zero, in the case of strcmp means "True"

  
  if(table->entries[index] != NULL && (table->entries[index]->item_holder->item->kind == item->item->kind && (HAS_SAME_NAME_TRIVIAL(table->entries[index]->item_holder, item)) == 0)){
    I_FREE_ITEM_HOLDER(item);
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
	I_FREE_ITEM_HOLDER(item);
	current_entry->item_holder->amount += amount;
	return;
      }
      current_entry = current_entry->next_entry;
    }
    current_entry->next_entry = malloc(sizeof(Entry));
    current_entry->next_entry->item_holder = item;
    current_entry->next_entry->next_entry = NULL;
    //printf("called a item count incr");
    table->item_count++;
  }
}


Item_Weight u_remove_item(Item_Holder *item, int amount, U_Hashtable *table){
  unsigned long long index = U_HASH_ITEM(item,table);
  
  Entry *previous_entry = table->entries[index];
  Entry *current_entry = table->entries[index]->next_entry;
  Item_Weight item_weight;
  // If the item we are looking for is at the top-level, then assert if we are removing all occurences of the items and act correspondingly
  // Unsure why but we have to wrap the HAS_SAME_NAME_TRIVIAL macro in parenthesis in this case, but not for item insert for it to actually return a value
  if(table->entries[index] != NULL && (table->entries[index]->item_holder->item->kind == item->item->kind  && (HAS_SAME_NAME_TRIVIAL(table->entries[index]->item_holder, item)) == 0)){
    I_COPY_ITEM_HOLDER(item_weight.item_h,table->entries[index]->item_holder,1);
    item_weight.weight_loss = (table->entries[index]->item_holder->amount * table->entries[index]->item_holder->item->weight); 
  if(amount >= table->entries[index]->item_holder->amount){
    //error lies somewhere here - it's the free item holder for some reason
    // it is because perhaps we oveeride the set of null by replacing it with the next entry
    item_weight.deleted = DELETED;
    Entry *replacement = table->entries[index]->next_entry;
    /*We opt to defer the actual freeing of the item holder to the function call that called the u_remove_item function because attempting to free it in this function and then setting it to null had unxpected results in that even though it was set to null inside of u_remove_item, the pointer would come out as not null in later checks in the function that called u_remove_item. It is an unfortunate dvision of code logic, but no more clever solution could be found, other than setting the amount to 0, which behaved as expected*/
    table->entries[index]->item_holder->amount = 0;
    free(table->entries[index]);
    table->entries[index] = replacement;
    table->item_count--;
  }
    else{
      table->entries[index]->item_holder->amount -= amount;
      item_weight.weight_loss = (amount * table->entries[index]->item_holder->item->weight);
      item_weight.deleted = NOT_DELETED;
    }
     return item_weight;
  }

  
  
    
  
  // If the item was not found at the top-level, start the search in the chained sequence of items and act accordingly, depending on whether we remove all occurences of said item
  //strcmp returns 0 iff the strings are equal, otherwise it returns a nonzero value, so we have to check if the return value is nonzero to see if we have to go through the Entry
  //chain
  
    //    int i = HAS_SAME_NAME_TRIVIAL(table->entries[index]->item_holder, item);
    //    printf("%s%d", " second case of removal", i);
    //    printf("%s",material_name_modifier[((struct Weapon *)table->entries[index]->item_holder->item->item_specific_info)->material]);
    
    //Edge case of when the immedediately next entry was the item we were looking for
      else if(current_entry->item_holder->item->kind == item->item->kind && (HAS_SAME_NAME_TRIVIAL(current_entry->item_holder, item)) == 0){
      I_COPY_ITEM_HOLDER(item_weight.item_h,current_entry->item_holder,1);
      item_weight.weight_loss = (table->entries[index]->item_holder->amount * table->entries[index]->item_holder->item->weight); 
       if(amount >= current_entry->item_holder->amount){
	 previous_entry->next_entry = current_entry->next_entry;
	 item_weight.deleted = DELETED;
	 current_entry->item_holder->amount = 0;
	 free(current_entry);
	 table->item_count--;
	
      }
      else{   
      item_weight.weight_loss = (current_entry->item_holder->amount * current_entry->item_holder->item->weight);
      item_weight.deleted = NOT_DELETED;
      current_entry->item_holder->amount -= amount;
      }
       return item_weight;
    }
  
    else{
    while(current_entry != NULL){
      //printf("material of weapon: %d,",((Weapon *)current_entry->item_holder->item->item_specific_info)->material);
      //  printf("%s", " checking ");
      if(current_entry->item_holder->item->kind == item->item->kind && (HAS_SAME_NAME_TRIVIAL(current_entry->item_holder, item)) == 0){	
	I_COPY_ITEM_HOLDER(item_weight.item_h,current_entry->item_holder,1);
	item_weight.weight_loss = (table->entries[index]->item_holder->amount * table->entries[index]->item_holder->item->weight); 
	if(amount >= current_entry->item_holder->amount){
	 previous_entry->next_entry = current_entry->next_entry;
	 item_weight.deleted = DELETED;
	 current_entry->item_holder->amount = 0;
	 free(current_entry);
	 current_entry = NULL;
	 table->item_count--;
	}
	else{
	//printf("fell though here 2");
	table->entries[index]->item_holder->amount -= amount;
	item_weight.weight_loss = (amount * current_entry->item_holder->item->weight);
	item_weight.deleted = NOT_DELETED;
	
	}
	return item_weight;
      }
      previous_entry = current_entry;
      current_entry = current_entry->next_entry;
     }
    }

  //printf("fell though here 3");
    // A safety guard more than anything else, if all else fails, we found no item and we stand to lose no weight 
  item_weight.weight_loss = 0;
  item_weight.item_h = NULL;
  return item_weight;
  
}
  




/*
char *faku(){
  char *val = malloc(sizeof(char));
  return val;
}
*/




