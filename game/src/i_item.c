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
#include "i_item.h"
#include "m_modifier.h"
#include <math.h>
 
I_Armor *i_gen_armor(I_Quality_Level q, I_Material material,I_Equipment_Kind armor_type){
  I_Armor *arm = malloc(sizeof(I_Armor));
  arm->quality =q;
  arm->material = material;
  arm->armor_type = armor_type;
  if(armor_type >= helmet && armor_type <= mask){
    arm->slot = head_slot;
  }
  else if(armor_type >= chestplate && armor_type <= chainmail){
    arm->slot = torso_slot;
  }

  else if(armor_type == boots){
    arm->slot = feet_slot;
  }
  return arm;
}

I_Weapon *i_gen_weapon(I_Quality_Level q,I_Variant variant,I_Material material,I_Weapon_Group group,I_Weapon_Kind k){
  I_Weapon *weapon = malloc(sizeof(I_Weapon));
  weapon->quality = q;
  weapon->variant = variant;
  weapon->material = material;
  weapon->kind = k;
  weapon->group =group;
  weapon->slot = mainhand_slot;
  //  printf("&s",mele_weapon_name_modifier[]);
  return weapon;
}


extern inline void i_derive_item_name(I_Item *i,char *bfr){
  char *fpath = NULL;
  switch(i->kind){
  case reagent:
    fpath = malloc(sizeof(char) * (strlen("/usr/lib/revenant_files/item_files/reagent_files/")) + 5);
    sprintf(fpath,"/usr/lib/revenant_files/item_files/reagent_files/%d",i->id);
    ir_readin_char(fpath,"name",bfr);
    break;
  case consumable:
    fpath = malloc(sizeof(char) * (strlen("/usr/lib/revenant_files/item_files/consumable_files/")) + 5);
    sprintf(fpath,"/usr/lib/revenant_files/item_files/consumable_files/%d",i->id);
    ir_readin_char(fpath,"name",bfr);
    break;
  default:
    break;
  }
  free(fpath);
}

char *i_variant_name(I_Variant v){
  return s_create_text_const(m_handed_modifier[v]);
}

char *i_material_name(I_Material material){
  return s_create_text_const(m_material_name_modifier[material]);
}

char *i_quality_name(I_Quality_Level q){
  return s_create_text_const(m_quality_name_modifier[q]);
}

char *i_mele_weapon_name(I_Quality_Level q, I_Material material, I_Variant v, I_Weapon_Kind kind){
  char *qual =s_create_text_const(m_quality_name_modifier[q]);
  char *mat = s_create_text_const(m_material_name_modifier[material]);
  char *variant = s_create_text_const(m_handed_modifier[v]);
  char *kin = s_create_text_const(m_mele_weapon_name_modifier[kind]);
  char *qq = s_create_text(" quality ");
  char *temp = s_merge_text(qual,qq);
  char *temp1 = s_merge_text(temp,mat);
  char *temp2 = s_merge_text(temp1,variant);
  char *name = s_merge_text(temp2,kin);
  return name;
}

I_Item *i_make_armor(I_Quality_Level q, I_Material material,I_Equipment_Kind armor_type){
  I_Item *i = malloc(sizeof(I_Item));
  /*
  Material_Modifier m = material_modifiers[material];
  Variant_Modifier v = itemslot_modifiers[w];
  
  
  Armor *a = malloc(sizeof(Armor));
  a->armor = (uint64_t)ceil(m.armor_modifier * v.stats_modifier);
  i->value = (uint32_t)ceil(m.value_modifier * v.value_modifier);
  i->weight = m.base_weight_modifier * v.weight_modifier;
  i->item_specific_info = a;
  */
  i->item_specific_info = i_gen_armor(q,material,armor_type);
  i->kind = armor;
  
  
  return i; //needs to assert more attributes
}
I_Item *i_make_mele_weapon(I_Quality_Level q, I_Material material, I_Variant v, I_Weapon_Kind weapon_kind){

  I_Item *i = malloc(sizeof(I_Item));
  
  I_Weapon *w = i_gen_weapon(q,v,material,mele,weapon_kind);
  i->item_specific_info = w;
  i->kind = weapon;
  M_Material_Modifier m = m_material_modifiers[material];
  M_Variant_Modifier va = m_variant_modifiers[v];
    
  
  w->dmg = (uint64_t)ceil(m.dmg_modifier * va.stats_modifier);
  i->weight = m.base_weight_modifier*va.weight_modifier;
  
  i->value = (uint32_t)ceil(m.value_modifier * va.value_modifier);
  i->item_specific_info = w;
  strcpy(i->representation, m_weapon_representations[1]);
 
  return i;
}





