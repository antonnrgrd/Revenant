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
#include "dbr_db_reader.h"
#include "l_log.h"
/*
Programmers note here, when binding variables, to SQL statements, The leftmost SQL parameter has an index of 1 whereas 
when running a query,  the leftmost column of the result set has the index 0
*/
/*
Dbr_Selected_Dialogue_Qresult dbr_get_dialogue_response(Game_State *gs,Dia_Dialogue_Manager *manager, int selected_choice){
  Dbr_Selected_Dialogue_Qresult selected_dialogue_info;
  sqlite3_stmt* stmt;
  char *err_msg = 0;
  strcpy(gs->bfr,"SELECT next_dialogue_id, choice_consequence FROM dialogue_option_reponses \n\
         WHERE npc_id = ? AND current_dialogue_id = ? AND selected_dialogue_id = ?;");
  int result_statement = sqlite3_prepare_v2(gs->db,gs->bfr, NBYTES, &stmt, NULL);
  sqlite3_bind_int(stmt, DBR_DIALOGUE_OPTION_RESPONSES_NPC_ID_INDEX_QUERY, manager->npc_id);
  sqlite3_bind_int(stmt, DBR_DIALOGUE_OPTION_RESPONSES_CURENT_DIALOGUE_ID_INDEX_QUERY, manager->current_dialogue_id);
  sqlite3_bind_int(stmt, DBR_DIALOGUE_OPTION_RESPONSES_SELECTED_DIALOGUE_ID_INDEX_QUERY, selected_choice);

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
  selected_dialogue_info.next_dialogue_id = sqlite3_column_int(stmt, DBR_NEXT_DIALOGUE_ID_INDEX_QRESULT);
  selected_dialogue_info.selected_dialogue_consequence = sqlite3_column_int(stmt, DBR_SELECTED_DIALOGUE_CONSEQUENCE_INDEX_QRESULT);
  selected_dialogue_info.next_dialogue_screen_num_options = sqlite3_column_int(stmt, DBR_NEXT_DIALOGUE_SCREEN_NUM_OPTIONS_INDEX_QRESULT);
  sqlite3_finalize(stmt);
  return selected_dialogue_info;
}
*/
Dia_Dialogue_Manager *dbr_readin_dialogue_manager(int np_id){
  Dia_Dialogue_Manager *manager = malloc(sizeof(Dia_Dialogue_Manager));
}

void dbr_create_db_all_content(Game_State *gs){
  sqlite3 *db;
  int success = sqlite3_open(DBR_DATABASE_PATH, &db);
  if(success != YES){
    sqlite3_close(db);
    sprintf(gs->bfr, "Couldn\'t open the database for database creation");
    l_write_log(gs->bfr, L_ERR,NO);
  }
}

void dbr_create_dialogue_tables(Game_State *gs,sqlite3 *db){
  int create_table_statement = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS dialogue_interactions(dialogue_folder_id int,current_dialogue_id int, selected_option int, consequence int, num_dialogue_options int,  PRIMARY KEY () );", NULL,NULL, &gs->query_manager->sqlite_bfr);
  if(create_table_statement != SQLITE_OK){
    l_write_log(gs->query_manager->sqlite_bfr, L_WARN,L_LOG_VERBOSELY);
    // A bit tacky, but the alternative would be have two seperate buffers to maintain
    sprintf(gs->bfr, "An error occured in the dbr_create_dialogue_tables function when attempting to create the table dialogue_interactions, receiving the error code %d. See the message above for hints as to what went wrong",create_table_statement);
    l_write_log(gs->bfr, L_ERR,L_LOG_SILENTLY);
  }
  int add_row_statement;
  add_row_statement = sqlite3_exec(db,"INSERT INTO dialogue_interactions() ",NULL,NULL,&gs->query_manager->sqlite_bfr);
  
}

void dbr_print_rows(Game_State *gs, char *query){
  int select_table_statement = sqlite3_exec(gs->db, query, dbr_print_rows_from_query,NULL,&gs->query_manager->sqlite_bfr);
  if(select_table_statement != SQLITE_OK){
    sprintf(gs->bfr, "An error occured when running the debug query %s - See the message preceeding this message for a hint as to what went wrong", query);
    l_write_log(gs->bfr, L_ERR,L_LOG_SILENTLY);
  }
}

int dbr_print_rows_from_query(void *data, int argc, char **argv, char **colNames){
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", colNames[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}
void dbr_close_db_connection(sqlite3 *db){
  int result = sqlite3_close(db);
  /* If the result is not ok, the most likely error is a an unfinished backup, unfinalized prepared sql statement or
   unclosed BLOB handle. We won't be running backups, won't be using BLOBS and we use the sqlite3 wrapper for sql statements so this should ideally not be possible */
  if (result != SQLITE_OK){
    /*Log WARNING level only as call to function could stem from hard error and we wan't to avoid recursion loops.*/
    l_write_log("Couldn\'t close the db connection as it had a hanging database operation. See preceeding messages for hints as to what it could be",L_WARN,L_LOG_VERBOSELY);
  }
  else{
    db = NULL;
  }
}
