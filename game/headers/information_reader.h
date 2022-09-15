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
typedef enum{integer, string, floating}Return_Type;
void *ir_readin_data(FILE *information_file, char *variable,Return_Type type);
Creature *ir_readin_creature(char *creature_file_path);
#endif
