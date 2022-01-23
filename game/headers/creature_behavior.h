
#ifndef CREATURE_BEHAVIOR
#define CREATURE_BEHAVIOR
#include "creature.h"
#include <math.h>
#include "move_handler.h"
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// We want to avoid looking out of bounds of the current zone we are in and so if the range we attempt to look in when looking for a path around an obstacle, we always make sure that we looking within min-max of the 
#define MAX_Y_SEARCH_BOUNDARY(c,current_zone,offset)(((c->position.global_y + offset) > (current_zone->height-1)) ? ((current_zone->height-1) - c->position.global_y) : (offset))
#define MIN_Y_SEARCH_BOUNDARY(c,current_zone,offset)(((c->position.global_y - offset) < (0)) ? (c->position.global_y) : (offset))
// We create separate boundary search macros for x and y coordinates. Technically, a single macro that checks wehther it is the y or x boundary that we are testing for could be devised, but i already have enough ugly-ass macros 
#define MAX_X_SEARCH_BOUNDARY(c,current_zone,offset)(((c->position.global_x + offset) > (current_zone->width - 1)) ? ((current_zone->width-1) - c->position.global_x): (offset))
#define MIN_X_SEARCH_BOUNDARY(c,current_zone,offset)(((c->position.global_x - offset) < (0)) ? (c->position.global_x) : (offset))

#define WITHIN_BOUND 0
#define OUT_OF_BOUND 1
void cb_pursue_target(Creature *c,Game_World *current_zone, WINDOW *draw_screen);

void cb_from_target(Creature *c,Game_World *current_zone, WINDOW *draw_screen);

void cb_follow_target(Creature *c,Game_World *current_zone, WINDOW *draw_screen);

void cb_attack_target(Creature *c,Game_World *current_zone, WINDOW *draw_screen);

void cb_idle(Creature *c,Game_World *current_zone, WINDOW *draw_screen);

extern void (*creature_behavior_handler[4])(Creature *c,Game_World *current_zone, WINDOW *draw_screen);

void cb_act(Creature *c,Game_World *current_zone, WINDOW *draw_screen);

void cb_pursure_target_oob(Creature *c,Game_World *current_zone, WINDOW *draw_screen);

void cb_pursue_target_inb(Creature *c ,Game_World *current_zone, WINDOW *draw_screen);


#endif

