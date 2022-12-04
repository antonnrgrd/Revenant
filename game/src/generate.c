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

#include "generate.h"
#include <ncurses.h>
#include "filereader.h"
extern inline void g_place_trader(){

}

int gen_int(int min,int max){
  
  return rand() % (max - min + 1) + min;
}

void g_tileset(Mersienne_Twister *twister){
  int max_y = 0;
  int max_x = 0;
  char *ascii = malloc(sizeof(char));
  getmaxyx(stdscr, max_y,max_x);
  for(int i = 0; i < max_x; i++){
    for(int j = 0; j < max_y; j++){
      char letter = alphabet[GEN_VALUE_RANGE(0,14+1, twister)];
      ascii[0] = letter;
      init_pair(1,COLOR_CYAN,COLOR_BLACK);
      attron(COLOR_PAIR(1));
	mvprintw(i,j, ascii);

    }
  }
  refresh();
  //  getch();
  free(ascii);
}

Game_World *g_generate_game_world(int width, int height){
  Game_World *world = malloc(sizeof(Game_World));
  world->width = width;
  world->height = height;
  getmaxyx(stdscr, world->max_y,world->max_x);
  world->tiles = malloc(height * sizeof(Tile *));
  for(int i = 0; i < width; i++){
    world->tiles[i]= malloc( width * sizeof(Tile));
  }
  for(int j = 0; j < height; j++){
    for(int k = 0; k < width; k++){
      world->tiles[j][k].content = malloc(sizeof(char));
      world->tiles[j][k].content[0] = alphabet[gen_int(0,10)];
    }
   }
  for(int a = 100; a < 200; a++){
    for(int b = 100; b < 200; b++){
      world->tiles[a][b].content[0] = ' ';
    }
   }
  return world;
  }


Item_Holder *g_generate_item(Mersienne_Twister *twister){
  Item_Holder *item_holder = malloc(sizeof(Item_Holder));
  int item_type = GEN_VALUE_RANGE(1,5,twister); //D4(twister);
  char *fpath = NULL;
  if(item_type == GENERATE_CONSUMABLE){
    fpath = malloc(sizeof(char) * (strlen("/usr/lib/revenant_files/item_files/consumable_files/")) + 10);
    sprintf(fpath,"/usr/lib/revenant_files/item_files/consumable_files/%d",GEN_VALUE_RANGE(0, NUM_DEFINED_CONSUMABLES,twister));
    item_holder->item = fr_readin_consumable(fpath);
    item_holder->amount = D_GENERIC(5,15,twister);
  }
  else if(item_type == GENERATE_REAGENT){
    fpath = malloc(sizeof(char) * (strlen("/usr/lib/revenant_files/item_files/reagent_files/")) + 10);
    sprintf(fpath,"/usr/lib/revenant_files/item_files/reagent_files/%d",GEN_VALUE_RANGE(0,NUM_DEFINED_REAGENTS,twister));
    Item *reagent = fr_readin_reagent(fpath);
    item_holder->item = reagent;
    item_holder->amount = D_GENERIC(5,15,twister);
  }
  else if(item_type == GENERATE_ARMOR){
    int valid_materials[] = {12,13,14,15,16};
    int quality = D8_0(twister);
    Item *armor = i_make_armor(quality,valid_materials[GEN_VALUE_RANGE(0,4,twister)],GEN_VALUE_RANGE(0,NUM_DEFINED_EQUIPMENT_TYPES,twister));
    item_holder->item = armor;
    item_holder->amount = D3(twister);
  }
  else if(item_type == GENERATE_WEAPON){
    int valid_materials[] = {12,13,14,15,16};
    int variant = GEN_VALUE_RANGE(0, 1+1, twister);
    int quality = D8_0(twister);
    int kind = D2_0(twister);
    Item *weapon = i_make_mele_weapon(quality, valid_materials[GEN_VALUE_RANGE(0,4,twister)], variant,kind);
    item_holder->item = weapon;
    item_holder->amount = D3(twister);
  }
  if(fpath){
     free(fpath);
  }
  return item_holder;
}

extern const char *alphabet = "#          ";

U_Hashtable *g_generate_merchant_inventory(int min_amount, int max_amount, Mersienne_Twister *twister) {
  int num_items_to_be_generated = GEN_VALUE_RANGE(min_amount, max_amount+1, twister);
  int current_generated = 0;
  U_Hashtable *merchant = u_initialize_hashtable(10, twister);
  while (current_generated < num_items_to_be_generated){
    Item_Holder *item = g_generate_item(twister);
    u_add_item(item, item->amount, merchant);
    current_generated++;
    //printf("amount generated %d \n",current_generated);
  }
  return merchant;
}
