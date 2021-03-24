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
#include "u_hash.h"
#include "creature.h"



void inv_access_inv();


int inv_add_item(Item_Holder *item_h, U_Hashtable *inventory, Creature *player);

#endif
