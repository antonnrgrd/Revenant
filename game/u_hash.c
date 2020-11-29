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
#include "u_hash.h"
#include "strings.h"
#include "inventory.h"
/*
Generously provided by Laurence Gonsalves from StackOverflow from a related question
Although C has a built-in random number generator, it is piss-poor and so i choose to use this
instead. Has a small chance of running for quite a while or return 0. Might need to fix this
*/

/*Okay  */


int uh_rand_num(int range){
  int divisor = RAND_MAX/range;
  int retval;
  do{
    retval = rand() / divisor;
  }while (retval > range);
  /*A hack to ensure that value is not zero, is necessary for value of a. tbf dunno how much it throws off uniformity */
  return retval+1;
}
/* A hack of a method that unlike the mthod above allows return the value of 0, need for universal hashing */
int uh_rand_num_z(int range){
    int divisor = RAND_MAX/range;
    int retval;
    do{
      retval = rand()/divisor;
    }while(retval > range);
      return retval;
}
U_Hashtable *uh_init_table(int size){
  U_Hashtable *table = malloc(sizeof(U_Hashtable));
  table->size = size;
  table->entries = malloc( size * sizeof(Entry *));
  table->a = (unsigned long long) uh_rand_num(INT_MAX);
  table->b =(unsigned long long) uh_rand_num_z(INT_MAX);
  return table;
}

Entry *uh_lookup(U_Hashtable *hashtable,uint64_t key){
  int index = ((hashtable->a*key+hashtable->b) % BFP) % hashtable->size;
  if(hashtable->entries[index]->key == key){
  return hashtable->entries[index];
  }
  else{
    Entry *cur=hashtable->entries[index]->next_entry;
    while(cur != NULL){
      if(cur->key == key){
	return cur;
      }
      else{
	cur = cur->next_entry;
      }
    }
  }
  return NULL;
}

/*Okay, so assigning a struct value is a bitch i can't trivially assign using =, so i must awkawrd memcpy instead */
void uh_insert(Entry *entry, U_Hashtable *hashtable){
  int i = 0;
  uint64_t index = ((hashtable->a*entry->key+hashtable->b) % BFP) % hashtable->size;
  printf("%s%ld%s%ld%s","Value of index we insert our entry with key ", entry->key, " is ", index , "\n");
  /*since kinfs are one-indexed a value of zero means the index is uninitialized i.e free */
  Entry *current = hashtable->entries[index];
  //dprintf("%s", "does code reach here?? \n");
  if( current != NULL){
    printf("%s", "collision detected \n");
    printf("%s%d%s","Value of the index there is a collision in is ", i , "\n");
    while(current->next_entry != NULL){
      current = current->next_entry;
      i++;
      printf("%s%d%s","Value of the position we are chaining the value to is ", i , "\n");
    }
    current->next_entry = entry;
  }
  else{
    hashtable->entries[index] = entry;
  }
}

void uh_destroy_table_simple(U_Hashtable *hashtable){ //destroys an entire table for simple data types
  for(int i = 0; i < hashtable->size; i++){
    Entry *cur = hashtable->entries[i];
    if(cur != NULL){
      Entry *chained_entry = cur->next_entry;
      printf("%s%ld%s","The key value we are freeing is ",cur->key,"\n");
      free(cur->value);
      free(cur);
      // printf("%s", "does code reach here? \n");
    while(chained_entry != NULL){
	Entry *next = chained_entry->next_entry;
	/* Of course assume value is non recursive i.e if it's a struct it does not contain other structs. Also assumes data is not NULL, then then again, who'd do something like that*/
	printf("%s%ld%s","The key value we are freeing is ",chained_entry->key,"\n");
	free(chained_entry->value);
	free(chained_entry);
	chained_entry = next;
       }
      }
     }
  free(hashtable->entries);
  free(hashtable);
}
/*A tester function that forces insertion of an lement at a specific index to test deleting */
void uh_force_insert(Entry *entry,int index, U_Hashtable *hashtable){
  /*Since we malloc mem for struct, the only way to assert if struct is initialized is the float val */
  Entry *current = hashtable->entries[index];
  if( current != NULL){
    while(current->next_entry != NULL){
      current = current->next_entry;
    }
    current->next_entry = entry;
  }
  else{
    memcpy(&hashtable->entries+index, &entry, sizeof(Entry));
    free(entry);
  }
}

