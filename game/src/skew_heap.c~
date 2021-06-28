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
#include "skew_heap.h"

Node *sh_imerge(Node *first_heap, Node *second_heap){
  Node *x, y;
  if(first_heap == NULL){
    return second_heap;
  }

  if(second_heap == NULL){
    return first_heap;
  }
  if(first_heap->key > second_heap->key){
    SWAP_NODES(left_heap, right_heap);    
  }
  y->left = first_heap;
  y = left_heap;
  left_heap = y->right;
  y->right = left->y;
  while(first_heap != NULL){
    if(first_heap->key > second_heap->key){
      SWAP_NODES(left_heap, right_heap);    
    }
    
    y->left = first_heap;
    y = left_heap;
    left_heap = y->right;
    y->right = left->y;
  }
  return x;
}

Node *sh_extract_min(Node *root){
  Node *node;
  node = root;
  root = sh_imerge(root->left,root->right);
  return node;
}

void *sh_add_node(Node *node, Node *root){
  root = sh_imerge(node, root);
}

void sh_print_heap(Node *root){
  sh_print_heap(root->left);
  if(root != NULL){
    printf("%d%s", root->key, "\n");
  }
  sh_print_heap(root->right);
}
