/*This file is part of Revnant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar.  If not, see <https://www.gnu.org/licenses/>. */


#ifndef DIALOGUE
#define DIALOGUE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include "strings.h"




typedef struct Dialogue{
  uint8_t option_count; //how many neighbour options there are
  uint8_t counter;//a helper variable so that we know which current point we assign dialogue to
  char *option;
  char *response;
  int ending;
  uint16_t id; //just an id that helps me identify
  struct Dialogue **dialogue_options;
}Dialogue;

typedef struct Dialogue_Header{
  int size;
  int current_pointer;
  char *greeting_dialogue;
  Dialogue **chat;
} Dialogue_Header;

Dialogue_Header *d_init_dialogue_header(int ssize, char *greeting);
void d_add_dialogue(Dialogue_Header *header, int parent, int child);
char *d_create_text(char *arg);

void d_assign_dialogue(Dialogue_Header *header, int offset,uint8_t options, char *option, char *response, int ending);

void d_destroy_dialogue_sequence(Dialogue_Header *header);

void d_dialogue_loop(Dialogue_Header *header);

void d_display_dialogue(Dialogue *d);
#endif

