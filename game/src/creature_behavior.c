#include "creature_behavior.h"


void cb_pursue_target(Creature *c , Creature *target ,Game_World *current_zone){
  if(abs(c->position.global_x - target->position.global_x) > 0 && abs(c->position.global_y - target->position.global_y) > 0){
  if(abs(c->position.global_x - target->position.global_x) <= DEFAULT_MAX_X && abs(c->position.global_y - target->position.global_y) <= DEFAULT_MAX_X){
    c->target_is_within_bound = WITHIN_BOUND;
  }
  else{
    c->target_is_within_bound = OUT_OF_BOUND;
  }
  if(c->target_is_within_bound == WITHIN_BOUND){
    cb_pursue_target_inb(c,target,current_zone);
  }

  else{
    cb_pursure_target_oob(c,target,current_zone);
  }
}
}
void cb_attack_target(Creature *c, Creature *target ,Game_World *current_zone){
  
}

void cb_idle(Creature *c, Creature *target ,Game_World *current_zone){
  ;
}

void cb_roam(Creature *c, Creature *target ,Game_World *current_zone){
  
  int direction =  (rand() % (5 -  0 + 1) + 1);
  /* Important: we evaluate if the change in position exceeds the boundary of the game map, THEN check if the tile we try to move to is validto avoid the possibility of accessing an offset outside of the malloc'ed area to avoid segmentation faults. THis is due to logical and short circuiting (if the first statement is false, don't evluate the second) */
   if(direction == UP){
     if(c->position.global_y+1 < current_zone->height && numerical_responses[current_zone->tiles[c->position.global_y+1][c->position.global_x].content[0]] != 1 ){
       c->position.global_y++;
       if(abs(c->position.global_x - target->position.global_x) <= DEFAULT_MAX_Y -1){
	 	 mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
	 c->position.local_y++;
    mvprintw(c->position.local_y,c->position.local_x,c->representation);
    }
       else{
	 c->position.local_y++;
       }
       c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
     }
   }
   
   if(direction == DOWN){
     if( c->position.global_y-1 > -1 && numerical_responses[current_zone->tiles[c->position.global_y-1][c->position.global_x].content[0]] != 1){
       c->position.global_y--;
       if(abs(c->position.global_x - target->position.global_x) <= DEFAULT_MAX_Y -1){
	  mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
	  c->position.local_y--;
    mvprintw(c->position.local_y,c->position.local_x,c->representation);
    }
       else{
	 c->position.local_y--;
       }
     }
   }
       
     
   


   if(direction == LEFT){
     if( c->position.global_x-1 > -1 && numerical_responses[current_zone->tiles[c->position.global_y][c->position.global_x-1].content[0]] != 1){
       c->position.global_x--;       
       if(abs(c->position.global_x - target->position.global_x) <= DEFAULT_MAX_X -1){
	  mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
	  c->position.local_x--;
    mvprintw(c->position.local_y,c->position.local_x,c->representation);
    }
       else{
	 c->position.local_x--;
       }
     }
   }

       
  
     
   
   if(direction == RIGHT){
     if(c->position.global_x+1 < current_zone->width && numerical_responses[current_zone->tiles[c->position.global_y][c->position.global_x+1].content[0]] != 1){
       c->position.global_x++;
       if(abs(c->position.global_x - target->position.global_x) <= DEFAULT_MAX_X -1){	 
	  mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
	  c->position.local_x++;
    mvprintw(c->position.local_y,c->position.local_x,c->representation);
    return;
    }
       else{
	 c->position.local_x++;
       }
     }
   }
}



void cb_flee_target(Creature *c, Creature *target ,Game_World *current_zone){

}

/*Function to have a creature pursue a target when it is out of the player's view boundary. We don't make the usual check to see if it is a passable tile the creature is trying to step on. We choose not to, because otherwise, we would end up having to do arbitrarily complex checks to move around objects, detcet if the creature is stuck and if it is stuck, get unstuck, etc. concrete cases will be written in the manual at some point*/

