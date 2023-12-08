#!/bin/bash

echo "Creating game world"

echo "Compiling SQLite CLI"
gcc shell.c sqlite3.c -lpthread -ldl -lm -o sqlite3

echo "c
