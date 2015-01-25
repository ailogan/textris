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
  
  const size_t num_elements = width*height;

  p.playfield_pointer = (color_t*)calloc(num_elements, sizeof(color_t));

  for(size_t s = 0; s < num_elements; s++){
    p.playfield_pointer[s] = none;
  }

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
  
  for (int x = 0; x < p->height; x++){

    /*Each line starts with the border*/
    for(int i = 0; i < p->border_width; i++){
      color_printf(p->border_color, "%s", border);
    }
    
    /*Now the playfield*/
    for(int y = 0; y < p->width; y++){
      const color_t element = p->playfield_pointer[y + (x*p->width)];

      if(element == none){
	color_printf(gray, "%s", empty);
      }
      else{
	color_printf(element, "%s", full);
      }
    }

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

  return 0;
}
  
