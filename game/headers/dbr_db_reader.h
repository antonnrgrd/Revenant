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
#include "dbr_db_reader_struct.h"

Dbr_Selected_Dialogue_Qresult dbr_get_dialogue_response(Game_State *gs,Dia_Dialogue_Manager *manager, int selected_choice);
Dia_Dialogue_Manager *dbr_readin_dialogue_manager(int np_id);
void dbr_add_dialogue_to_db(int dialogue_folder_id, int current_dialogue_id,int consequence,int num_options);
void dbr_create_db_all_content(Game_State *gs);
void dbr_create_all_tables(Game_State *gs);
void dbr_create_dialogue_tables(Game_State *gs,sqlite3 *db);
int dbr_does_table_exist(char *table,sqlite3 *db);
#define DBR_RESET_QUERY_MANAGER(query_manager){\
  query_manager->current_row_index = 0;	       \
  query_manager->num_rows_encountered = 0;     \
  }
#endif
