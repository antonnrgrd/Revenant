#!/bin/bash

#A dummy hack to create an empty database. VACUMM rebuilds the database file"
./sqlite3 /usr/lib/revenant_files/db_folder/revenant_database.db "VACUUM;"  ".exit"
./create_revenant_dialogue_database.sh "/usr/lib/revenant_files/db_folder/revenant_database.db"

