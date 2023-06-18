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
#include "generic_macros.h"
#include "u_hash.h"
#include "game_state.h"
#include "information_reader.h"
#include "item.h"
#include "generate.h"
#include "move_handler.h"

#define INITIATED_EXCHANGE 0
#define NOT_INITIATED_EXCHANGE 1
#define EXESSIVE_ADDITIONAL_WEIGHT 2
#define INSUFFICIENT_CASH 3
#define INVALID_VALUE 4

//screen, y,x, "%s X %d", quality_name_modifier[((union Equipment)item_holder->item->item_specific_info).weapon->quality]


extern inline void msg_print_item(Item_Holder *item_holder, WINDOW *screen, int x, int y);
static inline void msg_pickup_item(Game_State *game_state, Item_Holder *item_holder);
// In order to make changes to a panel visible, we firstly need to call update panel to make the changes to the panels visible, then make doupdate to make said changes ivisible to the physical screen. To avoid having to call these methods all the time, we wrap them inside a macro
#define UPDATE_PANEL_INFO() update_panels(); doupdate();


//MSG_MOVE_TO_NEW_POS(item_list, init_free_pos, max_index, log)
/* We stop at second last index because we set pointers to null and if we include the last index, we attempt to print the item at the last index, which is null, causing seg fault*/
#define MSG_COMPRESS_ITEM_LIST(item_list, init_free_pos, max_index, log) for(int i = init_free_pos; i < max_index-1; i++ ){ item_list[i] = item_list[i+1]; wmove(log,i+2,5); wclrtoeol(log);  msg_print_item(item_list[i],log,5,i+2); } /* item_list[max_index-1] = NULL; */ wmove(log,max_index-1+2,5); wclrtoeol(log); box(gs->logs[INVENTORY_LOG],0,0); wmove(log,init_free_pos+2,5); UPDATE_PANEL_INFO();

int msg_show_log(Game_State *gs, int panel_index);

//We only bother moving down the first 9 messages because the we intend only to have the last 10 actions available in the log so we delete the last message(the one to be "pushed" out of the "stack") 

//We malloc a message buffer of type (chtype * MAX_MSG_LENGTH) as mvwinchnstr needs a sufficiently big enough buffer to store the copied string to and 50 is the guessed biggest possible length we will need. chtype is a special datatype used by ncurses a type of string, if you will.

int msg_find_log_position(Game_State *gs);

int msg_find_item_position(WINDOW *log, int max_y,Item_Holder *item, Item_Holder **item_list);



#define UPDATE_ADD_TO_LOG(game_state,position,offset) strcpy(gs->ingame_log[position-2],gs->current_event); mvwprintw(game_state->logs[EVENT_LOG],position+1,offset, gs->current_event); 


#define UPDATE_PUSH_ADD_TO_LOG(game_state) wmove(game_state->logs[EVENT_LOG],12,14); wclrtoeol(game_state->logs[EVENT_LOG]);  strcpy(game_state->ingame_log[9], game_state->ingame_log[8]); mvwprintw(game_state->logs[EVENT_LOG],12,14, game_state->ingame_log[9]); for(int i = 8; i > 0; i--){ wmove(game_state->logs[EVENT_LOG],i+3,12); wclrtoeol(game_state->logs[EVENT_LOG]); strcpy(game_state->ingame_log[i], game_state->ingame_log[i-1]); mvwprintw(game_state->logs[EVENT_LOG],i+3,12, game_state->ingame_log[i]); } wmove(game_state->logs[EVENT_LOG],3,12); wclrtoeol(game_state->logs[EVENT_LOG]); strcpy(game_state->ingame_log[0], game_state->current_event); mvwprintw(game_state->logs[EVENT_LOG],3,12, game_state->ingame_log[0]);

#define MSG_PRINT_DAMAGE_CREATURE(screen,creature_id,damage) char *file_path_bfr = malloc(sizeof(char) * strlen("/usr/lib/revenant_files/creature_files/") +5); sprintf(file_path_bfr,"/usr/lib/revenant_files/creature_files/%d",creature_id); char *name;  ir_readin_char(file_path_bfr, "name",name); mvwprintw(game_state->logs[MAIN_SCREEN],DEFAULT_MAX_Y,0, "%s%s%s%d%s", "You damage ", name , " for ", 10, " damage"); free(file_path_bfr); free(name);





void msg_update_event_log(Game_State *gs);

//     

#define CLEAR_MSG_LINE() wmove(game_state->logs[MAIN_SCREEN],DEFAULT_MAX_Y,0); wclrtoeol(game_state->logs[MAIN_SCREEN]);

#define WRITE_TO_LOG(log_index)

#define INIT_EVENT_LOG(window) mvwprintw(window,1,25, "PAST 10 EVENTS" ); char number[] = "1."; for(int i = 3; i < 13; i++){ number[0] = (i-2) + '0'; mvwprintw(window,i,10,number ); } mvwprintw(window,12,10, "10.");
//For some reason, you have to specify the arguments in this order, in order to print them correctly
//To the screen. Perhaps because it's a maxture of static and dynamic strings
#define INIT_INVENTORY_LOG(window, inv_msg) mvwprintw(window,1,25, inv_msg );

