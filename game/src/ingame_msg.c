/*This file is part of Revenant.
65;6800;1cRevenant is free software: you can redistribute it and/or modify
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
      mvwprintw(game_state->logs[MAIN_SCREEN],0,0, "%s%s%s%s%s%d%s", "Pickup ",quality_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->quality], material_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->material],equipment_kind_modifier[((struct Armor *)item_holder->item->item_specific_info)->armor_type], " amount: ", item_holder->amount, " ? [y/n/a/d]");
    }
    else{
      mvwprintw(game_state->logs[MAIN_SCREEN],0,0, "%s%s%s%s%s", "Pickup ",quality_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->quality], material_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->material],equipment_kind_modifier[((struct Armor *)item_holder->item->item_specific_info)->armor_type], " ? [y/n/a/d]");
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

static inline void msg_print_item(Item_Holder *item_holder, WINDOW *screen, int x, int y){
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
      mvwprintw(screen, y,x, "%s%s%s%s%d", quality_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->quality],material_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->material], armorslot_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->armor_type], " X ", item_holder->amount);
    }
    else{
      mvwprintw(screen, y,x, "%s%s%s", quality_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->quality],material_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->material],  armorslot_name_modifier[((struct Armor *)item_holder->item->item_specific_info)->armor_type]);
    }
  }
    
  else{
    char *file_path = I_GET_FILEPATH(item_holder->item);
      ir_print_string(file_path, "name", screen,x,y,PRINT_ITEM, item_holder);
      free(file_path);
    }
}

int msg_trading_session(int global_x, int global_y,Game_State *gs){
  int tmp_amount_holder;
  int curr_curs_pos = 2;
  int column_position = 2;
  int current_printed_item = 0;
  Item_Holder **item_list = malloc(sizeof(Item_Holder* ) * ((U_Hashtable * )gs->current_zone->tiles[global_y][global_x].foe)->item_count);
  MSG_CLEAR_SCREEN(gs->logs[TRADING_LOG]);
  INIT_INVENTORY_LOG(gs->logs[TRADING_LOG], "Merchant\'s wares");
  for(int i = 0; i < ((U_Hashtable * )gs->current_zone->tiles[global_y][global_x].foe)->size; i++ ){
    if(((U_Hashtable * )gs->current_zone->tiles[global_y][global_x].foe)->entries[i] != NULL){
      Entry  *current_entry = ((U_Hashtable * )gs->player->additional_info)->entries[i];
      while(current_entry != NULL){
	msg_print_item(current_entry->item_holder,gs->logs[TRADING_LOG],5,column_position);
        current_entry = current_entry->next_entry;
	column_position++;
      }
    }
  }  
  top_panel(gs->panels[TRADING_LOG]);
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
    else if (ch == 'y'){
      char amount_bfr[5];
      int bfr_index = 0;
      MSG_CLEAR_SCREEN(gs->logs[NOTIFICATION_LOG]);
      mvprintw(gs->logs[NOTIFICATION_LOG],5,5, "Enter amount you want to buy");
      top_panel(gs->panels[NOTIFICATION_LOG]);
      UPDATE_PANEL_INFO();
      while(1){
	ch = getch();
	if(bfr_index < 4 && ch != KEY_BACKSPACE){
	  amount_bfr[bfr_index] = ch;
	  bfr_index ++;
	}
	else if(ch == KEY_BACKSPACE && bfr_index != 0){
	  amount_bfr[bfr_index] = "";
	  bfr_index --;
	}
	else if(ch == 'q'){
	  break;
	}
	else if(ch == 'y'){
	  char *endptr;
	  int amount = strtol(amount_bfr, &endptr, 10);
	  if( *endptr == '\0' && amount > 0){
	    int cost = amount * item_list[curr_curs_pos-2]->item->value;
	    float additional_weight = amount * item_list[curr_curs_pos-2]->item->weight;
	    if( cost <= (((Player_Info * )gs->player->additional_info)->inventory)->money && gs->player->current_carry + additional_weight <= gs->player->max_carry){

	    }
	    else if (cost > (((Player_Info * )gs->player->additional_info)->inventory)->money){
	      MSG_CLEAR_SCREEN(gs->logs[NOTIFICATION_LOG]);
	      mvprintw(gs->logs[NOTIFICATION_LOG],5,5, "You do not have suffcient money to buy that many");
	      UPDATE_PANEL_INFO();
	    }
	    else{
	      MSG_CLEAR_SCREEN(gs->logs[NOTIFICATION_LOG]);
	      mvprintw(gs->logs[NOTIFICATION_LOG],5,5, "You cannot carry that much");
	      UPDATE_PANEL_INFO();
	    }
	  }
	  else if(amount < 0 ){
	    MSG_CLEAR_SCREEN(gs->logs[NOTIFICATION_LOG]);
	    mvprintw(gs->logs[NOTIFICATION_LOG],5,5, "Don't be silly, you cannot buy a negative amount of items");
	    UPDATE_PANEL_INFO();
	  }
	  else{
	    MSG_CLEAR_SCREEN(gs->logs[NOTIFICATION_LOG]);
	    mvprintw(gs->logs[NOTIFICATION_LOG],5,5, "Please only provide integers when speciyfing the amount");
	    UPDATE_PANEL_INFO();
	  }
	}
      }
    }
    else if(ch == 's')  {
      msg_display_inventory(gs,CONTEXT_SELLING, ((U_Hashtable * )gs->current_zone->tiles[global_y][global_x].foe));
    }
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
  //We return max_y+1 since we add the item to the end of the list. However
  //when we add the item, we increase the number of items in the list, so we have have to add a +1
  //By how we malloc for the item_list, we SHOULD be guaranteed that there are enough free pointers to do this 
  //printf("ITEM NOT ALREADY IN LIST");
  return max_y+1;
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
 
int msg_display_inventory(Game_State *gs,int context, U_Hashtable *merchant){
  int tmp_amount_holder;
  int curr_curs_pos = 2;
  int current_printed_item = 0;
  MSG_CLEAR_SCREEN(gs->logs[INVENTORY_LOG]);
  INIT_INVENTORY_LOG(gs->logs[INVENTORY_LOG], "Items in inventory");
  Item_Holder **item_list = NULL;
  if(context == CONTEXT_SELLING){
    item_list = malloc(sizeof(Item_Holder* ) * (((Player_Info * )gs->player->additional_info)->inventory)->item_count);
  }
  int column_position = 2;
  for(int i = 0; i < (((Player_Info * )gs->player->additional_info)->inventory)->size; i++ ){
    if((((Player_Info * )gs->player->additional_info)->inventory)->entries[i] != NULL){
      Entry  *current_entry = (((Player_Info * )gs->player->additional_info)->inventory)->entries[i];
      while(current_entry != NULL){
	msg_print_item(current_entry->item_holder,gs->logs[INVENTORY_LOG],5,column_position);
        current_entry = current_entry->next_entry;
	column_position++;
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
  }
} 
 
int msg_display_inventory_equip_context(Game_State *gs){
  int available_equipment = 0;
  int tmp_amount_holder;
  MSG_CLEAR_SCREEN(gs->logs[INVENTORY_LOG]);
  INIT_INVENTORY_LOG(gs->logs[INVENTORY_LOG], "Available equipment");
  int curr_curs_pos = 2;
  int column_position = 2;
  int current_printed_item = 0;
  Item_Holder **item_list = NULL;
  if((((Player_Info * )gs->player->additional_info)->inventory)->item_count > 0){
    item_list = malloc(sizeof(Item_Holder* ) * (((Player_Info * )gs->player->additional_info)->inventory)->item_count);
  }
  for(int i = 0; i < (((Player_Info * )gs->player->additional_info)->inventory)->size; i++ ){
    if((((Player_Info * )gs->player->additional_info)->inventory)->entries[i] != NULL){
      Entry  *current_entry = (((Player_Info * )gs->player->additional_info)->inventory)->entries[i];
      while(current_entry != NULL){
	if(current_entry->item_holder->item->kind == weapon || current_entry->item_holder->item->kind == armor ){
	item_list[current_printed_item] =  current_entry->item_holder;  
	msg_print_item(current_entry->item_holder,gs->logs[INVENTORY_LOG],5,column_position);
	column_position++;
	current_printed_item++;
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
    else if (ch == KEY_DOWN && curr_curs_pos < DEFAULT_MAX_Y - 2 && item_list[(curr_curs_pos-2)+1] != NULL && item_list != NULL){
      curr_curs_pos++;
      wmove(gs->logs[INVENTORY_LOG],curr_curs_pos,5);
      update_panels();
      doupdate();
    }
    //probably faulty with how we assign item holder pointers to the item list
    else if (ch == 'y' && ( item_list != NULL && item_list[curr_curs_pos-2]!= NULL)){
     mvwprintw(gs->logs[MAIN_SCREEN],DEFAULT_MAX_Y,0, "%s", "You equip ");
     /*We temporarily set the amount of the item we equip to be one since
      item printer prints the amount of the item, unless the amount we have is 1
     and we do not want the amount printed, just the item's name*/
     tmp_amount_holder = item_list[curr_curs_pos-2]->amount;
     item_list[curr_curs_pos-2]->amount = 1;
     msg_print_item(item_list[curr_curs_pos-2],gs->logs[MAIN_SCREEN],11,DEFAULT_MAX_Y);
     item_list[curr_curs_pos-2]->amount = tmp_amount_holder;     
          msg_update_event_log(gs);
      UPDATE_PANEL_INFO();
      //we subtract 2 from curr_curs_pos to "map" from current cursor position to the actual postion of the item
      //in the item list. This is because the item list starts at index 0, whereas the cursor position starts at 2
     Item_Holder *previously_equipped = inv_equip_item(item_list[curr_curs_pos-2], ((U_Hashtable * )gs->player->additional_info), gs->player);
      if(item_list[curr_curs_pos-2]->amount == 1){
       	wclrtoeol(gs->logs[INVENTORY_LOG]);
	item_list[curr_curs_pos-2]=NULL;
      	MSG_COMPRESS_ITEM_LIST(item_list,curr_curs_pos-2,available_equipment,gs->logs[INVENTORY_LOG]);
	available_equipment--;
	//	any_null(item_list);     
           }
             
     else{
       wclrtoeol(gs->logs[INVENTORY_LOG]);
	 box(gs->logs[INVENTORY_LOG],0,0);
	 msg_print_item(item_list[curr_curs_pos-2],gs->logs[INVENTORY_LOG],5,curr_curs_pos);
	 UPDATE_PANEL_INFO();
     }
       
     if(previously_equipped != NULL){
       int list_pos = msg_find_item_position(gs->logs[INVENTORY_LOG],available_equipment,previously_equipped,item_list);
       if(list_pos != ALREADY_LISTED){
       item_list[list_pos] = previously_equipped;
       msg_print_item(item_list[list_pos],gs->logs[INVENTORY_LOG],5,list_pos+1);
       available_equipment++;
       UPDATE_PANEL_INFO();
       }
       else{ 
	 free(previously_equipped);
	 MSG_REDRAW_INVENTORY(item_list,available_equipment,gs->logs[INVENTORY_LOG]);
	 UPDATE_PANEL_INFO();
       }
     }  
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
      return CONTINUE_TURN;
    }
  }
}
   
      
 
