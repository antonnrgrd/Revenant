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
#ifndef DIALOGUE_STRUCT
#define DIALOGUE_STRUCT
#define DIA_END_DIALOGUE 0
#define DIA_CONTINUE_DIALOGUE 1
#define DIA_NO_NEXT_DIALOGUE_ID -1
#define DIA_NO_SKILLCHECK -1
#define DIA_NO_SKILL_ID -1
#define DIA_NULL_AMOUNT_DIALOGUE_OPTIONS -1

typedef struct {
  /*the id of the folder we should look in for the dialogue files*/
  int dialogue_folder_id;
  /*The id of the initial dialogue file the player should see upon engaging conversation*/
  int initial_dialogue_id;
  /**/
  int npc_id;
  int num_dialogue_options;
  int current_dialogue_id;
  int next_char_offset;
  int prev_char_offset;
  int *saved_prev_offsets;
  int current_saved_offset_index;
  int encountered_double_lf;
  int set_offset;
  /*Note: if using single bit, bit-packed values, you need to use an unsigned int. If you use a regular signed int, you need at least two bits worth, in order to be able to differentiate between positive and negative numbers, otherwise, you get unusual behavior */
  unsigned int reached_eof : 1;
  /*In the event that the text file fits into a single window, we need to keep extra track of this to avoid unecessarily updating the next and prev char offsets. I don't know if we already store sufficient logic to check this but at this point i am too lazy and have spendt too much time to bother coming up with a more clever solution */
  unsigned int single_page_file : 1;
}Dia_Dialogue_Manager;

typedef struct{
  short set_next_offset;
  short set_prev_offset;
}Dia_Offset_Changes;
#endif
