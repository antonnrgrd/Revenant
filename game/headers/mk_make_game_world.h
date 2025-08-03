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
#ifndef MK_GAME_WORLD
#define MK_GAME_WORLD
#include <sqlite3.h>
void mk_make_all_tables(sqlite3 *db);
void mk_populate_table_(sqlite3 *db);
void mk_make_database(sqlite3 *db);
#endif
