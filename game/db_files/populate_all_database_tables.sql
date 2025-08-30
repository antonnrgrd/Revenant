.parameter init

/* Generic DBR values BEGIN */
.parameter set :DBR_UNDEF -1
/* Generic DBR values END */

/* dia_dialogue check flags outcomes definitions BEGIN */

.parameter set :DBR_CHECK_SUCCESS 0
.parameter set :DBR_CHECK_FAILURE 1

/* dia_dialogue check flags outcomes definitions END */

/*dia_dialogue_selected_option_handler definitions BEGIN  */
.parameter set :DBR_END_DIALOGUE 0

.parameter set :DBR_CONTINUE_DIALOGUE 1
/*dia_dialogue_selected_option_handler definitions END  */

/* dia_dialogue_option_triggers definitions BEGIN*/
.parameter set :DBR_SET_INITIAL_DIALOGUE_ID 0

.parameter set :DBR_SET_NPC_BEHAVIOR 1

.parameter set :DBR_SET_NPC_BEHAVIOR 2

.parameter set :DBR_MODIFY_PC_MONEY 3

.parameter set :DBR_MODIFY_PC_INVENTORY 4

.parameter set :DBR_UPDATE_PC_QUEST_STATUS 5

.parameter set :DBR_SET_NPC_LOCATION 6

/* dia_dialogue_option_triggers definitions END*/


/* dia_dialogue_interactions definitions BEGIN */
.parameter set :DBR_ISSLOG_GENERIC_NPC 0
.parameter set :DBR_BOOTSTRAP_NPC 1
/* dia_dialogue_interactions definitions END */

/* Creature ID's BEGIN */

/* Creature ID's END */



 /*dia_dialogue_interactions ROWS BEGIN*/
INSERT INTO dia_dialogue_interactions VALUES (:DBR_ISSLOG_GENERIC_NPC,0,4);
INSERT INTO dia_dialogue_interactions VALUES (:DBR_ISSLOG_GENERIC_NPC,1,4);
INSERT INTO dia_dialogue_interactions VALUES (:DBR_ISSLOG_GENERIC_NPC,2,1);
INSERT INTO dia_dialogue_interactions VALUES (:DBR_ISSLOG_GENERIC_NPC,3,1);
INSERT INTO dia_dialogue_interactions VALUES (:DBR_ISSLOG_GENERIC_NPC,4,1);
INSERT INTO dia_dialogue_interactions VALUES (:DBR_ISSLOG_GENERIC_NPC,5,1);
INSERT INTO dia_dialogue_interactions VALUES (:DBR_ISSLOG_GENERIC_NPC,6,1);
INSERT INTO dia_dialogue_interactions VALUES (:DBR_ISSLOG_GENERIC_NPC,7,1);


/*dia_dialogue_interactions ROWS END*/

/*dia_dialogue_selected_option_handler ROWS BEGIN*/
INSERT INTO dia_dialogue_selected_option_handler VALUES (:DBR_ISSLOG_GENERIC_NPC,0,0,:DBR_CONTINUE_DIALOGUE,1,:DBR_UNDEF);
INSERT INTO dia_dialogue_selected_option_handler VALUES (:DBR_ISSLOG_GENERIC_NPC,0,1,:DBR_CONTINUE_DIALOGUE,5,:DBR_UNDEF);
INSERT INTO dia_dialogue_selected_option_handler VALUES (:DBR_ISSLOG_GENERIC_NPC,0,2,:DBR_END_DIALOGUE,:DBR_UNDEF,:DBR_UNDEF);
INSERT INTO dia_dialogue_selected_option_handler VALUES (:DBR_ISSLOG_GENERIC_NPC,0,3,:DBR_CONTINUE_DIALOGUE,6,:DBR_UNDEF);

INSERT INTO dia_dialogue_selected_option_handler VALUES (:DBR_ISSLOG_GENERIC_NPC,1,0,:DBR_CONTINUE_DIALOGUE,0,:DBR_UNDEF);

INSERT INTO dia_dialogue_selected_option_handler VALUES (:DBR_ISSLOG_GENERIC_NPC,2,0,:DBR_CONTINUE_DIALOGUE,0,:DBR_UNDEF);

INSERT INTO dia_dialogue_selected_option_handler VALUES (:DBR_ISSLOG_GENERIC_NPC,3,0,:DBR_CONTINUE_DIALOGUE,0,:DBR_UNDEF);

INSERT INTO dia_dialogue_selected_option_handler VALUES (:DBR_ISSLOG_GENERIC_NPC,4,0,:DBR_CONTINUE_DIALOGUE,0,:DBR_UNDEF);

INSERT INTO dia_dialogue_selected_option_handler VALUES (:DBR_ISSLOG_GENERIC_NPC,5,0,:DBR_CONTINUE_DIALOGUE,0,:DBR_UNDEF);

INSERT INTO dia_dialogue_selected_option_handler VALUES (:DBR_ISSLOG_GENERIC_NPC,6,0,:DBR_END_DIALOGUE,:DBR_UNDEF,:DBR_UNDEF);

INSERT INTO dia_dialogue_selected_option_handler VALUES (:DBR_ISSLOG_GENERIC_NPC,7,0,:DBR_END_DIALOGUE,:DBR_UNDEF,:DBR_UNDEF);
/*dia_dialogue_selected_option_handler ROWS END*/

/* dia_dialogue_option_triggers ROWS BEGIN */
INSERT INTO dia_dialogue_option_triggers VALUES (:DBR_ISSLOG_GENERIC_NPC,0,3,:DBR_CHECK_SUCCESS,:DBR_SET_INITIAL_DIALOGUE_ID);
/* dia_dialogue_option_triggers ROWS END */

/*dia_trigger_set_initial_dialogue ROWS BEGIN */
INSERT INTO dia_trigger_set_initial_dialogue VALUES (:DBR_ISSLOG_GENERIC_NPC,0,3,:DBR_CHECK_SUCCESS,:DBR_ISSLOG_GENERIC_NPC,7);
/*dia_trigger_set_initial_dialogue ROWS END */
