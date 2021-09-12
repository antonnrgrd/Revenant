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

#ifndef CREATURE_MACROS
#define CREATUE_MACROS
/* basically a crap ton of macros, intended to replace indices to avoid using magic numbers */
#define ANIMAL 0
/*Note to self: these cases SHOULD also work when y or x coordinates are equal since then MAX == MIN and then local coord + ( max - min ) -> within bounds -> creature gets drawn on map */
#define GET_MAX_CREATURE_Y(first_creature, second_creature)(first_creature->position.global_y > second_creature->position.global_y) ? first_creature->position.global_y : second_creature->position.global_y
#define GET_MAX_CREATURE_X(first_creature, second_creature)(first_creature->position.global_x > second_creature->position.global_x) ? first_creature->position.global_x : second_creature->position.global_x

#define GET_MIN_CREATURE_Y(first_creature, second_creature)(first_creature->position.global_y < second_creature->position.global_y) ? first_creature->position.global_y : second_creature->position.global_y
#define GET_MIN_CREATURE_X(first_creature, second_creature)(first_creature->position.global_x < second_creature->position.global_x) ? first_creature->position.global_x : second_creature->position.global_x

#define GET_MIN_CREATURE_LOCAL_X(first_creature, second_creature)(first_creature->position.global_x < second_creature->position.global_x) ? first_creature->position.local_x : second_creature->position.local_x
#define GET_MIN_CREATURE_LOCAL_Y(first_creature, second_creature)(first_creature->position.global_y < second_creature->position.global_y) ? first_creature->position.local_y : second_creature->position.local_y



#endif
