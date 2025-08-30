/*This file is part of Revenant.
Revenant is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
Revenant  is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with Revenant.  If not, see <https://www.gnu.org/licenses/>. */
#ifnef Q_QUEST_STRUCT
#define Q_QUEST_STRUCT
typedef enum {talk_to,deliver_item,kill_target,reach_location}Q_objective_type;
typedef enum {completed}Q_quest_status;
typedef struct {
  char *name;
  int quest_id;
  int status;
  void *current_objective;
  void *reward;
}Q_Quest;
#endif
