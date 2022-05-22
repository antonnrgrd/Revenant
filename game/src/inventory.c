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
#include "creature.h"
#include "u_hash.h"
#include <stdlib.h>

void inv_equip_item(Item_holder *target_item,U_Hashtable *inventory){
  Item *previously_equipped ;
  if(target_item->item->kind == weapon){
    tmp = inventory->equipment_list[((struct Weapon *)source_item_holder->item->item_specific_info)->worn_in];
    inventory->equipment_list[((struct Weapon *)source_item_holder->item->item_specific_info)->worn_in] = target_item->item;
    free(target_item);
      
  }
  if(target_item->item->kind == armor){
    tmp = inventory->equipment_list[((struct Armor *)source_item_holder->item->item_specific_info)->worn_in];
    inventory->equipment_list[((struct Armor *)source_item_holder->item->item_specific_info)->worn_in] = target_item->item;
    free(target_item);
  }
  
}



int inv_add_item(Item_Holder *item_h, U_Hashtable *inventory, Creature *player){
  
  if((player->current_carry + (item_h->amount * item_h->item->weight)) > player->max_carry ){
    return WEIGHT_LIMIT_EXCEEDED;
  }
  
  
  else{
    u_add_item(item_h, item_h->amount, inventory);
    player->current_carry += (item_h->amount * item_h->item->weight);
    return SUCCESS_ADDITION;
  }
}

/*
void inv_remove_item(int argcount,char *name, int amount, U_Hashtable *inventory, Creature *player){
  Item_Weight removed_weight = u_remove_item(argcount,amount,inventory,name);
  player->current_carry -= removed_weight.weight_loss;
}

*/
