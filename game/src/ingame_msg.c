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

int msg_trading_session(int global_x, int global_y,Game_State *gs){
  //  (((Player_Info * )gs->player->additional_info)->inventory)->money = 10000;
  int tmp_amount_holder;
  int curr_curs_pos = 2;
  int column_position = 2;
  int current_printed_item = 0;
  int available_items = 0;
  Item_Holder **item_list = malloc(sizeof(Item_Holder* ) * ((U_Hashtable * )gs->current_zone->tiles[global_y][global_x].foe)->item_count);
  MSG_CLEAR_SCREEN(gs->logs[TRADING_LOG]);
  INIT_INVENTORY_LOG(gs->logs[TRADING_LOG], "Merchant\'s wares");
  for(int i = 0; i < ((U_Hashtable * )gs->current_zone->tiles[global_y][global_x].foe)->size; i++ ){
    if(((U_Hashtable * )gs->current_zone->tiles[global_y][global_x].foe)->entries[i] != NULL){
      Entry  *current_entry = ((U_Hashtable * )gs->current_zone->tiles[global_y][global_x].foe)->entries[i];
      while(current_entry != NULL){
	msg_print_item(current_entry->item_holder,gs->logs[TRADING_LOG],5,column_position);
	item_list[column_position-2] = current_entry->item_holder;
        current_entry = current_entry->next_entry;
	column_position++;
	available_items++;
      }
    }
  }
  top_panel(gs->panels[TRADING_LOG]);
  wmove(gs->logs[TRADING_LOG],curr_curs_pos,5);
  curs_set(TRUE);
  UPDATE_PANEL_INFO();
  int ch;
  while (1){
    ch = getch();
      if (ch == 'q'){
      free(item_list);
      curs_set(FALSE);
      hide_panel(gs->panels[TRADING_LOG]);
      update_panels();
      doupdate();
      return CONTINUE_TURN;
    }
    else if (ch == KEY_UP && curr_curs_pos > 2){
      curr_curs_pos--;
      wmove(gs->logs[TRADING_LOG],curr_curs_pos,5);
      update_panels();
      doupdate();
    }
    else if (ch == KEY_DOWN && curr_curs_pos < DEFAULT_MAX_Y - 2 && (curr_curs_pos-2)+1 < available_items && item_list != NULL){
      curr_curs_pos++;
      wmove(gs->logs[TRADING_LOG],curr_curs_pos,5);
      update_panels();
      doupdate();
    }
    else if(ch == KEY_RESIZE){
      msg_redraw_trading_session(gs,item_list,available_items,NOT_INITIATED_EXCHANGE,-1,NULL);
    }
    else if (ch == 'y'){
      char amount_bfr[5];
      /*oddly enough, when i previously declared the stack-located buffer, it wasn't necessary to enure the string was "clean" by copying
       whitespace to it, but after switching some code logic around, the buffer now contained garbage, resulting in weird issue when attempting to print it, so it is necessary to clear it first*/
      strcpy(amount_bfr, " ");
      int bfr_index = 0;
      MSG_SETUP_NOTIFICATION_LOG(gs, NOTIFICATION_LOG, YES, "Enter the amount you want to buy");
      int x_curs_pos = gs->notification_log_width_size/2;
      wmove(gs->logs[NOTIFICATION_LOG],gs->notification_log_height_size/2,gs->notification_log_width_size/2);
      UPDATE_PANEL_INFO();
      /*This is DEFINETLY breaking every software engineering standard for acceptable amount of else if statements, but I expect
       that (hopefully) the amount of situations in which this will occur will be sufficiently rare to the point where deriving a more
      elegant solution is not worth the effort or necessary*/
      while(1){
	ch = getch();
	/*We disallow the value to be 0 if it the first i.e 0-index, because a number beginning with 0 is not a valid number, nor is it sensical to allow the player to purchase 0 items*/
	if(isdigit(ch) && bfr_index < 4 && !( ch == '0' && bfr_index == 0) ){
	      amount_bfr[bfr_index] = ch;
	      wmove(gs->logs[NOTIFICATION_LOG],gs->notification_log_height_size/2,x_curs_pos-1);
	      wclrtoeol(gs->logs[NOTIFICATION_LOG]);
	      box(gs->logs[NOTIFICATION_LOG],0,0);
	      mvwprintw(gs->logs[NOTIFICATION_LOG],gs->notification_log_height_size/2,x_curs_pos,"%d", atoi(amount_bfr));
	      bfr_index++;
	      wmove(gs->logs[NOTIFICATION_LOG],gs->notification_log_height_size/2,x_curs_pos+bfr_index);
	      //x_curs_pos++;
	      UPDATE_PANEL_INFO();
	    }
	    else if( (ch == KEY_BACKSPACE || ch == KEY_DC || ch == 127) && bfr_index > 0){
	      amount_bfr[bfr_index-1] = ' ';
	      wmove(gs->logs[NOTIFICATION_LOG],gs->notification_log_height_size/2,x_curs_pos-1);
	      wclrtoeol(gs->logs[NOTIFICATION_LOG]);
	      mvwprintw(gs->logs[NOTIFICATION_LOG],gs->notification_log_height_size/2,x_curs_pos,"%s", amount_bfr);
	      box(gs->logs[NOTIFICATION_LOG],0,0);
	      bfr_index--;
	      wmove(gs->logs[NOTIFICATION_LOG],gs->notification_log_height_size/2,x_curs_pos+(bfr_index));
	      UPDATE_PANEL_INFO();
	
	      //x_curs_pos--;
	    }
	    else if (ch == 'q'){
	      hide_panel(gs->panels[NOTIFICATION_LOG]);
	      UPDATE_PANEL_INFO();
	      break;	      
	    }
	    else if(ch == KEY_RESIZE){
	      msg_redraw_trading_session(gs,item_list,available_items,INITIATED_EXCHANGE,-1,amount_bfr);
	    }
	    else if(ch ==  'y'){
	     if(strcmp(amount_bfr, " ") == 0){
	       mvwprintw(gs->logs[NOTIFICATION_LOG],(gs->notification_log_height_size/2)-1,gs->notification_log_width_size/3, "Please enter a number");
	     UPDATE_PANEL_INFO();
	     ch = getch();
	     wmove(gs->logs[NOTIFICATION_LOG],(gs->notification_log_height_size/2)-1,gs->notification_log_width_size/3);
	     wclrtoeol(gs->logs[NOTIFICATION_LOG]);
	     wmove(gs->logs[NOTIFICATION_LOG],gs->notification_log_height_size/2,gs->notification_log_width_size/2);
	     wclrtoeol(gs->logs[NOTIFICATION_LOG]);
	     box(gs->logs[NOTIFICATION_LOG],0,0);
	     strcpy(amount_bfr, " ");
	     UPDATE_PANEL_INFO();
	     }
	    else  if(item_list[curr_curs_pos-2]->item->value * atoi(amount_bfr) >= (((Player_Info * )gs->player->additional_info)->inventory)->money ){
		mvwprintw(gs->logs[NOTIFICATION_LOG],(gs->notification_log_height_size/2)-1,gs->notification_log_width_size/3, "Not enough money");
	     UPDATE_PANEL_INFO();
	     ch = getch();
	     wmove(gs->logs[NOTIFICATION_LOG],(gs->notification_log_height_size/2)-1,gs->notification_log_width_size/3);
	     wclrtoeol(gs->logs[NOTIFICATION_LOG]);
	     wmove(gs->logs[NOTIFICATION_LOG],gs->notification_log_height_size/2,gs->notification_log_width_size/2);
	     wclrtoeol(gs->logs[NOTIFICATION_LOG]);
	     box(gs->logs[NOTIFICATION_LOG],0,0);
	     strcpy(amount_bfr, " ");
	     UPDATE_PANEL_INFO();
	      }
	     else if( gs->player->current_carry + (item_list[curr_curs_pos-2]->item->weight * atoi(amount_bfr)) > gs->player->max_carry ){
	       mvwprintw(gs->logs[NOTIFICATION_LOG],(gs->notification_log_height_size/2)-1,gs->notification_log_width_size/3, "You cannot carry that many");
	     UPDATE_PANEL_INFO();
	     ch = getch();
	     wmove(gs->logs[NOTIFICATION_LOG],(gs->notification_log_height_size/2)-1,gs->notification_log_width_size/3);
	     wclrtoeol(gs->logs[NOTIFICATION_LOG]);
	     wmove(gs->logs[NOTIFICATION_LOG],gs->notification_log_height_size/2,gs->notification_log_width_size/2);
	     wclrtoeol(gs->logs[NOTIFICATION_LOG]);
	     box(gs->logs[NOTIFICATION_LOG],0,0);
	     strcpy(amount_bfr, " ");
	     UPDATE_PANEL_INFO();
	     }
	     else{
	         inv_exchange_item(item_list[curr_curs_pos-2], (U_Hashtable * )gs->current_zone->tiles[global_y][global_x].foe,gs->player, atoi(amount_bfr));
		MSG_ADD_PURCHASE_TO_EVENT_LOG(item_list[curr_curs_pos-2],gs,atoi(amount_bfr) );
	       if(item_list[curr_curs_pos-2]->amount == 0 ){
		 wclrtoeol(gs->logs[INVENTORY_LOG]);
		 I_FREE_ITEM_HOLDER(item_list[curr_curs_pos-2]);
		 available_items--;
	       }
	       else{
       // printf("this bit of logic here");
       wclrtoeol(gs->logs[INVENTORY_LOG]);
	 box(gs->logs[INVENTORY_LOG],0,0);
	 msg_print_item(item_list[curr_curs_pos-2],gs->logs[INVENTORY_LOG],5,curr_curs_pos);
	 UPDATE_PANEL_INFO();
     }
	      }
	     bfr_index = 0;
	    }
	}
      }
    }
  }
 

