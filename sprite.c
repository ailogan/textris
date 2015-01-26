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
  if(sprite->rotation > (sprite->num_bitmaps - 1)){
    return -1;
  }

  char* line = (char*)malloc((sprite->width * strlen(empty)));

  if(line == NULL){
    return -1;
  }

  for(size_t i = 0; i < sprite->height; i++){
    for(size_t j = 0; j < sprite->width; j++){

      /*Figure out which cell we want.  First get the right bitmap:*/
      const bitmap_t* bitmap = get_bitmap(sprite);
      
      /*Jump to the correct row:*/
      size_t index = (i * sprite->width);

      /*And then the right column in that row:*/
      index += j;
      
      uint8_t element = bitmap[index];

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
  sprite.bitmaps_p = NULL;

  /*Not the world's greatest way to indicate errors, but whatever.*/
  if(piece == NULL){
    return sprite;
  }

  size_t sprites_size = piece->num_bitmaps * piece->width * piece->height;

  sprite.bitmaps_p = (bitmap_t*)calloc(sprites_size, sizeof(uint8_t));

  if(sprite.bitmaps_p == NULL){
    return sprite;
  }

  memcpy(sprite.bitmaps_p, piece->bitmaps, sprites_size);

  sprite.num_bitmaps = piece->num_bitmaps;
  sprite.width = piece->width;
  sprite.height = piece->height;
  
  sprite.color = piece->color;

  sprite.rotation = 0;

  /*We need to know more about the playfield to set this up.*/
  sprite.pos_x = 0;
  sprite.pos_y = 0;

  return sprite;
}

void destruct_sprite(sprite_t* sprite){
  if(sprite == NULL){
    return;
  }

  if(sprite->bitmaps_p != NULL){
    free(sprite->bitmaps_p);
    sprite->bitmaps_p = NULL;
  }

  return;
}

void rotate_cw(sprite_t* sprite){
  if(sprite == NULL){
    return;
  }

  sprite->rotation--;

  sprite->rotation %= sprite->num_bitmaps;
}

void rotate_ccw(sprite_t* sprite){
  if(sprite == NULL){
    return;
  }

  sprite->rotation++;

  sprite->rotation %= sprite->num_bitmaps;
}

/*Returns a pointer to the current bitmap or NULL if something's wrong.  Or maybe just somewhere off of the end of memory.  It's C, you never really know.*/
const bitmap_t* get_bitmap(const sprite_t * const s){
  
  if(s == NULL){
    return NULL;
  }

  if(s->rotation > (s->num_bitmaps - 1)){
    return NULL;
  }

  const size_t bitmap_offset = (s->width * s->height) * s->rotation;

  /*Pointer aritmetic!*/
  const bitmap_t* current_bitmap = s->bitmaps_p + bitmap_offset;

  return current_bitmap;
}


