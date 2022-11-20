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


#ifndef GENERATE
#define GENERATE
#include <ncurses.h>
#include "gameinfo.h"
#include "rng.h"
extern const char *alphabet;

Game_World *g_generate_game_world(int width, int height);

U_Hastable *g_generate_merchant_inventory(int min_amount, int max_amount, Mersienne_Twister *twister){
  int num_items_to_be_generated = GEN_VALUE_RANGE(min_amount, max_amount+1);
  int current_generated = 0;
  /*This is admittedly a guess at how big the buffer will need to be to hold any possible filepath*/
  char *bfr = malloc(sizeof(char) * 100);
  
}

void g_generate_merchant();
#endif

