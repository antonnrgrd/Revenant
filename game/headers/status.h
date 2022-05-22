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
#define ST_SET_NTH_BIT
#define ST_RESET_DEBUFFS(creature)for(int i = 0; i < 10; i++){  creature->debuff_flags = creature->debuff_flags & (~(1<< i)); }
#define ST_STATUS_OK(creature)({int ok = 0; for(int i = 0; i < 10; i++){ nth_status_bit =  (creature->debuff_flags >> i) & 1; ok | nth_status_bit; } ok;})
#endif
