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


/*Enum only covers foreground colors*/

typedef enum {
  black = 30,
  red,
  green,
  yellow,
  blue,
  magenta,
  cyan,
  white
} color_t;

/*Like printf, but it wraps the ANSI color codes around the string.*/
int color_printf(color_t color, const char* fmt, ...);