void i_free_interactable(I_Item *item){
  ;
}
void i_free_valuable(I_Item *item){
  ;
}
void i_free_reagent(I_Item *item){
  free((I_Reagent *)item->item_specific_info);
}
void i_free_consumable(I_Item *item){
  free((I_Consumable *)item->item_specific_info);
}

void i_free_armor(I_Item *item){
  free((I_Armor *)item->item_specific_info);
}








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


void i_swap_pointers(I_Item_Holder *i,I_Item_Holder *j){
  I_Item_Holder *k;
  k = i;
  i = j;
  j = k;
}

I_Item_Holder *i_make_item_holder(I_Item *item, unsigned amount){
  I_Item_Holder *item_holder = malloc(sizeof(I_Item_Holder));
  item_holder->item = item;
  item_holder->amount = amount;
  
}


void i_print_equippable_name(I_Item *i, WINDOW *inv_screen,int x, int y){
  if(i->kind==weapon ){
  mvwprintw("%s",inv_screen,y,x,i, m_variant_modifiers[((I_Weapon *)i)->variant]);
  }

  else{
    ;
  }
  
}


char *i_derive_item_name_equipment(I_Item *i){
  if(i->kind == weapon){
    I_Weapon *w = (I_Weapon *)i->item_specific_info;
    char *weapon_name = m_quality_name_modifier[w->quality];
    strcat(weapon_name, m_material_name_modifier[w->material]);
    strcat(weapon_name, m_handed_modifier[w->variant]);
    strcat(weapon_name,m_mele_weapon_name_modifier[w->kind]);
    return weapon_name;
  }
  else{
    ;
  }
}

char *i_get_name(I_Item *i){
  /*
  char *name = NULL;
  char *bfr = NULL;
  char *myname = ir_readin_char("/usr/lib/revenant_files/item_files/reagent_files/0","name");
  switch(i->kind){
  case reagent:
    printf("%d",strlen("/usr/lib/revenant_files/item_files/reagent_files/"));
    bfr = malloc(sizeof(char) * (strlen("/usr/lib/revenant_files/item_files/reagent_files/")) + 5);
    sprintf(bfr,"/usr/lib/revenant_files/item_files/reagent_files/%d",i->id);
    char mybfr[60];
    sprintf(mybfr,"/usr/lib/revenant_files/item_files/reagent_files/%d",i->id);
    //    char *myname = ir_readin_char("/usr/lib/revenant_files/item_files/reagent_files/0","name");
    name = ir_readin_char(bfr,"name");
    break;
  case consumable:
    bfr = malloc(sizeof(char) * (strlen("/usr/lib/revenant_files/item_files/consumable_files/")) + 5);
    sprintf(bfr,"/usr/lib/revenant_files/item_files/consumable_files/%d",i->id);
    name = malloc(sizeof(char));
    break;
  free(bfr);
  return name;
  }
  */
  char *file_path_bfr = malloc(sizeof(char) * strlen("/usr/lib/revenant_files/creature_files/") +5);
  sprintf(file_path_bfr,"/usr/lib/revenant_files/creature_files/%d",i->id);
  char *name = ir_readin_char(file_path_bfr, "name");
  return name;
}


void i_copy_reagent(I_Item_Holder *source_item,I_Item_Holder *target_item){
  source_item->item->item_specific_info = malloc(sizeof(I_Reagent));
  ((I_Reagent *)source_item->item->item_specific_info)->reagent_kind = ((I_Reagent *)target_item->item->item_specific_info)->reagent_kind;
  ((I_Reagent *)source_item->item->item_specific_info)->id = ((I_Reagent *)target_item->item->item_specific_info)->id;
}

void i_copy_consumable(I_Item_Holder *source_item,I_Item_Holder *target_item){
  source_item->item->item_specific_info = malloc(sizeof(I_Consumable));
  ((I_Consumable *)source_item->item->item_specific_info)->id = ((I_Consumable *)target_item->item->item_specific_info)->id;
  ((I_Consumable *)source_item->item->item_specific_info)->hp_change = ((I_Consumable *)target_item->item->item_specific_info)->hp_change;
}

