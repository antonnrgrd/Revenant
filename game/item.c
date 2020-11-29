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
  reagent->variant = variant;
  reagent->weight = weight;
  reagent->kind = kind;
  return reagent;
}

Armor *i_gen_armor(){
  Armor *arm = malloc(sizeof(armor));
  return arm;
}

Weapon *i_gen_mele_weapon(Quality_Level q,Variant variant,Material material,Wkind kind,uint16_t skill,Mele_Weapon_Kind k){
  Weapon *weapon = malloc(sizeof(weapon));
  weapon->variant = variant;
  weapon->material = material;
  weapon->kind = kind;
  weapon->skill = skill;
  //  item->name = i_weapon_name(q,material,v,k);
  return weapon;
}

Consumable *i_gen_consumable(uint32_t healing, uint32_t value, float weight, uint16_t skill){
  Consumable *consumable = malloc(sizeof(Consumable));
  consumable->healing = healing;
  consumable->weight = weight;
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
char *i_mele_weapon_name(Quality_Level q, Material material, Variant v, Mele_Weapon_Kind kind){
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

Item *i_make_armor(Quality_Level q, Material material, Worn_in w){
  Material_Modifier m = material_modifiers[material];
  Variant_Modifier v = itemslot_modifiers[w];
  Item *i = malloc(sizeof(Item));
  Armor *a = malloc(sizeof(Armor));//redundant, to be cleaned up
  a->armor = (uint64_t)ceil(m.armor_modifier * v.stats_modifier);
  a->skill = 10;
  a->slot = w;
  a->material = material;
  i->value = (uint32_t)ceil(m.value_modifier * v.value_modifier);
  i->weight = m.base_weight_modifier * v.weight_modifier;
  i->specifier.equipment.armor = a;

  i->name = i_armor_name(q,material,w);
  i->description = NULL;
  i->kind = armor;
  i->quest_item = 0; //doesn't belong to any quest if 0
  return i; //needs to assert more attributes
}
void i_armor_info(Item *i){
  printf("%s%s", i->name,"\n");
  printf("%s%f%s", "Its weight is " ,i->weight," kilos \n");
  printf("%s%d%s", "Its value is " ,i->value," gold \n");
  printf("%s%ld%s","It provides ", i->specifier.equipment.armor->armor, " armor \n");
}
Item *i_make_mele_weapon(Quality_Level q, Material material, Variant v, Mele_Weapon_Kind kind){
  Item *i = malloc(sizeof(Item));
  Weapon *w = malloc(sizeof(Weapon));
  Material_Modifier m = material_modifiers[material];
  Variant_Modifier va = variant_modifiers[v];
  w->variant = v;
  w->quality = q;
  w->material = material;
  w->kind = mele;
  w->type = kind;
  w->skill = 15;
  w->dmg = (uint64_t)ceil(m.dmg_modifier * va.stats_modifier);
  i->name = i_mele_weapon_name( q, material, v,  kind);
  i->weight = m.base_weight_modifier*va.weight_modifier;
  i->description = NULL;
  i->value = (uint32_t)ceil(m.value_modifier * va.value_modifier);
  i->kind = equippable;
  i->quest_item = 0;
  i->specifier.equipment.kind = weaponry;
  i->specifier.equipment.weapon = w;
  return i;
}

void i_mele_weapon_info(Item *i){
  printf("%s%s", i->name,"\n");
  printf("%s%f%s", "Its weight is " ,i->weight," kilos \n");
  printf("%s%d%s", "Its value is " ,i->value," gold \n");
  printf("%s%ld%s","It does a minimum of  ", i->specifier.equipment.weapon->dmg, " damage \n");
}

Item *i_make_weapon_or_shield(Equipment_Kind k,Material material, Variant v, Worn_in w,Quality_Level q,Mele_Weapon_Kind kind){
  if(k == weaponry){ //needs to have added case for armor later to as to initialize a humanoid enemy with a shield as ooposed to an offhand weapon
    Item *i = i_make_mele_weapon(q,material,v,kind);
    return i;
  }
}

void i_free_item(Item *i){
  free_item_handler[i->kind](i);
  free(i->name);
  free(i->description);
}



/*to be implemented */
void i_free_interactable(Item *i){
  ;
}
void i_free_valuable(Item *i){
  ;
}
void i_free_reagent(Item *i){
  free(i->specifier.reagent);
}
void i_free_consumable(Item *i){
  free(i->specifier.consumable);
}
void i_free_equippable(Item *i){
  if(i->specifier.equipment.kind == armor){
    free(i->specifier.equipment.armor);
  }
  else{
    free(i->specifier.equipment.weapon);
  }
}


void (*free_item_handler[5])() = {i_free_interactable, i_free_valuable, i_free_reagent, i_free_consumable, i_free_equippable};

void (*copy_item_handler[5])()= {i_copy_interactable,i_copy_valuable,i_copy_reagent,i_copy_consumable,i_copy_equippable};

Item *i_copy_item(Item *i){
  Item *item = malloc(sizeof(Item));
  copy_item_handler[i->kind](i,item);
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
}

void i_swap_pointers(Item_Holder *i,Item_Holder *j){
  Item_Holder *k;
  k = i;
  i = j;
  j = k;
}
