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

#include "color_utils.h"
#include "sprite.h"
#include "textronomos.h"

int main(){
  
  for(int j = 0; j < 7; j++){
    
    sprite_t my_sprite = init_sprite(&(textronomo[j].blocks), 4, 4, 4, textronomo[j].color);
  
    for(int j = 0; j < 4; j++){
      print_sprite(my_sprite);
      rotate_cw(&my_sprite);
      printf("\n");
    }

    destruct_sprite(&my_sprite);
  }

  return EXIT_SUCCESS;
}
