
#ifndef CREATURE_BEHAVIOR
#define CREATURE_BEHAVIOR
#include "creature.h"
#include "placeholder.h"
#include <math.h>
#include "move_handler.h"
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
/* We want to avoid looking out of bounds of the current zone we are in and so if the range we attempt to look in when looking for a path around an obstacle, we always make sure that we looking within min-max of the */
#define MAX_Y_SEARCH_BOUNDARY(c,current_zone,offset)(((offset+c->position.global_y) > (current_zone->height)) ? (current_zone->height) : (offset+c->position.global_y))
#define MIN_Y_SEARCH_BOUNDARY(c,current_zone,offset)(((offset-c->position.global_y) < (0)) ? (0) : (offset-c->position.global_y))
/* We create separate boundary search macros for x and y coordinates. Technically, a single macro that checks wehther it is the y or x boundary that we are testing for could be devised, but i already have enough ugly-ass macros .*/
#define MAX_X_SEARCH_BOUNDARY(c,current_zone,offset)(((offset+c->position.global_x)> (current_zone->width)) ? (current_zone->width): (offset+c->position.global_x))
#define MIN_X_SEARCH_BOUNDARY(c,current_zone,offset)(((offset-c->position.global_x) < (0)) ? (0) : (offset-c->position.global_x))

#define WITHIN_BOUND 0
#define OUT_OF_BOUND 1
void cb_pursue_target(Creature *c , Creature *target ,Game_World *current_zone);

void cb_from_target(Creature *c , Creature *target ,Game_World *current_zone);

void cb_follow_target(Creature *c , Creature *target ,Game_World *current_zone);

void cb_attack_target(Creature *c , Creature *target ,Game_World *current_zone);

void cb_idle(Creature *c, Creature *target ,Game_World *current_zone);

void (*creature_behavior_handler[4])(Creature *c , Creature *target ,Game_World *current_zone);

void cb_act(Creature *c , Creature *target ,Game_World *current_zone);

void cb_pursure_target_oob(Creature *c, Creature *target ,Game_World *current_zone);

void cb_pursue_target_inb(Creature *c, Creature *target ,Game_World *current_zone);


#endif
