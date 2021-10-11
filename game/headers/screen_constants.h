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
#ifndef SCREEN_CONSTANTS
#define SCREEN_CONSTANTS
#define Y 121
#define N 110
#define A 97
#define S 115
#define DEFAULT_MAX_X 80
#define DEFAULT_MAX_Y 24
#define DEFAULT_MIN_Y 0
#define DEFAULT_MAX_INFOBAR_WIDTH 13
#define LOG_EVENT(msg) for(int i = DEFAULT_MAX_Y; i < DEFAULT_MAX_Y+10; i++) long int msg = winchnstr(stdscr, i,2,35); move(i,2); clrtoeol(); (for int j = i; j < DEFAULT_MAX_Y+10; j++) mvprintw(j,2,msg);
#endif
