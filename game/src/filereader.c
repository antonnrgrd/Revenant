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
#include "filereader.h"
#include "item.h"
Item *fr_readin_reagent(char *reagent_file_path){
  struct Item *i = malloc(sizeof(Item));
  Reagent *reagent = malloc(sizeof(Reagent));
  //printf("%d", sizeof(Reagent));
  reagent->id = ir_readin_int(reagent_file_path,"id");
  i->weight = ir_readin_float(reagent_file_path,"weight");
  i->item_specific_info = reagent;
  i->id = reagent->id;
  return i;
}

Item *fr_readin_consumable(char *consumable_file_path){
  struct Item *i = malloc(sizeof(Item));
  Consumable *consumable = malloc(sizeof(Consumable));
  consumable->id = ir_readin_int(consumable_file_path,"id");
  i->weight = ir_readin_float(consumable_file_path,"weight");
  i->item_specific_info = consumable;
  i->id = consumable->id;
  return i;
}
