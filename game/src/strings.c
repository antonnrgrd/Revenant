/*This file is part of Revenant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */


#include "strings.h"

char *s_create_text(char *arg){
  int length = strlen(arg);
  char *text = malloc( length * sizeof(char));
  strcpy(text,arg);
  return text;
}

char *s_create_text_const(const char *arg){ //a variant that works for const values bc i'm too lazy to fix the original function
  int length = strlen(arg);
  char *text = malloc( length * sizeof(char));
  strcpy(text,arg);
  return text;
}

//a function that concatenates two strings, destryoying them in the process
char *s_merge_text(char *first_arg,char *second_arg){
  int first_length = strlen(first_arg);
  int second_length = strlen(second_arg);
  char *string_result = malloc(first_length+second_length * sizeof(char));
  string_result[0] = '\0'; //ensures memory is empty string
  strcat(string_result,first_arg);
  strcat(string_result,second_arg);
  free(first_arg);
  free(second_arg);
  return(string_result);
}



int s_only_whitespace(char *bfr){
    /* We only bother checking the first character because with how we write messages to the log, it suffices to check
     the first character to decide if the rest of the string is empty i.e if the first character is empty/nonempty, it applies to the rest of the string*/
    if(bfr[0] > EMPTY_STR_RANGE){
      
      return 0;
    }
  return 1; 
}

 
int s_char_count(char *string, char *character){
  int i = 0;
  int occurence_count = 0;
  while(string[i] != '\0'){
    if(string[i] == character){
      occurence_count++;
    }
    i++;
  }
  return occurence_count;
}

uint64_t s_uint_from_string(int argcount, ...){
  va_list string_list;
  va_start(string_list, argcount);
  uint64_t value = 0;
  int j = 0;
  int k = 0;
  for(int i = 0; i < argcount; i++){
    char *str = va_arg(string_list,char* );
    while(str[k] != '\0'){
    uint64_t position = str[j] - 'a'; //won't work in all positions, but find numerical position in alphabet e.g a = 1, b =2, c = 3
    value = value + position * (uint64_t) pow(2, (j%3));
    j++;
    k++;
    }
    k=0;
  }
  va_end(string_list);
  return value;
}

char *s_append_to_string(char *target_string, char *string_to_append){
   int length = strlen(string_to_append);
   memmove(target_string + length, target_string, strlen(target_string) + 1);
   memcpy(target_string, string_to_append, length);
   return target_string;
}

char *s_replace_all_char_occurences(char *target_string, char *character_to_replace, char *replacement_char){
  char *current_string = strchr(target_string,character_to_replace);
    while (current_string != NULL) {
        *current_string = replacement_char;
        current_string = strchr(current_string,character_to_replace);
    }
    return target_string;
}
