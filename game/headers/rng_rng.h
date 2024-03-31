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
#include "rng_rng_struct.h"
/* Imitates die rolls, using the mersenne twister under the hood*. Arguement for upper value range is given as  limit+1 since the function for ensuring the value is in the given range
is [min,max( and therefore use max+1 to ensure that we could also potentially generate the max value */
#define RNG_GEN_VALUE_RANGE(lower,upper,twister)(rng_extract_number(twister) % (upper-lower) + lower)
#define RNG_D4(twister)GEN_VALUE_RANGE(1,4+1,twister)
#define RNG_D3(twister)GEN_VALUE_RANGE(1,3+1,twister)
#define RNG_D2(twister)GEN_VALUE_RANGE(1,2+1,twister)
#define RNG_D2_0(twister)GEN_VALUE_RANGE(0,1+1,twister)
#define RNG_D20(twister)GEN_VALUE_RANGE(1,20+1,twister)
#define RNG_D100(twister)GEN_VALUE_RANGE(1,100+1,twister)
#define RNG_D10(twister)GEN_VALUE_RANGE(1,10+1,twister)
#define RNG_D6(twister)GEN_VALUE_RANGE(1,6+1,twister)
#define RNG_D8(twister)GEN_VALUE_RANGE(1,8+1,twister)
#define RNG_D8_0(twister)GEN_VALUE_RANGE(0,8+1,twister)
#define RNG_D_GENERIC(lower,upper,twister)GEN_VALUE_RANGE(lower, upper+1,twister)
void rng_seed_mt(int seed, Rng_Mersienne_Twister *twister);

int rng_extract_number(Rng_Mersienne_Twister *twister);

void rng_twist(Rng_Mersienne_Twister *twister);

Rng_Mersienne_Twister *rng_generate_twister();
#endif
