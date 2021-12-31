/*This file is part of Revenant.
cRevenant is free software: you can redistribute it and/or modify
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
// basically a crap ton of macros, intended to replace indices to avoid using magic numbers 
#define ANIMAL 0
#include "screen_constants.h"
#define WITHIN_BOUNDS 1
#define OUT_OF_BOUNDS 0
//Note to self: these cases SHOULD also work when y or x coordinates are equal since then MAX == MIN and then local coord + ( max - min ) -> within bounds -> creature gets drawn on map 

#define SET_TO_MIN_X(player)(player->position.global_x - (player->position.local_x - DEFAULT_MAX_INFOBAR_WIDTH))
#define SET_TO_MAX_X(player)(player->position.global_x + (DEFAULT_MAX_X - player->position.local_x))

#define SET_TO_MIN_Y(player)(player->position.global_y - (player->position.local_y - DEFAULT_MIN_Y))
#define SET_TO_MAX_Y(player)(player->position.global_y + (DEFAULT_MAX_Y - player->position.local_y))


#define GET_MAX_CREATURE_Y(first_creature, second_creature)(first_creature->position.global_y > second_creature->position.global_y) ? first_creature->position.global_y : second_creature->position.global_y
#define GET_MAX_CREATURE_X(first_creature, second_creature)(first_creature->position.global_x > second_creature->position.global_x) ? first_creature->position.global_x : second_creature->position.global_x

#define GET_MIN_CREATURE_Y(first_creature, second_creature)(first_creature->position.global_y < second_creature->position.global_y) ? first_creature->position.global_y : second_creature->position.global_y
#define GET_MIN_CREATURE_X(first_creature, second_creature)(first_creature->position.global_x < second_creature->position.global_x) ? first_creature->position.global_x : second_creature->position.global_x

#define GET_MIN_CREATURE_LOCAL_X(first_creature, second_creature)(first_creature->position.global_x < second_creature->position.global_x) ? first_creature->position.local_x : second_creature->position.local_x
#define GET_MIN_CREATURE_LOCAL_Y(first_creature, second_creature)(first_creature->position.global_y < second_creature->position.global_y) ? first_creature->position.local_y : second_creature->position.local_y

#define WITHIN_X_BOUNDS(creature, player)(creature->position.global_x > player->position.global_x ? player->position.local_x + creature->position.global_x-player->position.global_x < DEFAULT_MAX_X ? WITHIN_BOUNDS : OUT_OF_BOUNDS : creature->position.local_x + player->position.global_x-creature->position.global_x < DEFAULT_MAX_X ? WITHIN_BOUNDS : OUT_OF_BOUNDS )
#define WITHIN_Y_BOUNDS(creature, player)(creature->position.global_y > player->position.global_y ? player->position.local_y + creature->position.global_y-player->position.global_y < DEFAULT_MAX_Y ? WITHIN_BOUNDS : OUT_OF_BOUNDS : creature->position.local_y + player->position.global_y-creature->position.global_y < DEFAULT_MAX_Y ? WITHIN_BOUNDS : OUT_OF_BOUNDS) 

// This is basically a relic of my attempt at assigning the local coordinates to the creatures with a macro that uses the ternary operator. I still kept it around as a reminder for me about the limitations of nested ternary operators


//#define COMPUTE_RELATIVE_X_COORDS(creature,player)(creature->position.global_x > player->position.global_x) ? (player->position.local_x + (creature->position.global_x - player->position.global_x)) <= DEFAULT_MAX_X-1 ? (creature->position.local_x = (player->position.local_x + (creature->position.global_x - player->position.global_x))); : (creature->position.local_x =  DEFAULT_MAX_INFOBAR_WIDTH + ((creature->position.global_x - SET_TO_MIN_X(player)) % ((DEFAULT_MAX_X - DEFAULT_MAX_INFOBAR_WIDTH) + 1))); : (player->position.local_x - (player->position.global_x - creature->position.global_x)) >= DEFAULT_MAX_INFOBAR_WIDTH ? (creature->position.local_x = player->position.local_x - (player->position.global_x - creature->position.global_x)); : (creature->position.local_x = ((DEFAULT_MAX_X -1) - (((SET_TO_MAX_X(player)) - creature->position.global_x ) % ((DEFAULT_MAX_X - DEFAULT_MAX_INFOBAR_WIDTH) + 1)))); 

//#define COMPUTE_RELATIVE_Y_COORDS(creature,player)(creature->position.global_y > player->position.global_y ? ((player->position.local_y + (creature->position.global_y - player->position.global_y )) <= DEFAULT_MAX_Y - 1 ? creature->position.local_y = (creature->position.local_y - player->position.local_y) : creature->position.local_y = DEFAULT_MIN_Y + ((creature->position.global_y - SET_TO_MIN_Y(player) ) % ((DEFAULT_MAX_Y - DEFAULT_MIN_Y)+1)) ) : player->position.local_y - (player->position.global_y - creature->position.global_y) >= DEFAULT_MIN_Y ? creature->position.local_y = player->position.local_y - (player->position.global_y - creature->position.global_y) : creature->position.local_y = (DEFAULT_MAX_Y-1) -  ((SET_TO_MAX_Y(player) - creature->position.global_y ) % ((DEFAULT_MAX_Y - DEFAULT_MIN_Y)+1))

//#define COMPUTE_RELATIVE_COORDS(creature,player)COMPUTE_RELATIVE_X_COORDS(creature,player)COMPUTE_RELATIVE_Y_COORDS(creature,player)

#endif

