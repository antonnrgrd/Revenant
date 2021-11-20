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
  REDRAW_MAP(game_state->player,game_state->current_zone, game_state->player->position.global_x,game_state->player->position.global_y,rows, cols);
  // gs_print_foes(game_state);
  refresh();
  while(1){
    refresh(); 
    ch = getch();
    switch(ch){
    case KEY_UP:
      mv_check_move_handler(game_state->player->position.global_x, game_state->player->position.global_y-1,game_state->player->position.local_x, game_state->player->position.local_y-1, game_state->player,game_state);
      break;
    case KEY_DOWN:
      mv_check_move_handler(game_state->player->position.global_x, game_state->player->position.global_y+1,game_state->player->position.local_x, game_state->player->position.local_y+1, game_state->player,game_state);      
      break;
    case KEY_LEFT:
      mv_check_move_handler(game_state->player->position.global_x-1,game_state->player->position.global_y ,game_state->player->position.local_x-1, game_state->player->position.local_y,game_state->player,game_state);
      break;
    case KEY_RIGHT:
      mv_check_move_handler(game_state->player->position.global_x+1, game_state->player->position.global_y ,game_state->player->position.local_x+1, game_state->player->position.local_y, game_state->player,game_state);
      break;
    case 'q':
      return;
    case 'l':
      msg_show_status(game_state->logs[0]);
      break;
    case S:
      ;
      break;
    default:
      break;
    }
        ll_iter_list_as_creature(game_state->active_creatures,game_state->current_zone);
  }
}
