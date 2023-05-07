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


#include <panel.h>
#include "gameinfo.h"
#include "linked_list.h"
#include "screen_constants.h"
#include "rng.h"

#define NUM_EVENTS 10
#define MAX_MSG_LENGTH 100
// To avoid using magic numbers, we opt to use macros that represent the indices of the of the panels, e.g index 1 is designated to be the
//event log and so is represented by the macro EVENT_LOG. Panels are an extension of ncurses that basically simplifies the handling of multiple concurrent windows that overlap each other, which are stored in arrays
 
#define MAIN_SCREEN 0
#define EVENT_LOG 1
#define INVENTORY_LOG 2
#define PLAYER_STATUS_LOG 3
#define QUEST_LOG 4
#define TRADING_LOG 5
#define NOTIFICATION_LOG 6
#define NUM_WINDOWS 7

#define CONTEXT_MAIN MAIN_SCREEN
#define CONTEXT_LOG EVENT_LOG
#define CONTEXT_INVENTORY INVENTORY_LOG
#define CONTEXT_PLAYER_STATUS 3
#define CONTEXT_QUEST 4
#define CONTEXT_TRADING 5
#define CONTEXT_NOTIFICATION 6
#define NUM_WINDOWS 7


#define CONTEXT_SELLING 0
#define CONTEXT_INSPECTING 1
//
#define LOG_WIDTH 15
#define LOG_Height 15
//The main struct that will encapsulate all information about the game currently present 
typedef struct Game_State{
  char *current_event;
  char **ingame_log;
  char action_context;
  int notification_log_offset;
  int num_rows;
  int num_cols;
  int found_rows;
  int found_cols;
  int notification_log_height_size;
  int notification_log_width_size;
  struct Creature *player;
  Game_World *current_zone;
  Linked_List *active_creatures;
  PANEL *panels[7];
  WINDOW *logs[7];
  Mersienne_Twister *twister;
}Game_State;


#endif
