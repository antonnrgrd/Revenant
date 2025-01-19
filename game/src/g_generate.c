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

#include "g_generate.h"
#include <ncurses.h>
int gen_int(int min,int max){
  
  return rand() % (max - min + 1) + min;
}

void g_tileset(Rng_Mersienne_Twister *twister){
  int max_y = 0;
  int max_x = 0;
  char *ascii = malloc(sizeof(char));
  getmaxyx(stdscr, max_y,max_x);
  for(int i = 0; i < max_x; i++){
    for(int j = 0; j < max_y; j++){
      char letter = alphabet[RNG_GEN_VALUE_RANGE(0,14+1, twister)];
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
      world->tiles->entry = NULL;
    }
   }
  for(int a = 100; a < 200; a++){
    for(int b = 100; b < 200; b++){
      world->tiles[a][b].content[0] = ' ';
    }
   }
  return world;
  }

extern const char *alphabet = "#          ";

U_Hashtable *g_generate_merchant_inventory(int min_amount, int max_amount, Rng_Mersienne_Twister *twister) {
  int num_items_to_be_generated = RNG_GEN_VALUE_RANGE(min_amount, max_amount+1, twister);
  int current_generated = 0;
  U_Hashtable *merchant = u_initialize_hashtable(10, twister);
  merchant->money = 1000;
  while (current_generated < num_items_to_be_generated){
    I_Item_Holder *item = g_generate_item(twister);
    u_add_item(item, item->amount, merchant);
    current_generated++;
  }
  return merchant;
}

void g_generate_trader(int global_x, int global_y ,Rng_Mersienne_Twister *twister, Game_State *gs){
  U_Hashtable *merchant =  g_generate_merchant_inventory(1,2,twister);
  gs->current_zone->tiles[global_y][global_x].content[0] = 't';
  gs->current_zone->tiles[global_y][global_x].foe = merchant;  
}

I_Item_Holder *g_generate_item(Rng_Mersienne_Twister *twister){
  int item_type = RNG_GEN_VALUE_RANGE(4,5,twister); //D4(twister);
  char *fpath = NULL;
  if(item_type == GENERATE_CONSUMABLE){
    fpath = malloc(sizeof(char) * (strlen("/usr/lib/revenant_files/item_files/consumable_files/")) + 10);
    sprintf(fpath,"/usr/lib/revenant_files/item_files/consumable_files/%d",RNG_GEN_VALUE_RANGE(0, NUM_DEFINED_CONSUMABLES,twister));
    I_Item_Holder *consumable = ir_readin_consumable(fpath,RNG_D_GENERIC(5,15,twister));
    free(fpath);
    return consumable;
  }
  else if(item_type == GENERATE_REAGENT){
    fpath = malloc(sizeof(char) * (strlen("/usr/lib/revenant_files/item_files/reagent_files/")) + 10);
    sprintf(fpath,"/usr/lib/revenant_files/item_files/reagent_files/%d",RNG_GEN_VALUE_RANGE(0,NUM_DEFINED_REAGENTS,twister));
    I_Item *reagent = ir_readin_reagent(fpath,RNG_D_GENERIC(5,15,twister));
    free(fpath);
    return reagent;
  }
  else if(item_type == GENERATE_ARMOR){
    I_Item_Holder *item_holder = malloc(sizeof(I_Item_Holder));
    int valid_materials[] = {12,13,14,15,16};
    int quality = RNG_D8_0(twister);
    I_Item *armor = i_make_armor(quality,valid_materials[RNG_GEN_VALUE_RANGE(0,4,twister)],RNG_GEN_VALUE_RANGE(0,NUM_DEFINED_EQUIPMENT_TYPES,twister));
    item_holder->item = armor;
    item_holder->amount = RNG_D3(twister);
    return item_holder;
  }
  else if(item_type == GENERATE_WEAPON){
    I_Item_Holder *item_holder = malloc(sizeof(I_Item_Holder));
    int valid_materials[] = {12,13,14,15,16};
    int variant = RNG_GEN_VALUE_RANGE(0, 1+1, twister);
    int quality = RNG_D8_0(twister);
    int kind = RNG_D2_0(twister);
    I_Item *w = i_make_mele_weapon(quality, valid_materials[RNG_GEN_VALUE_RANGE(0,4,twister)], variant,kind);
    item_holder->item = w;
    item_holder->item->kind = weapon;
    item_holder->amount = 1;//D3(twister);
    return item_holder;
  }
}

void g_generate_dialogue(int global_x, int global_y,int dialogue_folder_id, int initial_dialogue_id,int npc_id, Game_State *gs){
  Dia_Dialogue_Manager *manager = dia_init_dialogue_manager(dialogue_folder_id, initial_dialogue_id, npc_id,gs);
  gs->current_zone->tiles[global_y][global_x].content[0] = '!';
  gs->current_zone->tiles[global_y][global_x].foe = manager;
}

U_Hashtable *g_generate_merchant_inventory_hardcoded_items(Rng_Mersienne_Twister *twister){
  U_Hashtable *merchant = u_initialize_hashtable(10, twister);
  merchant->money = 1000;
  I_Item_Holder *item_holder_1 = malloc(sizeof(I_Item_Holder));
  I_Item *w_1 = i_make_mele_weapon(epic, runite, one_hand,sword);
  item_holder_1->item = w_1;
  item_holder_1->item->kind = weapon;
  item_holder_1->amount = 1;
  u_add_item(item_holder_1, item_holder_1, merchant);

  I_Item_Holder *item_holder_2 = malloc(sizeof(I_Item_Holder));
  I_Item *w_2 = i_make_mele_weapon(poor, bronze, two_hand,axe);
  item_holder_2->item = w_2;
  item_holder_2->item->kind = weapon;
  item_holder_2->amount = 1;
  u_add_item(item_holder_2, item_holder_2->amount, merchant);

  I_Item_Holder *item_holder_3 = malloc(sizeof(I_Item_Holder));
  I_Item *w_3 = i_make_mele_weapon(adequate, steel, two_hand,mace);
  item_holder_3->item = w_3;
  item_holder_3->item->kind = weapon;
  item_holder_3->amount = 1;
  u_add_item(item_holder_3, item_holder_3->amount, merchant);
  return merchant;
}
