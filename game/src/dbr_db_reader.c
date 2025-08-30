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
#include <stdlib.h>
#include "dia_dialogue_struct.h"
/*
Programmers note here, when binding variables, to SQL statements, The leftmost SQL parameter has an index of 1 whereas 
when running a query,  the leftmost column of the result set has the index 0
*/

extern const char *dbr_map_trigger_type_to_trigger_table[]= {"dia_trigger_set_initial_dialogue"};

Dbr_Selected_Dialogue_Qresult dbr_get_dialogue_response(Game_State *gs,Dia_Dialogue_Manager *manager, int selected_choice){
  Dbr_Selected_Dialogue_Qresult qresult;
  sqlite3_exec(gs->db, gs->bfr, dbr_print_rows_from_query,NULL,&gs->query_manager->sqlite_bfr);
}

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

void dbr_execute_statement(char *statement, char *log_level ,sqlite3 *db, Game_State *gs){
  int statement_return_value = sqlite3_exec(gs->db, statement, dbr_print_rows_from_query,NULL,&gs->query_manager->sqlite_bfr);
  if(statement_return_value != SQLITE_OK){
    sprintf(gs->bfr, "An error occured when attempting to execute the statement %s, caused by the issue: %s, resulting in the errorcode %d", statement,gs->query_manager->sqlite_bfr, statement_return_value);
    /*We parameterize the log level because in some instances, we are interested in seeing any and all errors in the logs and in other cases, we want to give up immediately
     because in that case, the database is most likely in an inconsistent state*/
    l_write_log(gs->bfr, log_level,L_LOG_SILENTLY);
  }
}

int dbr_pass_inf_to_dialogue_qresult(void *passed_struct, int num_cols, char **column_value, char **column_name){
  Dia_Dialogue_Manager *manager = (Dia_Dialogue_Manager *)passed_struct;
  manager->current_dialogue_id = atoi(column_value[4]);
  manager->num_dialogue_options = atoi(column_value[2]);
  return 0;
}

int dbr_get_next_dialogue_id(void *game_state, int num_cols, char **column_value, char **column_name){
  Game_State *gs = (Game_State *)game_state;
  int next_dialogue_id_decision = atoi(column_value[3]);
  /*Next dialogue id has no checks to decide it, trivially
   set the next dialogue id to be the dialogue id in the "successful check" column*/
  if(next_dialogue_id_decision == DBR_CONTINUE_DIALOGUE){
    gs->dialogue_manager->current_dialogue_id = atoi(column_value[4]);
    sprintf(gs->bfr, "SELECT * FROM dia_dialogue_option_triggers WHERE dialogue_folder_id = %d AND current_dialogue_id = %d AND selected_option = %d AND on_outcome=%d;",atoi(column_value[0]),atoi(column_value[1]), atoi(column_value[2]),DBR_CHECK_SUCCESS);
       int query_code = sqlite3_exec(gs->db, gs->bfr, dbr_apply_triggers, gs, &gs->query_manager->sqlite_bfr);
       DBR_EVAL_SQL_EXECUTION(query_code,gs->bfr,gs);
  }
  /*If the next dialogue has its */
  else if(next_dialogue_id_decision == DBR_END_DIALOGUE){
    gs->dialogue_manager->current_dialogue_id = DBR_UNDEF;
  }
  /* Otherwise, assume some kind of conditional check is required to decide next dialogue id. Maybe implement  */
  else if (next_dialogue_id_decision >= DBR_CHECK_NPC_HAS_SKILL && next_dialogue_id_decision <= DBR_CHECK_NPC_HAS_ITEM){
    /*Logic for check here */
    if (gs->query_manager->check_status == DBR_CHECK_SUCCESS){
       gs->dialogue_manager->current_dialogue_id = atoi(column_value[4]);
       sprintf(gs->bfr, "SELECT * FROM dia_dialogue_option_triggers WHERE dialogue_folder_id = %d AND current_dialogue_id = %d AND selected_option = %d AND on_outcome=%d;",DBR_CHECK_SUCCESS);
       int query_code = sqlite3_exec(gs->db, gs->bfr, dbr_apply_triggers, gs, &gs->query_manager->sqlite_bfr);
       DBR_EVAL_SQL_EXECUTION(query_code,gs->bfr,gs);
    }
    else if (gs->query_manager->check_status == DBR_CHECK_FAILURE){
      gs->dialogue_manager->current_dialogue_id = atoi(column_value[5]);
      sprintf(gs->bfr, "SELECT * FROM dia_dialogue_option_triggers WHERE dialogue_folder_id = %d AND current_dialogue_id = %d AND selected_option = %d AND on_outcome=%d;",DBR_CHECK_FAILURE);
       int query_code = sqlite3_exec(gs->db, gs->bfr, dbr_apply_triggers, gs, &gs->query_manager->sqlite_bfr);
       DBR_EVAL_SQL_EXECUTION(query_code,gs->bfr,gs);
    }
    else{
      ;
    }
  }
  return 1;
}
int dbr_get_num_dialogue_options(void *game_state, int num_cols, char **column_value, char **column_name){
  Game_State *gs = (Game_State *)game_state;
  gs->dialogue_manager->num_dialogue_options = column_value[0];
}

int dbr_apply_triggers(void *game_state, int num_cols, char **column_value, char **column_name){
  Game_State *gs = (Game_State *)game_state;
  int trigger_type = atoi(column_value[4]);
  char *trigger_table =dbr_map_trigger_type_to_trigger_table[trigger_type];
  sprintf(gs->bfr, "SELECT * FROM %s WHERE dialogue_folder_id = %d AND current_dialogue_id = %d AND selected_option = %d AND on_outcome=%d;",trigger_table, atoi(column_value[0]), atoi(column_value[1]),atoi(column_value[2]),atoi(column_value[3]));
  int query_code = sqlite3_exec(gs->db, gs->bfr, dbr_trigger_set_initial_dialogue_id, gs, &gs->query_manager->sqlite_bfr);
  DBR_EVAL_SQL_EXECUTION(query_code,gs->bfr,gs);
}

int dbr_trigger_set_initial_dialogue_id(void *game_state, int num_cols, char **column_value, char **column_name){
  Game_State *gs = (Game_State *)game_state;
  gs->dialogue_manager->initial_dialogue_id = atoi(column_value[5]);
}
