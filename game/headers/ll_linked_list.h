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
#include "ll_linked_list_struct.h"
#include "game_state_struct.h"
#include "c_creature.h"
#define LL_APPEND_NODE_CREATURE(list, c) Ll_Node *node = malloc(sizeof(Ll_Node)); node->value = c; ( list->initial_node == NULL) ? (list->initial_node = node),(list->last_node = node) : (list->last_node->next = node), (list->last_node = node)

Ll_Linked_List *ll_initialize_linked_list();

/* 08/01/2025 verified it frees all data */
#define LL_FREE_NODE_AS_CREATURE(gs,node){    \
    c_free_creature(gs,(C_Creature *)node->value);	\
    FREE_NULL(node);					\
  }

void ll_free_linked_list_as_creatures(Game_State *gs,Ll_Linked_List *list);
#endif
