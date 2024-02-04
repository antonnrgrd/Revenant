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
#ifndef DB_READER
#define DB_READER
#include <sqlite3.h>
#include "game_state_struct.h"
#include "dialogue.h"
/*Sqlite 3 needs the number of bytes that the sql statement is. If it is negative, it will simply read the passed sql statement until it 
encounters a 0 terminator. We use this macro by defualt to instruct it to do so*/
#define NBYTES -1
typedef struct{
  int next_dialogue_id;
  int consequence;
  int reaction;
}Selected_Dialogue_Info;

Selected_Dialogue_Info dbr_get_dialogue_response(Game_State *gs,Dialogue_Manager *manager, int selected_choice);
#endif
