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
#include "rng.h"
void rng_seed_mt(int seed, Mersienne_Twister *twister){
  twister->index = NN;
  twister->mt[0] = seed;
  for(int i = 1; i < NN; i++ ){
    twister->mt[i] =   (int) ( ((unsigned int) (F * (twister->mt[i] ^ (twister->mt[i-1] >> (W-2))) + i))) & ~(0xFFFFFFFF << W);
  }
}

int rng_extract_number(Mersienne_Twister *twister){
  if(twister->index > NN){
  rng_twist(twister);
  }
  int y = twister->mt[twister->index];
  y = y ^ ((y >> U) & D);
  y = y ^ ((y << S) & B);
  y = y ^ ((y >> T) & CC);
  y = y ^ (y >> L);
  twister->index++;
  return (int) ( ((unsigned int) (y)) & ~(0xFFFFFFFF << W) ) ;
}

void rng_twist(Mersienne_Twister *twister){
  for (int i = 0; i < NN; i++){
    int x = (twister->mt[i] & twister->upper_mask) + (twister->mt[i+1 % NN] & twister->lower_mask) ;
    int xA = x >> 1;
    if(x % 2 != 0){
      xA = xA ^ A;
    }
    twister->mt[i] = twister->mt[(i + M) % NN] ^ xA;
  }
  twister->index = 0;
}

Mersienne_Twister *rng_generate_twister(){
  Mersienne_Twister *twister = malloc(sizeof(Mersienne_Twister));
  twister->mt =  malloc(NN * sizeof(int));
  twister->index = NN+1;
  twister->lower_mask = (1 << R) - 1;
  twister->upper_mask = (int) ( ((unsigned int) ~(twister->lower_mask)) & ~(0xFFFFFFFF << W) );
  srand(time(0));
  rng_seed_mt(rand(),twister);
  return twister;
}
  
