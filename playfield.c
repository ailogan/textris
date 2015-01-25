/*
 * playfield.c
 *
 * Andrew Logan
 * 1/25/15
 *
 * Helper functions for the playfield.
 */

/*returns an initialized playfield struct on success, caller has to check to see if playfield_pointer is NULL.*/

#include "playfield.h"

playfield init_playfield(const uint8_t width, const uint8_t height, const uint8_t border_width, const color_t border_color){

  playfield field;

  field.width = width;
  field.height = height;
  field.border_width = border_width;
  field.border_color = border_color;

  /*Caller has to check for NULL here.*/
  /*TODO: Is there a better way to do this?*/
  field.playfield_pointer = (uint8_t*)calloc(width*height, sizeof(uint8_t));

  return field;
}

