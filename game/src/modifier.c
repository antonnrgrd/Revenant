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

#include "modifier.h"
extern const char* handed_modifier[]= {" 1-handed"," 2-handed"};

extern const char* material_name_modifier[]={" carbon fiber"," plastic"," clay", " leather"," gold"," silver"," custom", " granite", " marble"," flint"," iron"," bronze"," steel", " mithril", " adamantite", " runite", " titanium", " laser", " plasma", " matterbane"};

extern const char *quality_name_modifier[]={"Poor","Apprenticeship", "Journyman","Masterwork", "Grandmaster","Epic" ,"Legendary","Artefact"};

extern const  char *armorslot_name_modifier[]={" helmet"," necklace"," ring"," chestwear"," leggings"," cape"};

extern const char *mele_weapon_name_modifier[]={" sword"," mace"," axe"};

extern const Material_Modifier material_modifiers[]={{1.75, 135.0, 50, 75}, {0.9,50, 5, 14}, {1.76, 20, 0.0, 5}, {0.76, 40,20,5},{19.2, 800, 0.5, 0.7}, {10.49, 450, 2, 1.5},{19.2, 800, 0.5, 0.7}, {1.0, 1.0, 1.0, 1.0},{2.75, 100, 75, 65},{2.711, 200, 50, 55},{1.39, 80, 40, 30},{7.874, 200, 80 , 90 },{8.8 , 350, 100, 120},{7.85, 300, 90, 100},{4, 900, 150, 200},{12, 1000, 175, 180},{9.8, 3500, 210, 160},{4.5, 700, 100, 120} ,{0.8, 1500, 14.0, 500},{18,5000,500,489} }; //material for material modifers

Variant_Modifier variant_modifiers[] = {{1.2,1,1},{1.5,1.2,1.5}}; //modifier for 1 and 2 handed weapons


extern Variant_Modifier itemslot_modifiers[] = {{0.3, 1.1, 1.3},{0.1, 0.5, 0.3},{0.1, 0.5, 0.3},{4, 5, 10},{3, 4, 8},{2, 1.75, 1.5}}; //abuse of struct name but whatev. a modifier for the slot name i.e how the equipment being a helmet, leggings, etc. affect the stats

extern const char *weapon_representations[] = {"{", "|"};

extern const char *equipment_kind_modifier[] = {"helmet", "hood", "hat","mask", "boots", "shoes"};
