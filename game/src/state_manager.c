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
  REDRAW_MAP(game_state,game_state->player,game_state->current_zone,game_state->logs[MAIN_SCREEN], game_state->player->position.global_x,game_state->player->position.global_y,rows, cols);
  wrefresh(game_state->logs[MAIN_SCREEN]);
  while(1){
    while(player_turn == CONTINUE_TURN ){
    getmaxyx(stdscr,game_state->num_cols, game_state->num_rows);
    wrefresh(game_state->logs[MAIN_SCREEN]);  
    ch = getch();
    // Listenting for KEY_RESIZE is not sufficient to detect that the screen has been reized by clicking of the resize icon on the terminal, so we have to listen for the screen size being different than previously to detect this case
    /*
    if(ch < 0 || ch > 255){
      getmaxyx(stdscr,game_state->found_cols, game_state->found_rows);
      getmaxyx(stdscr,game_state->curr_cols, game_state->curr_rows);
      REDRAW_MAP(game_state->player,game_state->current_zone,game_state->logs[MAIN_SCREEN], game_state->player->position.global_x,game_state->player->position.global_y,rows, cols);
    }
    */
    switch(ch){
    case KEY_RESIZE:
       REDRAW_MAP(game_state,game_state->player,game_state->current_zone,game_state->logs[MAIN_SCREEN], game_state->player->position.global_x,game_state->player->position.global_y,rows, cols);
      break;
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
    case 'R':
      REDRAW_MAP(game_state,game_state->player,game_state->current_zone,game_state->logs[MAIN_SCREEN], game_state->player->position.global_x,game_state->player->position.global_y,rows, cols);
      break;
    default:
      break;
     }
    }
    ll_iter_list_as_creature(game_state->active_creatures,game_state);
    game_state->player->curr_ap = game_state->player->max_ap;
    player_turn = CONTINUE_TURN;
  }
}

