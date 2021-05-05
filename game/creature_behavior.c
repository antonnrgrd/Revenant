


/*Function to have a creature pursue a target when it is out of the player's view boundary. We don't make the usual check to see if it is a passable tile the creature is trying to step on. We choose not to, because otherwise, we would end up having to do arbitrarily complex checks to move around objects, detcet if the creature is stuck and if it is stuck, get unstuck, etc. concrete cases will be written in the manual at some point*/

void cb_pursure_target_oob(Creature *c, Creature *target ,Game_World *current_zone){
  /* In order to pursue a target, we effectively try out all moves the creature can take to move closer to the current target. Provided the
 distance becomes smaller and it is a valid tile to step on, make a move */

  /*Direction we need to move to approach target */
  int direction:4;
  int made_valid_move:-1;
  /* moving up */
  if( (abs(c->position.global_y+1 - target->position.global_y ) < abs(c->position.global_y - c->position.global_y ))){
  direction = UP;
    made_valid_move = 0;
    c->position.global_y +=1;
    c->standing_on[0] = current_zone->tiles[c.position.global_y][c.position.global_x];
    if(c.position.local_y+1 >  DEFAULT_MAX_Y - 1){
      c.position.local_y = 0;
    }
    else{
      c.position.local_y += 1;
     }
    }

  /* Moving down */
  if( (abs(c->position.global_y-1 - target->position.global_y ) < abs(c->position.global_y - c->position.global_y ))){
    direction = DOWN;
    made_valid_move = 0;
    c->position.global_y -=1;
    if(c.position.local_y-1 <  0){
      c.position.local_y = DEFAULT_MAX_Y - 1;
    }
    else{
      c.position.local_y -= 1;
    }
  }
    /* move right */
  if( (abs(c->position.global_x+1 - target->position.global_x ) < abs(c->position.global_x - c->position.global_x ))){
    direction = RIGHT;
	made_valid_move = 0;
	c->position.global_x +=1;
    if(c.position.local_x+1 >  DEFUALT_MAX_X - 1){
      c.position.local_x = 0;
    }
    else{
      c.position.local_x += 1;
     }
  }
    /* move left */

  if( (abs(c->position.global_x-1 -target->position.global_x ) < abs(c->position.global_x - c->position.global_x ))){
    direction = LEFT;
    if(numerical_responses[(current_zone->tiles[c.position.global_y][c.position.global_x-1]) != 1){
    made_valid_move = 0;  
    c->position.global_x -=1;
    if(c.position.local_x -=1 < 0  ){
      c.position.local_x = DEFUALT_MAX_X - 1;
    }
    else{
      c.position.local_x -= 1;
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
void cb_pursue_target_in(Creature *c, Creature *target ,Game_World *current_zone){
  int direction;
  int made_valid_move = -1;
  if( (abs(c->position.global_y+1 - target->position.global_y ) < abs(c->position.global_y - c->position.global_y ))]){
  direction = UP;
  if(numerical_responses[current_zone->tiles[c.position.global_y+1][c.position.global_x] != 1){
    made_valid_move = 0;
    c->position.global_y +=1;
    c->standing_on[0] = current_zone->tiles[c.position.global_y][c.position.global_x];
    if(c.position.local_y+1 >  DEFAULT_MAX_Y - 1){
      c.position.local_y = 0;
    }
    else{
      c.position.local_y += 1;
     }
    }
    
    }
   }
  /* Moving down */
  if( (abs(c->position.global_y-1 - target->position.global_y ) < abs(c->position.global_y - c->position.global_y ))]){
    direction = DOWN;
    made_valid_move = 0;
    c->position.global_y -=1;
    if(c.position.local_y-1 <  0){
      c.position.local_y = DEFAULT_MAX_Y - 1;
    }
    else{
      c.position.local_y -= 1;
    }
  }
    /* move right */
  if( (abs(c->position.global_x+1 - target->position.global_x ) < abs(c->position.global_x - c->position.global_x ))){
    direction = RIGHT;
    if(numerical_responses[current_zone->tiles[c.position.global_y][c.position.global_x+1] != 1){
    made_valid_move = 0;
    c->position.global_x +=1;
    if(c.position.local_x+1 >  DEFUALT_MAX_X - 1){
      c.position.local_x = 0;
    }
    else{
      c.position.local_x += 1;
     }
  }
      }
      
    /* move left */
      
  if( (abs(c->position.global_x-1 -target->position.global_x ) < abs(c->position.global_x - c->position.global_x ))]){
    direction = LEFT;
    if(numerical_responses[current_zone->tiles[c.position.global_y][c.position.global_x-1] != 1)){
    made_valid_move = 0;  
    c->position.global_x -=1;
    if(c.position.local_x -=1 < 0  ){
      c.position.local_x = DEFUALT_MAX_X - 1;
    }
    else{
      c.position.local_x -= 1;
    }
 }
}
  
  if(made_valid_move != 0){
    if(direction == UP){
      int left_dist, int right_dist = 0
    }

    if(direction == DOWN){

    }

    if(direction == LEFT){

    }

    if(direction == RIGHT){

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
  


