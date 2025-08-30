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
#ifndef DBR_READER_STRUCT
#define DBR_READER_STRUCT


/*C has some constraints wrt. the length of the variable/macro names. As much as i want to make it ultra clear where a
 macro/ variable fits tn, i will have to limit the names' length and instead use comments to group related values together*/

/* dia_dialogue check flags outcomes definitions BEGIN */

#define DBR_CHECK_SUCCESS 0
#define DBR_CHECK_FAILURE 1

/* dia_dialogue check flags outcomes definitions END */

/* Generic DBR values BEGIN */
#define DBR_UNDEF -1
/* Generic DBR values END */

/*dia_dialogue_selected_option_handler definitions BEGIN  */

#define DBR_END_DIALOGUE 0

#define DBR_CONTINUE_DIALOGUE 1

#define DBR_CHECK_NPC_HAS_SKILL 2

#define DBR_CHECK_NPC_HAS_ITEM 3

/*dia_dialogue_selected_option_consequence_handler definitions END  */

/* dia_dialogue_interactions definitions BEGIN */
#define DBR_ISSLOG_GENERIC_NPC 0

#define DBR_BOOTSTRAP_NPC 1
/* dia_dialogue_interactions definitions END */


/* Creature ID's BEGIN */
#define DBR_SHORT_FACED_BEAR 0
#define DBR_CROCODILE 1
/* Creature ID's END */

/* dia_dialogue_option_triggers definitions BEGIN*/
#define DBR_SET_INITIAL_DIALOGUE_ID 0

#define DBR_SET_NPC_BEHAVIOR 1

#define DBR_SET_NPC_BEHAVIOR 2

#define DBR_MODIFY_PC_MONEY 3

#define DBR_MODIFY_PC_INVENTORY 4

#define DBR_UPDATE_PC_QUEST_STATUS 5

#define DBR_SET_NPC_LOCATION 6

/* dia_dialogue_option_triggers definitions END*/


typedef struct{
  int current_row_index;
  int num_rows_encountered;
  /*Quite annoyingly, sqlite manages memory *slightly* differently than standard C, hence we need a seperate buffer that it can write to */
  char *sqlite_bfr;
  //Generic holder for data
  void *data;
  unsigned int check_status : 1;
}Dbr_Query_Manager;

typedef struct{
  int next_dialogue_id;
  int selected_dialogue_consequence;
  int next_dialogue_screen_num_options;
  int consequence;
}Dbr_Selected_Dialogue_Qresult;
#define DBR_DATABASE_PATH "/usr/lib/revenant_files/database/revenant.db"

extern const char *dbr_map_trigger_type_to_trigger_table[];
#endif