void cb_pursure_target_oob(Creature *c, Creature *target ,Game_World *current_zone){
  /* In order to pursue a target, we effectively try out all moves the creature can take to move closer to the current target. Provided the
 distance becomes smaller and it is a valid tile to step on, make a move */

  /* moving up */
  if( (abs(c->position.global_y+1 - target->position.global_y ) < abs(c->position.global_y - c->position.global_y ))){
    c->position.global_y +=1;
    c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
    if(c->position.local_y+1 >  DEFAULT_MAX_Y - 1){
      c->position.local_y = 0;
    }
    else{
      c->position.local_y += 1;
     }
    }

  // Moving down 
  if( (abs(c->position.global_y-1 - target->position.global_y ) < abs(c->position.global_y - c->position.global_y ))){
    c->position.global_y -=1;
    if(c->position.local_y-1 <  0){
      c->position.local_y = DEFAULT_MAX_Y - 1;
    }
    else{
      c->position.local_y -= 1;
    }
  }
    /* move right */
  if( (abs(c->position.global_x+1 - target->position.global_x ) < abs(c->position.global_x - c->position.global_x ))){
	c->position.global_x +=1;
    if(c->position.local_x+1 >  DEFAULT_MAX_X - 1){
      c->position.local_x = 0;
    }
    else{
      c->position.local_x += 1;
     }
  }
    /* move left */

  if( (abs(c->position.global_x-1 -target->position.global_x ) < abs(c->position.global_x - c->position.global_x ))){

    if(numerical_responses[current_zone->tiles[c->position.global_y][c->position.global_x-1].content[0] ] != 1){
    c->position.global_x -=1;
    if(c->position.local_x -=1 < 0  ){
      c->position.local_x = DEFAULT_MAX_X - 1;
    }
    else{
      c->position.local_x -= 1;
    }
    }
  }


    
  

  /*Finally, if the creature is now within the view distance of the player, draw it */

  if(abs(c->position.global_x - target->position.global_x) <= DEFAULT_MAX_X -1){
    mvprintw(c->position.local_y,c->position.local_x,c->representation);
    }
  if( abs(c->position.global_y - target->position.global_y) != DEFAULT_MAX_Y -1){
    mvprintw(c->position.local_y,c->position.local_x,c->representation);
  }
}


      /*mimmic pursuing behavior when the creature is within the players POW. Now, we HAVE to check if the tile it moves to is valid, because here the creature will be visible to the player */
