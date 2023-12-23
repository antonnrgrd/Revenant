#!/bin/bash

echo "Creating dialogue databases"
sqlite3 "$1"

create table dialogue_options_table(npc_id, two int);

create table dialogue_option_responses(npc_id int, current_dialogue_id int, selected_dialogue_id int, next_dialogue_id int, choice_consequence int);

#dialogue options for generic male npc in iislog
insert into table dialogue_option_responses values(0,0,1,1,0);
insert into table dialogue_option_responses values(0,0,2,5,0);
insert into table dialogue_option_responses values(0,0,3,0,0);
insert into table dialogue_option_responses values(0,0,4,6,0);

