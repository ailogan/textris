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
    printf("Failed to allocate memory for the T block\n");
    return EXIT_FAILURE;
  }

  memcpy(my_sprite.spritemap_pointer, t_block, sizeof(t_block));
  my_sprite.color = t_color;
  
  for(int i = 0; i < 4; i++){
    my_sprite.rotation = i;
    print_sprite(my_sprite);
    printf("\n");
  }

  free(my_sprite.spritemap_pointer);

  return EXIT_SUCCESS;
}
