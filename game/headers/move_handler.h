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
#define TEST(c,world, x,y, max_x, max_y) REDRAW_MAP(c,world, x,y, max_x, max_y) printf("%s" "done \n");
#define SPAWN_AT(creature,world, x,y) creature->standing_on[0] = mvinch(y,x); mvprintw(c->position.local_y,c->position.local_x, c->representation);  move(c->position.local_y,c->position.local_x); world->tiles[c->position.global_y][c->position.global_y].content[0] = c->representation[0];
#define ASSERT_COORDINATES()
#define LOOP_HEIGHT(world, x,y, max_x, max_y) for(int i = 0; i < max_y  && i+y < world->height;  i++)
#define LOOP_WIDTH(world, x,y, max_x, max_y) for(int j = 0; j < max_x  && j+x < world->width;  j++)
#define REDRAW_MAP(c,world, x,y, max_x, max_y)  LOOP_HEIGHT(world, x,y, max_x, max_y)  LOOP_WIDTH(world, x,y, max_x, max_y) mvprintw(i,j,(world->tiles[(c->position.global_y - (c->position.local_y))+i][(c->position.global_x - (c->position.local_x))+j].content));  mvprintw(c->position.local_y, c->position.local_x, c->representation);
void mv_check_move_handler(int x, int y, Creature *c,Game_World *current_zone);

void (*move_response_handler[2])(int x, int y, Creature *c,Game_World *current_zone);

void redraw_map(Creature *c, Game_World *world, int x, int y, int max_x, int max_y);
void move_response_move_character(int x, int y, Creature *c,Game_World *current_zone);

void move_response_halt_character(int x, int y, Creature *c,Game_World *current_zone);
#endif
