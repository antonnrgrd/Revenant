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
struct Item *ir_readin_reagent(char *reagent_file_path){
  struct Item *i = malloc(sizeof(Item));
  Reagent *reagent = malloc(sizeof(Reagent));
  reagent->id = ir_readin_int(reagent_file_path,"id");
  i->weight = ir_readin_float(reagent_file_path,"weight");
  i->item_specific_info = reagent;
  i->id = reagent->id;
  return i;
}

struct Item *ir_readin_consumable(char *consumable_file_path){
  struct Item *i = malloc(sizeof(Item));
  Consumable *consumable = malloc(sizeof(Consumable));
  consumable->id = ir_readin_int(consumable_file_path,"id");
  i->weight = ir_readin_float(consumable_file_path,"weight");
  i->item_specific_info = consumable;
  i->id = consumable->id;
  return i;
}
Creature *ir_readin_creature(char *creature_file_path,unsigned x, unsigned y, Game_World *world, Creature *target){
   
  Creature *c = malloc(sizeof(Creature));

  c->position.global_x=x;
  c->position.global_y=y;
  c->curr_ap = 1;
  c->max_ap = 1;
  c_compute_relative_coords(c, target);
  c->standing_on = malloc(sizeof(char));
  c->standing_on[0] = world->tiles[c->position.global_y][c->position.global_x].content[0];
  world->tiles[c->position.global_y][c->position.global_x].foe = c;
  c->has_moved_around_vertically = 0;
  c->has_moved_around_horizontally = 0;
  c->marked_for_deletion = NO;
 
  ir_readin_char(creature_file_path, "representation", c->representation);
  // c->representation = malloc(sizeof(char));
  //strcpy(c->representation, representation);
  //free(representation);
  c->species=ir_readin_int(creature_file_path, "species");
  c->id=ir_readin_int(creature_file_path, "id");
  c->limb_count = ir_readin_int(creature_file_path, "limb_count");
  c->weight = ir_readin_float(creature_file_path, "weight");
  c->max_carry = ir_readin_float(creature_file_path,"max_carry");
  c->current_carry = 0;
  c->max_health = ir_readin_int(creature_file_path,"max_health");
  c->curr_health = c->max_health;
  c->height = ir_readin_float(creature_file_path, "height");
  c->preferred_attack_type = ir_readin_int(creature_file_path,"preferred_attack_type");
  c->limbs = ir_readin_struct_limb(creature_file_path,"limbs");
  ir_readin_struct_attributes(creature_file_path,"attributes",c->attributes);
  /*
  
  
  
 
 
  
  
  
  
  */
    /*
  
  

  c->attributes = *(Attributes *)ir_readin_data(creature_file,"attributes",struct_attributes);
  
*/
  world->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];  
  
  return c;
}

void ir_readin_struct_attributes(char *file_path, char *variable, Attributes attributes){
   FILE *fp = fopen(file_path, "r");
  char * line = NULL;
  size_t len = 0;
  float rational;
  while((getline(&line, &len, fp)) != -1){
    char *variable_pointer = strstr(line, variable);
    if(variable_pointer != NULL){
      char *value_as_str = strtok(strchr(line, '=')+1, "\n");
      ir_readin_struct_attributes_values(attributes,value_as_str);
       break;
      }
    }
  if(line){
    free(line);
  }
  if(fp){
    fclose(fp);
  }
}
Limb *ir_readin_struct_limb(char *file_path, char *variable){
  FILE *fp = fopen(file_path, "r");
  char * line = NULL;
  size_t len = 0;
  Limb *creature_limbs;
  while((getline(&line, &len, fp)) != -1){
    char *variable_pointer = strstr(line, variable);
    if(variable_pointer != NULL){
      char *value_as_str = strtok(strchr(line, '=')+1, "\n");
      //We subtract 1 because the first bracket denotes the beginning of the list of limbs
      int limb_count  = s_char_count(value_as_str, '[') -1 ;
      creature_limbs = malloc(sizeof(Limb) * limb_count);
      ir_readin_struct_limb_values(creature_limbs,value_as_str, limb_count);
       break;
      }
    }
  if(line){
    free(line);
  }
  if(fp){
    fclose(fp);
  }
       return creature_limbs;
}

