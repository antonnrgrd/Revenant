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
#include "information_reader.h" 

Creature *ir_readin_creature(char *creature_file_path){
  Creature *creature = malloc(sizeof(Creature));
  FILE *creature_file = fopen(creature_file_path, "r");
  // int intv = *(int *)ir_readin_data(creature_file,"id",integer);
  // float floatv = *(float *)ir_readin_data(creature_file,"height",floating);
  char *charv = (char *)ir_readin_data(creature_file,"name",string);
  // printf("%g%s", floatv, "\n");
  //printf("%d%s", intv, "\n");
  // printf("%s%s", charv);
  fclose(creature_file);
  return creature;
}

void *ir_readin_data(FILE *information_file, char *variable,Return_Type type){
  void *value;
  char *line = NULL;
  size_t len = 0;
  while(getline(&line, &len, information_file) != -1){
    char *variable_pointer = strstr(line, variable);
    //printf("%s%s",line ,"\n");
    if(variable_pointer != NULL){
      //     printf("%s", variable_pointer);
      switch (type){
      case integer:
	int integer_value = atoi(strchr(line, '=')+1);
	value = &integer_value;
	return value;
	break;
      case floating:
	float float_value;
        float_value=atof(strchr(line, '=')+1);
	value = &float_value;
	return value;
	break;
      case string:
	char *string_value = strchr(line, '=')+1;
	value = string_value;
	return value;
        default:
	  break;
      }
    }
  }
}
  
