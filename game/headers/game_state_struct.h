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
/*The main struct that will encapsulate all information about the game currently present */
typedef struct Game_State{
  Creature *player;
  Game_World *current_zone;
  Linked_List *active_creatures;
  PANEL *logs[1];
}Game_State;
#endif