float ir_readin_float(char *file_path, char *variable){
  FILE *fp = fopen(file_path, "r");
  char * line = NULL;
  size_t len = 0;
  float rational;
  while((getline(&line, &len, fp)) != -1){
    char *variable_pointer = strstr(line, variable);
    if(variable_pointer != NULL){
      char *value_as_str = strtok(strchr(line, '=')+1, "\n");
      rational = atof(value_as_str); 
       break;
      }
    }
  if(line){
    free(line);
  }
  if(fp){
    fclose(fp);
  }
       return rational;
 }

int ir_readin_int(char *file_path, char *variable){
  FILE *fp = fopen(file_path, "r");
  char * line = NULL;
  size_t len = 0;
  int number;
  while((getline(&line, &len, fp)) != -1){
    char *variable_pointer = strstr(line, variable);
    if(variable_pointer != NULL){
      char *value_as_str = strtok(strchr(line, '=')+1, "\n");
      number = atoi(value_as_str);
       break;
      }
    }
  if(line){
    free(line);
  }
  if(fp){
    fclose(fp);
  }
       return number;
 }

char *yield_char(){
  char *val = malloc(sizeof(char));
  return val;
}
/*For reason i simply cannot comprehend, attempting to return a char pointer simply did not work.
It would work on its own, but trying to use that pointer would cause segmentation fault. inspecting with GDB
revealed that the point somehow ceased to be valid the instant the function returned the point. It was not NULL straight out invalid
THe fact that the approach works for every other data type baffles me. But for chars, we are forced to make do with a pass-by-reference
approach for reading in a char value*/
void ir_readin_char(char *file_path, char *variable,char *bfr){
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    size_t read;

    //fp = fopen("/usr/lib/revenant_files/item_files/reagent_files/0", "r");
    fp = fopen(file_path, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

   while ((read = getline(&line, &len, fp)) != -1) {
     char *variable_pointer = strstr(line, variable);
     if(variable_pointer != NULL){
       char *value_as_str = strtok(strchr(line, '=')+1, "\n");
       bfr = malloc(sizeof(char) * strlen(value_as_str) +5);
       strcpy(bfr , value_as_str);
       break;
     }
    }

   if(line)
     free(line);
   fclose(fp);
  /*
  FILE *fp = fopen(file_path, "r");
  if(fp == NULL){
    exit(EXIT_FAILURE);
  }
  char * line = NULL;
  size_t len = 0;
  char *bfr = NULL;
  while((getline(&line, &len, fp)) != -1){
    
    if(variable_pointer != NULL){
      char *value_as_str = strtok(strchr(line, '=')+1, "\n");
      bfr = malloc(sizeof(char) * (strlen(value_as_str) +1 ));
      strcpy(bfr,value_as_str);
       break;
      }
    }
  if(line){
    free(line);
  }
  if(fp){
    fclose(fp);
  }
       return bfr;
  */
 }

/*
char *ir_readin_char(char *file_path, char *variable){
  FILE *fp = fopen(file_path, "r");
  char * line = NULL;
  size_t len = 0;
  char *value_as_str;
  while((getline(&line, &len, fp)) != -1){
    char *variable_pointer = strstr(line, variable);
    if(variable_pointer != NULL){
      value_as_str = strtok(strchr(line, '=')+1, "\n");
       break;
      }
    }
  if(line){
    free(line);
  }
  if(fp){
    fclose(fp);
  }
  return value_as_str;
 }
*/
void ir_readin_data(char *file_path, char *variable, Return_Type expected_type, void *value){
  FILE *fp = fopen(file_path, "r");
  char * line = NULL;
  size_t len = 0;
  while((getline(&line, &len, fp)) != -1){
    char *variable_pointer = strstr(line, variable);
    if(variable_pointer != NULL){
      char *value_as_str = strtok(strchr(line, '=')+1, "\n");
      switch(expected_type){
      case integer:
	/*Deprecated, but still used for sake of ease */
        *(int * )value = atoi(value_as_str);
	break;
      case string:
	char *bfr = malloc(sizeof(char) * 100);
	strcpy(bfr,value_as_str);
	value = &bfr;
	break;
      case floating:
	*(float *)value = atof(value_as_str);
	break;
      case struct_limb:
	//We subtract 1 because the first bracket denotes the beginning of the list of limbs
	int limb_count  = s_char_count(value_as_str, '[') -1 ;
	Limb *creature_limbs = malloc(sizeof(Limb) * limb_count);
	//	ir_readin_struct_limb(creature_limbs,value_as_str, limb_count);
	value = creature_limbs;
        break;
      case struct_attributes:
	Attributes attributes;
	//	ir_readin_struct_attributes(attributes,value_as_str);
	value = &attributes;
	break;
      default:
	break;
      }
      free(line);
      fclose(fp);
      break;
    }
  }
}
  
void ir_readin_struct_limb_values(Limb *limbs,char *limb_as_string, int limb_count){
  /*We add +2 to the result of the strchr function because we then skip over the first
 [ character in the string, allowing us to more easily extract the value(s) in the list*/
  char *processed_limbs = strchr(limb_as_string, '[')+2;
  /*We need a tmp buffer because strtok not only returns a string, but also modifies the original string in question*/
  char *tmp_bfr = malloc(sizeof(char) * strlen(processed_limbs));
  for(int i = 0; i < limb_count; i++ ){
    strcpy(tmp_bfr,processed_limbs);
    char *sublist = strtok(tmp_bfr,"]");
    char *value_as_str = strtok(sublist,",");
    /*At this point I realized that had I instead of a custom-defined struct used a matrix of ints, we could have read in the data using and index-based for loop
     but that would have meant that instead of a set of named attributes we would just have an array of integer values and would need
    some other way to identify which int in the array represented which variable of the limb, perhaps some kind of index mapping but that would have been a whole other can of worms so i decided to commit the implemtation of the struct as-is*/
    limbs[i].kind = atoi(value_as_str);

    value_as_str = strtok(NULL, ",");

    limbs[i].status = atoi(value_as_str);

    value_as_str = strtok(NULL, ",");

    limbs[i].durability = atoi(value_as_str);

    value_as_str = strtok(NULL, ",");

    limbs[i].damage = atoi(value_as_str);
    
    processed_limbs = strchr(processed_limbs, '[')+1;
  }
  free(tmp_bfr);
}

void ir_readin_struct_attributes_values(Attributes attributes,char *attributes_as_string){
   /*We add +2 to the result of the strchr function because we then skip over the first
 [ character in the string, allowing us to more easily extract the value(s) in the list*/
    char *attributes_sequence = strchr(attributes_as_string, '[')+2;
    
    char *value_as_str = strtok(attributes_sequence,",");
    
    attributes.stamina = atoi(value_as_str);

    value_as_str = strtok(NULL, ",");

    attributes.strength = atoi(value_as_str);

    value_as_str = strtok(NULL, ",");

    attributes.dexterity = atoi(value_as_str);

    value_as_str = strtok(NULL, ",");

    attributes.luck = atoi(value_as_str);

    value_as_str = strtok(NULL, ",");

    attributes.charisma = atoi(value_as_str);

    value_as_str = strtok(NULL, ",");

    attributes.intelligence = atoi(value_as_str);

    value_as_str = strtok(NULL, ",");

    attributes.wisdom = atoi(value_as_str);
}
/*
int ir_readin_int(char *file_path, char *variable){
  FILE *fp = fopen(file_path, "rw");
  char * line = NULL;
  size_t len = 0;
   while ((getline(&line, &len, fp)) != -1) {
  char *variable_pointer = strstr(line, variable);
    if(variable_pointer != NULL){
    char *value_as_str = strtok(strchr(line, '=')+1, "\n");
    return atoi(value_as_str);  
  free(line);    
  ffclose(fp);
 
  }
}
}
*/





  /*
      switch (type){
      case integer:
        int integer_value = atoi(strchr(line, '=')+1);
	printf("%d", integer_value);
	value = &integer_value;
	break;
	
  
  
      case floating:
	float float_value;
        float_value=atof(strchr(line, '=')+1);
	value = &float_value;
	break;
      case string:
	//We have to strip a newline from the value because each line read in the file is ended with a newline, which is
	 // not removed when we take the value as a string
	char *string_value = strtok(strchr(line, '=')+1, "\n");
	//printf("%s",string_value);
	value = string_value;
	break;
		
      case struct_limb:
	char *limb_as_string = strchr(line, '=')+1;
	//We subtract 1 because the first bracket denotes the beginning of the list of limbs
	int limb_count  = s_char_count(limb_as_string, '[') -1 ;
	Limb *creature_limbs = malloc(sizeof(Limb) * limb_count);
	ir_readin_struct_limb(creature_limbs,limb_as_string, limb_count);
	value = creature_limbs;
        break;
      case struct_attributes:
	char *attributes_as_string = strchr(line, '=')+1;
	Attributes attributes;
	ir_readin_struct_attributes(attributes,attributes_as_string);
	value = &attributes;

        default:
	  break;
      }
      */
   
  //      printf("%s%s%","could not find ",variable ," is apparently missing ");

/*
Okay so this is not a comment as much it is a more of a venting personal rant for myself. Originally the desired functionality for the information_reader source file was to provide functionality for reading in hard-coded values stored in files. This worked for evey single data type EXCEPT for char pointers. no matter the approach, it would also culminate in some sort of low-level error. Both approaches of returning a malloc'd char pointer or pass by reference approach where you assign the result to a char point argument failed. Interestingly enough, going through gdb revealed that in the function call of ir_readin_char, the desired return value was as expected. but the INSTANT the function call retuned, it was no longer valid. Either it was garbage or an unaccessible pointer. After countless approaches, it was given up on and instead, since the values ARE valid in the function call, any work with the strings will be done inside the function calls below. Besides my instances were i would use ir_readin_char, the char in question is single use, before calling a free, so the functions save me from havign to make a a malloc, only to immediately free it afterwrads. Funnily enough, ir_readin_char works for assigning the character representation for ir_readin_creature, but nowwhere else. Rant over
*/
void ir_print_string(char *file_path, char *variable, WINDOW *screen, int x, int y, int printing_specification, Item_Holder *item_holder){
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    size_t read;

    fp = fopen(file_path, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

   while ((read = getline(&line, &len, fp)) != -1) {
     char *variable_pointer = strstr(line, variable);
     if(variable_pointer != NULL){
       char *value_as_str = strtok(strchr(line, '=')+1, "\n");
       switch(printing_specification){
       case PRINT_ITEM:
	 if(item_holder->amount != 1){
	    mvwprintw(screen, y,x, "%s%s%d", value_as_str , " X ", item_holder->amount);
	 }
	 else{
	   mvwprintw(screen, y,x, "%s", value_as_str);  
	 }
	 break;
       default:
	 break;
       }
       mvprintw(screen,y,x,value_as_str);
       break;
     }
    }

   if(line)
     free(line);
   fclose(fp);
 }

unsigned long long ir_hash_string(char *file_path,char *variable, U_Hashtable *table){
   FILE *fp;
    char *line = NULL;
    size_t len = 0;
    size_t read;
    unsigned long long hash;
    fp = fopen(file_path, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

   while ((read = getline(&line, &len, fp)) != -1) {
     char *variable_pointer = strstr(line, variable);
     if(variable_pointer != NULL){
       char *value_as_str = strtok(strchr(line, '=')+1, "\n");
       hash = u_hash(1,table,value_as_str);
       break;
     }
    }

   if(line)
     free(line);
   fclose(fp);
   return hash;
 }

int ir_compare_strings(char *first_file_path, char *second_file_path, char *variable){
  FILE *fp;
    char *line = NULL;
    size_t len = 0;
    size_t read;
    char *first_string;
    char *second_string;
    fp = fopen(first_file_path, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

   while ((read = getline(&line, &len, fp)) != -1) {
     char *variable_pointer = strstr(line, variable);
     if(variable_pointer != NULL){
       first_string = strtok(strchr(line, '=')+1, "\n");
     }
    }

   if(line)
     free(line);
   fclose(fp);

   fp = fopen(second_file_path, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

   while ((read = getline(&line, &len, fp)) != -1) {
     char *variable_pointer = strstr(line, variable);
     if(variable_pointer != NULL){
       second_string = strtok(strchr(line, '=')+1, "\n");
     }
    }

   if(line)
     free(line);
   fclose(fp);
   return strcmp(first_string,second_string);
   
}
