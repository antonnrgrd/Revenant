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
#include "item.h"
#include "modifier.h"
#include <math.h>
 
 
Reagent *i_gen_reagent(Variant variant,float weight,uint32_t value,Reagent_Kind kind){
  Reagent *reagent = malloc(sizeof(Reagent));
  //  reagent->variant = variant;
  reagent->weight = weight;
  reagent->kind = kind;
  return reagent;
}
 
Armor *i_gen_armor(Quality_Level q, Material material, Worn_in w,Equipment_Kind armor_type){
  Armor *arm = malloc(sizeof(armor));
  arm->quality =q;
  arm->material = material;
  arm->slot = w;
  arm->armor_type = armor_type;
  return arm;
}

Weapon *i_gen_weapon(Quality_Level q,Variant variant,Material material,Weapon_Group group,Weapon_Kind k){
  Weapon *weapon = malloc(sizeof(Weapon));
  weapon->quality = q;
  weapon->variant = variant;
  weapon->material = material;
  weapon->kind = k;
  weapon->group =group;
  weapon->slot = mainhand_slot;
  //  printf("&s",mele_weapon_name_modifier[]);
  return weapon;
}

Consumable *i_gen_consumable(uint32_t healing, uint32_t value, float weight, uint16_t skill){
  Consumable *consumable = malloc(sizeof(Consumable));
  consumable->healing = healing;
  //  consumable->weight = weight;
  consumable->skill = skill;
  return consumable;
}


char *i_variant_name(Variant v){
  return s_create_text_const(handed_modifier[v]);
}

char *i_material_name(Material material){
  return s_create_text_const(material_name_modifier[material]);
}

char *i_quality_name(Quality_Level q){
  return s_create_text_const(quality_name_modifier[q]);
}

char *i_armor_name(Quality_Level q, Material material, Worn_in w){
  char *qual =s_create_text_const(quality_name_modifier[q]);
  char *mat = s_create_text_const(material_name_modifier[material]);
  char *slot = s_create_text_const(armorslot_name_modifier[w]);
  char *temp = s_merge_text(qual,mat);
  char *name = s_merge_text(temp,slot);
  return name;
}
char *i_mele_weapon_name(Quality_Level q, Material material, Variant v, Weapon_Kind kind){
  char *qual =s_create_text_const(quality_name_modifier[q]);
  char *mat = s_create_text_const(material_name_modifier[material]);
  char *variant = s_create_text_const(handed_modifier[v]);
  char *kin = s_create_text_const(mele_weapon_name_modifier[kind]);
  char *qq = s_create_text(" quality ");
  char *temp = s_merge_text(qual,qq);
  char *temp1 = s_merge_text(temp,mat);
  char *temp2 = s_merge_text(temp1,variant);
  char *name = s_merge_text(temp2,kin);
  return name;
}

Item *i_make_armor(Quality_Level q, Material material, Worn_in w,Equipment_Kind armor_type){
  Item *i = malloc(sizeof(Item));
  /*
  Material_Modifier m = material_modifiers[material];
  Variant_Modifier v = itemslot_modifiers[w];
  
  
  Armor *a = malloc(sizeof(Armor));
  a->armor = (uint64_t)ceil(m.armor_modifier * v.stats_modifier);
  i->value = (uint32_t)ceil(m.value_modifier * v.value_modifier);
  i->weight = m.base_weight_modifier * v.weight_modifier;
  i->item_specific_info = a;
  */
  i->item_specific_info = i_gen_armor(q,material,w,armor_type);
  i->kind = armor;
  
  
  return i; //needs to assert more attributes
}
Item *i_make_mele_weapon(Quality_Level q, Material material, Variant v, Weapon_Kind weapon_kind){

  Item *i = malloc(sizeof(Item));
  i->representation = s_create_text_const(weapon_representations[1]);
  Weapon *w = i_gen_weapon(q,v,material,mele,weapon_kind);
  i->item_specific_info = w;
  i->kind = weapon;
  Material_Modifier m = material_modifiers[material];
  Variant_Modifier va = variant_modifiers[v];
    
  
  w->dmg = (uint64_t)ceil(m.dmg_modifier * va.stats_modifier);
  i->weight = m.base_weight_modifier*va.weight_modifier;
  
  i->value = (uint32_t)ceil(m.value_modifier * va.value_modifier);
  i->quest_item = 0;
  i->item_specific_info = w;
  i->standing_on = malloc(sizeof(char));
  strcpy(i->representation, weapon_representations[1]);
 
  return i;
}


