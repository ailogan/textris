#ifndef PLAYFIELD_H
#define PLAYFIELD_H

/*
 * playfield.h
 *
 * Andrew Logan
 * 1/25/15
 *
 * Stuff that's useful for the playfield part of the game.
 */

#include <stdint.h>

#include "color_utils.h"
#include "sprite.h"

typedef struct{
  uint8_t width;
  uint8_t height;
  uint8_t border_width;
  uint8_t border_color;
  
  color_t* playfield_pointer;

} playfield_t;

playfield_t init_playfield(const uint8_t width, const uint8_t height, const uint8_t border_width, const color_t border_color);

void destruct_playfield(playfield_t* const p);

int print_playfield(const playfield_t* const p);


#endif /*PLAYFIELD_H*/
