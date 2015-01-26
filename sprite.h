#ifndef SPRITE_H
#define SPRITE_H

/*
 * sprite.h
 *
 * Andrew Logan
 * 1/20/15
 *
 * Utilities that will be useful for dealing with sprites.
 */

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "color_utils.h"
#include "piece.h"

/*They said it'd never be useful!  Bwahahahahaha*/
typedef struct{
  int x;
  int y;
} pos_t;

pos_t init_pos(const int x, const int y);

pos_t copy_pos(const pos_t * const source);

/*Maaaaaaybe not super-thrilled about this one still.*/
typedef uint8_t bitmap_t;

typedef struct{
  color_t color;
  size_t num_bitmaps;
  size_t width;
  size_t height;
  bitmap_t* bitmaps_p;
  size_t rotation; /*Which bitmap is the current one?.*/
  uint8_t pos_x;
  uint8_t pos_y;
} sprite_t;

/*Output a sprite to the screen.*/
int print_sprite(const sprite_t* const sprite);

/*Initialize a sprite.  Caller is responsible for checking whether spritemap_pointer is NULL*/
sprite_t init_sprite(const piece_t* const piece);

/*Free all the stuff that needs freein'.*/
void destruct_sprite(sprite_t* sprite);

/*Rotate clockwise (assumes spritemap is set up so that looking at the next-largest sprite in the spritemap rotates the sprite counterclockwise)*/
void rotate_cw(sprite_t* sprite);

/*Rotate counterclockwise (assumes spritemap is set up so that looking at the next-largest sprite in the spritemap rotates the sprite counterclockwise)*/
void rotate_ccw(sprite_t* sprite);

/*Returns a pointer to the current bitmap or NULL if something's wrong.  Or maybe just somewhere off of the end of memory.  It's C, you never really know.*/
const bitmap_t* get_bitmap(const sprite_t * const s);

#endif /*SPRITE_H*/
