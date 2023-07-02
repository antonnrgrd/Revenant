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
#ifndef GENERIC_MACROS
#define GENERIC_MACROS
#include <stdlib.h>
#define YES 0
#define NO 1
#define END_TURN 0
#define CONTINUE_TURN 1
#define FREE_NULL(ptr) free(ptr); (ptr) = NULL
#define MAX(num_1, num_2) num_1 > num_2 ? num_1 : num_2
#define MIN(num_1, num_2) num_1 < num_2 ? num_1 : num_2
#define LF 10
#endif
