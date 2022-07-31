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


#ifndef LINKED_LIST
#define LINKED_LIST
#include <stdlib.h>
//#include "creature.h"
typedef struct Node{
  struct Node *next;
  void *value;
}Node;

typedef struct Linked_List{
  Node *initial_node;
  Node *last_node;
}Linked_List;

#define APPEND_NODE_CREATURE(list, c) Node *node = malloc(sizeof(Node)); node->value = c; ( list->initial_node == NULL) ? (list->initial_node = node),(list->last_node = node) : (list->last_node->next = node), (list->last_node = node)

Linked_List *ll_initialize_linked_list();

#endif

