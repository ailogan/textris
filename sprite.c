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

sprite_t init_sprite(const spritemap_t* spritemap, const size_t num_sprites, const size_t width, const size_t height, const color_t color){

  sprite_t sprite;
  size_t spritemap_size = num_sprites * width * height;

  sprite.spritemap_pointer = (spritemap_t*)calloc(spritemap_size, sizeof(uint8_t));

  if(sprite.spritemap_pointer != NULL){
    memcpy(sprite.spritemap_pointer, spritemap, spritemap_size);
  }

  sprite.num_sprites = num_sprites;
  sprite.width = height;
  sprite.height = height;
  
  sprite.color = color;

  sprite.rotation = 0;

  return sprite;
}

void destruct_sprite(sprite_t* sprite){
  if(sprite == NULL){
    return;
  }

  if(sprite->spritemap_pointer != NULL){
    free(sprite->spritemap_pointer);
    sprite->spritemap_pointer = NULL;
  }

  return;
}

void rotate_cw(sprite_t* sprite){
  if(sprite == NULL){
    return;
  }

  sprite->rotation--;

  sprite->rotation %= sprite->num_sprites;
}

void rotate_ccw(sprite_t* sprite){
  if(sprite == NULL){
    return;
  }

  sprite->rotation++;

  sprite->rotation %= sprite->num_sprites;
}