static inline void msg_pickup_item(Game_State *game_state, Item_Holder *item_holder){
  if(item_holder->item->kind == weapon){
    if(item_holder->amount != 1){
      mvwprintw(game_state->logs[MAIN_SCREEN],0,0, "%s%s%s%s%s%s%d%s", "Pickup ",quality_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->quality], material_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->material],handed_modifier[((struct Weapon *)item_holder->item->item_specific_info)->variant],mele_weapon_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->kind] , " amount: ", item_holder->amount, " ? [y/n/a/d]");
  }
    else{
      mvwprintw(game_state->logs[MAIN_SCREEN],0,0, "%s%s%s%s%s%s", "Pickup ",quality_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->quality], material_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->material],handed_modifier[((struct Weapon *)item_holder->item->item_specific_info)->variant],mele_weapon_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->kind] , " ? [y/n/a/d]");
    }
  }

  else if(item_holder->item->kind == armor){
    if(item_holder->amount != 1){
      mvwprintw(game_state->logs[MAIN_SCREEN],0,0, "%s%s%s%s%s%d%s", "Pickup ",quality_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->quality], material_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->material],equipment_type_modifier[((struct Armor *)item_holder->item->item_specific_info)->armor_type], " amount: ", item_holder->amount, " ? [y/n/a/d]");
    }
    else{
      mvwprintw(game_state->logs[MAIN_SCREEN],0,0, "%s%s%s%s%s", "Pickup ",quality_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->quality], material_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->material],equipment_type_modifier[((struct Armor *)item_holder->item->item_specific_info)->armor_type], " ? [y/n/a/d]");
    }
  }
    
  else{
    char *name;
    i_derive_item_name(item_holder->item,name);
    if (item_holder->amount != 1){
      mvwprintw(game_state->logs[MAIN_SCREEN],0,0, "%s%s%s%d%s", "Pickup ", name , " amount: ", item_holder->amount, " ? [y/n/a/d]"); free(name);
    }
      else{
	mvwprintw(game_state->logs[MAIN_SCREEN],0,0, "%s%s%s", "Pickup ", name , " ? [y/n/a/d]"); free(name);
	  }
      free(name);
    }
}

