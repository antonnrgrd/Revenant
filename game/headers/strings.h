/*This file is part of Revnant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */

#ifndef STRINGS
#define STRINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>
#include <ctype.h>
#define PRINT_STRING(argument)		\
  argument[0] = argument[0]-32;		\
  printf("%s%s",argument ,"\n");	\

char *s_create_text(char *arg);
char *s_create_text_const( const char *arg);
char *s_merge_text(char *first_arg,char *second_arg);
uint64_t s_uint_from_string(char *string);
void tester_function(char *arg);

int s_only_whitespace(char *bfr);
#endif

