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


#include "ingame_msg.h"
#include "game_state.h"
void msg_show_log(Game_State *gs, int panel_index){
  top_panel(gs->panels[panel_index]);
  // We defer the refreshing of screen contents of the panels until
  // we actually want to see them, because if we refresh them immedately upon manipulating it conflicts
  //with the contents of the main screen. update_panels + doupdate does this for us so no need to call wfrefresh
  update_panels(); 
  doupdate();
  int ch;
  while (1){
    ch = getch();
    if (ch == 'q'){
      hide_panel(gs->panels[panel_index]);
      update_panels();
      doupdate();
      return;
    }
  }
}
    
int msg_find_log_position(Game_State *gs){
  char *line_contents = malloc(MAX_MSG_LENGTH * sizeof(char));
  for(int i = 3; i< 13; i++){
    //The position at which we check the screen contents could potentially fail
    //Due to the fact that the last position of the message log hhas 2 digits (see the update event log function for more info)
      mvwinnstr(gs->logs[EVENT_LOG], i,12,line_contents,MAX_MSG_LENGTH-1);
      //printf("%d%s", line_contents[0], " ");
      //      printf("%d",s_only_whitespace(line_contents));
      if(s_only_whitespace(line_contents) == 1){
	free(line_contents);
	return i;
      }
  }
  //printf("%s",line_contents);  
  free(line_contents);
  return -1;
}

int msg_find_item_position(WINDOW *log, int max_y, int x_pos, Item_Holder *item, Item_Holder **item_list){
char *line_contents = malloc(MAX_MSG_LENGTH * sizeof(char));
  for(int i = 2; i < max_y; i++){
    //The position at which we check the screen contents could potentially fail
    //Due to the fact that the last position of the message log hhas 2 digits (see the update event log function for more info)
    

      if( (HAS_SAME_NAME(item, item_list[i-2])) == 0){
     return ALREADY_LISTED;
      }
    
      mvwinnstr(log, i,x_pos,line_contents,MAX_MSG_LENGTH-1);
      //printf("%d%s", line_contents[0], " ");
      //      printf("%d",s_only_whitespace(line_contents));
      if(s_only_whitespace(line_contents) == 1){
	free(line_contents);
	return i;
      }
  }
  //printf("%s",line_contents);  
  free(line_contents);
  return -1;
}

void msg_update_event_log(Game_State *gs){
  char *msg_bfr = malloc(MAX_MSG_LENGTH * sizeof(char));
  mvwinnstr(gs->logs[MAIN_SCREEN], DEFAULT_MAX_Y,0,msg_bfr,MAX_MSG_LENGTH-1);
  int free_log_position = msg_find_log_position(gs);
  // printf("%s%s%d%s",msg_bfr, " ", free_log_position, " ");
  if(free_log_position != -1){
    if(free_log_position < 12){
      UPDATE_ADD_TO_LOG(gs,position,msg_bfr,12);
    }
    else{
      //We change the offset where print is, if the found y position is 13 because the offset position is 2 digits and so we counter that by increasing the offset
      UPDATE_ADD_TO_LOG(gs,position,msg_bfr,14);
    }
  }
  else{
    UPDATE_PUSH_ADD_TO_LOG(gs,msg_bfr);
   }
}
 
