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
/*Sqlite 3 needs the number of bytes that the sql statement is. If it is negative, it will simply read the passed sql statement until it 
encounters a 0 terminator. We use this macro by defualt to instruct it to do so*/
#define NBYTES -1
/*
Programmers note here, when binding variables, to SQL statements, The leftmost SQL parameter has an index of 1 whereas 
when running a query,  the leftmost column of the result set has the index 0, hence the inconsistent assignment of values here.
If it has the name format *_QUERY, it is intended to be used in a query (1-indexed) but if it is has the name format
*_QRESULT, it intended to be used to extract the value from the query (0-indexed)
*/
#define DIALOGUE_OPTION_RESPONSES_NPC_ID_INDEX_QUERY 1
#define DIALOGUE_OPTION_RESPONSES_CURENT_DIALOGUE_ID_INDEX_QUERY 2
#define DIALOGUE_OPTION_RESPONSES_SELECTED_DIALOGUE_ID_INDEX_QUERY 3

#define NEXT_DIALOGUE_ID_INDEX_QRESULT 3
#define SELECTED_DIALOGUE_CONSEQUENCE_INDEX_QRESULT 4
#define NEXT_DIALOGUE_SCREEN_NUM_OPTIONS_INDEX_QRESULT 5

/*npc id's*/
#define GENERIC_ISSLOG_MALE_NPC 0

typedef struct{
  int next_dialogue_id;
  int selected_dialogue_consequence;
  int next_dialogue_screen_num_options;
}Selected_Dialogue_Qresult;

Selected_Dialogue_Qresult dbr_get_dialogue_response(Game_State *gs,Dialogue_Manager *manager, int selected_choice);
Dialogue_Manager *dbr_readin_dialogue_manager(int np_id);
#endif