void i_copy_armor(I_Item_Holder *source_item,I_Item_Holder *target_item){
  source_item->item->item_specific_info = malloc(sizeof(I_Armor));
  ((I_Armor *)source_item->item->item_specific_info)->quality = ((I_Armor *)target_item->item->item_specific_info)->quality;
  ((I_Armor *)source_item->item->item_specific_info)->armor = ((I_Armor *)target_item->item->item_specific_info)->armor;
  ((I_Armor *)source_item->item->item_specific_info)->slot = ((I_Armor *)target_item->item->item_specific_info)->slot;
  ((I_Armor *)source_item->item->item_specific_info)->material = ((I_Armor *)target_item->item->item_specific_info)->material;
  ((I_Armor *)source_item->item->item_specific_info)->skill = ((I_Armor *)target_item->item->item_specific_info)->skill;
  ((I_Armor *)source_item->item->item_specific_info)->armor = ((I_Armor *)target_item->item->item_specific_info)->armor;
  ((I_Armor *)source_item->item->item_specific_info)->weight_classification = ((I_Armor *)target_item->item->item_specific_info)->weight_classification;
}

void i_copy_weapon(I_Item_Holder *source_item,I_Item_Holder *target_item){
  source_item->item->item_specific_info = malloc(sizeof(I_Weapon));
  ((I_Weapon *)source_item->item->item_specific_info)->quality = ((I_Weapon *)target_item->item->item_specific_info)->quality;
  ((I_Weapon *)source_item->item->item_specific_info)->material = ((I_Weapon *)target_item->item->item_specific_info)->material;
  ((I_Weapon *)source_item->item->item_specific_info)->variant = ((I_Weapon *)target_item->item->item_specific_info)->variant;
  ((I_Weapon *)source_item->item->item_specific_info)->kind = ((I_Weapon *)target_item->item->item_specific_info)->kind;
  ((I_Weapon *)source_item->item->item_specific_info)->slot = ((I_Weapon *)target_item->item->item_specific_info)->slot;
  ((I_Weapon *)source_item->item->item_specific_info)->group = ((I_Weapon *)target_item->item->item_specific_info)->group;
}

/*
void i_copy_reagent(Item *source_item,Item_Holder *target_item){
  source_item->item_specific_info = malloc(sizeof(Reagent));
  ((Reagent *)source_item->item_specific_info)->reagent_kind = ((Reagent *)target_item->item->item_specific_info)->reagent_kind;
  ((Reagent *)source_item->item_specific_info)->id = ((Reagent *)target_item->item->item_specific_info)->id;
}

void i_copy_consumable(Item *source_item,Item_Holder *target_item){
  source_item->item_specific_info = malloc(sizeof(Consumable));
  ((Consumable *)source_item->item_specific_info)->id = ((Consumable *)target_item->item->item_specific_info)->id;
  ((Consumable *)source_item->item_specific_info)->hp_change = ((Consumable *)target_item->item->item_specific_info)->hp_change;
}

void i_copy_armor(Item *source_item,Item_Holder *target_item){
  source_item->item_specific_info = malloc(sizeof(Armor));
  ((Armor *)source_item->item_specific_info)->quality = ((Armor *)target_item->item->item_specific_info)->quality;
  ((Armor *)source_item->item_specific_info)->armor = ((Armor *)target_item->item->item_specific_info)->armor;
  ((Armor *)source_item->item_specific_info)->slot = ((Armor *)target_item->item->item_specific_info)->slot;
  ((Armor *)source_item->item_specific_info)->material = ((Armor *)target_item->item->item_specific_info)->material;
  ((Armor *)source_item->item_specific_info)->skill = ((Armor *)target_item->item->item_specific_info)->skill;
  ((Armor *)source_item->item_specific_info)->armor = ((Armor *)target_item->item->item_specific_info)->armor;
  ((Armor *)source_item->item_specific_info)->weight_classification = ((Armor *)target_item->item->item_specific_info)->weight_classification;
}

void i_copy_weapon(Item *source_item,Item_Holder *target_item){
  source_item->item_specific_info = malloc(sizeof(Weapon));
  ((Weapon *)source_item->item_specific_info)->quality = ((Weapon *)target_item->item->item_specific_info)->quality;
  ((Weapon *)source_item->item_specific_info)->variant = ((Weapon *)target_item->item->item_specific_info)->variant;
  ((Weapon *)source_item->item_specific_info)->material = ((Weapon *)target_item->item->item_specific_info)->material;
}
*/

extern void (*i_free_item_specific_info_handler[4])(I_Item *item) = {i_free_reagent,i_free_consumable , i_free_weapon,i_free_armor};

extern void (*i_item_holder_copy_handler[4])(I_Item_Holder *source_item,I_Item_Holder *target_item) = {i_copy_reagent, i_copy_consumable, i_copy_weapon,i_copy_armor};

void i_free_weapon(I_Item *item){
  free((I_Weapon *)item->item_specific_info);
}

/* 19-01-2025 verified it frees all data */
void i_free_item_holder(I_Item_Holder *item_holder){
  I_FREE_ITEM(item_holder->item);
  FREE_NULL(item_holder);
}
