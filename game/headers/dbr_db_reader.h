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
#ifndef DBR_READER
#define DBR_READER
#include <sqlite3.h>
#include "game_state_struct.h"
#include "dbr_db_reader_struct.h"
#include "dia_dialogue_struct.h"
#include "l_log.h"
#include <string.h>
#include "string.h"
Dbr_Selected_Dialogue_Qresult dbr_get_dialogue_response(Game_State *gs,Dia_Dialogue_Manager *manager, int selected_choice);
Dia_Dialogue_Manager *dbr_readin_dialogue_manager(int np_id);
void dbr_add_dialogue_to_db(int dialogue_folder_id, int current_dialogue_id,int consequence,int num_options);
void dbr_create_db_all_content(Game_State *gs);
void dbr_create_all_tables(Game_State *gs);
void dbr_create_dialogue_tables(Game_State *gs,sqlite3 *db);
int dbr_does_table_exist(char *table,sqlite3 *db);
void dbr_print_rows(Game_State *gs, char *query);
/* We generate the str to be logged in this unusual fashion because at this point in the execution flow, the game state buffer already has it's contents  */
#define DBR_EVAL_SQL_EXECUTION(sql_exec_code,statement,gs) sql_exec_code != SQLITE_OK ?  s_append_to_string(gs->bfr, "An error occured when attempting to execute the statement: "), strcat(gs->bfr, ", caused by the sql error "), strcat(gs->bfr, gs->query_manager->sqlite_bfr), l_write_log(gs->bfr, L_WARN,L_LOG_SILENTLY)  : sql_exec_code;

#define DBR_RESET_QUERY_MANAGER(query_manager){\
  query_manager->current_row_index = 0;	       \
  query_manager->num_rows_encountered = 0;     \
  }
#define DBR_INITIALIZE_QUERY_MANAGER(query_manager){\
  query_manager->current_row_index = 0;	       \
  query_manager->num_rows_encountered = 0;     \
  query_manager->sqlite_bfr = NULL;     \
  }
void dbr_close_db_connection(sqlite3 *db);
int dbr_print_rows_from_query(void *data, int argc, char **argv, char **colNames);
void dbr_execute_statement(char *statement, char *log_level, sqlite3 *db, Game_State *gs);

int dbr_pass_inf_to_dialogue_qresult(void *passed_struct, int num_cols, char **column_value, char **column_name);
#endif

int dbr_get_next_dialogue_id(void *game_state, int num_cols, char **column_value, char **column_name);

int dbr_get_num_dialogue_options(void *game_state, int num_cols, char **column_value, char **column_name);

#define DBR_GET_NUM_DIALOGUE_OPTON(gs){\
  sprintf(gs->bfr, "SELECT num_dialogue_options FROM dia_dialogue_interactions WHERE dialogue_folder_id = %d AND current_dialogue_id = %d;", manager->dialogue_folder_id); \
  int query_code = sqlite3_exec(gs->db, gs->bfr, dbr_get_num_dialogue_options, manager, &gs->query_manager->sqlite_bfr); \
  DBR_EVAL_SQL_EXECUTION(query_code,gs->bfr,gs);			\
  }

int dbr_readin_game_world();

int dbr_apply_triggers(void *game_state, int num_cols, char **column_value, char **column_name);

int dbr_trigger_set_initial_dialogue_id(void *game_state, int num_cols, char **column_value, char **column_name);
