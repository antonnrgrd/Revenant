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

Item_Holder *inv_equip_item(Item_Holder *target_item_holder,U_Hashtable *inventory, Creature *player){

  Item_Weight item_removal = u_remove_item(target_item_holder,1,inventory, NO);
  Item *tmp;
  if(target_item_holder->item->kind == weapon){
    tmp = inventory->equipment_list[((struct Weapon *)target_item_holder->item->item_specific_info)->slot];  
    inventory->equipment_list[((struct Weapon *)target_item_holder->item->item_specific_info)->slot] = target_item_holder->item;
  }
  if(target_item_holder->item->kind == armor){
    tmp = inventory->equipment_list[((struct Armor *)target_item_holder->item->item_specific_info)->slot];
    inventory->equipment_list[((struct Armor *)target_item_holder->item->item_specific_info)->slot] = target_item_holder->item;
  }

  if(tmp != NULL){
  Item_Holder *added_item = malloc(sizeof(Item_Holder));
  added_item->item = tmp;
  added_item->amount=1;
  inv_add_item(added_item,inventory,player);
  return added_item;
  }

  return NULL;
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
