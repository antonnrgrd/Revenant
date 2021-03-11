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
#include "tiles.h"
#include "creature.h"
#include "item.h"
#include "tiles.h"
#include "inventory.h"
/*These are the dimensions that our computer screen should AT LEAST have. If it does not possess these, something is quite fishy */
#define DEFAULT_MAX_Y 24
#define DEFAULT_MAX_X 80
#define DEFAULT_MAX_INFOBAR_WIDTH 13
#define TEST(c,world, x,y, max_x, max_y) REDRAW_MAP(c,world, x,y, max_x, max_y) printf("%s" "done \n");
#define SPAWN_AT(creature,world, x,y) /*creature->standing_on[0] = mvinch(y,x);*/ mvprintw(c->position.local_y,c->position.local_x, c->representation);  move(c->position.local_y,c->position.local_x); /* world->tiles[c->position.global_y][c->position.global_y].content[0] = c->representation[0] */ c->position.local_x = x; c->position.local_y = y; c->position.global_x = 42; c->position.global_y = y; 
#define ASSERT_COORDINATES()
#define LOOP_HEIGHT(world, x,y, max_x, max_y) for(int i = 1; i < DEFAULT_MAX_Y  && i+y < world->height;  i++)
#define LOOP_WIDTH(world, x,y, max_x, max_y) for(int j = DEFAULT_MAX_INFOBAR_WIDTH; j < DEFAULT_MAX_X  && j+x < world->width;  j++)
#define REDRAW_MAP(c,world, x,y, max_x, max_y)  LOOP_HEIGHT(world, x,y, max_x, max_y)  LOOP_WIDTH(world, x,y, max_x, max_y) mvprintw(i,j,(world->tiles[(c->position.global_y - (c->position.local_y))+i][(c->position.global_x - (c->position.local_x))+j].content));  mvprintw(c->position.local_y, c->position.local_x, c->representation);


#define GET_NEXT_IN_PILE(game_world,x,y) (game_world->tiles[y][x]->entry->next_entry == NULL)? game_world->tiles[y][x]->content[0] = game_world->tiles[y][x]->entry->item_holder->item->standing_on[0]; replacement = game_world->tiles[y][x]->entry->next_entry; free(game_world->tiles[y][x]->entry); : game_world->tiles[y][x]->content[0] = game_world->tiles[y][x]->entry->next_entry->item_holder->item->standing_on[0]; replacement = game_world->tiles[y][x]->entry->next_entry; free(game_world->tiles[y][x]->entry);

#define SPAWN_ITEM(game_world,item_holder,x,y) item_holder->item->representation[0] = game_world->tiles[y][x]->content[0]; game_world->tiles[y][x]->content[0] =  item_holder->item->representation[0]; gw_add_to_pile(item_holder,game_world->tiles[y][x]->entry);
#define DROP_ITEM(game_world,item_holder,x,y,c) item_holder->item->representation[0] = game_world->tiles[y][x]->content[0]; game_world->tiles[y][x]->content[0] =  item_holder->item->representation[0]; mvprintw(c->position.global_y-c->position.local_y,c->position.global_x-c->position.local_x, item_holder->item->representation); gw_add_to_pile(item_holder,game_world->tiles[y][x]->entry);



void gw_add_to_pile(Item_Holder *item, Entry *item_pile);

void mv_check_move_handler(int global_x, int gloval_y, int local_x, int local_y, Creature *c,Game_World *current_zone);

void (*move_response_handler[2])(int global_x, int global_y, int local_x, int local_y,Creature *c,Game_World *current_zone);


void move_response_move_character(int global_x, int global_y, int local_x, int local_y,Creature *c,Game_World *current_zone);

void move_response_halt_character(int global_x, int global_y,int local_x, int local_y, Creature *c,Game_World *current_zone);

void move_response_loot_item(int global_x, int global_y,int local_x, int local_y, Creature *c,Game_World *current_zone);
#endif
