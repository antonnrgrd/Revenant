.parameter init

/* Generic DBR values BEGIN */
.parameter set :DBR_UNDEF -1
/* Generic DBR values END */
/*dia_dialogue_selected_option_consequence_handler definitions BEGIN  */
.parameter set :DBR_END_DIALOGUE 0

.parameter set :DBR_CONTINUE_DIALOGUE 1

.parameter set :DBR_DO_SKILLCHECK 2

.parameter set :DBR_DO_ITEMCHECK 3

.parameter set :DBR_SET_NPC_BEHAVIOR 4

.parameter set :DBR_MODIFY_PC_MONEY 5

.parameter set :DBR_MODIFY_PC_INVENTORY 6

.parameter set :DBR_UPDATE_PC_QUEST_STATUS 7
/*dia_dialogue_selected_option_consequence_handler definitions END  */

/* dia_dialogue_interactions definitions BEGIN */
.parameter set :DBR_ISSLOG_GENERIC_NPC 0
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
/*dia_dialogue_interactions ROWS END*/

/*dia_dialogue_selected_option_consequence_handler ROWS BEGIN*/
INSERT INTO dia_dialogue_selected_option_consequence_handler VALUES (:DBR_ISSLOG_GENERIC_NPC,0,0,:DBR_CONTINUE_DIALOGUE,1);
INSERT INTO dia_dialogue_selected_option_consequence_handler VALUES (:DBR_ISSLOG_GENERIC_NPC,0,1,:DBR_CONTINUE_DIALOGUE,5);
INSERT INTO dia_dialogue_selected_option_consequence_handler VALUES (:DBR_ISSLOG_GENERIC_NPC,0,2,:DBR_END_DIALOGUE,:DBR_UNDEF);
INSERT INTO dia_dialogue_selected_option_consequence_handler VALUES (:DBR_ISSLOG_GENERIC_NPC,0,3,:DBR_CONTINUE_DIALOGUE,6);

INSERT INTO dia_dialogue_selected_option_consequence_handler VALUES (:DBR_ISSLOG_GENERIC_NPC,0,1,:DBR_CONTINUE_DIALOGUE,4);


/*dia_dialogue_selected_option_consequence_handler ROWS END*/

