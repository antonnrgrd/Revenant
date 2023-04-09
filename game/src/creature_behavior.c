#include "creature_behavior.h"
#include "status.h"

void cb_pursue_target(Creature *c,Game_State *game_state){
  /*Future note to self: we make the same check for the in-bound variant of the pursue method for every possible direction, perhaps there is some potential for simplyfying the logic
as the check here has already decided that the distance in at least one direction is greater than 1, i.e it is possible to make a move that brings the creature closer to its target*/
  if((abs(c->position.global_y - c->target->position.global_y)) > 1 || (abs(c->position.global_x - c->target->position.global_x)) > 1){
 // We use the in-bounds pursuing strategy ONLY if the the target the creature is pursuing is within the viewing distance of the player X and Y coordinate-wise, because that in turn is both necessary and sufficient for the creature to be within-view of the player   
  if(WITHIN_X_BOUNDS(c,c->target) & WITHIN_Y_BOUNDS(c,c->target) == WITHIN_BOUNDS){

    c->target_is_within_bound = WITHIN_BOUND;
  }
  else{
    c->target_is_within_bound = OUT_OF_BOUND;    
  }
  if(c->target_is_within_bound == WITHIN_BOUND){
    
    cb_pursue_target_inb(c,game_state);
  }
      
  else{
    cb_pursure_target_oob(c,game_state);
  }
   }
}
  

  void cb_attack_target(Creature *c,Game_State *game_state){
  if(abs(c->position.global_y - c->target->position.global_y ) <= 1 && abs(c->position.global_x - c->target->position.global_x ) <= 1){
    //we subtract 1 from limb count since an array of n limbs has a max index of n-1
    Limb attacking_limb = c->limbs[GEN_VALUE_RANGE(0,c->limb_count-1, game_state->twister)];
    CLEAR_MSG_LINE();
    //    mvwprintw(game_state->logs[MAIN_SCREEN],DEFAULT_MAX_Y,0, "%s%s%d%s", c_retrieve_creature_name(c) , " hits you for ", 10, " damage");
    ir_print_damage_to_creature(game_state,c,c->target);
    msg_update_event_log(game_state);
    if(c->target->curr_health <= 0){
    ST_SET_FLAG_BIT(c->target, DEAD);
    CLEAR_MSG_LINE();
    mvwprintw(game_state->logs[MAIN_SCREEN],DEFAULT_MAX_Y,0, "%s", "You have died");
    msg_update_event_log(game_state);
    }
    
    else{
    CLEAR_MSG_LINE();
    //    mvwprintw(game_state->logs[MAIN_SCREEN],DEFAULT_MAX_Y,0, "%s%s%s%d%s", c_retrieve_creature_name(c) , " hits", c_retrieve_creature_name(c->target),  " for ", 10, " damage");
    msg_update_event_log(game_state);
    }
  }
  else{
    cb_pursue_target(c,game_state);
  }
  
}

void cb_idle(Creature *c,Game_State *game_state){
  ;
}

