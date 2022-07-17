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
#ifndef BIT_MACROS
#define BIT_MACROS
CLEAR_BIT_ARRAY(bit_array)
SET_ITH_BIT(bit_array)
CLEAR_ITH_BIT(bit_array,offset) bit_array & ~(1 << offset);
ASSERT_ITH_BIT_SET(bit_array, offset)((num & (1 << i)) != 0);
#endif