int msg_display_inventory(Game_State *gs,int context, U_Hashtable *merchant);

int msg_display_inventory_equip_context(Game_State *gs);

int msg_display_equipped_equipment(Game_State *gs);

/*ncurses has built-in functionality for clearing */
#define MSG_CLEAR_SCREEN(window)werase(window); box(window,0,0);
//We print i+2 to print at the desired position in the equipment log
#define MSG_REDRAW_INVENTORY(available_equipment,num_items,window) MSG_CLEAR_SCREEN(window); INIT_INVENTORY_LOG(gs->logs[INVENTORY_LOG], "Available equipment");  for(int i = 0; i < num_items; i++){msg_print_item(available_equipment[i],gs->logs[INVENTORY_LOG],5,i+2);}


#define MSG_ENABLE_SCROLLING(window) scrollok(window, TRUE); idlok(window, TRUE);

#define MSG_ITEM_PICKUP_NONEQUIPPABLE(game_state, item_holder) char *name /* = i_derive_item_name(item_holder->item); mvwprintw(game_state->logs[MAIN_SCREEN],0,0, "%s%s%s%d%s", "Pickup ", name , " amount: ", item_holder->amount, " ? [y/n/a/d]"); free(name);
									     #define MSG_ITEM_PICKUP_WEAPON(game_state, item_holder) mvwprintw(game_state->logs[MAIN_SCREEN],0,0, "%s%s%s%s%s%s%d%s", "Pickup ",quality_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->quality], material_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->material],handed_modifier[((struct Weapon *)item_holder->item->item_specific_info)->variant],mele_weapon_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->kind] , " amount: ", item_holder->amount, " ? [y/n/a/d]")*/

#define MSG_ITEM_PICKUP_ARMOR(game_state, item_holder)mvwprintw(game_state->logs[MAIN_SCREEN],0,0, "%s%s%s%s%s%d%s", "Pickup ",quality_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->quality], material_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->material],equipment_kind_modifier[((struct Armor *)item_holder->item->item_specific_info)->armor_type], " amount: ", item_holder->amount, " ? [y/n/a/d]")

#define MSG_ITEM_PICKUP_EQUIPPABLE(game_state, item_holder) item_holder->item->kind == weapon ? MSG_ITEM_PICKUP_WEAPON(game_state, item_holder):MSG_ITEM_PICKUP_ARMOR(game_state, item_holder)
#define MSG_ITEM_PICKUP(game_state, item_holder) /* item_holder->item->kind == weapon || item_holder->item->kind == armor ? MSG_ITEM_PICKUP_EQUIPPABLE(game_state,item_holder): */ MSG_ITEM_PICKUP_NONEQUIPPABLE(game_state,item_holder)
int msg_trading_session(int global_x, int global_y,Game_State *gs);

void msg_redraw_inventory(Game_State *gs, Item_Holder **item_list, int context, int num_items);
void msg_redraw_equipped_equipment(Game_State *gs);
void msg_redraw_inventory_equip_context(Game_State *gs, Item_Holder **item_list, int num_items, int curs_pos);

#define MSG_ADD_EQUIP_EVENT_TO_LOG(item_holder, gs) item_holder->item->kind == armor ? sprintf(gs->current_event, "You equip %s %s %s",quality_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->quality], material_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->material], equipment_type_modifier[((struct Armor *)item_holder->item->item_specific_info)->armor_type]), msg_update_event_log(gs) : sprintf(gs->current_event, "You equip %s%s%s%s",quality_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->quality], handed_modifier[((struct Weapon *)item_holder->item->item_specific_info)->variant] ,material_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->material] , mele_weapon_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->kind]), msg_update_event_log(gs)

#define MSG_ADD_ATTACK_OPPONENT_EVENT_TO_LOG(creature, gs)ir_add_damage_to_creature_to_log(gs, gs->player, creature);  msg_update_event_log(gs);

#define MSG_ADD_CREATURE_ATTACK_EVENT_TO_LOG(creature,target, gs)ir_add_damage_to_creature_to_log(gs,creature,target);  msg_update_event_log(gs);

#define MSG_ADD_PURCHASE_TO_EVENT_LOG(item,gs,amount) ir_add_item_purchase_to_log(gs,item,amount); msg_update_event_log(gs);
void msg_add_attack_event_to_log(Item_Holder *item_holder);

void msg_add_attack_player_event_to_log();

void msg_redraw_log(Game_State *gs);
#define MSG_SETUP_NOTIFICATION_LOG(gs, log_index, interaction_enabled, msg)  MSG_CLEAR_SCREEN(gs->logs[log_index]); mvwprintw(gs->logs[log_index],1,gs->notification_log_width_size/4, msg); top_panel(gs->panels[log_index]); UPDATE_PANEL_INFO(); interaction_enabled == YES ? curs_set(TRUE) :curs_set(FALSE)

#define MSG_PUT_DOWN_NOTIFICATION_LOG(gs, log_index) hide_panel(gs->panels[log_index]); UPDATE_PANEL_INFO();

void msg_redraw_trading_session(Game_State *gs,Item_Holder **item_list,int num_items, int event_flag, char amount_bfr[5]);
#endif

