#ifndef PIECE_H
#define PIECE_H

/*
 * piece.h
 *
 * Andrew Logan
 * 1/25/15
 *
 * Have to lift this definition into its own file because of some nasty circular dependencies otherwise.
 */

typedef struct{
  const char* name;
  const color_t color;
  const size_t num_sprites;
  const size_t width;
  const size_t height;
  const uint8_t* const sprites;
} piece_t;

#endif /*PIECE_H*/