void msg_display_inventory(Game_State *gs){
  MSG_CLEAR_SCREEN(gs->logs[INVENTORY_LOG]);
  INIT_INVENTORY_LOG(gs->logs[INVENTORY_LOG], "inventory");
  int column_position = 2;
  for(int i = 0; i < ((U_Hashtable * )gs->player->additional_info)->size; i++ ){
    if(((U_Hashtable * )gs->player->additional_info)->entries[i] != NULL){
      Entry  *current_entry = ((U_Hashtable * )gs->player->additional_info)->entries[i];
      while(current_entry != NULL){
	PRINT_ITEM(current_entry->item_holder,gs->logs[INVENTORY_LOG],5,column_position);
        current_entry = current_entry->next_entry;
	column_position++;
      }
    }
  }
  
  top_panel(gs->panels[INVENTORY_LOG]);
  update_panels(); 
  doupdate();
  int ch;
  while (1){
    ch = getch();
    if (ch == 'q'){
      hide_panel(gs->panels[INVENTORY_LOG]);
      update_panels();
      doupdate();
      return;
    }
  }
} 

 
void msg_display_inventory_equip_context(Game_State *gs){
  int tmp_amount_holder;
  MSG_CLEAR_SCREEN(gs->logs[INVENTORY_LOG]);
  int curr_curs_pos = 2;
  int column_position = 2;
  int current_printed_item = 0;
  Item_Holder **item_list = malloc(sizeof(Item_Holder* ) * ((U_Hashtable * )gs->player->additional_info)->item_count);
  for(int i = 0; i < ((U_Hashtable * )gs->player->additional_info)->size; i++ ){
    if(((U_Hashtable * )gs->player->additional_info)->entries[i] != NULL){
      Entry  *current_entry = ((U_Hashtable * )gs->player->additional_info)->entries[i];
      while(current_entry != NULL){
	item_list[current_printed_item] =  current_entry->item_holder;
	if(current_entry->item_holder->item->kind == weapon || current_entry->item_holder->item->kind == armor ){
	PRINT_ITEM(current_entry->item_holder,gs->logs[INVENTORY_LOG],5,column_position);
        current_entry = current_entry->next_entry;
	column_position++;
	current_printed_item++;
       }
      }
    }
  }
  
  wmove(gs->logs[INVENTORY_LOG],curr_curs_pos,5);
  curs_set(TRUE);
  top_panel(gs->panels[INVENTORY_LOG]);
  update_panels(); 
  doupdate();
  int ch;
  while (1){
    ch = getch();
    if (ch == 'q'){
      free(item_list);
      curs_set(FALSE);
      hide_panel(gs->panels[INVENTORY_LOG]);
      update_panels();
      doupdate();
      return;
    }
    else if (ch == KEY_UP && curr_curs_pos > 2){
      curr_curs_pos--;

      wmove(gs->logs[INVENTORY_LOG],curr_curs_pos,5);
      update_panels();
      doupdate();
    }
    else if (ch == KEY_DOWN && curr_curs_pos < DEFAULT_MAX_Y - 2 ){
      curr_curs_pos++;
      wmove(gs->logs[INVENTORY_LOG],curr_curs_pos,5);
      update_panels();
      doupdate();
    }
    //probably faulty with how we assign item holder pointers to the item list
    else if (ch == 'y'){
      

     mvwprintw(gs->logs[MAIN_SCREEN],DEFAULT_MAX_Y,0, "%s", "You equip ");
     /*We temporarily set the amount of the item we equip to be one since
      item printer prints the amount of the item, unless the amount we have is 1
     and we do not want the amount printed, just the item's name*/
     tmp_amount_holder = item_list[curr_curs_pos-2]->amount;
     item_list[curr_curs_pos-2]->amount = 1;
     PRINT_ITEM(item_list[curr_curs_pos-2],gs->logs[MAIN_SCREEN],11,DEFAULT_MAX_Y);
     item_list[curr_curs_pos-2]->amount = tmp_amount_holder;
     
     msg_update_event_log(gs);
     UPDATE_PANEL_INFO();
     //we subtract 2 from curr_curs_pos to "map" from current cursor position to the actual postion of the item
      //in the item list. This is because the item list starts at index 0, whereas the cursor position starts at 2
     Item_Holder *previously_equipped = inv_equip_item(item_list[curr_curs_pos-2], ((U_Hashtable * )gs->player->additional_info), gs->player);
     
        if(item_list[curr_curs_pos-2]->amount == 1){
	wclrtoeol(gs->logs[INVENTORY_LOG]);
	 box(gs->logs[INVENTORY_LOG],0,0);
	 UPDATE_PANEL_INFO();
       }
	  
     else{
       wclrtoeol(gs->logs[INVENTORY_LOG]);
	 box(gs->logs[INVENTORY_LOG],0,0);
	 PRINT_ITEM(item_list[curr_curs_pos-2],gs->logs[INVENTORY_LOG],5,curr_curs_pos);
	 UPDATE_PANEL_INFO();
     }
	  
	
     if(previously_equipped != NULL){
       //max Y range exceeds list of items bound is current error
              int list_pos = msg_find_item_position(gs->logs[INVENTORY_LOG],DEFAULT_MAX_Y,5,previously_equipped,item_list);
       /*
       if(list_pos != ALREADY_LISTED){
	PRINT_ITEM(item_list[curr_curs_pos-2],gs->logs[INVENTORY_LOG],11,list_pos);
       item_list[list_pos] = previously_equipped;
       */
       }
     }
	
    }
  }

