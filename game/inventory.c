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
#include <stdlib.h>

int inv_add_item(Item_Holder *item, U_Hashtable *inventory, Creature *player){
  if((player->current_carry + (item->amount * item->item->weight)) > player->max_carry ){
    return WEIGHT_LIMIT_EXCEEDED;
  }
  else{
    u_add_item(item, item->amount, inventory);
    player->current_carry += (item->amount * item->item->weight);
    return SUCCESS_ADDITION;
  }
}

void inv_remove_item(char *name, int amount, U_Hashtable *inventory, *Creature player){
  removed_weight = u_remove_item()
  player->current_carry -= removed_weight;
}
