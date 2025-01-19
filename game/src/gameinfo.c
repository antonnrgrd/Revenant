/*This file is part of Revenant.

Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Revenant is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */

#include "gameinfo.h"

/*A giant jumptable. The basic idea is that when the player makes a move in a direction, the response should be based on the tiles kind. they way this hsould be handled is that we check the character at a location. The character has a decimal representation. That deciaml representation will represent an index in this lookup table. The returned value will then act as yet antoher offset to an array of functions that handle said behavior. It is 256 rather than 255 in size as the the extended ascii table has 255 characters in total  */    /*        ignore whatever is in here                             */
int numerical_responses[256] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* <- 25 element*/0,0,0,0,0,0,0,0, 5, 1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,50,/* <- 50th element */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,100/* <- 100 element */,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,150/* <- 150 character */ ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 ,200, /* <- 200th char */0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,250/* <- 250th character */,0,0,0,0};


/*08/01/2025 TODO
I need to rewrite the logic almost entirely  for the Tile struct to make cleaning it up not be a total nightmare, but for now, it will let it be, however, this will definetly cause memory leaks when cleaing them up.
*/
gm_free_tile(Tile *tile){
  FREE_NULL(tile->content);
  U_FREE_ENTRY(tile->entry);
  FREE_NULL(tile);
  /* freeing the creature here could potentially be dangerous as we might have free'd it earlier on  */
  c_free_creature((C_Creature *)tile->foe);
}