extern inline void msg_print_item(Item_Holder *item_holder, WINDOW *screen, int x, int y){
  if(item_holder->item == NULL){
    mvwprintw(screen, y,x,"None");
  }
  
  else if(item_holder->item->kind == weapon){
    if(item_holder->amount != 1){
      mvwprintw(screen, y,x, "%s%s%s%s%s%d", quality_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->quality],handed_modifier[((struct Weapon *)item_holder->item->item_specific_info)->variant],material_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->material], mele_weapon_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->kind], " X ", item_holder->amount);
  }
    else{
      mvwprintw(screen, y,x, "%s%s%s%s", quality_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->quality],handed_modifier[((struct Weapon *)item_holder->item->item_specific_info)->variant],material_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->material], mele_weapon_name_modifier[((struct Weapon *)item_holder->item->item_specific_info)->kind]);
    }
  }

  else if(item_holder->item->kind == armor){
    if(item_holder->amount != 1){
      mvwprintw(screen, y,x, "%s%s%s%s%d", quality_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->quality],material_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->material], equipment_type_modifier[((struct Armor *)item_holder->item->item_specific_info)->armor_type], " X ", item_holder->amount);
    }
    else{
      mvwprintw(screen, y,x, "%s%s%s", quality_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->quality],material_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->material],  equipment_type_modifier[((struct Armor *)item_holder->item->item_specific_info)->armor_type]);
    }
  }
    
  else{
    char *file_path = I_GET_FILEPATH(item_holder->item);
      ir_print_string(file_path, "name", screen,x,y,PRINT_ITEM, item_holder);
      free(file_path);
    }
}
 
void any_null(Item_Holder **item_list){
  printf("%s", "This run ");
  for(int i = 0; i < 4; i++)
    if(item_list[i] == NULL){
      printf("%s%d"," " ,i);
    }
}
         
int msg_show_log(Game_State *gs, int panel_index){
  top_panel(gs->panels[panel_index]);
  /*MSG_CLEAR_SCREEN is not a suitable macro as it additionally clears the log screen entirely, so we will have to make
do with just redrawing the box around the log*/
  box(gs->logs[EVENT_LOG],0,0);
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
      return CONTINUE_TURN;
    }
    else if(ch == KEY_RESIZE){
      msg_redraw_log(gs);
    }
  }
}
               
int msg_find_log_position(Game_State *gs){
  
  for(int i = 0; i< NUM_EVENTS; i++){
    //The position at which we check the screen contents could potentially fail
    //Due to the fact that the last position of the message log hhas 2 digits (see the update event log function for more info)
    
      if(s_only_whitespace(gs->ingame_log[i]) == 1){
	return i;
      }
  }
  return -1;
  
}
  
int msg_find_item_position(WINDOW *log, int max_y,Item_Holder *item, Item_Holder **item_list){
  for(int i = 0; i < max_y; i++){
  // Because the equipment can be either of type armor or weapon, we have to be sure that they are the same type before even
  //bothering to check if the names are the same
    
    //printf("%d", max_y);
  if(item->item->kind == item_list[i]->item->kind){
    //It is very important to put parenthesis around the macro call because otherwise, for unknown causes
    //it returns a faulty value
    if((HAS_SAME_NAME(item, item_list[i])) == 0){
      //printf("ITEM ALREADY IN LIST");
      return ALREADY_LISTED;
    }
   }  
  }
  //printf("ITEM NOT ALREADY IN LIST");
  //printf(" free position: %d",max_y);
  return max_y;
}

void msg_update_event_log(Game_State *gs){
  int free_log_position = msg_find_log_position(gs);
  if(free_log_position != -1){
    if(free_log_position < 9){
      /* We add plus two because the log begins at the cell-wise index of two*/
      UPDATE_ADD_TO_LOG(gs,free_log_position+2,12);
    }
    else{
      //We change the offset where print is, if the found y position is 13 because the offset position is 2 digits and so we counter that by increasing the offset
      UPDATE_ADD_TO_LOG(gs,free_log_position+2,14);
    }
  }
  else{
    UPDATE_PUSH_ADD_TO_LOG(gs);
   }
  wmove(gs->logs[MAIN_SCREEN],gs->num_cols-1, 0);
  wclrtoeol(gs->logs[MAIN_SCREEN]);
  mvwprintw(gs->logs[MAIN_SCREEN],gs->num_cols-1,0, gs->current_event);
  UPDATE_PANEL_INFO();
}
 
