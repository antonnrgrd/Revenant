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
#define ALREADY_LISTED -2
#include "screen_constants.h"
#include <ncurses.h>
#include <panel.h>
#include "game_state_struct.h"
#include "strings.h"
//screen, y,x, "%s X %d", quality_name_modifier[((union Equipment)item_holder->item->item_specific_info).weapon->quality]
#define MAX_MSG_LENGTH 50
#define PRINT_ITEM_WEAPON(item_holder,screen,x,y)item_holder->amount != 1 ? mvwprintw(screen, y,x, "%s%s%s%s%s%d", quality_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->quality],handed_modifier[((struct Weapon *)item_holder->item->item_specific_info)->variant],material_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->material], mele_weapon_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->kind], " X ", item_holder->amount) : mvwprintw(screen, y,x, "%s%s%s%s", quality_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->quality],handed_modifier[((struct Weapon *)item_holder->item->item_specific_info)->variant],material_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->material], mele_weapon_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->kind])

#define PRINT_ITEM_ARMOR(item_holder,screen,x,y)item_holder->amount != 1 ? mvwprintw(screen, y,x, "%s%s%s%s%d", quality_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->quality],material_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->material], armorslot_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->armor_type], " X ", item_holder->amount) : mvwprintw(screen, y,x, "%s%s%s", quality_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->quality],material_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->material],  armorslot_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->armor_type])

#define PRINT_ITEM_NONEQUIPPABLE(item_holder,screen,x,y)item_holder->amount != 1 ? mvwprintw(screen, y,x, "%s%s%d", i_derive_item_name[item_holder->item->kind], " X ", item_holder->amount) : mvwprintw(screen, y,x, "%s", i_derive_item_name[item_holder->item->kind])
#define PRINT_ITEM_EQUIPPABLE(item_holder,screen,x,y) item_holder->item->kind == weapon ? PRINT_ITEM_WEAPON(item_holder,screen,x,y) : PRINT_ITEM_ARMOR(item_holder,screen,x,y) 
#define PRINT_ITEM_NOT_NULL(item_holder,screen,x,y)item_holder->item->kind == weapon || item_holder->item->kind == armor ? PRINT_ITEM_EQUIPPABLE(item_holder,screen,x,y):PRINT_ITEM_NONEQUIPPABLE(item_holder,screen,x,y)
#define PRINT_ITEM_NULL(item_holder,screen,x,y)mvwprintw(screen, y,x,"None")
#define PRINT_ITEM(item_holder,screen,x,y) item_holder->item == NULL ?  PRINT_ITEM_NULL(item_holder,screen,x,y):PRINT_ITEM_NOT_NULL(item_holder,screen,x,y)
// In order to make changes to a panel visible, we firstly need to call update panel to make the changes to the panels visible, then make doupdate to make said changes ivisible to the physical screen. To avoid having to call these methods all the time, we wrap them inside a macro
#define UPDATE_PANEL_INFO() update_panels(); doupdate();


//MSG_MOVE_TO_NEW_POS(item_list, init_free_pos, max_index, log)
/* We stop at second last index because we set pointers to null and if we include the last index, we attempt to print the item at the last index, which is null, causing seg fault*/
#define MSG_COMPRESS_ITEM_LIST(item_list, init_free_pos, max_index, log) for(int i = init_free_pos; i < max_index-1; i++ ){ item_list[i] = item_list[i+1]; item_list[i+1] = NULL;  wmove(log,i+2,5); wclrtoeol(log);  PRINT_ITEM(item_list[i],log,5,i+2); } /* item_list[max_index-1] = NULL; */ wmove(log,max_index-1+2,5); wclrtoeol(log); box(gs->logs[INVENTORY_LOG],0,0); wmove(log,init_free_pos+2,5); UPDATE_PANEL_INFO();

void msg_show_log(Game_State *gs, int panel_index);

//We only bother moving down the first 9 messages because the we intend only to have the last 10 actions available in the log so we delete the last message(the one to be "pushed" out of the "stack") 

