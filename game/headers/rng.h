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
#ifndef RNG
#define RNG
#include <stdlib.h>
#include <time.h>
#define NUM_DEFINED_REAGENTS 2
#define NUM_DEFINED_CONSUMABLES 1
#define NUM_DEFINED_EQUIPMENT_TYPES 10
/*An implementation of a 32-bit mersienne twister. It will work on 64+ bit systems however, it only guarantees 32 bits of randomness, so pseudo-randomness is probably worse on 32+ bit systems*/
#define W 32
#define N 624
#define M 397
#define R 31
#define A 0x9908B0DF
#define U 11
#define D 0xFFFFFFFF
#define S 7
#define B 0x9D2C5680
#define T 15
#define C 0xEFC60000
#define L 18
#define F 1812433253
/* Imitates die rolls, using the mersenne twister under the hood*. Arguement for upper value range is given as  limit+1 since the function for ensuring the value is in the given range
is [min,max( and therefore use max+1 to ensure that we could also potentially generate the max value */
#define GEN_VALUE_RANGE(lower,upper,twister)(rng_extract_number(twister) % (upper-lower) + lower)
#define D4(twister)GEN_VALUE_RANGE(1,4+1,twister)
#define D3(twister)GEN_VALUE_RANGE(1,3+1,twister)
#define D2(twister)GEN_VALUE_RANGE(1,2+1,twister)
#define D2_0(twister)GEN_VALUE_RANGE(0,1+1,twister)
#define D20(twister)GEN_VALUE_RANGE(1,20+1,twister)
#define D100(twister)GEN_VALUE_RANGE(1,100+1,twister)
#define D10(twister)GEN_VALUE_RANGE(1,10+1,twister)
#define D6(twister)GEN_VALUE_RANGE(1,6+1,twister)
#define D8(twister)GEN_VALUE_RANGE(1,8+1,twister)
#define D8_0(twister)GEN_VALUE_RANGE(0,8+1,twister)
#define D_GENERIC(lower,upper,twister)GEN_VALUE_RANGE(lower, upper+1,twister)
typedef struct{
  int *mt;
  int index;
  int lower_mask;
  int upper_mask;
}Mersienne_Twister;

void rng_seed_mt(int seed, Mersienne_Twister *twister);

int rng_extract_number(Mersienne_Twister *twister);

void rng_twist(Mersienne_Twister *twister);

Mersienne_Twister *rng_generate_twister();
#endif