int msg_display_inventory(Game_State *gs,int context, U_Hashtable *merchant){
  int tmp_amount_holder;
  int curr_curs_pos = 2;
  int current_printed_item = 0;
  int num_encountered_items = 0;
  MSG_CLEAR_SCREEN(gs->logs[INVENTORY_LOG]);
  INIT_INVENTORY_LOG(gs->logs[INVENTORY_LOG], "Items in inventory");
  Item_Holder **item_list = NULL;
  item_list = malloc(sizeof(Item_Holder* ) * (((Player_Info * )gs->player->additional_info)->inventory)->item_count);
  int column_position = 2;
  for(int i = 0; i < (((Player_Info * )gs->player->additional_info)->inventory)->size; i++ ){
    if((((Player_Info * )gs->player->additional_info)->inventory)->entries[i] != NULL){
      Entry  *current_entry = (((Player_Info * )gs->player->additional_info)->inventory)->entries[i];
      while(current_entry != NULL){
	msg_print_item(current_entry->item_holder,gs->logs[INVENTORY_LOG],5,column_position);
	item_list[column_position-2] = current_entry->item_holder;
        current_entry = current_entry->next_entry;
	column_position++;
	num_encountered_items++;
      }
    }
  }  
  top_panel(gs->panels[INVENTORY_LOG]);
  if(context == CONTEXT_SELLING){
    wmove(gs->logs[INVENTORY_LOG],curr_curs_pos,5);
    curs_set(TRUE);
  }
  UPDATE_PANEL_INFO();
  int ch;
  while (1){
    ch = getch();
    if (ch == 'q'){
      hide_panel(gs->panels[INVENTORY_LOG]);
      FREE_NULL(item_list);
      curs_set(FALSE);
      UPDATE_PANEL_INFO();
      return CONTINUE_TURN;
    }
    else if (ch == KEY_UP && curr_curs_pos > 2 && context == CONTEXT_SELLING){
      curr_curs_pos--;
      wmove(gs->logs[INVENTORY_LOG],curr_curs_pos,5);
      update_panels();
      doupdate();
    }       
    else if (ch == KEY_DOWN && curr_curs_pos < DEFAULT_MAX_Y - 2 && item_list[(curr_curs_pos-2)+1] != NULL && context == CONTEXT_SELLING){
      curr_curs_pos++;
      wmove(gs->logs[INVENTORY_LOG],curr_curs_pos,5);
      update_panels();
      doupdate();
    }
    else if(ch == KEY_RESIZE){
      msg_redraw_inventory(gs, item_list, context, num_encountered_items);
    }
    else if(ch == 'R'){
      msg_redraw_inventory(gs, item_list, context, num_encountered_items);
    }
  }
} 
 
