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
#ifndef STATUS
#define STATUS
#include "bit_macros.h"
#include "game_state_struct.h"
#include "creature.h"
#define DEAD 0
#define PARALYZED 1
#define POISONED  2
#define BLEEDING 3
#define FROZEN 4
#define ST_RESET_DEBUFFS(creature)for(int i = 0; i < 10; i++){  creature->status_flags = creature->status_flags & (~(1<< i)); }
#define ST_STATUS_OK(creature)({int ok = 0; for(int i = 0; i < 10; i++){ nth_status_bit =  (creature->status_flags >> i) & 1; ok | nth_status_bit; } ok;})
#define ST_CHECK_FLAG_SET(creature, position)creature->status_flags & (1<<(position))
#define ST_SET_FLAG_BIT(creature, position)creature->status_flags << (position - 1)
void st_status_handler_player(Creature *c);
void st_apply_statuses(Creature *c);
void st_handle_status_dead(Creature *c,Game_State *game_state);
#endif

