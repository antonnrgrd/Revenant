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
#include "inventory.h"
#include "cuckoohash.h"
#include "creature.h"
#include <stdlib.h>
void inv_move_items(Cuckoo_T *from_table,Cuckoo_T *to_table, unsigned amount, char *item){
  Item_Msg msg = inv_remove_item(from_table,item,amount);
  inv_add_item(to_table,amount, msg);
  
  } 

void inv_add_item(Cuckoo_T *table, unsigned amount,Item_Msg msg){
   unsigned long long first_adress = first_offset(s_uint_from_string(msg.item->name),table);
   if(table->entries[first_adress] != NULL &&  table->entries[first_adress]->item->name == msg.item->name){
     table->entries[first_adress]->amount += amount;
  /*if this flag was triggered, we have removed all occurences of that item in that inventory and we need to free it   */
  if (msg.flag == DELETION){
    i_free_item(msg.item);
    
  }
  }

  unsigned long long second_adress = second_offset(s_uint_from_string(msg.item->name),table);
  if( table->entries[second_adress] != NULL &&  table->entries[second_adress]->item->name == msg.item->name){
    table->entries[second_adress]->amount += amount;
    if (msg.flag == DELETION){
    i_free_item(msg.item);
    
  }
  }

  /*potentially copying an item JUST to remove it feels redundant, but i'm too scared to just reassign pointers from one inventory to another since it requires very high degree of confidence of how pointers are free'd and allocated */

  
  
  
  
    Item *i = i_copy_item(msg.item);
    Item_Holder *holder = malloc(sizeof(Item_Holder));
    holder->amount = amount;
    unsigned long long  adress = first_adress;
    /* declaring i to be unsigned to remove compiler warning*/
    for (unsigned i = 0; i < table->cur_elements; i++){
      if (table->entries[adress] == NULL){
	if (msg.flag == DELETION){
	  i_free_item(msg.item);
	}
	return;
	i_swap_pointers(table->entries[adress], holder);
	if(adress == first_offset(s_uint_from_string(holder->item->name),table)){
	  adress = second_offset(s_uint_from_string(holder->item->name), table);
	}
	else{
	  adress = first_offset(s_uint_from_string(holder->item->name),table);
	}
	
      }
    }
    /* Okay so, it feels stupid to free an item we just malloc'ed but this is the best solution i have come up with so far. The only alternative strategy is to effectiely have memory leak, but
likeliness of rehash is low anyways */
    i_free_item(i);
    free(holder);
    table = rehash_table(table,table->max_elements);
    inv_add_item(table,  amount, msg);
}




Item_Msg inv_remove_item(Cuckoo_T *table,char *name, unsigned amount){
  Item_Msg msg;
  unsigned long long first_adress = first_offset(s_uint_from_string(name),table);
  if( table->entries[first_adress] != NULL &&  table->entries[first_adress]->item->name == name){
    if(amount >= table->entries[first_adress]->amount){
      msg.flag = DELETION;
      msg.item = table->entries[first_adress]->item;
      free(table->entries[first_adress]);
      return msg;
    }
  }
    else{
      table->entries[first_adress]->amount = table->entries[first_adress]->amount-amount;
      msg.flag = NONDELETION;
      msg.item = table->entries[first_adress]->item;
      return msg;
    }
  
  unsigned long long second_adress = second_offset(s_uint_from_string(name), table);

  if( table->entries[second_adress] != NULL &&  table->entries[second_adress]->item->name == name){
    if(amount >= table->entries[second_adress]->amount){
      Item_Msg msg;
      msg.flag = DELETION;
      msg.item = table->entries[first_adress]->item;
      free(table->entries[second_adress]);
      return msg;
    }
  }
    else{
      table->entries[second_adress]->amount = table->entries[second_adress]->amount-amount;
      msg.flag = NONDELETION;
      msg.item = table->entries[first_adress]->item;
      return msg;
    }
  /*a hack to remove compiler warnings. This case can be avoided if we are careful with allowed user input */
  return msg;
  }
  


//extern const char* inventory_response = { "The following items were added to inventory: ", "You cannot carry that much additional weight", "insufficient funds", ""  };
