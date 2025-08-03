CREATE TABLE IF NOT EXISTS dia_dialogue_interactions(dialogue_folder_id int, current_dialogue_id int, num_dialogue_options int, PRIMARY KEY (dialogue_folder_id,current_dialogue_id));

CREATE TABLE IF NOT EXISTS dia_dialogue_selected_option_consequence_handler(dialogue_folder_id int, current_dialogue_id int, selected_option int, consequence int, next_current_dialogue_id_if_successful int, PRIMARY KEY(dialogue_folder_id,current_dialogue_id,selected_option), FOREIGN KEY(dialogue_folder_id, current_dialogue_id) REFERENCES dia_dialogue_interactions(dialogue_folder_id,current_dialogue_id));
