/*
 * Textris
 *
 * Andrew Logan
 * 1/20/15
 *
 * You know how sometimes you have a terrible idea that you just can't shake?  Yeah, me neither.
 *
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "color_utils.h"
#include "sprite.h"
#include "playfield.h"
#include "textronomos.h"
#include "ansi_screen.h"

int main(){

  save_screen();
  hide_cursor();
  clear_screen();

  /*width, height, border width, border color*/
  playfield_t background_playfield = init_playfield(10,20,2,red);

  int collided_at_start = 0;

  /*Seed the PRNG*/
  srand(time(NULL));

  do{
    /*Yes it's not uniform.  No, I don't care right now.*/
    int random_piece = (rand() % 7);
    sprite_t sprite = init_sprite(&(textronomo[random_piece]));
    
    int collision = 0;
    
    pos_t spritepos = init_pos(3,-2);
    
    do{
      pos_t prior_spritepos = copy_pos(&spritepos);

      spritepos.y++;

      /*TODO: do something better here too.*/
      size_t prior_rotation = sprite.rotation;

      /*The world's crappiest tetris AI right here.*/
      int move = (rand() % 10);

      switch(move){
      case 1:
      case 2:
      case 7:
	spritepos.x--;
	printf("left\n");
	break;
	
      case 3:
      case 4:
      case 8:
	spritepos.x++;
	printf("right\n");
	break;

      case 5:
	rotate_cw(&sprite);
	printf("cw\n");
	break;

      case 6:
	rotate_ccw(&sprite);
	printf("ccw\n");
	break;

      default:
	break;
	/*Yup.  20% of the time it doesn't do anything.*/
      }

      playfield_t work_playfield = copy_playfield(&background_playfield);
      
      collision = blit(&work_playfield, &sprite, spritepos.x, spritepos.y);
      
      /*eg: we didn't hit a thing.*/
      if(collision != 0){
	/*Did we rotate and drop and hit a thing?*/
	if(sprite.rotation != prior_rotation){
	  sprite.rotation = prior_rotation;

	  playfield_t temp_playfield = copy_playfield(&background_playfield);

	  int temp_collision = blit(&temp_playfield, &sprite, spritepos.x, spritepos.y);
	  
	  if(temp_collision == 0){
	    /*Rotation was illegal, but dropping is fine.*/
	    work_playfield = copy_playfield(&temp_playfield);
	    collision = 0;
	  }

	  /*Rotation didn't matter, so keep it at the previous one.*/
	  destruct_playfield(&temp_playfield);
	}

	/*Did we move on the x axis and hit a thing?*/
	if(prior_spritepos.x != spritepos.x){
	  playfield_t temp_playfield = copy_playfield(&background_playfield);

	  int temp_collision = blit(&temp_playfield, &sprite, prior_spritepos.x, spritepos.y);
	  
	  if(temp_collision == 0){
	    /*Yes.  So that's not a collision?*/
	    spritepos.x = prior_spritepos.x;
	    work_playfield = copy_playfield(&temp_playfield);
	    collision = 0;
	  }
	}	 
      }

      if(collision == 0){
	clear_screen();
	print_playfield(&work_playfield);
      }

      else{
	/*We still hit a thing, even after fiddling with the setup.*/
	blit(&background_playfield, &sprite, prior_spritepos.x, prior_spritepos.y);
	clear_screen();
	print_playfield(&background_playfield);
	
	if(prior_spritepos.y == -2){
	  collided_at_start = 1;
	}
      }
      
      destruct_playfield(&work_playfield);
      
      usleep(75*1000);
    }while(collision == 0);

    printf("hit a thing\n");

    if(collided_at_start != 0){
      printf("game over\n");
    }

    destruct_sprite(&sprite);
    
  }while(collided_at_start == 0);

  getchar();

  restore_screen();

  print_playfield(&background_playfield);

  show_cursor();

  return EXIT_SUCCESS;

  /*
  for(int j = 0; j < 7; j++){
    
    sprite_t my_sprite = init_sprite(&(textronomo[j]));
  
    for(int j = 0; j < 4; j++){
      print_sprite(&my_sprite);
      rotate_cw(&my_sprite);
      usleep(500 * 1000); //Yaaaaaay microseconds

      clear_screen();
    }
    
    destruct_sprite(&my_sprite);
  }

  sleep(1);
  
  restore_screen();
  show_cursor();

  return EXIT_SUCCESS;
*/
}