void uh_print(U_Hashtable *hashtable){
  for(int i = 0; i < hashtable->size; i++){
    if(hashtable->entries[i]!= NULL){
      printf("%ld",hashtable->entries[i]->key);
      if(hashtable->entries[i] != NULL){
	printf("%s", "(");
	Entry *cur = hashtable->entries[i]->next_entry;
	while(cur != NULL){
	  printf("%ld",cur->key);
	  cur = cur->next_entry;
	}
	printf("%s", ")");
      }
    }
  }
}

void uh_add_int_entry(unsigned long long key, int value, U_Hashtable *hashtable){
  Entry *entry = uh_create_entry(key);
  entry->value = malloc(sizeof(int));
  *(int *)entry->value = value;
  uh_insert(entry, hashtable);
}

void uh_add_string_entry(int key, char *value, U_Hashtable *hashtable){
  int length = strlen(value);
  Entry *entry = uh_create_entry(key);
  entry->value = malloc(length *sizeof(char));
  strcpy(entry->value, value);
  uh_insert(entry, hashtable);
}

void uh_add_float_entry(int key, float value, U_Hashtable *hashtable){
  Entry *entry = uh_create_entry(key);
  entry->value = malloc(sizeof(float));
  *(float *)entry->value  = value;
  uh_insert(entry, hashtable);
} 

void uh_add_item_entry(Item *i, U_Hashtable *hashtable){
  uint64_t key = s_uint_from_string(i->name);
  Entry *entry = uh_create_entry_item(i, key);
  uh_insert(entry, hashtable);
}

Entry *uh_lookup_item(U_Hashtable *hashtable,char *name){ //a regular 
  uint64_t key = s_uint_from_string(name);
  return uh_lookup(hashtable, key);
}

Entry *uh_create_entry_item(Item *i, uint64_t key){
  Entry *e = malloc(sizeof(Entry));
  e->key = key;
    *(Item **)e->value = i;
  return e;
}

Entry *uh_create_entry(uint64_t key){
  Entry *e = malloc(sizeof(Entry));
  e->key = key;
  return e;
}

void *uh_destroy_entry(U_Hashtable *hashtable,uint64_t key){
  uint64_t index = ((hashtable->a*key+hashtable->b) % BFP) % hashtable->size;
  Entry *current = hashtable->entries[index];
  if(current != NULL && current->key == key){
    if(current->next_entry != NULL){
      hashtable->entries[index] = current->next_entry;
    }
    free(current->value);
    free(current);
  }
  else{
    Entry *child = current->next_entry;
    while(current != NULL){
      if(child->key == key){
	current->next_entry = child->next_entry;
	free(child->value);
	free(child);
      }
      else{
	current = current->next_entry;
	child = child->next_entry;
      }
    }
  }
}

Entry_Pairs uh_find_entry_pairs(U_Hashtable *hashtable,char *name){
  uint64_t key = s_uint_from_string(name);
  uint64_t index = ((hashtable->a*key+hashtable->b) % BFP) % hashtable->size;
  Entry *current = hashtable->entries[index];
  Entry_Pairs pair;
  pair.offset = index;
  pair.parent = current;
  pair.child = NULL;
  if(current != NULL && ((Item_Holder *)current->value)->item->name == name){
      return pair;
  }
  else{
    Entry *child = current->next_entry;
    while(current != NULL){
      if(((Item_Holder *)current->value)->item->name){
	return pair;
      }
      else{
	current = current->next_entry;
	child = child->next_entry;
      }
    }
   }
    return pair;
  }    
    
Entry *uh_create_entry_item_holder(Item *i, unsigned long long amount){
  uint64_t key = s_uint_from_string(i->name);
  Entry *e = uh_create_entry(key);
  ((Item_Holder *)e->value)->item = i;
  ((Item_Holder *)e->value)->count = amount;
  return e;
}