//We malloc a message buffer of type (chtype * MAX_MSG_LENGTH) as mvwinchnstr needs a sufficiently big enough buffer to store the copied string to and 50 is the guessed biggest possible length we will need. chtype is a special datatype used by ncurses a type of string, if you will.

int msg_find_log_position(Game_State *gs);

int msg_find_item_position(WINDOW *log, int max_y,Item_Holder *item, Item_Holder **item_list);



#define UPDATE_ADD_TO_LOG(game_state,position,msg_bfr,offset) mvwprintw(game_state->logs[EVENT_LOG],free_log_position,offset, msg_bfr); free(msg_bfr);  


#define UPDATE_PUSH_ADD_TO_LOG(game_state,msg_bfr) mvwprintw(game_state->logs[EVENT_LOG],13,14, msg_bfr); wmove(game_state->logs[EVENT_LOG],12,14); wclrtoeol(game_state->logs[EVENT_LOG]); mvwinnstr(game_state->logs[EVENT_LOG], 11,12,msg_bfr,MAX_MSG_LENGTH-1); mvwprintw(game_state->logs[EVENT_LOG],12,14, msg_bfr); for(int i = 11; i > 2; i--){ wmove(game_state->logs[EVENT_LOG],i,12); wclrtoeol(game_state->logs[EVENT_LOG]);  mvwinnstr(game_state->logs[EVENT_LOG], i-1,12,msg_bfr,MAX_MSG_LENGTH-1); mvwprintw(game_state->logs[EVENT_LOG],i,12, msg_bfr); } mvwinnstr(game_state->logs[EVENT_LOG], 13,14,msg_bfr,MAX_MSG_LENGTH-1); mvwprintw(game_state->logs[EVENT_LOG],3,12, msg_bfr); wmove(game_state->logs[EVENT_LOG],13,14); wclrtoeol(game_state->logs[EVENT_LOG]); free(msg_bfr);  

/*  mvwinnstr(game_state->logs[EVENT_LOG], i,12,msg_bfr,MAX_MSG_LENGTH-1); mvprintw(game_state->logs[EVENT_LOG], i+1,12,msg_bfr); wmove(game_state->logs[EVENT_LOG],i,12); wclrtoeol(game_state->logs[EVENT_LOG]); }  free(msg_bfr); */



void msg_update_event_log(Game_State *gs);

//     

#define CLEAR_MSG_LINE() wmove(game_state->logs[MAIN_SCREEN],DEFAULT_MAX_Y,0); wclrtoeol(game_state->logs[MAIN_SCREEN]);

#define WRITE_TO_LOG(log_index)

#define INIT_EVENT_LOG(window) mvwprintw(window,1,25, "PAST 10 EVENTS" ); char number[] = "1."; for(int i = 3; i < 13; i++){ number[0] = (i-2) + '0'; mvwprintw(window,i,10,number ); } mvwprintw(window,12,10, "10.");
//For some reason, you have to specify the arguments in this order, in order to print them correctly
//To the screen. Perhaps because it's a maxture of static and dynamic strings
#define INIT_INVENTORY_LOG(window, inv_name) mvwprintw(window,1,25,"%s" inv_name, "Items in " );

void msg_display_inventory(Game_State *gs);

void msg_display_inventory_equip_context(Game_State *gs);

void msg_display_equipped_equipment(Game_State *gs);

/*ncurses has built-in functionality for clearing */
#define MSG_CLEAR_SCREEN(window)werase(gs->logs[INVENTORY_LOG]); box(window,0,0);
//We print i+2 to print at the desired position in the equipment log
#define MSG_REDRAW_INVENTORY(available_equipment,num_items,window) MSG_CLEAR_SCREEN(window); for(int i = 0; i < num_items; i++){PRINT_ITEM(available_equipment[i],gs->logs[INVENTORY_LOG],5,i+2);}
#endif

