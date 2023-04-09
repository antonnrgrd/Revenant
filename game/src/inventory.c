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

Item_Holder *inv_equip_item(Item_Holder *target_item_holder,Player_Info *player_info, Creature *player){
  Item_Weight item_removal = u_remove_item(target_item_holder,1,player_info->inventory);
  if(item_removal.item_h == NULL){
    return;
  }
  Item *retrieved_item = item_removal.item_h->item;
  
  Item *tmp = NULL;
  if(retrieved_item->kind == weapon){
    tmp = player_info->equipment_list[((struct Weapon *)retrieved_item->item_specific_info)->slot];  
    player_info->equipment_list[((struct Weapon *)retrieved_item->item_specific_info)->slot] = retrieved_item;

  }
  if(retrieved_item->kind == armor){
    tmp = player_info->equipment_list[((struct Armor *)retrieved_item->item_specific_info)->slot];
    player_info->equipment_list[((struct Armor *)retrieved_item->item_specific_info)->slot] = retrieved_item;
  }
  if(tmp != NULL){
    Item_Holder *added_item = malloc(sizeof(Item_Holder));
    added_item->item = tmp;
    added_item->amount=1;
    inv_add_item(added_item,player_info->inventory,player);
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

