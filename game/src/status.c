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
#include "status.h"
void st_status_handler_player(Creature *c){
  for(int i = 0; i < 0; i++){
    if(ST_CHECK_FLAG_SET(c,i)){
      ;
    }
  }
  if(ST_CHECK_FLAG_SET(c,DEAD)){
    ;
  }
}

