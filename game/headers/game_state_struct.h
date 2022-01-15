/*This file is part of Revenant.
Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
Revenant  is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */


#ifndef GAME_STATE_STRUCT
#define GAME_STATE_STRUCT

#include "creature.h"
#include <panel.h>
#include "gameinfo.h"
#include "linked_list.h"
#include "screen_constants.h"
// To avoid using magic numbers, we opt to use macros that represent the indices of the of the panels, e.g index 1 is designated to be the
//event log and so is represented by the macro EVENT_LOG. Panels are an extension of ncurses that basically simplifies the handling of multiple concurrent windows that overlap each other, which are stored in arrays
 

#define EVENT_LOG 0
#define PLAYER_STATUS_LOG 1
#define INVENTORY_LOG 2
#define QUEST_LOG 3
#define NUM_WINDOWS 4
//
#define LOG_WIDTH 15
#define LOG_Height 15
//The main struct that will encapsulate all information about the game currently present 
typedef struct Game_State{
  Creature *player;
  Game_World *current_zone;
  Linked_List *active_creatures;
  PANEL *panels[1];
  WINDOW *logs[1];
}Game_State;


#endif

