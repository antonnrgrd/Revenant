#ifndef CUCKOO
#define CUCKOO
#include <time.h>
#include "cuckoohash.h"
Cuckoo_T *generate_table(unsigned size){
  Cuckoo_T *table = malloc(sizeof(Cuckoo_T));
  table->first_a = generate_value(1, BFP);
  table->first_b = generate_value(0, BFP);

  table->second_a = generate_value(1, BFP_2);
  table->second_b = generate_value(0, BFP_2);

  table->cur_elements = 0;
  table->max_elements = size-1;

  table->entries = malloc( size * sizeof(Item_Holder *));
  
  return table;
}


unsigned generate_value(unsigned long long min, unsigned long long max){
  return (unsigned) (rand() % (max - min ) +1 );
}



unsigned long long first_offset(unsigned long long key, Cuckoo_T *table ){
  return ((table->first_a*key+table->first_b )) % table->max_elements;
}

unsigned long long second_offset(unsigned long long key, Cuckoo_T *table ){
    return ((table->second_a*key+table-> second_b )) % table->max_elements;
}

/* Absolutely bonkers to define two "insertion" operations , but when rehashing, there are multiple things we need or don't need to handle. I should probably come up with a more clever scheme at some point */
void c_insert_item(Cuckoo_T *table, Item_Holder *i){
  unsigned long long first_adress = first_offset(s_uint_from_string(i->item->name),table);
  if(table->entries[first_adress] == NULL){
    table->entries[first_adress] = i;

  }
  unsigned long long second_adress = second_offset(s_uint_from_string(i->item->name),table);
  if(table->entries[second_adress] == NULL){
    table->entries[second_adress] = i;
  }
  unsigned long long  adress = first_adress;
  for (unsigned j = 0; j < table->cur_elements; j++){
      if(table->entries[adress] == NULL){
	table->entries[adress] = i;
	return;
	i_swap_pointers(table->entries[adress], i);
	if(adress == first_offset(s_uint_from_string(i->item->name),table)){
	  adress = second_offset(s_uint_from_string(i->item->name), table);
	}
	else{
	  adress = first_offset(s_uint_from_string(i->item->name),table);
	}
      }
    }
  table =  rehash_table(table,table->max_elements);
  c_insert_item(table,i);
}

Cuckoo_T *rehash_table(Cuckoo_T *table,unsigned size){
  Cuckoo_T *new_table = generate_table(size);
  for(unsigned i = 0; i < new_table->max_elements; i++){
    if(table->entries[i] != NULL){
      c_insert_item(table,table->entries[i]);
    }
  }
  return new_table;
}
#endif