msg_display_equipped_equipment(Game_State *gs){
  MSG_CLEAR_SCREEN(gs->logs[INVENTORY_LOG]);
  //Since the imtem printer macro assumes a item holder,
  //we make a dummy item holder to temporarily hold the
  //equipped items we want to print
  Item_Holder *item_holder = malloc(sizeof(Item_Holder));
  item_holder->amount = 1;
  mvwprintw(gs->logs[INVENTORY_LOG],1,25, "Items equipped");
  mvwprintw(gs->logs[INVENTORY_LOG],4,25, "Head slot:");
  item_holder->item = ((U_Hashtable * )gs->player->additional_info)->equipment_list[head_slot];
  PRINT_ITEM(item_holder,gs->logs[INVENTORY_LOG],25,5);  
  mvwprintw(gs->logs[INVENTORY_LOG],6,25, "Neck slot:");
  item_holder->item = ((U_Hashtable * )gs->player->additional_info)->equipment_list[neck_slot];
  PRINT_ITEM(item_holder,gs->logs[INVENTORY_LOG],25,7);  
  mvwprintw(gs->logs[INVENTORY_LOG],8,25, "Torso slot:");
  item_holder->item = ((U_Hashtable * )gs->player->additional_info)->equipment_list[torso_slot];
  PRINT_ITEM(item_holder,gs->logs[INVENTORY_LOG],25,9);  
  mvwprintw(gs->logs[INVENTORY_LOG],12,5, "Finger slot:");
  item_holder->item = ((U_Hashtable * )gs->player->additional_info)->equipment_list[finger_slot];
  PRINT_ITEM(item_holder,gs->logs[INVENTORY_LOG],5,13);  
  mvwprintw(gs->logs[INVENTORY_LOG],15,25, "Legs slot:");
  item_holder->item = ((U_Hashtable * )gs->player->additional_info)->equipment_list[legs_slot];
  PRINT_ITEM(item_holder,gs->logs[INVENTORY_LOG],25,16);  
  mvwprintw(gs->logs[INVENTORY_LOG],18,25, "Feet slot:");
  item_holder->item = ((U_Hashtable * )gs->player->additional_info)->equipment_list[feet_slot];
  PRINT_ITEM(item_holder,gs->logs[INVENTORY_LOG],25,19);  
  mvwprintw(gs->logs[INVENTORY_LOG],10,3, "Mainhand slot:");
  item_holder->item = ((U_Hashtable * )gs->player->additional_info)->equipment_list[mainhand_slot];
  PRINT_ITEM(item_holder,gs->logs[INVENTORY_LOG],3,11);  
  mvwprintw(gs->logs[INVENTORY_LOG],10,38, "Offhand slot:");
  item_holder->item = ((U_Hashtable * )gs->player->additional_info)->equipment_list[offhand_slot];
  PRINT_ITEM(item_holder,gs->logs[INVENTORY_LOG],38,11);  
  mvwprintw(gs->logs[INVENTORY_LOG],2,40, "Back slot:");
  item_holder->item = ((U_Hashtable * )gs->player->additional_info)->equipment_list[back_slot];
  PRINT_ITEM(item_holder,gs->logs[INVENTORY_LOG],40,3);  
  top_panel(gs->panels[INVENTORY_LOG]);
  update_panels(); 
  doupdate();
  free(item_holder);
  int ch;
  while (1){
    ch = getch();
    if (ch == 'q'){                   
      hide_panel(gs->panels[INVENTORY_LOG]);
      update_panels();
      doupdate();
      return;
    }
  }
}
   
      
 
