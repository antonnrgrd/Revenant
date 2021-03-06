/*This file is part of Revnant.
Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */

#ifndef TILES
#define TILES
#include <time.h>
#include "creature.h"
#include "placeholder.h"
extern int numerical_responses[255];
/*36 previously */



typedef struct Level{
  char **tiles;
  unsigned room_count;
  struct Room **rooms;
 struct  Creature **creatures;
  unsigned monster_count;
  unsigned level;
} Level;

typedef struct Room{
  Position position;
  unsigned height;
  unsigned width;
  Position **doors;
  //Creature **monsters;
  //Item **loot;
}Room;

Room **tiles_dungeon_generate(unsigned dungeon_size);
Room *tiles_generate_room(unsigned x, unsigned y, unsigned height, unsigned width);
void tiles_fill_room(Room *room);
void tiles_connect_rooms(Position *door_one, Position *door_two);
char **tiles_save_positions();
Level *tiles_generate_level(unsigned lvl);
#endif
