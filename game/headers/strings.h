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
#include <stdarg.h>
#define EMPTY_STR_RANGE 32
#define STR_SLICE(string)({char *val_as_str = strchr(string,"=")+1; val_as_str;})

char *s_create_text(char *arg);
char *s_create_text_const( const char *arg);
char *s_merge_text(char *first_arg,char *second_arg);
uint64_t s_uint_from_string(int argcount, ...);
int s_only_whitespace(char *bfr);
int s_char_count(char *string, char *character);
#endif