//Note to self, if i ever in the future have an error with the creatures, it's because i'm a fool and didn't realize you specify coordinates y,x, not x,y and managed to change this in a couple of places. I went through the code and changed it back to the correct order, but i might have missed a few places. subnote: simplify statemens by grouping them toegther in a macro at some point 
void cb_roam(Creature *c,Game_State *game_state){
  int direction =  (rand() % (5 -  0 + 1) + 1);
  // Important: we evaluate if the change in position exceeds the boundary of the game map, THEN check if the tile we try to move to is validto avoid the possibility of accessing an offset outside of the malloc'ed area to avoid segmentation faults. THis is due to logical AND short circuiting (if the first statement is false, don't evluate the second) 
   if(direction == UP){
     if(c->position.global_y+1 < game_state->current_zone->height && numerical_responses[game_state->current_zone->tiles[c->position.global_y+1][c->position.global_x].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y+1][c->position.global_x].foe == NULL ){
       game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
       c->position.global_y++;
       c->position.local_y++;
       if(abs(c->position.global_x - c->target->position.global_x) <= DEFAULT_MAX_Y -1){	 
	 mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on);
	 mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
    }
       c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
       game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
       game_state->current_zone->tiles[c->position.global_y-1][c->position.global_x].foe = NULL;
       game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
     }
   }
   
   if(direction == DOWN){
     if( c->position.global_y-1 > -1 && numerical_responses[game_state->current_zone->tiles[c->position.global_y-1][c->position.global_x].content[0]] != 1){
       game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
       mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on[0]);
       c->position.global_y--;
       c->position.local_y--;
       if(abs(c->position.global_x - c->target->position.global_x) <= DEFAULT_MAX_Y -1){
	  mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on[0]);	  
	  mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
    }
       c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
       game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
       game_state->current_zone->tiles[c->position.global_y+1][c->position.global_x].foe = NULL;
       game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
     }
   }
       
     
   


   if(direction == LEFT){
     if( c->position.global_x-1 > -1 && numerical_responses[game_state->current_zone->tiles[c->position.global_y][c->position.global_x-1].content[0]] != 1){
       mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on);
       game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
       c->position.global_x--;
       c->position.local_x--;
       if(abs(c->position.global_x - c->target->position.global_x) <= DEFAULT_MAX_X -1){
	  mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
    }
       c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
       game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
       game_state->current_zone->tiles[c->position.global_y][c->position.global_x+1].foe = NULL;
       game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
     }
   }

       
  
     
   
   if(direction == RIGHT){
     if(c->position.global_x+1 < game_state->current_zone->width && numerical_responses[game_state->current_zone->tiles[c->position.global_y][c->position.global_x+1].content[0]] != 1){
       mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on);
       game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
       c->position.global_x++;
       c->position.local_x++;
       if(abs(c->position.global_x - c->target->position.global_x) <= DEFAULT_MAX_X -1){	  
	 mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
       }
       c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
       game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
       game_state->current_zone->tiles[c->position.global_y][c->position.global_x-1].foe = NULL;
       game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
     }
   }
}



void cb_flee_target(Creature *c,Game_State *game_state){
  ;
}

//Function to have a creature pursue a target when it is out of the player's view boundary. We don't make the usual check to see if it is a passable tile the creature is trying to step on. We choose not to, because otherwise, we would end up having to do arbitrarily complex checks to move around objects, detcet if the creature is stuck and if it is stuck, get unstuck, etc. concrete cases will be written in the manual at some point

  void cb_pursure_target_oob(Creature *c,Game_State *game_state){
  // In order to pursue a target, we effectively try out all moves the creature can take to move closer to the current target. Provided the
  // distance becomes smaller and it is a valid tile to step on, make a move 
  
  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
  // moving up 
  if( (abs(c->position.global_y+1 - c->target->position.global_y ) < abs(c->position.global_x - c->target->position.global_x ))){
    c->position.global_y +=1;
    c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
    game_state->current_zone->tiles[c->position.global_y-1][c->position.global_x].foe = NULL;
    if(c->position.local_y+1 >  DEFAULT_MAX_Y - 1){
      c->position.local_y = 0;
    }
    else{
      c->position.local_y += 1;
     }
    //If we have made a move, we jump to the label in the function where we assert if the creature is now within the player's view because otherwise, because how we check if a move affects the distance between creature and target, a move that undoes the movement just made might now become valid. e.g making a move down might making a move up valid, undoing the move down.
     
    goto CHECK_WITHIN_BOUNDS;
    }

  // Moving down 
  if( (abs(c->position.global_y-1 - c->target->position.global_y ) < abs(c->position.global_x - c->target->position.global_x ))){
    c->position.global_y -= 1;
    c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
    game_state->current_zone->tiles[c->position.global_y+1][c->position.global_x].foe = NULL;
    if(c->position.local_y-1 <  0){
      c->position.local_y = DEFAULT_MAX_Y - 1;
    }
    else{
      c->position.local_y -= 1;
    }
    goto CHECK_WITHIN_BOUNDS;
  }
    // move right 
  if( (abs(c->position.global_x+1 - c->target->position.global_x ) < abs(c->position.global_x - c->target->position.global_x ))){
	c->position.global_x += 1;
	c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	game_state->current_zone->tiles[c->position.global_y][c->position.global_x-1].foe = NULL;
    if(c->position.local_x+1 >  DEFAULT_MAX_X - 1){
      c->position.local_x = 0;
    }
    else{
      c->position.local_x += 1;
     }
    goto CHECK_WITHIN_BOUNDS;
  }
// move left 

  if( (abs(c->position.global_x-1 -c->target->position.global_x ) < abs( c->position.global_x - c->target->position.global_x ))){

    c->position.global_x -= 1;
    c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
    game_state->current_zone->tiles[c->position.global_y][c->position.global_x+1].foe = NULL;
    
    if(c->position.local_x-1 < 0  ){
      c->position.local_x = DEFAULT_MAX_X - 1;
    }
    else{
      c->position.local_x -= 1;
    }
    
    goto CHECK_WITHIN_BOUNDS;
  }

  
 CHECK_WITHIN_BOUNDS:  
  c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
  //Finally, if the creature is now within the view distance of the player, draw it 
  
  if(WITHIN_X_BOUNDS(c,c->target) & WITHIN_Y_BOUNDS(c,c->target) == WITHIN_BOUNDS){
    
    mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
    }
}

