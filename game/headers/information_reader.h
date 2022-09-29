/*This file is part of Revenant.
Revenant is free software: you can redistribute it and/or modify
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
#include "strings.h"


typedef enum{integer, string, floating,struct_limb,struct_attributes}Return_Type;
void ir_readin_data(char *file_path, char *variable,Return_Type expected_type, void *value);
Creature *ir_readin_creature(char *creature_file_path,unsigned x, unsigned y, Game_World *world, Creature *target);
void ir_readin_struct_limb(Limb *limbs,char *limb_as_string, int limb_count);
void ir_readin_struct_attributes(Attributes attributes,char *attributes_as_string);
int ir_readin_int(char *file_path, char *variable);
#define IR_RETRIEVE_CREATURE_NAME(creature_id)({void *ptr; char bfr[3]; ir_readin_data(strcat("/home/anton/revenant/game/creature_files/",itoa(creature_id,bfr,10)),"name",string,ptr); char *name = (char *)ptr; name;})
#endif
