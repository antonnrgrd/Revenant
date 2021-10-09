/*This file is part of Revenant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar.  If not, see <https://www.gnu.org/licenses/>. */

#include "tiles.h"
#include "creature.h"
#include <ncurses.h>
#include <stdlib.h>
/*A giant jumptable. The basic idea is that when the player makes a move in a direction, the response should be based on the tiles kind. they way this hsould be handled is that we check the character at a location. The character has a decimal representation. That deciaml representation will represent an index in this lookup table. The returned value will then act as yet antoher offset to an array of functions that handle said behavior. It is 256 rather than 255 in size as the the extended ascii table has 255 characters in total  */    /*        ignore whatever is in here                             */
int numerical_responses[256] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,50,/* <- 50th element */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,100/* <- 100 element */,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,150/* <- 150 character */ ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 ,200, /* <- 200th char */0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,250/* <- 250th character */,0,0,0,0};

Room *tiles_generate_room(unsigned x, unsigned y, unsigned height, unsigned width){
  Room *room = malloc(sizeof(Room));
  room->position.global_x =x;
  room->position.global_y =y;
  room->height = height;
  room->width = width;
  room->doors = malloc(sizeof(Position *) * 4);
  for(int i = 0; i < 4; i++){
    room->doors[i] = malloc(sizeof(Position));
  }
  /* top door */
  room->doors[0]->global_x = rand() % (room->width - 2 ) + room->position.global_x + 1;
  room->doors[0]->global_y = room->position.global_y;

  /* left door */
  room->doors[1]->global_y = rand() % (room->height - 2) + room->position.global_y +1 ;
  room->doors[1]->global_x = room->position.global_x;

  /* bottom door */
  room->doors[2]->global_x = rand() % (room->width - 2 ) + room->position.global_x + 1;
  room->doors[2]->global_y = room->position.global_y + room->height - 1;

  /* rightt door */
  room->doors[3]->global_y = rand() % (room->height - 2) + room->position.global_y +1;
  room->doors[3]->global_x = room->position.global_x +room->width -1 ;
  return room;
}
 
Room **tiles_dungeon_generate(unsigned dungeon_size){
  Room **rooms = malloc(sizeof(Room *) * dungeon_size);
  /* for(unsigned i = 0; i< dungeon_size; i++){
    rooms[i] = tiles_generate_room(10,10, 20, 20);
    } */
  rooms[0] = tiles_generate_room(13,13, 6, 8);
  rooms[1] = tiles_generate_room(40,2, 6, 8);
  rooms[2] = tiles_generate_room(40,10, 6, 12);
  for(unsigned j = 0; j <dungeon_size; j++ ){
    tiles_fill_room(rooms[j]);
  }
  tiles_connect_rooms(rooms[0]->doors[3] ,rooms[2]->doors[1]);
  tiles_connect_rooms(rooms[1]->doors[2] ,rooms[0]->doors[0]); 
    return rooms;
    
}

void tiles_fill_room(Room *room){
  for(unsigned i = room->position.global_x; i < room->position.global_x+room->width; i++){
    mvprintw(room->position.global_y, i, "#"); /* draws top of room*/
    mvprintw(room->position.global_y + room->height -1 , i, "#"); /* draws bottom of room */
  }
  for (unsigned j = room->position.global_y +1; j < room->position.global_y+room->height - 1; j++){
    mvprintw(j, room->position.global_x, "#");
    mvprintw(j, room->position.global_x + room->width -1 , "#");
  }
  /* draw doors */

  mvprintw(room->doors[0]->global_y, room->doors[0]->global_x, "+");
  mvprintw(room->doors[1]->global_y, room->doors[1]->global_x, "+");
  mvprintw(room->doors[2]->global_y, room->doors[2]->global_x, "+");
  mvprintw(room->doors[3]->global_y, room->doors[3]->global_x, "+");
}

void tiles_connect_rooms(Position *door_one, Position *door_two){
  Position tmp;
  Position previous;
  int count = 0;
  tmp.global_x = door_one->global_x;
  tmp.global_y = door_one->global_y;
  previous = tmp;
  while(1){
    /* step left, does taking this step move us any closer to the other door and is this space unoccupied?*/
    if((abs((tmp.global_x -1) - door_two->global_x) < abs(tmp.global_x - door_two->global_x)) && (mvinch(tmp.global_y, tmp.global_x -1 ) == ' ')){
      // mvprintw(tmp.y, tmp.x -1, "#");
      previous.global_x = tmp.global_x;
      tmp.global_x = tmp.global_x -1;
    }

    /* step right, does taking this step move us any closer to the other door and is this space unoccupied?*/
    else if((abs((tmp.global_x + 1) - door_two->global_x) < abs(tmp.global_x - door_two->global_x)) && (mvinch(tmp.global_y, tmp.global_x + 1 ) == ' ')){
      // mvprintw(tmp.y, tmp.global_x + 1, "#");
      previous.global_x = tmp.global_x;
      tmp.global_x = tmp.global_x +1;
    }
    /*step down */
    else if((abs((tmp.global_y + 1) - door_two->global_y) < abs(tmp.global_y - door_two->global_y)) && (mvinch(tmp.global_y +1, tmp.global_x  ) == ' ')){
      // mvprintw(tmp.y + 1, tmp.global_x , "#");
      previous.global_y = tmp.global_y;
      tmp.global_y = tmp.global_y +1;
    }
  

   /*step up */
    else if((abs((tmp.global_y - 1) - door_two->global_y) < abs(tmp.global_y - door_two->global_y)) && (mvinch(tmp.global_y -1, tmp.global_x  ) == ' ')){
      // mvprintw(tmp.y - 1, tmp.global_x , "#");
      previous.global_y = tmp.global_y;
      tmp.global_y = tmp.global_y -1;
    }
    else{
      if (count == 0){
	tmp = previous;
	count++;
	continue;
      }
      else{
      return;
      }
    }
    mvprintw(tmp.global_y, tmp.global_x, ";");
    //    getch();
  }
 }

char **tiles_save_positions(){
  char **positions = malloc(sizeof(char *) * 25);
  for(unsigned y = 0; y < 25; y++){
    positions[y] = malloc(sizeof(char) * 100);
    for(unsigned x = 0; x < 100; x++){
      positions[y][x] = mvinch(y,x);
    }
  }
  return positions;
}

Level *tiles_generate_level(unsigned lvl){
  Level * level = malloc(sizeof(Level));
  level->level = lvl;
  level->room_count = 3;
  level->rooms = tiles_dungeon_generate(3);
  level-> tiles = NULL;
  return level;
}
