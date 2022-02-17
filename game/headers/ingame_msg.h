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
#include "game_state_struct.h"
#include "strings.h"
#define MAX_MSG_LENGTH 50

// In order to make changes to a panel visible, we firstly need to call update panel to make the changes to the panels visible, then make doupdate to make said changes ivisible to the physical screen. To avoid having to call these methods all the time, we wrap them inside a macro
#define UPDATE_PANEL_INFO() update_panels(); doupdate();



void msg_show_log(Game_State *gs, int panel_index);

//We only bother moving down the first 9 messages because the we intend only to have the last 10 actions available in the log so we delete the last message(the one to be "pushed" out of the "stack") 

//We malloc a message buffer of type (chtype * MAX_MSG_LENGTH) as mvwinchnstr needs a sufficiently big enough buffer to store the copied string to and 50 is the guessed biggest possible length we will need. chtype is a special datatype used by ncurses a type of string, if you will.

int msg_find_log_position(Game_State *gs);



#define UPDATE_ADD_TO_LOG(game_state,position,msg_bfr)wmove(game_state->logs[MAIN_SCREEN],DEFAULT_MAX_Y,0); mvwinnstr(game_state->logs[MAIN_SCREEN], DEFAULT_MAX_Y,0,msg_bfr,MAX_MSG_LENGTH-1); wclrtoeol(game_state->logs[MAIN_SCREEN]); mvwprintw(game_state->logs[EVENT_LOG],free_log_position,12, msg_bfr); free(msg_bfr);  


#define UPDATE_PUSH_ADD_TO_LOG(game_state,msg_bfr)wmove(game_state->logs[MAIN_SCREEN],DEFAULT_MAX_Y,0); mvwinnstr(game_state->logs[MAIN_SCREEN], DEFAULT_MAX_Y,0,msg_bfr,MAX_MSG_LENGTH-1);wclrtoeol(game_state->logs[MAIN_SCREEN]); mvwprintw(game_state->logs[EVENT_LOG],15,20, msg_bfr); wmove(game_state->logs[EVENT_LOG],13,0); wclrtoeol(game_state->logs[EVENT_LOG]); for(int i = 13; i > 2; i--){ mvwinnstr(game_state->logs[EVENT_LOG], i,12,msg_bfr,MAX_MSG_LENGTH-1); mvprintw(game_state->logs[EVENT_LOG], i+1,12,msg_bfr); wmove(game_state->logs[EVENT_LOG],i,12); wclrtoeol(game_state->logs[EVENT_LOG]); }  free(msg_bfr); 



void msg_update_event_log(Game_State *gs);

//     



#define WRITE_TO_LOG(log_index)

#define INIT_EVENT_LOG(window) mvwprintw(window,1,25, "PAST 10 EVENTS" ); char number[] = "1."; for(int i = 3; i < 13; i++){ number[0] = (i-2) + '0'; mvwprintw(window,i,10,number ); } mvwprintw(window,12,10, "10.");
#endif

