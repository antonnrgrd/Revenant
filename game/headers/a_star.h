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
#ifndef A_STAR
#define A_STAR
#include "skew_heap.h"
#include "placeholder.h"
#define CURRENT_POS 0
#define MV_UP 1
#define MV_DOWN 2
#define MV_L 3
#define MV_R 4

/* We save the path as a sequences of moves to make in order to reach goal (e.g up, left, down, down etc.) to save memory */
typedef struct Path{
  int pathlength;
  short *moves;
}Path;

Path *reconstruct_path();

Path *a_star(Position start, Position destination);
#endif