void i_free_item(Item *i){
  free_item_handler[i->kind](i);
}




void i_free_interactable(Item *i){
  ;
}
void i_free_valuable(Item *i){
  ;
}
void i_free_reagent(Item *i){
  //  free(i->specifier.reagent);
}
void i_free_consumable(Item *i){
  // free(i->specifier.consumable);
}
void i_free_equippable(Item *i){
  /*
  if(i->specifier.equipment.kind == armor){
    free(i->specifier.equipment.armor);
  }
  else{
    free(i->specifier.equipment.weapon);
  }
  */
}


void (*free_item_handler[5])(Item *i) = {i_free_interactable, i_free_valuable, i_free_reagent, i_free_consumable, i_free_equippable};

void (*copy_item_handler[5])(Item *i) = {i_copy_interactable,i_copy_valuable,i_copy_reagent,i_copy_consumable,i_copy_equippable};

Item *i_copy_item(Item *i){
  Item *item = malloc(sizeof(Item));
  copy_item_handler[i->kind](i);
  return item;
}

void i_copy_interactable(Item *i, Item *j){
  return;
}

void i_copy_valuable(Item *i, Item *j){
  return;
}

void i_copy_consumable(Item *i, Item *j){
  return;
}

void i_copy_reagent(Item *i, Item *j){
  return;
}

void i_copy_equippable(Item *i, Item *j){
  /*
  if(i->specifier.equipment.kind == armor){
    j->specifier.equipment.armor = memcpy(&i->specifier.equipment.armor,&i->specifier.equipment.armor, sizeof(Armor) );
  }
  else{
    j->specifier.equipment.weapon = memcpy(&i->specifier.equipment.weapon,&i->specifier.equipment.weapon, sizeof(Weapon) );
    Material_Modifier m = material_modifiers[i->specifier.equipment.weapon->material];
    Variant_Modifier va = variant_modifiers[i->specifier.equipment.weapon->variant];
    j->name = i_mele_weapon_name( i->specifier.equipment.weapon->quality, i->specifier.equipment.weapon->material, i->specifier.equipment.weapon->variant,  i->specifier.equipment.weapon->kind);
    j->weight = m.base_weight_modifier*va.weight_modifier;
    j->description = NULL;
    j->value = (uint32_t)ceil(m.value_modifier * va.value_modifier);
    j->kind = equippable;
    j->quest_item = 0;
    j->specifier.equipment.kind = weaponry;
  }
  */
}

void i_swap_pointers(Item_Holder *i,Item_Holder *j){
  Item_Holder *k;
  k = i;
  i = j;
  j = k;
}

Item_Holder *i_make_item_holder(Item *item, unsigned amount){
  Item_Holder *item_holder = malloc(sizeof(Item_Holder));
  item_holder->item = item;
  item_holder->amount = amount;
  
}

void i_print_reagent_name(Item *i, WINDOW *inv_screen,int x, int y){
  mvwprintw(inv_screen,y,x,i, reagent_definitions[i->id].name);
}

void i_print_consumable_name(Item *i, WINDOW *inv_screen,int x, int y){
  mvwprintw(inv_screen,y,x,i, consumable_definitions[i->id].name);
}

void i_print_equippable_name(Item *i, WINDOW *inv_screen,int x, int y){
  if(i->kind==weapon ){
  mvwprintw("%s",inv_screen,y,x,i, variant_modifiers[((Weapon *)i)->variant]);
  }

  else{
    ;
  }
  
}

extern char* (*i_derive_item_name[3])(Item *i) = {i_derive_item_name_reagent,i_derive_item_name_consumable,i_derive_item_name_equipment};


char *i_derive_item_name_reagent(Item *i){
  return reagent_definitions[i->id].name;
}
char *i_derive_item_name_consumable(Item *i){
  return consumable_definitions[i->id].name;
}
char *i_derive_item_name_equipment(Item *i){
  if(i->kind == weapon){
    Weapon *w = (Weapon *)i->item_specific_info;
    char *weapon_name = quality_name_modifier[w->quality];
    strcat(weapon_name, material_name_modifier[w->material]);
    strcat(weapon_name, handed_modifier[w->variant]);
    strcat(weapon_name,mele_weapon_name_modifier[w->kind]);
    return weapon_name;
  }
  else{
    ;
  }
}

extern Reagent_Definition reagent_definitions[] = {{0,"raw trout", 5.0}};
extern Consumable_Definition consumable_definitions[] = {{0, "apple", 1, 1.3}};
