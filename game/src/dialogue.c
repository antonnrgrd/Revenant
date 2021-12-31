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

/*
#include "dialogue.h"

void point(){
  printf("Does code reach here? \n");
}

Dialogue_Header *d_init_dialogue_header(int ssize, char *greeting){
  Dialogue_Header *header = malloc(sizeof(Dialogue_Header));
  header->size = ssize;
  header->chat = malloc( ssize * sizeof(Dialogue *));
  header->greeting_dialogue = s_create_text(greeting);
  //  point();
  return header;
}
void d_display_dialogue(Dialogue *d){
  int j = 1;
  for(int i = 0; i < d->counter; i++){
    printf("%d%s%s%s", j,". ", d->dialogue_options[i]->option, "\n");
    printf("%s%s", d->dialogue_options[i]->response, "\n");
    j++;
  }
}


void d_assign_dialogue(Dialogue_Header *header, int offset,uint8_t options, char *option, char *response, int ending){
  //  point();
  header->chat[offset] = malloc(sizeof(Dialogue));
  header->chat[offset]->option_count = options;
  header->chat[offset]->dialogue_options = malloc(options * sizeof(Dialogue *) );
  header->chat[offset]->option = s_create_text(option);
  header->chat[offset]->response = s_create_text(response);
  header->chat[offset]->counter = 0;
  header->chat[offset]->ending = ending;
  header->chat[offset]->id = offset;
  //printf("%d%d%s",header->chat[offset]->id,header->chat[offset]->ending, "\n");
}

void d_destroy_dialogue_sequence(Dialogue_Header *header){
  for(int i = 0; i < header->size; i++){
    free(header->chat[i]->option);
    free(header->chat[i]->response);
    free(header->chat[i]->dialogue_options);
    free(header->chat[i]);
  }
  free(header->chat);
  free(header->greeting_dialogue);
  free(header);
}

void d_dialogue_loop(Dialogue_Header *header){
  printf("%s%s", header->greeting_dialogue, "\n");
  Dialogue *cur = header->chat[0];
  d_display_dialogue(cur);
  int i = 0;
 LOOP:do{
    int choice;
    scanf("%d", &choice);
    //    printf("%s%d%s","You chose ", choice , "\n");
    //printf("%s", "does code reach here?");
    if(choice > 0 && choice  <= cur->option_count+1){
      // printf("%d%s", cur->dialogue_options[choice]->ending, "\n");
      if((cur->dialogue_options[choice-1]->ending) == 1){
	i=1;
	//	printf("%s", "End of chat, deleting code");
	//	printf("%s", "deleting code");
	d_destroy_dialogue_sequence(header);
	return;
      }
      else{
	//printf("%d%s",cur->dialogue_options[choice]->ending,"\n" );
      printf("%s%s", cur->dialogue_options[choice-1]->response, "\n");
      cur = cur->dialogue_options[choice-1];
      d_display_dialogue(cur);
     }
      //printf("%s", "does code reach here?");
      goto LOOP;
    }
  }while(i != 1);
  printf("%s", "does code reach here?");
  d_destroy_dialogue_sequence(header);
  } 



 */

//void d_add_dialogue(Dialogue_Header *header, int parent, int child){
  //Dialogue *p = header->chat[parent];
  // Dialogue *c = header->chat[child];
  // p->dialogue_options[p->counter]=c;
   // p->counter++;
  //  d_display_dialogue(p);
  // printf("%s%d%s%d%s","Added ",header->chat[child]->id, " to ", header->chat[parent]->id, "\n");
  // Dialogue *cur = p->dialogue_options[p->counter];
   // char *str = cur->response;
   // printf("%s%s", str,"\n"); */
   //   printf("%s%d%s%d%s","Added ",header->chat[child]->id, " has ",p->dialogue_options[p->counter]->id , " as response\n");
  
     //}


