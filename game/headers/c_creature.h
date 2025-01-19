/*This file is part of Revenant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */


#ifndef CREATURE
#define CREATURE
#include "c_creature_struct.h"
extern void (*c_free_creature_body_type[1])(C_Creature *c);
void c_free_animal(C_Creature *c);



C_Creature *c_generate_creature(C_Creature_Kind kind, int id,unsigned x,unsigned y,Game_World *world,C_Creature *target);



void c_initialize_humanoid_inf(C_Creature *c, int id);


C_Color *c_copy_color(C_Color color);

C_Creature *c_random_player(int y, int x ,Game_State *gs, Game_World *gw);

void c_compute_relative_coords(C_Creature *creature, C_Creature *player);

void c_cleanup_creature(C_Creature *c,Game_World *world);

char  *c_retrieve_creature_name(C_Creature *c);

void c_free_player_info(C_Player_Info *player_info);
#endif
