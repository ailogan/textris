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

playfield_t init_playfield(const uint8_t width, const uint8_t height, const uint8_t border_width, const color_t border_color){

  playfield_t p;

  p.width = width;
  p.height = height;
  p.border_width = border_width;
  p.border_color = border_color;

  /*Caller has to check for NULL here.*/
  /*TODO: Is there a better way to do this?*/
  p.playfield_pointer = (uint8_t*)calloc(width*height, sizeof(uint8_t));

  return p;
}

void destruct_playfield(playfield_t* const p){
  if(p == NULL){
    return;
  }

  if(p->playfield_pointer == NULL){
    return;
  }

  free(p->playfield_pointer);
  p->playfield_pointer = NULL;
}

int print_playfield(const playfield_t* const p){
  char *empty  = "--";
  char *full   = "[]"; 
  char *border = "#";

  if(p == NULL){
    return -1;
  }
  
  /*Width times two characters to display each block plus a null at the end.*/
  size_t playfield_line_width = (p->width * 2) + 1;

  char *line = (char*)calloc(playfield_line_width, sizeof(char));
  if(line == NULL){
    return -1;
  }

  for (int x = 0; x < p->height; x++){

    int line_index = 0;

    /*Each line starts with the border*/
    for(int i = 0; i < p->border_width; i++){
      color_printf(p->border_color, "%s", border);
    }
    
    /*Now the playfield*/
    for(int y = 0; y < p->width; y++){
      const int element = p->playfield_pointer[y + (x*p->width)];

      if(element == 0){
	strncpy(&(line[line_index]), empty, strlen(empty));
	line_index += strlen(empty);
      }
      else{
	strncpy(&(line[line_index]), full, strlen(full));
	line_index += strlen(full);
      }
    }

    color_printf(gray, "%s", line);

    /*And the border on the other side*/
    /*Each line starts with the border*/
    for(int i = 0; i < p->border_width; i++){
      color_printf(p->border_color, "%s", border);
    }

    /*And a newline to finish it off.*/
    printf("\n");

  }

  /*Final line is all border*/
  for(int i = 0; i < ((p->width * 2) + (2*p->border_width)); i++){
    color_printf(p->border_color, "%s", border);
  }

  /*And a final newline.*/
  printf("\n");

  free(line);
  return 0;
}
  