//Make additional check if a creature is standing on the on i.e it has an opponent struct in its foe pointer

      //mimmic pursuing behavior when the creature is within the players POW. Now, we HAVE to check if the tile it moves to is valid, because here the creature will be visible to the player 
void cb_pursue_target_inb(Creature *c,Game_State *game_state){
  int direction;
  
  // We check both that we get closer to the target AND that the distance is greater than 1, because a distance of only one implies we are standing right next to the target
  
  //Move Down
  if( (abs(c->position.global_y+1 - c->target->position.global_y )) < (abs(c->position.global_y - c->target->position.global_y)) && (abs(c->position.global_y - c->target->position.global_y)) > 1 ) {
    // We don't move horizontally/vertically if we previously have made a move along said axis, in an attempt to move around an object, because otherwise, moving along said axis might undo the move we just made in an attempt to navigate around an obstacle, e.g go back one tile to where we initally got stuck
    if(c->has_moved_around_vertically != 1){
    direction = DOWN;
    if(numerical_responses[game_state->current_zone->tiles[c->position.global_y+1][c->position.global_x].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y+1][c->position.global_x].foe == NULL){
     // If we have successfully made a move along any axis, we un-register that we made a move along the opposite axis, because the fact that we moved along said axis, implies that we are no longer stuck and thus no longer need to be aware of moving back to the inital position where we got stuck
    c->has_moved_around_horizontally = 0;
    game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
    mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on);
    c->position.global_y +=1;
    c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
    game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
    game_state->current_zone->tiles[c->position.global_y-1][c->position.global_x].foe = NULL;
    game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
    if(c->position.local_y+1 >  DEFAULT_MAX_Y - 1){
      c->position.local_y = 0;
    }
    else{
      c->position.local_y += 1;
     }
    mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
    return;
    }
    }
    
}

  //Moving UP 
    if( (abs(c->position.global_y-1 - c->target->position.global_y )) < (abs(c->position.global_y - c->target->position.global_y)) && (abs(c->position.global_y - c->target->position.global_y)) > 1 ){
      if(c->has_moved_around_vertically != 1){
    direction = UP;

    if(numerical_responses[game_state->current_zone->tiles[c->position.global_y-1][c->position.global_x].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y-1][c->position.global_x].foe == NULL ){
      c->has_moved_around_horizontally = 0;
      game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
      mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on);
      c->position.global_y -=1;
      c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
      game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
      game_state->current_zone->tiles[c->position.global_y+1][c->position.global_x].foe = NULL;
      game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
    if(c->position.local_y-1 <  1){
      c->position.local_y = DEFAULT_MAX_Y - 1;
    }
    else{
      c->position.local_y -= 1;
    }
    mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
     return;
    }
      }
    
  }

  
  //move right 
  
  
    if( (abs(c->position.global_x+1 - c->target->position.global_x )) < (abs(c->position.global_x - c->target->position.global_x )) && (abs(c->position.global_x - c->target->position.global_x)) > 1 ){
      if(c->has_moved_around_horizontally != 1){
    direction = RIGHT;
    if(numerical_responses[game_state->current_zone->tiles[c->position.global_y][c->position.global_x+1].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y][c->position.global_x+1].foe == NULL){
      c->has_moved_around_vertically = 0;
      game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
       mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on);
	c->position.global_x +=1;
	c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
	game_state->current_zone->tiles[c->position.global_y][c->position.global_x-1].foe = NULL;
	game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
    if(c->position.local_x+1 >  DEFAULT_MAX_X - 1){
      c->position.local_x = 0;
    }
    else{
      c->position.local_x += 1;
     }
    mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
     return;
    }

      }
  }

  // move left 
  
  if( (abs(c->position.global_x-1 - c->target->position.global_x )) < (abs(c->position.global_x - c->target->position.global_x )) && (abs(c->position.global_x - c->target->position.global_x) > 1)){
    if(c->has_moved_around_horizontally != 1){
    direction = LEFT;
    if(numerical_responses[game_state->current_zone->tiles[c->position.global_y][c->position.global_x-1].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y][c->position.global_x-1].foe == NULL){
      c->has_moved_around_vertically = 0;
      game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
    mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on);
    c->position.global_x -=1;
    c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
    game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
    game_state->current_zone->tiles[c->position.global_y][c->position.global_x+1].foe = NULL;
    game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
    if(c->position.local_x - 1 < 0  ){
      c->position.local_x = DEFAULT_MAX_X - 1;
    }
    else{
      c->position.local_x -= 1;
    }
    mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
    return;
 }
    }
      }

  // If we failed to make a move that directly makes progress towards the target it is pursuing, find a "move" that helps us navigate around the obstacle. For the sake of computational effeciency, we do so by checking a max range of 10 tiles (5 tiles either way around the obstacle tile) that could potentially provide a path around. If moving either way aroudn the obstacle eventually provides a clear path, just take it.This very basic scheme is for the sake of simplicity.
  
  if(direction == LEFT){
    //Initalize the values using the search boundary macro OUTSIDE of the for loop, rather than inside it. I suspect the macro is continously    evaluated when used to initalize the value inside of it and by all acounts, it seems to work.
    int start_search_boundary = MAX_Y_SEARCH_BOUNDARY(c, game_state->current_zone, 1);
    int end_search_boundary = MAX_Y_SEARCH_BOUNDARY(c, game_state->current_zone, 5);
    for(int j = start_search_boundary; j <= end_search_boundary; j++){
      //
	  if(numerical_responses[game_state->current_zone->tiles[c->position.global_y+j][c->position.global_x].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y+j][c->position.global_x].foe == NULL){
	    if(numerical_responses[game_state->current_zone->tiles[c->position.global_y+j][c->position.global_x-1].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y+j][c->position.global_x-1].foe == NULL ){
	    c->has_moved_around_vertically = 1;
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
	  mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on);
	  //mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y+j, c->position.local_x-1, "X");
	  c->position.global_y++;
	  c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
	  game_state->current_zone->tiles[c->position.global_y-1][c->position.global_x].foe = NULL;
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
	  if(c->position.local_y+1 > DEFAULT_MAX_Y - 1  ){
	    c->position.local_y = 0;
	    return;
	  }
	  else{
	    //printf("%s%d½%d%s", "xy values:", c->position.local_y, c->position.local_x, " " );
	    c->position.local_y++;
	    mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
	    //	    printf("%s%s", " What's in front of the npc: ", game_state->current_zone->tiles[c->position.global_y][c->position.global_x-1]);
	    // printf("%s", "this was called");
	    return;
	    // break;
	  }
	  //	 return; 
	}
	  }

	  else{
	    break;
	  }
      }

    start_search_boundary = MIN_Y_SEARCH_BOUNDARY(c, game_state->current_zone, 1);
    end_search_boundary = MIN_Y_SEARCH_BOUNDARY(c, game_state->current_zone, 5);
      
     for(int j = start_search_boundary; j <= end_search_boundary; j++){
       //mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y-j, c->position.local_x, "X");
	  if(numerical_responses[game_state->current_zone->tiles[c->position.global_y-j][c->position.global_x].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y-j][c->position.global_x].foe == NULL){
	    if(numerical_responses[game_state->current_zone->tiles[c->position.global_y-j][c->position.global_x-1].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y-j][c->position.global_x-1].foe == NULL){
	    c->has_moved_around_vertically = 1;
	    game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
	  mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on);
	  c->position.global_y--;
	  c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
	  game_state->current_zone->tiles[c->position.global_y+1][c->position.global_x].foe = NULL;
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
	  if(c->position.local_y-1 < 1  ){
	    c->position.local_y = DEFAULT_MAX_Y -1;
	    return;
	  }
	  else{
	    c->position.local_y--;
	    mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
	    return;
	    // break;
	  }
	  //return;
	}
	  }
	  else{
	    break;
	  }
      }
     //return;
  }
  
    if(direction == RIGHT){
      int start_search_boundary = MAX_Y_SEARCH_BOUNDARY(c, game_state->current_zone, 1);
      int end_search_boundary = MAX_Y_SEARCH_BOUNDARY(c, game_state->current_zone, 6);
      for(int j =start_search_boundary; j <= end_search_boundary; j++){
	//printf("%s%d%s", " ", j, " ");
	//printf("%s%d%s", " ", c->position.global_y+j, " ");
	  if(numerical_responses[game_state->current_zone->tiles[c->position.global_y+j][c->position.global_x].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y+j][c->position.global_x].foe == NULL ){
	    if(numerical_responses[game_state->current_zone->tiles[c->position.global_y+j][c->position.global_x+1].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y+j][c->position.global_x+1].foe == NULL){
	    c->has_moved_around_vertically = 1;
	    game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
	    
	    //printf("%s", "valid DOWN found " );
	    //  mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y+j, c->position.local_x+1, "X");
	  mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on);
	  
	  c->position.global_y++;
	  c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
	  game_state->current_zone->tiles[c->position.global_y-1][c->position.global_x].foe = NULL;
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
	  if(c->position.local_y+1 > DEFAULT_MAX_Y - 1  ){
	    c->position.local_y = 0;
	    return;
	    // break;
	  }
	  else{
	    //printf("%s", " and we can move nromally" );
	    c->position.local_y++;
	    mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
	    return;
	    //break;
	  }
	  //return; 
	}
	  }
	  else{
	    break;
	  }
      }
      start_search_boundary = MIN_Y_SEARCH_BOUNDARY(c, game_state->current_zone, 1);
      end_search_boundary = MIN_Y_SEARCH_BOUNDARY(c, game_state->current_zone, 6);
  
     for(int j = start_search_boundary; j <= end_search_boundary; j++){
       // mvwprintw(game_state->logs[MAIN_SCREEN],c->position.local_y-j, c->position.local_x, "X");
	  if(numerical_responses[game_state->current_zone->tiles[c->position.global_y-j][c->position.global_x].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y-j][c->position.global_x].foe == NULL ){
	    if(numerical_responses[game_state->current_zone->tiles[c->position.global_y-j][c->position.global_x+1].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y-j][c->position.global_x+1].foe == NULL){
	    c->has_moved_around_vertically = 1;
	    game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
	    //printf("%s", "valid  UP found " );
	    // mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y-j, c->position.local_x+1, "X");
	  mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on);
	  c->position.global_y--;
	  c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
	  game_state->current_zone->tiles[c->position.global_y+1][c->position.global_x].foe = NULL;
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
	  if(c->position.local_y-1 < 0  ){
	    c->position.local_y = DEFAULT_MAX_Y -1;
	    return;
	  }
	  else{
	    c->position.local_y--;
	    mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
	    return;
	  }
	  
	}
	  }
	    else{
       break;
	    }
      }
     
     
    }

    //
    if(direction == UP ){
      int start_search_boundary = MIN_X_SEARCH_BOUNDARY(c, game_state->current_zone, 1);
      int end_search_boundary = MIN_X_SEARCH_BOUNDARY(c, game_state->current_zone, 5);
      for(int j = start_search_boundary; j <= end_search_boundary; j++){
	//mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y, c->position.local_x-j, "X");
	//printf("%s%d", "offset: ", j);
	if(numerical_responses[game_state->current_zone->tiles[c->position.global_y][c->position.global_x - j].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y][c->position.global_x - j].foe == NULL ){
	  if(numerical_responses[game_state->current_zone->tiles[c->position.global_y - 1][c->position.global_x - j].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y - 1][c->position.global_x - j].foe == NULL){
	  c->has_moved_around_horizontally = 1;
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
	
	  mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on);
	  c->position.global_x--;
	  c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x+1].foe = NULL;
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
	  if(c->position.local_x-1 < DEFAULT_MAX_INFOBAR_WIDTH  ){
	    c->position.local_x = DEFAULT_MAX_X -1;
	    //printf("%s%d"," x: ",c->position.local_x );
	    // break;
	     return;
	  } 
	  else{
	    //    printf("%s%d"," x before : ",c->position.local_x );
	    c->position.local_x--;
	    //  printf("%s%d"," x after : ",c->position.local_x );
	     mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
	     return;
	  }
	}
	}
	else{
	  break;
	}
      }
      start_search_boundary = MAX_X_SEARCH_BOUNDARY(c, game_state->current_zone, 1);
      end_search_boundary = MAX_X_SEARCH_BOUNDARY(c, game_state->current_zone, 5);
      for(int j = start_search_boundary; j <= end_search_boundary; j++){
	//mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y, c->position.local_x+j, "X");
	if(numerical_responses[game_state->current_zone->tiles[c->position.global_y][c->position.global_x + j].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y][c->position.global_x + j].foe == NULL){
	  if(numerical_responses[game_state->current_zone->tiles[c->position.global_y - 1][c->position.global_x + j].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y - 1][c->position.global_x + j].foe == NULL ){
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
	  c->has_moved_around_horizontally = 1;
	  //printf("%s", "right ");
	  // mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y-1, c->position.local_x+j, "X");
	  mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on);
	  c->position.global_x++;
	  c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x-1].foe = NULL;
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
	  if(c->position.local_x+1 > DEFAULT_MAX_X -1  ){
	    c->position.local_x = DEFAULT_MAX_INFOBAR_WIDTH;
	    return;
	    
	  }
	  else{
	    c->position.local_x++;
	    mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
	    return;
	  }
	  
	}
	}
	else{
	  break;
	}
      }
   }

    if(direction == DOWN){
      int start_search_boundary = MIN_X_SEARCH_BOUNDARY(c, game_state->current_zone, 1);
      int end_search_boundary = MIN_X_SEARCH_BOUNDARY(c, game_state->current_zone, 5);
	for(int j = start_search_boundary; j <= end_search_boundary; j++){
	  // mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y, c->position.local_x-j, "X");
	if(numerical_responses[game_state->current_zone->tiles[c->position.global_y][c->position.global_x - j].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y][c->position.global_x - j].foe == NULL ){
	  if(numerical_responses[game_state->current_zone->tiles[c->position.global_y + 1][c->position.global_x - j].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y + 1][c->position.global_x - j].foe == NULL){
	  c->has_moved_around_horizontally = 1;
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
	  // mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y+1, c->position.local_x-j, "X");
	  mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on);
	  c->position.global_x--;
	  c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x+1].foe = NULL;
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
	  if(c->position.local_x-1 < DEFAULT_MAX_INFOBAR_WIDTH  ){
	    c->position.local_x = DEFAULT_MAX_X -1;
	    return;
	  }
	  else{
	    c->position.local_x--;
	    mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
	    return;
	  }
	  //  return;
	}
	}
	else{
	  break;
	}
      }
      start_search_boundary = MAX_X_SEARCH_BOUNDARY(c, game_state->current_zone, 1);
      end_search_boundary = MAX_X_SEARCH_BOUNDARY(c, game_state->current_zone, 5);
      for(int j = start_search_boundary; j <= end_search_boundary; j++){
	//	mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y, c->position.local_x+j, "X");
	if(numerical_responses[game_state->current_zone->tiles[c->position.global_y][c->position.global_x + j].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y][c->position.global_x + j].foe == NULL ){
	  if( numerical_responses[game_state->current_zone->tiles[c->position.global_y + 1][c->position.global_x + j].content[0]] != 1 && game_state->current_zone->tiles[c->position.global_y + 1][c->position.global_x + j].foe == NULL){
	  c->has_moved_around_horizontally = 1;
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
	  //  mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y+1, c->position.local_x-j, "X");
	  mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->standing_on);
	  c->position.global_x++;
	  c->standing_on[0] = game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation;
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x-1].foe = NULL;
	  game_state->current_zone->tiles[c->position.global_y][c->position.global_x].foe = c;
	  if(c->position.local_x+1 > DEFAULT_MAX_X -1  ){
	    c->position.local_x =  DEFAULT_MAX_INFOBAR_WIDTH;
	    return;
	  }
	  else{
	    c->position.local_x++;
	    mvwprintw(game_state->logs[MAIN_SCREEN], c->position.local_y,c->position.local_x,c->representation);
	    return;
	  }

	}
	}
	else{
	  break;
	}
      }
      //return;
   }
   
  
}


void cb_act(Creature *c,Game_State *game_state){
    c->curr_ap--; 
    (*creature_behavior_handler[c->behavior])(c,game_state);
}

void (*creature_behavior_handler[4])(Creature *c,Game_State *game_state) = {cb_idle, cb_roam,cb_pursue_target, cb_attack_target};
