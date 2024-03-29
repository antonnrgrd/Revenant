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
 
Armor *i_gen_armor(Quality_Level q, Material material,Equipment_Kind armor_type){
  Armor *arm = malloc(sizeof(Armor));
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


extern inline void i_derive_item_name(Item *i,char *bfr){
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

char *i_variant_name(Variant v){
  return s_create_text_const(handed_modifier[v]);
}

char *i_material_name(Material material){
  return s_create_text_const(material_name_modifier[material]);
}

char *i_quality_name(Quality_Level q){
  return s_create_text_const(quality_name_modifier[q]);
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

Item *i_make_armor(Quality_Level q, Material material,Equipment_Kind armor_type){
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
  i->item_specific_info = i_gen_armor(q,material,armor_type);
  i->kind = armor;
  
  
  return i; //needs to assert more attributes
}
Item *i_make_mele_weapon(Quality_Level q, Material material, Variant v, Weapon_Kind weapon_kind){

  Item *i = malloc(sizeof(Item));
  
  Weapon *w = i_gen_weapon(q,v,material,mele,weapon_kind);
  i->item_specific_info = w;
  i->kind = weapon;
  Material_Modifier m = material_modifiers[material];
  Variant_Modifier va = variant_modifiers[v];
    
  
  w->dmg = (uint64_t)ceil(m.dmg_modifier * va.stats_modifier);
  i->weight = m.base_weight_modifier*va.weight_modifier;
  
  i->value = (uint32_t)ceil(m.value_modifier * va.value_modifier);
  i->item_specific_info = w;
  strcpy(i->representation, weapon_representations[1]);
 
  return i;
}





void i_free_interactable(Item_Holder *item){
  ;
}
void i_free_valuable(Item_Holder *item){
  ;
}
void i_free_reagent(Item_Holder *item){
  free((Reagent *)item->item->item_specific_info);
}
void i_free_consumable(Item_Holder *item){
  free((Consumable *)item->item->item_specific_info);
}

void i_free_armor(Item_Holder *item){
  free((Armor *)item->item->item_specific_info);
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


void i_print_equippable_name(Item *i, WINDOW *inv_screen,int x, int y){
  if(i->kind==weapon ){
  mvwprintw("%s",inv_screen,y,x,i, variant_modifiers[((Weapon *)i)->variant]);
  }

  else{
    ;
  }
  
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

char *i_get_name(Item *i){
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


void i_copy_reagent(Item_Holder *source_item,Item_Holder *target_item){
  source_item->item->item_specific_info = malloc(sizeof(Reagent));
  ((Reagent *)source_item->item->item_specific_info)->reagent_kind = ((Reagent *)target_item->item->item_specific_info)->reagent_kind;
  ((Reagent *)source_item->item->item_specific_info)->id = ((Reagent *)target_item->item->item_specific_info)->id;
}

void i_copy_consumable(Item_Holder *source_item,Item_Holder *target_item){
  source_item->item->item_specific_info = malloc(sizeof(Consumable));
  ((Consumable *)source_item->item->item_specific_info)->id = ((Consumable *)target_item->item->item_specific_info)->id;
  ((Consumable *)source_item->item->item_specific_info)->hp_change = ((Consumable *)target_item->item->item_specific_info)->hp_change;
}

void i_copy_armor(Item_Holder *source_item,Item_Holder *target_item){
  source_item->item->item_specific_info = malloc(sizeof(Armor));
  ((Armor *)source_item->item->item_specific_info)->quality = ((Armor *)target_item->item->item_specific_info)->quality;
  ((Armor *)source_item->item->item_specific_info)->armor = ((Armor *)target_item->item->item_specific_info)->armor;
  ((Armor *)source_item->item->item_specific_info)->slot = ((Armor *)target_item->item->item_specific_info)->slot;
  ((Armor *)source_item->item->item_specific_info)->material = ((Armor *)target_item->item->item_specific_info)->material;
  ((Armor *)source_item->item->item_specific_info)->skill = ((Armor *)target_item->item->item_specific_info)->skill;
  ((Armor *)source_item->item->item_specific_info)->armor = ((Armor *)target_item->item->item_specific_info)->armor;
  ((Armor *)source_item->item->item_specific_info)->weight_classification = ((Armor *)target_item->item->item_specific_info)->weight_classification;
}

void i_copy_weapon(Item_Holder *source_item,Item_Holder *target_item){
  source_item->item->item_specific_info = malloc(sizeof(Weapon));
  ((Weapon *)source_item->item->item_specific_info)->quality = ((Weapon *)target_item->item->item_specific_info)->quality;
  ((Weapon *)source_item->item->item_specific_info)->material = ((Weapon *)target_item->item->item_specific_info)->material;
  ((Weapon *)source_item->item->item_specific_info)->variant = ((Weapon *)target_item->item->item_specific_info)->variant;
  ((Weapon *)source_item->item->item_specific_info)->kind = ((Weapon *)target_item->item->item_specific_info)->kind;
  ((Weapon *)source_item->item->item_specific_info)->slot = ((Weapon *)target_item->item->item_specific_info)->slot;
  ((Weapon *)source_item->item->item_specific_info)->group = ((Weapon *)target_item->item->item_specific_info)->group;
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

extern void (*i_free_item_handler[4])(Item_Holder *item) = {i_free_reagent,i_free_consumable , i_free_weapon,i_free_armor};

extern void (*i_item_holder_copy_handler[4])(Item_Holder *source_item,Item_Holder *target_item) = {i_copy_reagent, i_copy_consumable, i_copy_weapon,i_copy_armor};

void i_free_weapon(Item_Holder *item){
  free((Weapon *)item->item->item_specific_info);
}
