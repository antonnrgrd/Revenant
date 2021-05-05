











#ifndef CREATURE_BEHAVIOR
#define CREATURE_BEHAVIOR
#include "creature.h"
#include "placeholder.h"
#include <math.h>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
void cb_pursue_target(Creature *c);

void cb_flee_from_target(Creature *c);

void cb_follow_target(Creature *c);

void cb_attack_target(Creature *c);

#endif
