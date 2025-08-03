CREATE TABLE IF NOT EXISTS dia_dialogue_interactions(dialogue_folder_id int, current_dialogue_id int, num_dialogue_options int, PRIMARY KEY (dialogue_folder_id,current_dialogue_id));

CREATE TABLE IF NOT EXISTS dia_dialogue_selected_option_handler(dialogue_folder_id int, current_dialogue_id int, selected_option int, consequence int, next_current_dialogue_id_if_successful int, next_current_dialogue_id_if_fail int PRIMARY KEY(dialogue_folder_id,current_dialogue_id,selected_option), FOREIGN KEY(dialogue_folder_id, current_dialogue_id) REFERENCES dia_dialogue_interactions(dialogue_folder_id,current_dialogue_id));

CREATE TABLE IF NOT EXISTS dia_dialogue_option_triggers(dialogue_folder_id int, current_dialogue_id int, selected_option int, on_outcome int, trigger_type int);

CREATE TABLE IF NOT EXISTS dia_trigger_set_initial_dialogue(dialogue_folder_id int, current_dialogue_id int, selected_option int, new_initial_id int,PRIMARY KEY(dialogue_folder_id,current_dialogue_id,selected_option));
