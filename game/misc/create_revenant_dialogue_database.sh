#!/bin/bash

#Note - any and all variables defined in this box are intended to mirror that of those in dialogue.h
#Always double check that they match!
###
END_DIALOGUE=0
CONTINUE_DIALOGUE=1
NO_NEXT_DIALOGUE_ID=-1
NO_SKILLCHECK=-1
NO_SKILL_ID=-1
NULL_AMOUNT_DIALOGUE_OPTIONS=-1

#Note - any and all variables defined in this box are intended to mirror that of those in db_reader.h
#Always double check that they match!
GENERIC_ISSLOG_MALE_NPC=0
###
echo "Creating dialogue databases"
sqlite3 "$1"

#############################################################################################################################################

#The table that stores all dialogue information and reactions to players selecting certain dialogue options

#You should always handle the dialogue id's one at a time e.g first 0, then 1, then 2, etc.

#The current and next dialogue id refer to the id's stored in the revenant files and the selected dialogue, the dialogue picked from
#the set of possible options. Both are 0-indexed


create table dialogue_option_responses(npc_id int, current_dialogue_id int, selected_dialogue_id int, next_dialogue_id int, selected_dialogue_consequence int, next_dialogue_screen_num_options int);



##Generic isslog male dialogue, has 6 dialogue files 
insert into table dialogue_option_responses values($GENERIC_ISSLOG_MALE_NPC,0,0,1,$CONTINUE_DIALOGUE,4);
insert into table dialogue_option_responses values($GENERIC_ISSLOG_MALE_NPC,0,1,5,$CONTINUE_DIALOGUE,1);
insert into table dialogue_option_responses values($GENERIC_ISSLOG_MALE_NPC,0,1,$NO_NEXT_DIALOGUE_ID,$END_DIALOGUE,$NULL_AMOUNT_DIALOGUE_OPTIONS);
insert into table dialogue_option_responses values($GENERIC_ISSLOG_MALE_NPC,0,3,6,1);

#############################################################################################################################################
create table dialogue_skillcheck_requirement(npc_id int, current_dialogue_id int, selected_dialogue_id int, skllcheck_id int, skillcheck_requirement int);
