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
  
  /*
  save_screen();
  hide_cursor();
  clear_screen();
  */

  /*width, height, border width, border color*/
  playfield_t my_playfield = init_playfield(10,20,2,red);

  sprite_t t_sprite = init_sprite(&(textronomo[0]));
  sprite_t j_sprite = init_sprite(&(textronomo[1]));

  blit(&my_playfield, &t_sprite, 0,0);

  blit(&my_playfield, &j_sprite, 4,0);

  print_playfield(&my_playfield);

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
