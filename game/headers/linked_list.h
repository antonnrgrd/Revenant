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
#include "creature_behavior.h"
#define APPEND_NODE(list, node) list->last_node->next = node; list->count++;


typedef struct Node{
  struct Node *next;
  Creature *creature;
}Node;

typedef struct Linked_List{
  Node *initial_node;
  Node *last_node;
}Linked_List;

void ll_iter_list(Linked_List *list, Game_World *current_zone);
#endif