void cb_pursue_target_inb(Creature *c, Creature *target ,Game_World *current_zone){
  
  printf("%u%s",(abs(c->position.global_x-1 - target->position.global_x )), " dist if move left ");
  printf("%u%s",(abs(c->position.global_x - target->position.global_x )), " dist initial");

  printf("%u%s",(abs(c->position.global_x+1 - target->position.global_x )), " dist if move right  ");
  printf("%u%s",(abs(c->position.global_x - target->position.global_x )), " dist initial");
  /*
  printf("%u%s",(abs(c->position.global_x+1 - target->position.global_x )), " dist if move  ");
  printf("%u%s",(abs(c->position.global_x - target->position.global_x )), " dist initial  ");
  */
  int direction;
  //Move Down
  
  if( (abs(c->position.global_y+1 - target->position.global_y )) < (abs(c->position.global_y - target->position.global_y) )){
    direction = DOWN;
    if(numerical_responses[current_zone->tiles[c->position.global_y+1][c->position.global_x].content[0]] != 1){
    mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
    c->position.global_y +=1;
    c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
    if(c->position.local_y+1 >  DEFAULT_MAX_Y - 1){
      //printf("%s","????");
      c->position.local_y = 0;
    }
    else{
      c->position.local_y += 1;
     }
    mvprintw(c->position.local_y,c->position.local_x,c->representation);
    }
    return;
}
  
  //Moving UP 
  if( (abs(c->position.global_y-1 - target->position.global_y )) < (abs(c->position.global_y - target->position.global_y )) ){
   
    direction = UP;
    if(numerical_responses[current_zone->tiles[c->position.global_y-1][c->position.global_x].content[0]] != 1){
      mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
      c->position.global_y -=1;
      c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
    if(c->position.local_y-1 <  0){
      c->position.local_y = DEFAULT_MAX_Y - 1;
    }
    else{
      c->position.local_y -= 1;
    }
    }
    mvprintw(c->position.local_y,c->position.local_x,c->representation);
     return;
  }
  
  //move right 
  printf("%s", "At some point, this WILL COME TRUE");
  
  if( (abs(c->position.global_x+1 - target->position.global_x )) < (abs(c->position.global_x - target->position.global_x )) ){
    direction = RIGHT;
    if(numerical_responses[current_zone->tiles[c->position.global_y-1][c->position.global_x].content[0]] != 1){
       mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
	c->position.global_x +=1;
	c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
    if(c->position.local_x+1 >  DEFAULT_MAX_X - 1){
      c->position.local_x = 0;
    }
    else{
      c->position.local_x += 1;
     }
    }
    mvprintw(c->position.local_y,c->position.local_x,c->representation);
     return;
  }
  // move left 
  
  if( (abs(c->position.global_x-1 - target->position.global_x )) < (abs(c->position.global_x - target->position.global_x )) ){
    
    direction = LEFT;
    if(numerical_responses[current_zone->tiles[c->position.global_y][c->position.global_x-1].content[0]] != 1){
       mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
    c->position.global_x -=1;
    c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
    if(c->position.local_x -=1 < 0  ){
      c->position.local_x = DEFAULT_MAX_X - 1;
    }
    else{
      c->position.local_x -= 1;
    }
    mvprintw(c->position.local_y,c->position.local_x,c->representation);
    return;
 }
      }     
  // If we failed to make a move that directly makes progress towards the target it is pursuing, find a "move" that helps us navigate around any obstacle
  
  if(direction == LEFT){
    for(int i = MIN_Y_SEARCH_BOUNDARY(c, current_zone, 10); i < MAX_Y_SEARCH_BOUNDARY(c, current_zone, 10); i++){
	for(int j = MAX_X_SEARCH_BOUNDARY(c, current_zone, 10); j < MAX_X_SEARCH_BOUNDARY(c, current_zone, 10); j++){
	if(numerical_responses[current_zone->tiles[i][j].content[0]] != 1){
	  c->position.global_x--;
	  if(c->position.local_x -=1 < 0  ){
	    c->position.local_x = DEFAULT_MAX_X - 1;
	  }
	  else{
	    c->position.local_x--;
	  }
	  mvprintw(c->position.local_y,c->position.local_x,c->representation);
	  return;
	}
      }
    }
  }
    if(direction == RIGHT){
      for(int i = MIN_Y_SEARCH_BOUNDARY(c, current_zone, 10); i < MAX_Y_SEARCH_BOUNDARY(c, current_zone, 10); i++){
      for(int j = MAX_X_SEARCH_BOUNDARY(c, current_zone, 10); j < MAX_X_SEARCH_BOUNDARY(c, current_zone, 10); j++){
	if(numerical_responses[current_zone->tiles[i][j].content[0]] != 1){
	  c->position.global_x++;
	  if(c->position.local_x +=1 < 0  ){
	    c->position.local_x = DEFAULT_MAX_X - 1;
	  }
	  else{
	    c->position.local_x++;
	  }
	  mvprintw(c->position.local_y,c->position.local_x,c->representation);
	  return;
	}
      }
    }
    }


    if(direction == UP ){
      for(int i = MIN_Y_SEARCH_BOUNDARY(c, current_zone, 10); i < MAX_Y_SEARCH_BOUNDARY(c, current_zone, 10); i++){
      for(int j = MAX_X_SEARCH_BOUNDARY(c, current_zone, 10); j < MAX_X_SEARCH_BOUNDARY(c, current_zone, 10); j++){
	if(numerical_responses[current_zone->tiles[i][j].content[0]] != 1){
	  c->position.global_y++;
	  if(c->position.local_y +=1 > DEFAULT_MAX_Y -1  ){
	    c->position.local_y = 0;
	  }
	  else{
	    c->position.local_y++;
	  }
	  mvprintw(c->position.local_y,c->position.local_x,c->representation);
	  return;
	}
      }
    }
   }

    if(direction == DOWN ){
      for(int i = MIN_Y_SEARCH_BOUNDARY(c, current_zone, 10); i < MAX_Y_SEARCH_BOUNDARY(c, current_zone, 10); i++){
	for(int j = MAX_X_SEARCH_BOUNDARY(c, current_zone, 10); j < MAX_X_SEARCH_BOUNDARY(c, current_zone, 10); j++){
	if(numerical_responses[current_zone->tiles[i][j].content[0]] != 1){
	  c->position.global_y--;
	  if(c->position.local_y -=1 < 0  ){
	    c->position.local_y = DEFAULT_MAX_Y - 1;
	  }
	  else{
	    c->position.local_y++;
	  }
	  mvprintw(c->position.local_y,c->position.local_x,c->representation);
	  return;
	  
	}
      }
    }
   }
   
  
}


void cb_act(Creature *c , Creature *target ,Game_World *current_zone){
  (*creature_behavior_handler[c->behavior])(c,target, current_zone);
}

void (*creature_behavior_handler[4])(Creature *c , Creature *target ,Game_World *current_zone) = {cb_idle, cb_roam,cb_pursue_target, cb_flee_target};
	
  
  


