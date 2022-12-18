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

#include "state_manager.h"
void game_loop(Game_State *game_state){
  int ch;
  int player_turn = CONTINUE_TURN;
  REDRAW_MAP(game_state->player,game_state->current_zone,game_state->logs[MAIN_SCREEN], game_state->player->position.global_x,game_state->player->position.global_y,rows, cols);
  wrefresh(game_state->logs[MAIN_SCREEN]);
  while(1){
    while(player_turn == CONTINUE_TURN ){
    wrefresh(game_state->logs[MAIN_SCREEN]);  
    ch = getch();
    switch(ch){
    case KEY_UP:
    player_turn = mv_check_move_handler(game_state->player->position.global_x, game_state->player->position.global_y-1,game_state->player->position.local_x, game_state->player->position.local_y-1, game_state->player,game_state);
      break;
    case KEY_DOWN:
   player_turn =   mv_check_move_handler(game_state->player->position.global_x, game_state->player->position.global_y+1,game_state->player->position.local_x, game_state->player->position.local_y+1, game_state->player,game_state);      
      break;
    case KEY_LEFT:
     player_turn = mv_check_move_handler(game_state->player->position.global_x-1,game_state->player->position.global_y ,game_state->player->position.local_x-1, game_state->player->position.local_y,game_state->player,game_state);
      break;
    case KEY_RIGHT:
    player_turn =  mv_check_move_handler(game_state->player->position.global_x+1, game_state->player->position.global_y ,game_state->player->position.local_x+1, game_state->player->position.local_y, game_state->player,game_state);
      break;
    case 'q':
      return;
    case 'l':
      player_turn =  msg_show_log(game_state,EVENT_LOG);
      break;
    case 'i':
      player_turn = msg_display_inventory(game_state, CONTEXT_INSPECTING, NULL);
      break;
    case 'e':
      player_turn = msg_display_inventory_equip_context(game_state);
      break;
    case 'E':
      msg_display_equipped_equipment(game_state);
      break;
    default:
      break;
    }
    ll_iter_list_as_creature(game_state->active_creatures,game_state);
    player_turn = CONTINUE_TURN;
    }
  }
}

