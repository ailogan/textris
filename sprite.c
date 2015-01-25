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
int print_sprite(const sprite_t* const sprite){
  const char* block = "[]";
  const char* empty = "  ";

  /*We're about to use sprite.rotation as an index into the sprites, so make sure it's reasonable.*/
  if(sprite->rotation > (sprite->num_sprites - 1)){
    return -1;
  }

  char* line = (char*)malloc((sprite->width * strlen(empty)));

  if(line == NULL){
    return -1;
  }

  size_t sprite_size = sprite->height * sprite->width;

  for(size_t i = 0; i < sprite->height; i++){
    for(size_t j = 0; j < sprite->width; j++){
      size_t index;

      /*Figure out which cell we want.  First get to the right sprite:*/
      index = sprite_size * sprite->rotation;
      
      /*Then jump to the correct row:*/
      index += (i * sprite->width);

      /*And then the right column in that row:*/
      index += j;
      
      uint8_t element = sprite->sprites_pointer[index];

      if(element == 0){
	memcpy(&(line[j*strlen(empty)]), empty, strlen(empty));
      }
      else{
	memcpy(&(line[j*strlen(block)]), block, strlen(block));
      }
    }
    color_printf(sprite->color, "%s\n", line);
  }
  
  free(line);
  
  return 0;
}

sprite_t init_sprite(const piece_t* const piece){

  sprite_t sprite;
  sprite.sprites_pointer = NULL;

  /*Not the world's greatest way to indicate errors, but whatever.*/
  if(piece == NULL){
    return sprite;
  }

  size_t sprites_size = piece->num_sprites * piece->width * piece->height;

  sprite.sprites_pointer = (sprites_t*)calloc(sprites_size, sizeof(uint8_t));

  if(sprite.sprites_pointer == NULL){
    return sprite;
  }

  memcpy(sprite.sprites_pointer, piece->sprites, sprites_size);

  sprite.num_sprites = piece->num_sprites;
  sprite.width = piece->width;
  sprite.height = piece->height;
  
  sprite.color = piece->color;

  sprite.rotation = 0;

  return sprite;
}

void destruct_sprite(sprite_t* sprite){
  if(sprite == NULL){
    return;
  }

  if(sprite->sprites_pointer != NULL){
    free(sprite->sprites_pointer);
    sprite->sprites_pointer = NULL;
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

