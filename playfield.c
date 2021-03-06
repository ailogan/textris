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

/*Constructors are cool.*/
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

/*A copy constructor for a playfield_t.  Or, well, as close as you can get with structs in C.  Why the hell am I writing this in C?*/
playfield_t copy_playfield(const playfield_t * const source){
  playfield_t dest = init_playfield(source->width, source->height, source->border_width, source->border_color);

  if(dest.playfield_pointer == NULL){
    return dest;
  }

  /*Nifty.  Now we throw away the default playfield and fill it with the one from source.*/
  for(int i = 0; i < source->width * source->height; i++){
    dest.playfield_pointer[i] = source->playfield_pointer[i];
  }

  return dest;
}

/*Free what needs freein.*/
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
    for(int j = 0; j < p->border_width; j++){
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

/*Overlay sprite onto background.  Top corner of sprite goes at (x,y), x and y are both relative from the top left corner.  Modifies background.  Returns 1 if the sprite collided with something, returns -1 if there was an error.  0 means success.*/
int blit(playfield_t * const background, const sprite_t * const sprite, const int8_t x, const int8_t y){
  if((x >= background->width) ||
     (y >= background->height)){
    /*Well, there you go.*/
    return -1;
  }

  int collision = 0;

  const color_t sprite_color = sprite->color;
  const size_t sprite_width = sprite->width;
  const size_t sprite_height = sprite->height;

  /*Get the pointer to the bitmap we care about.  We already know the width and height from the sprite.*/
  const bitmap_t* bitmap = get_bitmap(sprite);

  size_t sprite_y = 0;

  /*Negative means "shift up"*/
  if(y < 0 && (abs(y) <= sprite_height)){
    sprite_y = abs(y);
  }

  /*Don't run off the edges of the playfield, but also don't run off the edges of the sprite (don't scribble memory if x or y are off the edge of the playfield).*/
  for(int y_idx = (y < 0 ? 0 : y); y_idx < background->height; y_idx++){
    if(sprite_y >= sprite_height){
      break;
    }

    size_t sprite_x = 0;


    /*Check for collisions with the left wall*/
    if(x < 0){
      for (int i = 0; i < abs(x); i++){
	size_t bitmap_idx = (sprite_y * sprite_width) + i;

	uint8_t element = bitmap[bitmap_idx];

	/*A non-transparent part of the sprite would be drawn on top of the wall.*/
	if(element != 0){
	  collision = 1;
	}
      }
    }

    int x_idx;

    if(x < 0){
      x_idx = 0;
    }
    else{
      x_idx = x;
    }

    for(; x_idx < background->width; x_idx++){
      if(sprite_x >= sprite_width){
	break;
      }

      /*I hope you like offsets.*/
      size_t background_idx = (y_idx * background->width) + x_idx;
      size_t bitmap_idx = (sprite_y * sprite_width) + sprite_x;

      uint8_t element = bitmap[bitmap_idx];

      /*Look at the next element on our next time through.*/
      sprite_x++;

      /*Zero means the sprite is transparent there.*/
      if(element == 0){
	continue;
      }

      else{
	/*Otherwise put the appropriate color in the appropriate place, overwriting whatever was there before.  Check to see if we're hitting something, though.*/
	if(background->playfield_pointer[background_idx] != none){
	  collision = 1;
	}
	background->playfield_pointer[background_idx] = sprite_color;
      }
    }
    /*Check for collisions with the walls.  Would, unfortunately, be a lot easier if the border was part of the playfield.*/
    if((sprite_x < sprite_width) && x_idx == background->width){
      size_t bitmap_idx = (sprite_y * sprite_width) + sprite_x;
      uint8_t element = bitmap[bitmap_idx];

      /*A non-transparent part of the sprite would be drawn on top of the wall.*/
      if(element != 0){
	collision = 1;
      }
    }

    sprite_y++;
  }
  
  /*Did the bottom of the sprite get cut off? (because we end with sprite_y++ we expect it to be equal to sprite_height if the whole thing was displayed)*/
  if(sprite_y < sprite_height){
    collision = 1;
  }

  return collision;
}
