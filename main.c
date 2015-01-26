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
    int sprite_x = 3;

    int previous_sprite_y;
    int sprite_y = -2;
    
    do{
      previous_sprite_y = sprite_y;

      playfield_t work_playfield = copy_playfield(&background_playfield);
      
      collision = blit(&work_playfield, &sprite, sprite_x, ++sprite_y);
      
      /*eg: we didn't hit a thing.*/
      if(collision == 0){
	clear_screen();
	print_playfield(&work_playfield);
      }
      else{
	/*If we did hit a thing, blit the previous location into the background and don't show the new one.*/
	blit(&background_playfield, &sprite, sprite_x, previous_sprite_y);
	clear_screen();
	print_playfield(&background_playfield);
	printf("hit a thing\n");
      }

      destruct_playfield(&work_playfield);
      
      usleep(75*1000);
    }while(collision == 0);

    if(previous_sprite_y == -2){
      collided_at_start = 1;
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
