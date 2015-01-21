/*
 * color_utils.c
 *
 * Andrew Logan
 * 1/20/15
 *
 * Set of routines and such to make dealing with ANSI VT100 color codes easier.
 *
 */

#include "color_utils.h"

int color_printf(color_t color, const char* fmt, ...){
  va_list ap;
  int retval;

  va_start(ap, fmt);

  printf("\x1b[%dm", color);
  
  retval = vprintf(fmt, ap);

  printf("\x1b[0m");

  return retval;
}
