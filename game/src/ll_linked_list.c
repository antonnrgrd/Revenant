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


#include "ll_linked_list.h"
#include "c_creature.h"
void ll_prepend_node_creature(Ll_Linked_List *ll, C_Creature *c){
  Ll_Node *node = malloc(sizeof(Ll_Node));
  node->next = NULL;
  node->value = c;
  if(ll->initial_node == NULL){
    ll->initial_node = node;
  }
  else{
    Ll_Node *current = ll->initial_node;
    int i = 0;
    while(current->next != NULL){
      current = current->next;
      i++;
    }
    current->next = node;
  }
}

Ll_Linked_List *ll_initialize_linked_list(){
  Ll_Linked_List *ll = malloc(sizeof(Ll_Linked_List));
  ll->initial_node = NULL;
  return ll;
}

