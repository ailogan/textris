/*
 * ansi_screen.h
 *
 * Andrew Logan
 * 1/25/15
 *
 * Yes, I should just use ncurses instead.
 */


/*Save the current state of the screen.*/
void save_screen();

/*Restore the previously-saved screen.*/
void restore_screen();

void show_cursor();

void hide_cursor();

/*Yup.*/
void clear_screen();
