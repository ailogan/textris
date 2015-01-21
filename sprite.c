/*
 * sprite.c
 *
 * Andrew Logan
 * 1/20/15
 *
 * Utilities that will be useful for dealing with sprites.
 */

#include "sprite.h"

/*Output a sprite to the screen.*/
int print_sprite(sprite_t sprite){
  const char* block = "[]";
  const char* empty = "  ";

  if(sprite.rotation > (NUM_SPRITES - 1)){
    return -1;
  }

  char* line = (char*)malloc((SPRITE_Y_SIZE * strlen(empty)));

  if(line == NULL){
    return -1;
  }

  for(size_t i = 0; i < SPRITE_X_SIZE; i++){
    for(size_t j = 0; j < SPRITE_Y_SIZE; j++){
      int element = (*sprite.spritemap_pointer)[sprite.rotation][i][j];

      if(element == 0){
	memcpy(&(line[j*strlen(empty)]), empty, strlen(empty));
      }
      else{
	memcpy(&(line[j*strlen(block)]), block, strlen(block));
      }
    }
    color_printf(sprite.color, "%s\n", line);
  }
  
  free(line);
  
  return 0;
}
