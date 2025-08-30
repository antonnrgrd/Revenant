/*
Creates all database tables, including constraints, triggers, index etc,
*/
---
CREATE TABLE IF NOT EXISTS dia_dialogue_interactions(dialogue_folder_id int, current_dialogue_id int, num_dialogue_options int, PRIMARY KEY (dialogue_folder_id,current_dialogue_id));
CREATE INDEX dia_dialogue_interactions_index on dia_dialogue_interactions(dialogue_folder_id,current_dialogue_id);
-----

-------------
CREATE TABLE IF NOT EXISTS dia_dialogue_selected_option_handler(dialogue_folder_id int, current_dialogue_id int, selected_option int, check_type int, next_dia_id_if_check_success int, next_dia_id_if_check_fail int, PRIMARY KEY (dialogue_folder_id,current_dialogue_id, selected_option));
CREATE INDEX dia_dialogue_selected_option_handler_index on  dia_dialogue_selected_option_handler(dialogue_folder_id,current_dialogue_id, selected_option);
-------------------

------------------------
CREATE TABLE IF NOT EXISTS dia_dialogue_option_triggers(dialogue_folder_id int, current_dialogue_id int, selected_option int, on_outcome int, trigger_type int, PRIMARY KEY (dialogue_folder_id, current_dialogue_id, selected_option, on_outcome, trigger_type));
CREATE INDEX dia_dialogue_option_triggers_index on dia_dialogue_option_triggers(dialogue_folder_id, current_dialogue_id, selected_option, on_outcome);
--------------------------
CREATE TABLE IF NOT EXISTS dia_trigger_set_initial_dialogue(dialogue_folder_id int, current_dialogue_id int, selected_option int, on_outcome int, target_dialogue_folder_id int, new_initial_id int, PRIMARY KEY(dialogue_folder_id, current_dialogue_id, selected_option, on_outcome, target_dialogue_folder_id));
CREATE INDEX dia_trigger_set_initial_dialogue_index on dia_trigger_set_initial_dialogue(dialogue_folder_id, current_dialogue_id, selected_option, on_outcome);
