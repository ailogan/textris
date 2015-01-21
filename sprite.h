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

#define NUM_SPRITES 4
#define SPRITE_X_SIZE 4
#define SPRITE_Y_SIZE 4

typedef uint8_t spritemap_t[NUM_SPRITES][SPRITE_X_SIZE][SPRITE_Y_SIZE];

typedef struct{
  color_t color;
  spritemap_t* spritemap_pointer;
  unsigned int rotation;
} sprite_t;

/*Output a sprite to the screen.*/
int print_sprite(sprite_t sprite);

#endif /*SPRITE_H*/
