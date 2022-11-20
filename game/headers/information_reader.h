/*This file is part of Revenant.
65;6800;1cRevenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
Revenant  is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */
#ifndef CREATURE_READER
#define CREATURE_READER
#define FILE_BUFFER_SIZE 50
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "creature.h"
#include "generic_macros.h"

typedef enum{integer, string, floating,struct_limb,struct_attributes}Return_Type;
void ir_readin_data(char *file_path, char *variable,Return_Type expected_type, void *value);
Creature *ir_readin_creature(char *creature_file_path,unsigned x, unsigned y, Game_World *world, Creature *target);
Item *ir_readin_reagent(char *reagent_file_path);
Item *ir_readin_consumable(char *consumable_file_path);
void ir_readin_struct_limb_values(Limb *limbs,char *limb_as_string, int limb_count);
void ir_readin_struct_attributes(char *creature_file_path,char *variable,Attributes attributes);
int ir_readin_int(char *file_path, char *variable);
void ir_readin_char(char *file_path, char *variable,char *bfr);
int ir_readin_int(char *file_path, char *variable);
float ir_readin_float(char *file_path, char *variable);
Limb *ir_readin_struct_limb(char *file_path, char *variable);
void ir_readin_struct_attributes_values(Attributes attributes,char *attributes_as_string);

void ir_print_string(char *file_path,char *variable, WINDOW *screen, int x, int y, int printing_specification,Item_Holder *item_holder);

int ir_compare_strings(char *first_file_path, char *second_file_path, char *variable);

unsigned long long ir_hash_string(char *file_path,char *variable, U_Hashtable *table);


#define IR_INITALIZE_STR_VAL(file_path,string_value, var_name) char *value = ir_readin_char(file_path,string_value); var_name = malloc(sizeof(char) * strlen(value)); strcpy(var_name,value); free(value)

char *yield_char();
#endif
