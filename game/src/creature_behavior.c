#include "creature_behavior.h"
 

void cb_pursue_target(Creature *c , Creature *target ,Game_World *current_zone){
  /* Check that distance is greater than 1, implying there is a distance between creature and target */
  
  if(abs(c->position.global_x - target->position.global_x) > 1 || abs(c->position.global_y - target->position.global_y) > 1){
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
       current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
       c->position.global_y++;
       c->position.local_y++;
       if(abs(c->position.global_x - target->position.global_x) <= DEFAULT_MAX_Y -1){	 
	 mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
	 mvprintw(c->position.local_y,c->position.local_x,c->representation);
    }
       c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
       current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
     }
   }
   
   if(direction == DOWN){
     if( c->position.global_y-1 > -1 && numerical_responses[current_zone->tiles[c->position.global_y-1][c->position.global_x].content[0]] != 1){
       current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
       mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
       c->position.global_y--;
       c->position.local_y--;
       if(abs(c->position.global_x - target->position.global_x) <= DEFAULT_MAX_Y -1){
	  mvprintw(c->position.local_y,c->position.local_x,c->standing_on);	  
	  mvprintw(c->position.local_y,c->position.local_x,c->representation);
    }
       c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
       current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
       
     }
   }
       
     
   


   if(direction == LEFT){
     if( c->position.global_x-1 > -1 && numerical_responses[current_zone->tiles[c->position.global_y][c->position.global_x-1].content[0]] != 1){
       mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
       current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
       c->position.global_x--;
       c->position.local_x--;
       if(abs(c->position.global_x - target->position.global_x) <= DEFAULT_MAX_X -1){
	  mvprintw(c->position.local_y,c->position.local_x,c->representation);
    }
       c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
       current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
     }
   }

       
  
     
   
   if(direction == RIGHT){
     if(c->position.global_x+1 < current_zone->width && numerical_responses[current_zone->tiles[c->position.global_y][c->position.global_x+1].content[0]] != 1){
       mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
       current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
       c->position.global_x++;
       c->position.local_x++;
       if(abs(c->position.global_x - target->position.global_x) <= DEFAULT_MAX_X -1){	  
	 mvprintw(c->position.local_y,c->position.local_x,c->representation);
       }
       c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
       current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
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
 
  int direction;
  
  /* We check both that we get closer to the target AND that the distance is greater than 1, because a distance of only one implies we are standing right next to the target */
  
  //Move Down
  if( (abs(c->position.global_y+1 - target->position.global_y )) < (abs(c->position.global_y - target->position.global_y)) && (abs(c->position.global_y - target->position.global_y)) > 1 ) {
    /*We don't move horizontally/vertically if we previously have made a move along said axis, in an attempt to move around an object, because otherwise, moving along said axis might undo the move we just made in an attempt to navigate around an obstacle, e.g go back one tile to where we initally got stuck*/
    if(c->has_moved_around_vertically != 1){
    direction = DOWN;
    if(numerical_responses[current_zone->tiles[c->position.global_y+1][c->position.global_x].content[0]] != 1){
     /* If we have successfully made a move along any axis, we un-register that we made a move along the opposite axis, because the fact that we moved along said axis, implies that we are no longer stuck and thus no longer need to be aware of moving back to the inital position where we got stuck*/  
    c->has_moved_around_horizontally = 0;
    current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
    mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
    c->position.global_y +=1;
    c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
    current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
    if(c->position.local_y+1 >  DEFAULT_MAX_Y - 1){
      
      c->position.local_y = 0;
    }
    else{
      c->position.local_y += 1;
     }
    mvprintw(c->position.local_y,c->position.local_x,c->representation);
    return;
    }
    }
    
}
  
  //Moving UP 
    if( (abs(c->position.global_y-1 - target->position.global_y )) < (abs(c->position.global_y - target->position.global_y)) && (abs(c->position.global_y - target->position.global_y)) > 1 ){
      if(c->has_moved_around_vertically != 1){
    direction = UP;
    if(numerical_responses[current_zone->tiles[c->position.global_y-1][c->position.global_x].content[0]] != 1){
      c->has_moved_around_horizontally = 0;
      current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
      mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
      c->position.global_y -=1;
      c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
      current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
    if(c->position.local_y-1 <  1){
      c->position.local_y = DEFAULT_MAX_Y - 1;
    }
    else{
      c->position.local_y -= 1;
    }
    mvprintw(c->position.local_y,c->position.local_x,c->representation);
     return;
    }
      }
    
  }
    
  
  //move right 
  
  
    if( (abs(c->position.global_x+1 - target->position.global_x )) < (abs(c->position.global_x - target->position.global_x )) && (abs(c->position.global_x - target->position.global_x)) > 1 ){
      if(c->has_moved_around_horizontally != 1){
    direction = RIGHT;
    
    if(numerical_responses[current_zone->tiles[c->position.global_y][c->position.global_x+1].content[0]] != 1){
      c->has_moved_around_vertically = 0;
      current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
       mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
	c->position.global_x +=1;
	c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
    if(c->position.local_x+1 >  DEFAULT_MAX_X - 1){
      c->position.local_x = 0;
    }
    else{
      c->position.local_x += 1;
     }
    mvprintw(c->position.local_y,c->position.local_x,c->representation);
     return;
    }

      }
  }
  // move left 
  
  if( (abs(c->position.global_x-1 - target->position.global_x )) < (abs(c->position.global_x - target->position.global_x )) && (abs(c->position.global_x - target->position.global_x) > 1)){
    if(c->has_moved_around_horizontally != 1){
    direction = LEFT;
    if(numerical_responses[current_zone->tiles[c->position.global_y][c->position.global_x-1].content[0]] != 1){
      c->has_moved_around_vertically = 0;
      current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
       mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
    c->position.global_x -=1;
    c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
    current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
    if(c->position.local_x - 1 < 0  ){
      //printf("%s", "This line was called, 198" );
      c->position.local_x = DEFAULT_MAX_X - 1;
    }
    else{
      c->position.local_x -= 1;
    }
    mvprintw(c->position.local_y,c->position.local_x,c->representation);
    return;
 }
    }
    
      }     
  // If we failed to make a move that directly makes progress towards the target it is pursuing, find a "move" that helps us navigate around the obstacle. For the sake of computational effeciency, we do so by checking a max range of 10 tiles (5 tiles either way around the obstacle tile) that could potentially provide a path around. If moving either way aroudn the obstacle eventually provides a clear path, just take it.This very basic scheme is for the sake of simplicity.
  
  if(direction == LEFT){
    /*Initalize the values using the search boundary macro OUTSIDE of the for loop, rather than inside it. I suspect the macro is continously    evaluated when used to initalize the value inside of it and by all acounts, it seems to work.*/
    int start_search_boundary = MAX_Y_SEARCH_BOUNDARY(c, current_zone, 1);
    int end_search_boundary = MAX_Y_SEARCH_BOUNDARY(c, current_zone, 5);
    for(int j = start_search_boundary; j <= end_search_boundary; j++){
      //
	  if(numerical_responses[current_zone->tiles[c->position.global_y+j][c->position.global_x].content[0]] != 1){
	    if(numerical_responses[current_zone->tiles[c->position.global_y+j][c->position.global_x-1].content[0]] != 1 ){
	    c->has_moved_around_vertically = 1;
	  current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
	  mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
	  //mvprintw(c->position.local_y+j, c->position.local_x-1, "X");
	  c->position.global_y++;
	  c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	  current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
	  if(c->position.local_y+1 > DEFAULT_MAX_Y - 1  ){
	    c->position.local_y++;
	    return;
	  }
	  else{
	    //printf("%s%d½%d%s", "xy values:", c->position.local_y, c->position.local_x, " " );
	    c->position.local_y++;
	    mvprintw(c->position.local_y,c->position.local_x,c->representation);
	    //	    printf("%s%s", " What's in front of the npc: ", current_zone->tiles[c->position.global_y][c->position.global_x-1]);
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

    start_search_boundary = MIN_Y_SEARCH_BOUNDARY(c, current_zone, 1);
    end_search_boundary = MIN_Y_SEARCH_BOUNDARY(c, current_zone, 5);
      
     for(int j = start_search_boundary; j <= end_search_boundary; j++){
       //mvprintw(c->position.local_y-j, c->position.local_x, "X");
	  if(numerical_responses[current_zone->tiles[c->position.global_y-j][c->position.global_x].content[0]] != 1){
	    if(numerical_responses[current_zone->tiles[c->position.global_y-j][c->position.global_x-1].content[0]] != 1){
	    c->has_moved_around_vertically = 1;
	    current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
	    //mvprintw(c->position.local_y-j, c->position.local_x-1, "X");
	  mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
	  c->position.global_y--;
	  c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	  current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
	  if(c->position.local_y-1 < 1  ){
	    c->position.local_y--;
	    //    break;
	    return;
	  }
	  else{
	    c->position.local_y--;
	    mvprintw(c->position.local_y,c->position.local_x,c->representation);
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
      int start_search_boundary = MAX_Y_SEARCH_BOUNDARY(c, current_zone, 1);
      int end_search_boundary = MAX_Y_SEARCH_BOUNDARY(c, current_zone, 6);
      for(int j =start_search_boundary; j <= end_search_boundary; j++){
	//printf("%s%d%s", " ", j, " ");
	//printf("%s%d%s", " ", c->position.global_y+j, " ");
	  if(numerical_responses[current_zone->tiles[c->position.global_y+j][c->position.global_x].content[0]] != 1 ){
	    if(numerical_responses[current_zone->tiles[c->position.global_y+j][c->position.global_x+1].content[0]] != 1){
	    c->has_moved_around_vertically = 1;
	    current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
	    //printf("%s", "valid DOWN found " );
	    //  mvprintw(c->position.local_y+j, c->position.local_x+1, "X");
	  mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
	  
	  c->position.global_y++;
	  c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	  current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
	  if(c->position.local_y+1 > DEFAULT_MAX_Y - 1  ){
	    c->position.local_y++;
	    return;
	    // break;
	  }
	  else{
	    //printf("%s", " and we can move nromally" );
	    c->position.local_y++;
	    mvprintw(c->position.local_y,c->position.local_x,c->representation);
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
      start_search_boundary = MIN_Y_SEARCH_BOUNDARY(c, current_zone, 1);
      end_search_boundary = MIN_Y_SEARCH_BOUNDARY(c, current_zone, 6);
      /* 21-8-2021 hereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee */ 
     for(int j = start_search_boundary; j <= end_search_boundary; j++){
       // mvprintw(c->position.local_y-j, c->position.local_x, "X");
	  if(numerical_responses[current_zone->tiles[c->position.global_y-j][c->position.global_x].content[0]] != 1 ){
	    if(numerical_responses[current_zone->tiles[c->position.global_y-j][c->position.global_x+1].content[0]] != 1){
	    c->has_moved_around_vertically = 1;
	    current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
	    //printf("%s", "valid  UP found " );
	    // mvprintw(c->position.local_y-j, c->position.local_x+1, "X");
	  mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
	  c->position.global_y--;
	  c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	  current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
	  if(c->position.local_y-1 < 1  ){
	    c->position.local_y--;
	    return;
	  }
	  else{
	    c->position.local_y--;
	    mvprintw(c->position.local_y,c->position.local_x,c->representation);
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
      int start_search_boundary = MIN_X_SEARCH_BOUNDARY(c, current_zone, 1);
      int end_search_boundary = MIN_X_SEARCH_BOUNDARY(c, current_zone, 5);
      for(int j = start_search_boundary; j <= end_search_boundary; j++){
	//mvprintw(c->position.local_y, c->position.local_x-j, "X");
	//printf("%s%d", "offset: ", j);
	if(numerical_responses[current_zone->tiles[c->position.global_y][c->position.global_x - j].content[0]] != 1 ){
	  if(numerical_responses[current_zone->tiles[c->position.global_y - 1][c->position.global_x - j].content[0]] != 1){
	  c->has_moved_around_horizontally = 1;
	  current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
	
	  mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
	  c->position.global_x--;
	  c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	  current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
	  if(c->position.local_x-1 < DEFAULT_MAX_INFOBAR_WIDTH  ){
	    c->position.local_x--;
	    //printf("%s%d"," x: ",c->position.local_x );
	    // break;
	     return;
	  } 
	  else{
	    //    printf("%s%d"," x before : ",c->position.local_x );
	    c->position.local_x--;
	    //  printf("%s%d"," x after : ",c->position.local_x );
	     mvprintw(c->position.local_y,c->position.local_x,c->representation);
	     return;
	  }
	}
	}
	else{
	  break;
	}
      }
      start_search_boundary = MAX_X_SEARCH_BOUNDARY(c, current_zone, 1);
      end_search_boundary = MAX_X_SEARCH_BOUNDARY(c, current_zone, 5);
      for(int j = start_search_boundary; j <= end_search_boundary; j++){
	//mvprintw(c->position.local_y, c->position.local_x+j, "X");
	if(numerical_responses[current_zone->tiles[c->position.global_y][c->position.global_x + j].content[0]] != 1){
	  if(numerical_responses[current_zone->tiles[c->position.global_y - 1][c->position.global_x + j].content[0]] != 1 ){
	  current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
	  c->has_moved_around_horizontally = 1;
	  //printf("%s", "right ");
	  // mvprintw(c->position.local_y-1, c->position.local_x+j, "X");
	  mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
	  c->position.global_x++;
	  c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	  current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
	  if(c->position.local_x+1 > DEFAULT_MAX_X -1  ){
	    c->position.local_x++;
	    return;
	    
	  }
	  else{
	    c->position.local_x++;
	    mvprintw(c->position.local_y,c->position.local_x,c->representation);
	    return;
	  }
	  
	}
	}
	else{
	  break;
	}
      }
   }

    if(direction == DOWN ){
      int start_search_boundary = MIN_X_SEARCH_BOUNDARY(c, current_zone, 1);
      int end_search_boundary = MIN_X_SEARCH_BOUNDARY(c, current_zone, 5);
	for(int j = start_search_boundary; j <= end_search_boundary; j++){
	  // mvprintw(c->position.local_y, c->position.local_x-j, "X");
	if(numerical_responses[current_zone->tiles[c->position.global_y][c->position.global_x - j].content[0]] != 1 ){
	  if(numerical_responses[current_zone->tiles[c->position.global_y + 1][c->position.global_x - j].content[0]] != 1){
	  c->has_moved_around_horizontally = 1;
	  current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
	  // mvprintw(c->position.local_y+1, c->position.local_x-j, "X");
	  mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
	  c->position.global_x--;
	  c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	  current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
	  if(c->position.local_x-1 < DEFAULT_MAX_INFOBAR_WIDTH  ){
	    c->position.local_x--;
	    return;
	  }
	  else{
	    c->position.local_x--;
	    mvprintw(c->position.local_y,c->position.local_x,c->representation);
	    return;
	  }
	  //  return;
	}
	}
	else{
	  break;
	}
      }
      start_search_boundary = MAX_X_SEARCH_BOUNDARY(c, current_zone, 1);
      end_search_boundary = MAX_X_SEARCH_BOUNDARY(c, current_zone, 5);
      for(int j = start_search_boundary; j <= end_search_boundary; j++){
	//	mvprintw(c->position.local_y, c->position.local_x+j, "X");
	if(numerical_responses[current_zone->tiles[c->position.global_y][c->position.global_x + j].content[0]] != 1 ){
	  if( numerical_responses[current_zone->tiles[c->position.global_y + 1][c->position.global_x + j].content[0]] != 1){
	  c->has_moved_around_horizontally = 1;
	  current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->standing_on[0];
	  //  mvprintw(c->position.local_y+1, c->position.local_x-j, "X");
	  mvprintw(c->position.local_y,c->position.local_x,c->standing_on);
	  c->position.global_x++;
	  c->standing_on[0] = current_zone->tiles[c->position.global_y][c->position.global_x].content[0];
	  current_zone->tiles[c->position.global_y][c->position.global_x].content[0] = c->representation[0];
	  if(c->position.local_x+1 > DEFAULT_MAX_X -1  ){
	    c->position.local_x++;
	    return;
	  }
	  else{
	    c->position.local_x++;
	    mvprintw(c->position.local_y,c->position.local_x,c->representation);
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


void cb_act(Creature *c , Creature *target ,Game_World *current_zone){
  (*creature_behavior_handler[c->behavior])(c,target, current_zone);
}

void (*creature_behavior_handler[4])(Creature *c , Creature *target ,Game_World *current_zone) = {cb_idle, cb_roam,cb_pursue_target, cb_flee_target};
	
  
  


