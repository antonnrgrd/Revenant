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
#ifndef MSG
#define MSG
#include "screen_constants.h"
#include <ncurses.h>
#include <panel.h>
#define MAX_MSG_LENGTH 50

/* We basically need a macro to clear a certain part of the window to */
#define CLEAR_REGION(start_y, end_y, num_rows, window)for(int i = start_y; i < end_y+1; i++){for(int j = i; j < num_rows+1; j++){mvprintw(window,i,j, " ");}}
#define INIT_LOG_SCREEN(log) char *ordering = malloc(sizeof(char) * 2); strcpy(ordering,"1."); for(int i = 0; i < 10; i++){mvprintw(log,1,0); ordering[0] = (i+1)+'0';} free(ordering); 

void msg_show_status(PANEL *log);

/*We only bother moving down the first 9 messages because the we intend only to have the last 10 actions available in the log so we delete the last message(the one to be "pushed" out of the "stack") */

/*We malloc a message buffer of type (chtype * MAX_MSG_LENGTH) as mvwinchnstr needs a sufficiently big enough buffer to store the copied string to and 50 is the guessed biggest possible length we will need. chtype is a special datatype used by ncurses a type of string, if you will.*/

#define UPDATE_EVENT_LOG(log) char *msg_bfr = malloc(MAX_MSG_LENGTH * sizeof(char)); clrtoeol(); for(int i = DEFAULT_MAX_Y+9; i > DEFAULT_MAX_Y-1; i--){ mvwinnstr(stdscr, i,0,msg_bfr,MAX_MSG_LENGTH-1); move(i,0); clrtoeol(); mvprintw(log, i+1,0,msg_bfr); } free(msg_bfr);


#endif
