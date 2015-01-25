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
  size_t num_sprites;
  size_t width;
  size_t height;
  spritemap_t* spritemap_pointer;
  size_t rotation; /*index into the spritemap.*/
} sprite_t;

/*Output a sprite to the screen.*/
int print_sprite(sprite_t sprite);

/*Initialize a sprite.  Caller is responsible for checking whether spritemap_pointer is NULL*/
sprite_t init_sprite(const spritemap_t* spritemap, const size_t num_sprites, const size_t width, const size_t height, const color_t color);

/*Free all the stuff that needs freein'.*/
void destruct_sprite(sprite_t* sprite);

/*Rotate clockwise (assumes spritemap is set up so that looking at the next-largest sprite in the spritemap rotates the sprite counterclockwise)*/
void rotate_cw(sprite_t* sprite);

/*Rotate counterclockwise (assumes spritemap is set up so that looking at the next-largest sprite in the spritemap rotates the sprite counterclockwise)*/
void rotate_ccw(sprite_t* sprite);


#endif /*SPRITE_H*/
