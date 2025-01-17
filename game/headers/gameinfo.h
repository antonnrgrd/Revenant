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


#ifndef PLACEHOLDER
#define PLACEHOLDER
#include "u_hash.h"
#include "ll_linked_list.h"

typedef struct Position{
  // Each creature will have two coordinate types, local and global. Global indicates where they are globally on the map, local
  // refers to where they are on the screen
  int global_x;
  int global_y;
  int local_x;
  int local_y;
}Position;

typedef struct Tile{
  /*Unsigned as it should guarantees [0, 255] range, removing the compiler warning about potentially using negative indexes because
   normals chars could potentially be negative.
   TODO: As it is a single char, maybe just have it be one char instead of a pointer? eg unsigned char content instead?
*/
  unsigned char *content;
  U_Entry *entry;
  //Instead of specifying that the tile can contain a creature struct, we use a void pointer instead because otherwise I would have to
  // re-structure the organization of the header files due to how certain structs are defined in certain header files 
  void *foe;
}Tile;


typedef struct Game_World{
  int width;
  int height;
  struct Tile **tiles;
  // Not exactly sure how expensive getmaxyx calls are, but at they very least, storing the values in max_x,max_y helps us avoid spamming
  //calls over and over 
  int max_x;
  int max_y;
}Game_World;

extern int numerical_responses[256];

#define GAMEINFO_PLACE_TRADER(trader, global_x,global_y, gamle_world) gs->current_zone->tiles[global_y][global_x].foe = trader; gs->current_zone->tiles[global_y][global_x].content[0] = 't';

void gm_free_game_wolrd(Game_World *current_zone);
void gm_free_tile(Tile *tile);
#endif


