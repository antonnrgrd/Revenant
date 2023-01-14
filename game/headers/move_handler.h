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


#ifndef MOVE_HANDLER
#define MOVE_HANDLER
#include <ncurses.h>
#include "gameinfo.h"
#include "creature.h"
#include "item.h"
#include "inventory.h"
#include "screen_constants.h"
#include "ingame_msg.h"
#include "game_state_struct.h"
#include "generic_macros.h"
#include "information_reader.h"
//#define MV_PRINT_DMG(creature) char *fpath = malloc(sizeof(char) * strlen() ) free(fpath);
#define TEST(c,world, x,y, max_x, max_y) REDRAW_MAP(c,world, x,y, max_x, max_y) printf("%s" "done \n");
#define ADD_TO_PILE(global_x,global_y, item, game_world) Entry *new_entry = malloc(sizeof(Entry)); new_entry->item_holder = item; new_entry->next_entry = game_world->tiles[global_y][global_x].entry; game_world->tiles[global_y][global_x].entry = new_entry;
#define SPAWN_AT(creature,world, x,y)  mvprintw(c->position.local_y,c->position.local_x, c->representation);  move(c->position.local_y,c->position.local_x);  c->position.local_x = x; c->position.local_y = y; c->position.global_x = 42; c->position.global_y = y; 

#define LOOP_HEIGHT(height, x,y, max_x, max_y) for(int i = 0; i < DEFAULT_MAX_Y  && i+y < height;  i++)
#define LOOP_WIDTH(width, x,y, max_x, max_y) for(int j = DEFAULT_MAX_INFOBAR_WIDTH; j < DEFAULT_MAX_X  && j+x < width;  j++)
#define REDRAW_MAP(c,current_zone,draw_screen, x,y, max_x, max_y)  LOOP_HEIGHT(current_zone->height, x,y, max_x, max_y)  LOOP_WIDTH(current_zone->width, x,y, max_x, max_y) mvwprintw(draw_screen,i,j,(current_zone->tiles[(c->position.global_y - (c->position.local_y))+i][(c->position.global_x - (c->position.local_x))+j].content));  mvwprintw(draw_screen,c->position.local_y, c->position.local_x, c->representation); c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0]; current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];


#define GET_NEXT_IN_PILE(game_world,x,y) (game_world->tiles[y][x]->entry->next_entry == NULL)? game_world->tiles[y][x]->content[0] = game_world->tiles[y][x]->entry->item_holder->item->standing_on[0]; replacement = game_world->tiles[y][x]->entry->next_entry; free(game_world->tiles[y][x]->entry); : game_world->tiles[y][x]->content[0] = game_world->tiles[y][x]->entry->next_entry->item_holder->item->standing_on[0]; replacement = game_world->tiles[y][x]->entry->next_entry; free(game_world->tiles[y][x]->entry);

#define SPAWN_ITEM(game_world,item_holder,x,y) item_holder->item->standing_on[0] = game_world->tiles[y][x].content[0]; game_world->tiles[y][x].content[0] = item_holder->item->representation[0];   ADD_TO_PILE(x,y, item_holder, game_world); 
#define DROP_ITEM(game_world,item_holder,x,y,c) item_holder->item->representation[0] = game_world->tiles[y][x]->content[0]; game_world->tiles[y][x]->content[0] =  item_holder->item->representation[0]; mvprintw(c->position.global_y-c->position.local_y,c->position.global_x-c->position.local_x, item_holder->item->representation); ADD_TO_PILE(global_x,global_y, item_holder, game_world);



void gw_add_to_pile(Item_Holder *item, Entry *item_pile);

int mv_check_move_handler(int global_x, int gloval_y, int local_x, int local_y, Creature *c,Game_State *game_state);

extern int (*move_response_handler[5])(int global_x, int global_y, int local_x, int local_y,Creature *c,Game_State *game_state);


int move_response_move_character(int global_x, int global_y, int local_x, int local_y,Creature *c,Game_State *game_state);

int move_response_halt_character(int global_x, int global_y,int local_x, int local_y, Creature *c,Game_State *game_state);

int move_response_loot_item(int global_x, int global_y,int local_x, int local_y, Creature *c,Game_State *game_state);

int move_response_attack_target(int global_x, int global_y,int local_x, int local_y, Creature *c,Game_State *game_state);

int move_response_initiate_trade(int global_x, int global_y,int local_x, int local_y, Creature *c,Game_State *game_state);

#endif

