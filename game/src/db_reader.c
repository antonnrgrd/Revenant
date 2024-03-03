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
#include "db_reader.h"
/*
Programmers note here, when binding variables, to SQL statements, The leftmost SQL parameter has an index of 1 whereas 
when running a query,  the leftmost column of the result set has the index 0
*/
Selected_Dialogue_Qresult dbr_get_dialogue_response(Game_State *gs,Dialogue_Manager *manager, int selected_choice){
  Selected_Dialogue_Info selected_dialogue_info;
  sqlite3_stmt* stmt;
  char *err_msg = 0;
  strcpy(gs->bfr,"SELECT next_dialogue_id, choice_consequence FROM dialogue_option_reponses \n\
         WHERE npc_id = ? AND current_dialogue_id = ? AND selected_dialogue_id = ?;");
  int result_statement = sqlite3_prepare_v2(gs->db,gs->bfr, NBYTES, &stmt, NULL);
  sqlite3_bind_int(stmt, DIALOGUE_OPTION_RESPONSES_NPC_ID_INDEX_QUERY, manager->npc_id);
  sqlite3_bind_int(stmt, DIALOGUE_OPTION_RESPONSES_CURENT_DIALOGUE_ID_INDEX_QUERY, manager->current_dialogue_id);
  sqlite3_bind_int(stmt, DIALOGUE_OPTION_RESPONSES_SELECTED_DIALOGUE_ID_INDEX_QUERY, selected_choice);

  int result = sqlite3_step(stmt);
  if(result != SQLITE_ROW){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    sprintf("%s - when running dbr_get_dialogue_response. Expected %d, got %d ", asctime (timeinfo), SQLITE_ROW, result );
    err_append_err(gs->bfr);
    sqlite3_finalize(stmt);
    exit(1);
  }
  selected_dialogue_info.next_dialogue_id = sqlite3_column_int(stmt, NEXT_DIALOGUE_ID_INDEX_QRESULT);
  selected_dialogue_info.selected_dialogue_consequence = sqlite3_column_int(stmt, SELECTED_DIALOGUE_CONSEQUENCE_INDEX_QRESULT);
  selected_dialogue_info.next_dialogue_screen_num_options = sqlite3_column_int(stmt, NEXT_DIALOGUE_SCREEN_NUM_OPTIONS_INDEX_QRESULT);
  sqlite3_finalize(stmt);
  return selected_dialogue_info;
}

Dialogue_Manager *dbr_readin_dialogue_manager(int np_id){
  Dialogue_Manager *manager = malloc(sizeof(Dialogue_Manager));
}

