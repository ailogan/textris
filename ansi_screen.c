#ifndef ANSI_SCREEN_H
#define ANSI_SCREEN_H
/*
 * ansi_screen.c
 *
 * Andrew Logan
 * 1/25/15
 *
 * A collection of utilities that depend on the ANSI VT100 scancodes to do their thing.
 */

#include <stdio.h>

/*Save the current state of the screen.*/
void save_screen(){
  printf("\x1B[?47h");
}

/*Restore the previously-saved screen.*/
void restore_screen(){
  printf("\x1B[?47l");
}

/**/
void hide_cursor(){
  printf("\x1B[?25l");
}

/**/
void show_cursor(){
  printf("\x1B[?25h");
}

/*Yup.*/
void clear_screen(){
  printf("\x1B[2J\x1B[H");
}

#endif /*ANSI_SCREEN_H*/
