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




extern const char *alphabet = "#          ";

