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
#include "dialogue.h"
#include "u_hash.h"
#include "creature.h"
#include "u_hash.h"
#include <stdlib.h>
#include <stdint.h>
#include <ncurses.h>
#include <curses.h>
#include "inventory.h" 
#include "item.h"
#include "strings.h"
#include "gameinfo.h"
#include "modifier.h"
#include "generate.h"
#include "game_state.h"
#include "gameinfo.h"
#include <time.h>
#include "creature_behavior.h"
#include "state_manager.h"
#include "ingame_msg.h"
#include "game_state_struct.h"
#include "rng.h"
#include "information_reader.h"
int main(int argc, char *argv[]){
  /*   
Item *weapon = i_make_mele_weapon(epic,bronze,one_hand,sword);
 Item *weapon_2 = i_make_mele_weapon(epic,steel,one_hand,sword); 
 Item *armor = i_make_armor(poor,mithril,helmet);
 Item *armor_2 = i_make_armor(adequate,steel,boots);
 Item_Holder *i = malloc(sizeof(Item_Holder));
 i->item = weapon;
 i->amount = 1;
  Item_Holder *j = malloc(sizeof(Item_Holder));
  j->item = weapon_2;
 j->amount = 5;
 Item_Holder *k = malloc(sizeof(Item_Holder));
 Item_Holder *l = malloc(sizeof(Item_Holder));
 l->item = armor;
 l->amount = 1;
 k->amount=1;
 k->item = armor;
  Item_Holder *m = malloc(sizeof(Item_Holder));
  m->item = armor_2;
 m->amount=1;
 Item_Holder *reagent = ir_readin_reagent("/usr/lib/revenant_files/item_files/reagent_files/1", 2);
 Item_Holder *food = ir_readin_consumable("/usr/lib/revenant_files/item_files/consumable_files/0", 4); 
  u_add_item(reagent,reagent->amount,((Player_Info * )gs->player->additional_info)->inventory);
  u_add_item(food,food->amount,((Player_Info * )gs->player->additional_info)->inventory);

 u_add_item(j,j->amount,((Player_Info * )gs->player->additional_info)->inventory);
 u_add_item(i,i->amount,((Player_Info * )gs->player->additional_info)->inventory);
  u_add_item(k,k->amount,((Player_Info *)gs->player->additional_info)->inventory);
   u_add_item(l,l->amount,((Player_Info * )gs->player->additional_info)->inventory);
   u_add_item(m,m->amount,((Player_Info * )gs->player->additional_info)->inventory);
  */  
  initscr();
 start_color();   
   Game_World *game_world = g_generate_game_world(1000,1000);
  Game_State *gs =  gs_create_game_state(game_world);   
  ((Player_Info *)gs->player->additional_info)->inventory = g_generate_merchant_inventory(3,3,gs->twister);  
  noecho();
  
  curs_set(FALSE);
   keypad(stdscr, TRUE);
    srand(time(NULL));
  raw();  
  game_loop(gs);
  endwin();
  
}
  
 
 
