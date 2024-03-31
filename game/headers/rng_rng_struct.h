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
#ifndef RNG_STRUCT
#define RNG_STRUCT
#include <stdlib.h>
#include <time.h>
#define NUM_DEFINED_REAGENTS 2
#define NUM_DEFINED_CONSUMABLES 1
#define NUM_DEFINED_EQUIPMENT_TYPES 10
/*An implementation of a 32-bit mersienne twister. It will work on 64+ bit systems however, it only guarantees 32 bits of randomness, so pseudo-randomness is probably worse on 32+ bit systems*/
#define W 32
/*The official notation in the description of the twiser stipulates a value represented by a N and C character. However, sqlite3 already used these symbols as macros, causing compiler confusion. The solution? replace it with NN and CC as the values instead*/
#define NN 624
#define M 397
#define R 31
#define A 0x9908B0DF
#define U 11
#define D 0xFFFFFFFF
#define S 7
#define B 0x9D2C5680
#define T 15
#define CC 0xEFC60000
#define L 18
#define F 1812433253

typedef struct{
  int *mt;
  int index;
  int lower_mask;
  int upper_mask;
}Rng_Mersienne_Twister;

#endif