int msg_display_inventory_equip_context(Game_State *gs){
  int available_equipment = 0;
  int tmp_amount_holder;
  MSG_CLEAR_SCREEN(gs->logs[INVENTORY_LOG]);
  INIT_INVENTORY_LOG(gs->logs[INVENTORY_LOG], "Available equipment");
  int curr_curs_pos = 2;
  int column_position = 2;
  int current_printed_items = 0;
  Item_Holder **item_list = NULL;
  /*We malloc an itemlist of size item_count to account for the maximal possible items we need to hold and set them to null
   to account for the fact that potentially not all items in the inventory are equipment*/
  if((((Player_Info * )gs->player->additional_info)->inventory)->item_count > 0){
    item_list = malloc(sizeof(Item_Holder* ) * (((Player_Info * )gs->player->additional_info)->inventory)->item_count);
  }
  for(int i = 0; i < (((Player_Info * )gs->player->additional_info)->inventory)->item_count; i++){
    item_list[i] = NULL;
  }
  for(int i = 0; i < (((Player_Info * )gs->player->additional_info)->inventory)->size; i++ ){
    if((((Player_Info * )gs->player->additional_info)->inventory)->entries[i] != NULL){
      Entry  *current_entry = (((Player_Info * )gs->player->additional_info)->inventory)->entries[i];
      while(current_entry != NULL){
	if(current_entry->item_holder->item->kind == weapon || current_entry->item_holder->item->kind == armor ){
	item_list[column_position-2] =  current_entry->item_holder;  
	msg_print_item(current_entry->item_holder,gs->logs[INVENTORY_LOG],5,column_position);
	column_position++;
	current_printed_items++;
	available_equipment++;
       }
	current_entry = current_entry->next_entry;
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
      return CONTINUE_TURN;
    }
    else if (ch == KEY_UP && curr_curs_pos > 2){
      curr_curs_pos--;
      wmove(gs->logs[INVENTORY_LOG],curr_curs_pos,5);
      update_panels();
      doupdate();
    }       
    else if (ch == KEY_DOWN && curr_curs_pos < DEFAULT_MAX_Y - 2 && (curr_curs_pos-2)+1 < available_equipment && item_list != NULL){
      curr_curs_pos++;
      wmove(gs->logs[INVENTORY_LOG],curr_curs_pos,5);
      update_panels();
      doupdate();
    }
    //    if( (ch == 'y' && ( item_list != NULL && item_list[curr_curs_pos-2]== NULL))){
    //    printf("this should not be allowed to happen!");
    //  }
    //probably faulty with how we assign item holder pointers to the item list
    else if (ch == 'y' && ( item_list != NULL && item_list[curr_curs_pos-2]!= NULL)){
      //printf(" quality: %d ",((struct Weapon *)item_list[curr_curs_pos-2]->item->item_specific_info)->quality );
      MSG_ADD_EQUIP_EVENT_TO_LOG(item_list[curr_curs_pos-2], gs);
      //mvwprintw(gs->logs[MAIN_SCREEN],gs->num_cols-1,0, "%s", "You equip ");
     /*We temporarily set the amount of the item we equip to be one since
      item printer prints the amount of the item, unless the amount we have is 1
     and we do not want the amount printed, just the item's name*/
     tmp_amount_holder = item_list[curr_curs_pos-2]->amount;
     item_list[curr_curs_pos-2]->amount = 1;
     //msg_print_item(item_list[curr_curs_pos-2],gs->logs[MAIN_SCREEN],11,gs->num_cols-1);
     item_list[curr_curs_pos-2]->amount = tmp_amount_holder;     
      UPDATE_PANEL_INFO();
      //we subtract 2 from curr_curs_pos to "map" from current cursor position to the actual postion of the item
      //in the item list. This is because the item list starts at index 0, whereas the cursor position starts at 2
     Item_Holder *previously_equipped = inv_equip_item(item_list[curr_curs_pos-2], ((U_Hashtable * )gs->player->additional_info), gs->player);

      /*If the item list is null, it means we equipped the only occurence of that item in the inventory*/
     if(item_list[curr_curs_pos-2]->amount == 0 ){
       	wclrtoeol(gs->logs[INVENTORY_LOG]);
	/*We deliberately defer freeing the item holder up until this point because when freeing the item holder and setting it to null
	  afterwards in the function call to remove it from the inventory, the check to assert if it was null at this point in the code would fail for some reason. We are therefore forced to free the item holder here*/
	I_FREE_ITEM_HOLDER(item_list[curr_curs_pos-2]);
      	MSG_COMPRESS_ITEM_LIST(item_list,curr_curs_pos-2,available_equipment,gs->logs[INVENTORY_LOG]);
	available_equipment--; 
	//if(item_list[curr_curs_pos-2] == NULL){
	// printf( "still null ");
	//}
	//	any_null(item_list);     
           }
      
             
     else{
       // printf("this bit of logic here");
       wclrtoeol(gs->logs[INVENTORY_LOG]);
	 box(gs->logs[INVENTORY_LOG],0,0);
	 msg_print_item(item_list[curr_curs_pos-2],gs->logs[INVENTORY_LOG],5,curr_curs_pos);
	 UPDATE_PANEL_INFO();
     }
       
     if(previously_equipped != NULL){
       int list_pos = msg_find_item_position(gs->logs[INVENTORY_LOG],available_equipment,previously_equipped,item_list);
       if(list_pos != ALREADY_LISTED){
	 //	 printf( "NOT LISTED found free postition in: %d", list_pos);
       item_list[list_pos] = previously_equipped;
       msg_print_item(item_list[list_pos],gs->logs[INVENTORY_LOG],5,list_pos+2);
       available_equipment++;
       UPDATE_PANEL_INFO();
       }
       else{
	 
	 free(previously_equipped);
	 MSG_REDRAW_INVENTORY(item_list,available_equipment,gs->logs[INVENTORY_LOG]);
	 UPDATE_PANEL_INFO();
       }
     }

     /*
     for(int i = 0; i < (((Player_Info * )gs->player->additional_info)->inventory)->item_count; i++ ){
      if(item_list[i] == NULL){
	printf(" %d null ", i);
      }
      else{
		printf(" %d NOT null ", i);
      }
    
     }
     */
     
    /*Provided that the item at the cursor is null af compressing the item list and that the current cursor position mapped to the available equipment +1 exceeds the avilalbe equipment (we are at the end of the equipment list), we have to move upwards to the next available piece of equipment. The exception being that (curr_curs_pos-2)-1 > -1 (we are are the only/last item in the item list)   */
     if( (item_list[(curr_curs_pos-2)] == NULL &&  (curr_curs_pos -1 ) +1 > available_equipment)  && (curr_curs_pos-2)-1 > -1){
	  //printf("null,just as expected");
	  
	  curr_curs_pos--;
	  wmove(gs->logs[INVENTORY_LOG],curr_curs_pos,5);

	}
	else{
	  wmove(gs->logs[INVENTORY_LOG],curr_curs_pos,5);
	}
	UPDATE_PANEL_INFO();
    }
    else if(ch == KEY_RESIZE){
      msg_redraw_inventory_equip_context(gs, item_list, available_equipment,curr_curs_pos);
    }
  }
}
int msg_display_equipped_equipment(Game_State *gs){
  MSG_CLEAR_SCREEN(gs->logs[INVENTORY_LOG]);
  //Since the imtem printer macro assumes a item holder,
  //we make a dummy item holder to temporarily hold the
  //equipped items we want to print
  Item_Holder *item_holder = malloc(sizeof(Item_Holder));
  item_holder->amount = 1;
  mvwprintw(gs->logs[INVENTORY_LOG],1,25, "Items equipped");
  mvwprintw(gs->logs[INVENTORY_LOG],4,25, "Head slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[head_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],25,5);  
  mvwprintw(gs->logs[INVENTORY_LOG],6,25, "Neck slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[neck_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],25,7);  
  mvwprintw(gs->logs[INVENTORY_LOG],8,25, "Torso slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[torso_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],25,9);  
  mvwprintw(gs->logs[INVENTORY_LOG],12,5, "Finger slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[finger_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],5,13);  
  mvwprintw(gs->logs[INVENTORY_LOG],15,25, "Legs slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[legs_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],25,16);  
  mvwprintw(gs->logs[INVENTORY_LOG],18,25, "Feet slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[feet_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],25,19);  
  mvwprintw(gs->logs[INVENTORY_LOG],10,3, "Mainhand slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[mainhand_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],3,11);  
  mvwprintw(gs->logs[INVENTORY_LOG],10,38, "Offhand slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[offhand_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],38,11);  
  mvwprintw(gs->logs[INVENTORY_LOG],2,40, "Back slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[back_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],40,3);  
  top_panel(gs->panels[INVENTORY_LOG]);
  UPDATE_PANEL_INFO();
  free(item_holder);
  int ch;
  while (1){
    ch = getch();
    if (ch == 'q'){                   
      hide_panel(gs->panels[INVENTORY_LOG]);
      update_panels();
      doupdate();
      return CONTINUE_TURN;
      
    }
    else if(ch == KEY_RESIZE){
      msg_redraw_equipped_equipment(gs);
      }
  }
}

void msg_redraw_inventory(Game_State *gs, Item_Holder **item_list, int context, int num_items){
  int x,y;
  getmaxyx(stdscr, y,x);
  if (x < 10 || y < 10){
    while(x < 10 || y < 10){
      int ch = getch();
      if(ch == KEY_RESIZE){
      getmaxyx(stdscr, y,x);
       }
      }
    gs->logs[INVENTORY_LOG] = newwin(LOG_Y_SIZE,LOG_X_SIZE,(gs->num_cols - 1) / 4 , (gs->num_rows - 1) / 4);
    gs->panels[INVENTORY_LOG] = new_panel(gs->logs[INVENTORY_LOG]);
      MSG_CLEAR_SCREEN(gs->logs[INVENTORY_LOG]);
      top_panel(gs->panels[INVENTORY_LOG]);
       REDRAW_MAP(gs,gs->player,gs->current_zone,gs->logs[MAIN_SCREEN], gs->player->position.global_x,gs->player->position.global_y,rows, cols);
      if(context == CONTEXT_INSPECTING){
    INIT_INVENTORY_LOG(gs->logs[INVENTORY_LOG], "Items in inventory");
  }
  else{
    INIT_INVENTORY_LOG(gs->logs[INVENTORY_LOG], "Merchant\'s wares");
  }
  int row_position = 2;
  for(int i = 0; i < num_items; i++){
  msg_print_item(item_list[i],gs->logs[INVENTORY_LOG],5,row_position);
  row_position++;
  } 
      UPDATE_PANEL_INFO();
    
  }
  else{
  //For some reason, you explicitly have to reisze the size of the window to the original
  //upon detecting a resize, otherwise it will upon being resized grow to beyond its original size, taking up
  //the entire screen
  wresize(gs->logs[INVENTORY_LOG],LOG_Y_SIZE,LOG_X_SIZE);
  MSG_CLEAR_SCREEN(gs->logs[INVENTORY_LOG]);
  REDRAW_MAP(gs,gs->player,gs->current_zone,gs->logs[MAIN_SCREEN], gs->player->position.global_x,gs->player->position.global_y,rows, cols);
  if(context == CONTEXT_INSPECTING){
    INIT_INVENTORY_LOG(gs->logs[INVENTORY_LOG], "Items in inventory");
  }
  else{
    INIT_INVENTORY_LOG(gs->logs[INVENTORY_LOG], "Merchant\'s wares");
  }
  int row_position = 2;
  for(int i = 0; i < num_items; i++){
  msg_print_item(item_list[i],gs->logs[INVENTORY_LOG],5,row_position);
  row_position++;
  }
  UPDATE_PANEL_INFO();
  }

}

void msg_redraw_equipped_equipment(Game_State *gs){
  //Programmers note: i suspect that if stdscr gets small enough, the current open window get automatically free'd
  //this is because the screen itself becomes transparent, making the background/main screen visisble and attempting to free the window in such a
  //situation leads to a double free error, implying it has already been deleted.
  int x,y;
  getmaxyx(stdscr, y,x);
  if (x < 10 || y < 10){
    while(x < 10 || y < 10){
      int ch = getch();
      if(ch == KEY_RESIZE){
      getmaxyx(stdscr, y,x);
       }
      }
    gs->logs[INVENTORY_LOG] = newwin(LOG_Y_SIZE,LOG_X_SIZE,(gs->num_cols - 1) / 4 , (gs->num_rows - 1) / 4);
    gs->panels[INVENTORY_LOG] = new_panel(gs->logs[INVENTORY_LOG]);
      MSG_CLEAR_SCREEN(gs->logs[INVENTORY_LOG]);
      top_panel(gs->panels[INVENTORY_LOG]);
       REDRAW_MAP(gs,gs->player,gs->current_zone,gs->logs[MAIN_SCREEN], gs->player->position.global_x,gs->player->position.global_y,rows, cols);
  Item_Holder *item_holder = malloc(sizeof(Item_Holder));
  item_holder->amount = 1;
  mvwprintw(gs->logs[INVENTORY_LOG],1,25, "Items equipped");
  mvwprintw(gs->logs[INVENTORY_LOG],4,25, "Head slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[head_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],25,5);  
  mvwprintw(gs->logs[INVENTORY_LOG],6,25, "Neck slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[neck_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],25,7);  
  mvwprintw(gs->logs[INVENTORY_LOG],8,25, "Torso slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[torso_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],25,9);  
  mvwprintw(gs->logs[INVENTORY_LOG],12,5, "Finger slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[finger_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],5,13);  
  mvwprintw(gs->logs[INVENTORY_LOG],15,25, "Legs slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[legs_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],25,16);  
  mvwprintw(gs->logs[INVENTORY_LOG],18,25, "Feet slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[feet_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],25,19);  
  mvwprintw(gs->logs[INVENTORY_LOG],10,3, "Mainhand slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[mainhand_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],3,11);  
  mvwprintw(gs->logs[INVENTORY_LOG],10,38, "Offhand slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[offhand_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],38,11);  
  mvwprintw(gs->logs[INVENTORY_LOG],2,40, "Back slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[back_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],40,3);  
  top_panel(gs->panels[INVENTORY_LOG]);
  UPDATE_PANEL_INFO();
  free(item_holder);
    
  }
  else{
  //For some reason, you explicitly have to reisze the size of the window to the original
  //upon detecting a resize, otherwise it will upon being resized grow to beyond its original size, taking up
  //the entire screen
  wresize(gs->logs[INVENTORY_LOG],LOG_Y_SIZE,LOG_X_SIZE);
  MSG_CLEAR_SCREEN(gs->logs[INVENTORY_LOG]);
  REDRAW_MAP(gs,gs->player,gs->current_zone,gs->logs[MAIN_SCREEN], gs->player->position.global_x,gs->player->position.global_y,rows, cols);
  Item_Holder *item_holder = malloc(sizeof(Item_Holder));
  item_holder->amount = 1;
  mvwprintw(gs->logs[INVENTORY_LOG],1,25, "Items equipped");
  mvwprintw(gs->logs[INVENTORY_LOG],4,25, "Head slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[head_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],25,5);  
  mvwprintw(gs->logs[INVENTORY_LOG],6,25, "Neck slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[neck_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],25,7);  
  mvwprintw(gs->logs[INVENTORY_LOG],8,25, "Torso slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[torso_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],25,9);  
  mvwprintw(gs->logs[INVENTORY_LOG],12,5, "Finger slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[finger_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],5,13);  
  mvwprintw(gs->logs[INVENTORY_LOG],15,25, "Legs slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[legs_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],25,16);  
  mvwprintw(gs->logs[INVENTORY_LOG],18,25, "Feet slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[feet_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],25,19);  
  mvwprintw(gs->logs[INVENTORY_LOG],10,3, "Mainhand slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[mainhand_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],3,11);  
  mvwprintw(gs->logs[INVENTORY_LOG],10,38, "Offhand slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[offhand_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],38,11);  
  mvwprintw(gs->logs[INVENTORY_LOG],2,40, "Back slot:");
  item_holder->item = ((Player_Info * )gs->player->additional_info)->equipment_list[back_slot];
  msg_print_item(item_holder,gs->logs[INVENTORY_LOG],40,3);  
  top_panel(gs->panels[INVENTORY_LOG]);
  UPDATE_PANEL_INFO();
  free(item_holder);
  }
}


void msg_redraw_inventory_equip_context(Game_State *gs, Item_Holder **item_list, int num_items, int curs_pos){
  int row_position = 2;  
  int x,y;
  getmaxyx(stdscr, y,x);
  if (x < 10 || y < 10){
    while(x < 10 || y < 10){
      int ch = getch();
      if(ch == KEY_RESIZE){
      getmaxyx(stdscr, y,x);
       }
      }
    gs->logs[INVENTORY_LOG] = newwin(LOG_Y_SIZE,LOG_X_SIZE,(gs->num_cols - 1) / 4 , (gs->num_rows - 1) / 4);
    gs->panels[INVENTORY_LOG] = new_panel(gs->logs[INVENTORY_LOG]);
    INIT_INVENTORY_LOG(gs->logs[INVENTORY_LOG], "Available equipment");
      MSG_CLEAR_SCREEN(gs->logs[INVENTORY_LOG]);
      top_panel(gs->panels[INVENTORY_LOG]);
       REDRAW_MAP(gs,gs->player,gs->current_zone,gs->logs[MAIN_SCREEN], gs->player->position.global_x,gs->player->position.global_y,rows, cols);
  for(int i = 0; i < num_items; i++){
    msg_print_item(item_list[i],gs->logs[INVENTORY_LOG],5,row_position);
    row_position++;
  top_panel(gs->panels[INVENTORY_LOG]);
  wmove(gs->logs[INVENTORY_LOG],curs_pos,5);
  UPDATE_PANEL_INFO();    
   }
  }
  else{
  //For some reason, you explicitly have to reisze the size of the window to the original
  //upon detecting a resize, otherwise it will upon being resized grow to beyond its original size, taking up
  //the entire screen
  wresize(gs->logs[INVENTORY_LOG],LOG_Y_SIZE,LOG_X_SIZE);
  MSG_CLEAR_SCREEN(gs->logs[INVENTORY_LOG]);
  INIT_INVENTORY_LOG(gs->logs[INVENTORY_LOG], "Available equipment");
  REDRAW_MAP(gs,gs->player,gs->current_zone,gs->logs[MAIN_SCREEN], gs->player->position.global_x,gs->player->position.global_y,rows, cols);
  for(int i = 0; i < num_items; i++){
    msg_print_item(item_list[i],gs->logs[INVENTORY_LOG],5,row_position);
    row_position++;
   }
  }
   wmove(gs->logs[INVENTORY_LOG],curs_pos,5);
   UPDATE_PANEL_INFO();    
}

void msg_redraw_log(Game_State *gs){
    int x,y;
  getmaxyx(stdscr, y,x);
  if (x < 10 || y < 10){
    while(x < 10 || y < 10){
      int ch = getch();
      if(ch == KEY_RESIZE){
      getmaxyx(stdscr, y,x);
       }
      }
    gs->logs[EVENT_LOG] = newwin(LOG_Y_SIZE,LOG_X_SIZE,(gs->num_cols - 1) / 4 , (gs->num_rows - 1) / 4 );
    gs->panels[EVENT_LOG] = new_panel(gs->logs[EVENT_LOG]);
    box(gs->logs[EVENT_LOG],0,0);
    INIT_EVENT_LOG(gs->logs[EVENT_LOG]);
    REDRAW_MAP(gs,gs->player,gs->current_zone,gs->logs[MAIN_SCREEN], gs->player->position.global_x,gs->player->position.global_y,rows, cols);
    for(int i = 0; i < NUM_EVENTS -1 ; i++){
      mvwprintw(gs->logs[EVENT_LOG], i+3, 12, gs->ingame_log[i]);
    }
  }
  else{
    INIT_EVENT_LOG(gs->logs[EVENT_LOG]);
    wresize(gs->logs[EVENT_LOG],LOG_Y_SIZE,LOG_X_SIZE);
    box(gs->logs[EVENT_LOG],0,0);
    REDRAW_MAP(gs,gs->player,gs->current_zone,gs->logs[MAIN_SCREEN], gs->player->position.global_x,gs->player->position.global_y,rows, cols);
    for(int i = 0; i < NUM_EVENTS -1 ; i++){
      mvwprintw(gs->logs[EVENT_LOG], i+3, 12, gs->ingame_log[i]);
    }
  }
  UPDATE_PANEL_INFO();    
}

void msg_redraw_trading_session(Game_State *gs,Item_Holder **item_list,int num_items, int initiated_exchange , int event_flag, char amount_bfr[5]){
  int x,y;
  int column_position = 2;
  getmaxyx(stdscr, y,x);
  if (x < 10 || y < 10){
    while(x < 10 || y < 10){
      int ch = getch();
      if(ch == KEY_RESIZE){
      getmaxyx(stdscr, y,x);
       }
      }
    gs->logs[TRADING_LOG] = newwin(LOG_Y_SIZE,LOG_X_SIZE,(gs->num_cols - 1) / 4 , (gs->num_rows - 1) / 4 );
    gs->panels[TRADING_LOG] = new_panel(gs->logs[TRADING_LOG]);
    box(gs->logs[TRADING_LOG],0,0);
    gs->logs[NOTIFICATION_LOG] = newwin(LOG_Y_SIZE/4,LOG_X_SIZE,(gs->num_cols - 1) / 2 , (gs->num_rows - 1) / 4);
     gs->panels[NOTIFICATION_LOG] = new_panel(gs->logs[NOTIFICATION_LOG]);
    INIT_EVENT_LOG(gs->logs[TRADING_LOG]);
  }
  else if(x  < gs->num_rows / 2 || y < gs->num_cols / 2){
     if (x < 10 || y < 10){
    while(x < 10 || y < 10){
      int ch = getch();
      if(ch == KEY_RESIZE){
      getmaxyx(stdscr, y,x);
       }
      }
    gs->logs[NOTIFICATION_LOG] = newwin(LOG_Y_SIZE/4,LOG_X_SIZE,(gs->num_cols - 1) / 2 , (gs->num_rows - 1) / 4);
     gs->panels[NOTIFICATION_LOG] = new_panel(gs->logs[NOTIFICATION_LOG]);
     }
  }
  
  
  
    if(x  < gs->num_rows / 2 || y < gs->num_cols / 2){
       gs->logs[NOTIFICATION_LOG] = newwin(LOG_Y_SIZE/4,LOG_X_SIZE,(gs->num_cols - 1) / 2 , (gs->num_rows - 1) / 4);
       gs->panels[NOTIFICATION_LOG] = new_panel(gs->logs[NOTIFICATION_LOG]);
    }
    
  wresize(gs->logs[TRADING_LOG],LOG_Y_SIZE,LOG_X_SIZE);
  REDRAW_MAP(gs,gs->player,gs->current_zone,gs->logs[MAIN_SCREEN], gs->player->position.global_x,gs->player->position.global_y,rows, cols);
  MSG_CLEAR_SCREEN(gs->logs[TRADING_LOG]);
  INIT_INVENTORY_LOG(gs->logs[TRADING_LOG], "Merchant\'s wares");
  for(int i = 0; i < num_items; i++){
    msg_print_item(item_list[i],gs->logs[TRADING_LOG],5,column_position);
    column_position++;
    }
  if(initiated_exchange == INITIATED_EXCHANGE){
    wresize(gs->logs[NOTIFICATION_LOG],LOG_Y_SIZE/4,LOG_X_SIZE);
    MSG_SETUP_NOTIFICATION_LOG(gs, NOTIFICATION_LOG, YES, "Enter the amount you want to buy");
    wmove(gs->logs[NOTIFICATION_LOG],gs->notification_log_height_size/2,gs->notification_log_width_size/2);
    mvwprintw(gs->logs[NOTIFICATION_LOG],gs->notification_log_height_size/2,gs->notification_log_width_size/2,"%d", atoi(amount_bfr));
    }
    
  UPDATE_PANEL_INFO();    
}
