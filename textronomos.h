#ifndef TEXTRONOMOS_H
#define TEXTRONOMOS_H

/*
 * textronomos.h
 *
 * Andrew Logan
 * 1/20/15
 *
 * Sprite definitions.  Format expects them to rotate counterclockwise, zeroth element is the shape's initial starting position.
 */

#include "color_utils.h"
#include "sprite.h"
#include "piece.h"

const uint8_t t_sprites[] = {0,0,0,0,
			     0,0,0,0,
			     1,1,1,0,
			     0,1,0,0,
			     
			     0,0,0,0,
			     0,1,0,0,
			     0,1,1,0,
			     0,1,0,0,
			     
			     0,0,0,0,
			     0,0,0,0,
			     0,1,0,0,
			     1,1,1,0,
			     
			     0,0,0,0,
			     0,1,0,0,
			     1,1,0,0,
			     0,1,0,0};


const uint8_t j_sprites[] = {0,0,0,0,
			     0,0,0,0,
			     1,1,1,0,
			     0,0,1,0,
			     
			     0,0,0,0,
			     0,1,1,0,
			     0,1,0,0,
			     0,1,0,0,
			     
			     0,0,0,0,
			     0,0,0,0,
			     1,0,0,0,
			     1,1,1,0,
			     
			     0,0,0,0,
			     0,1,0,0,
			     0,1,0,0,
			     1,1,0,0};

const uint8_t l_sprites[] = {0,0,0,0,
			     0,0,0,0,
			     1,1,1,0,
			     1,0,0,0,
			     
			     0,0,0,0,
			     0,1,0,0,
			     0,1,0,0,
			     0,1,1,0,
			     
			     0,0,0,0,
			     0,0,0,0,
			     0,0,1,0,
			     1,1,1,0,
			     
			     0,0,0,0,
			     1,1,0,0,
			     0,1,0,0,
			     0,1,0,0};

const uint8_t z_sprites[] = {0,0,0,0,
			     0,0,0,0,
			     1,1,0,0,
			     0,1,1,0,

			     0,0,0,0,
			     0,0,1,0,
			     0,1,1,0,
			     0,1,0,0};

const uint8_t s_sprites[] = {0,0,0,0,
			     0,0,0,0,
			     0,1,1,0,
			     1,1,0,0,

			     0,0,0,0,
			     0,1,0,0,
			     0,1,1,0,
			     0,0,1,0};

const uint8_t i_sprites[] = {0,0,0,0,
			     1,1,1,1,
			     0,0,0,0,
			     0,0,0,0,
			     
			     0,0,1,0,
			     0,0,1,0,
			     0,0,1,0,
			     0,0,1,0};

const uint8_t o_sprites[] = {0,0,0,0,
			     0,0,0,0,
			     0,1,1,0,
			     0,1,1,0};

/*So flexible arrays are totally a thing in C.  The problem shows up
  when you try to make an array of structs that contain a flexible
  array since (as far as I can tell) C requires all of the elements of
  an array to be the same size.  Hence this nonsense with
  pointers-to-arrays-defined-elsewhere.*/

piece_t textronomo[7] = {{.name="t_block", 
			  .color=cyan,
			  .num_sprites=4,
			  .width=4,
			  .height=4,
			  .sprites=t_sprites},
			 
			 {.name="j_block",
			  .color=bright_blue,
			  .num_sprites=4,
			  .width=4,
			  .height=4,
			  .sprites=j_sprites},
			 
			 {.name="l_block",
			  .color=orange,
			  .num_sprites=4,
			  .width=4,
			  .height=4,
			  .sprites=l_sprites},
			 
			 {.name="z_block",
			  .color=green,
			  .num_sprites=2,
			  .width=4,
			  .height=4,
			  .sprites=z_sprites},
			 
			 {.name="s_block",
			  .color=magenta,
			  .num_sprites=2,
			  .width=4,
			  .height=4,
			  .sprites=s_sprites},
			 
			 {.name="i_block",
			  .color=red,
			  .num_sprites=2,
			  .width=4,
			  .height=4,
			  .sprites=i_sprites},
			 
			 {.name="o_block",
			  .color=bright_yellow,
			  .num_sprites=1,
			  .width=4,
			  .height=4,
			  .sprites=o_sprites}};

#endif /*TEXTRONOMOS_H*/
