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
  
  sprite_t my_sprite;

  my_sprite.spritemap_pointer = (spritemap_t*)malloc(4 * 4 * 4 * sizeof(int));

  if(my_sprite.spritemap_pointer == NULL){
    printf("Failed to allocate memory for the blocks\n");
    return EXIT_FAILURE;
  }

  for(int j = 0; j < 7; j++){

    memcpy(my_sprite.spritemap_pointer, textronomo[j].blocks, sizeof(textronomo[j].blocks));
    my_sprite.color = textronomo[j].color;
  
    for(int j = 0; j < 4; j++){
      my_sprite.rotation = j;
      print_sprite(my_sprite);
      printf("\n");
    }
  }

  free(my_sprite.spritemap_pointer);

  return EXIT_SUCCESS;
}
