/*
 * color_utils.h
 *
 * Andrew Logan
 * 1/20/15
 *
 * Set of routines and such to make dealing with ANSI VT100 color codes easier.
 *
 */

#include <stdarg.h> /*For the varargs struff*/
#include <stdio.h>  /*printf, vprintf*/


/*Enum only covers foreground colors, assumes a terminal that supports 256-color indexing*/
typedef enum {
  black   = 0,
  red,
  green,
  yellow,
  blue,
  magenta,
  cyan,
  white,
  gray,
  bright_red,
  bright_green,
  bright_yellow,
  bright_blue,
  bright_magenta,
  bright_cyan,
  bright_white,
  orange   = 202,
  bright_orange = 208
} color_t;

/*Like printf, but it wraps the ANSI color codes around the string.*/
int color_printf(color_t color, const char* fmt, ...);
