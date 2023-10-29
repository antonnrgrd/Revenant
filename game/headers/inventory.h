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


#ifndef INVENTORY
#define SUCCESS_ADDITION 0
#define WEIGHT_LIMIT_EXCEEDED 1
#define BUY 0
#define SELL 1 
#include "u_hash.h"
#include "creature.h"


Item_Holder *inv_equip_item(Item_Holder *target_item_holder,Player_Info *player_info, Creature *player);
void inv_remove_item(int argcount,char *name, int amount, U_Hashtable *inventory, Creature *player);
int inv_add_item(Item_Holder *item_h, U_Hashtable *inventory, Creature *player);
void inv_exchange_item(Item_Holder *item_h, U_Hashtable *merchant_inventory, Creature *player, int num);
#endif

