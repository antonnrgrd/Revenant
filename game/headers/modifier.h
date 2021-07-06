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
#ifndef MODIFIER
#define MODIFIER
#include <float.h>
typedef struct Material_Modifiers{
  float base_weight_modifier;
  float value_modifier;
  float armor_modifier;
  float dmg_modifier;
}Material_Modifier;

typedef struct Variant_Modifiers{
  float weight_modifier;
  float value_modifier;
  float stats_modifier;
}Variant_Modifier;

extern const Material_Modifier material_modifiers[];

extern  Variant_Modifier variant_modifiers[];

extern Variant_Modifier itemslot_modifiers[];

extern const char* handed_modifier[];


extern const char* material_name_modifier[];

extern const char *quality_name_modifier[];

extern const char *armorslot_name_modifier[];

extern const char *mele_weapon_name_modifier[];

extern const char *weapon_representations[];
#endif
