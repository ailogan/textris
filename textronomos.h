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

const bitmap_t t_bitmaps[] = {0,0,0,0,
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


const bitmap_t j_bitmaps[] = {0,0,0,0,
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

const bitmap_t l_bitmaps[] = {0,0,0,0,
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

const bitmap_t z_bitmaps[] = {0,0,0,0,
			      0,0,0,0,
			      1,1,0,0,
			      0,1,1,0,

			      0,0,0,0,
			      0,0,1,0,
			      0,1,1,0,
			      0,1,0,0};

const bitmap_t s_bitmaps[] = {0,0,0,0,
			      0,0,0,0,
			      0,1,1,0,
			      1,1,0,0,

			      0,0,0,0,
			      0,1,0,0,
			      0,1,1,0,
			      0,0,1,0};

const bitmap_t i_bitmaps[] = {0,0,0,0,
			      1,1,1,1,
			      0,0,0,0,
			      0,0,0,0,
			     
			      0,0,1,0,
			      0,0,1,0,
			      0,0,1,0,
			      0,0,1,0};

const bitmap_t o_bitmaps[] = {0,0,0,0,
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
			  .num_bitmaps=4,
			  .width=4,
			  .height=4,
			  .bitmaps=t_bitmaps},
			 
			 {.name="j_block",
			  .color=bright_blue,
			  .num_bitmaps=4,
			  .width=4,
			  .height=4,
			  .bitmaps=j_bitmaps},
			 
			 {.name="l_block",
			  .color=orange,
			  .num_bitmaps=4,
			  .width=4,
			  .height=4,
			  .bitmaps=l_bitmaps},
			 
			 {.name="z_block",
			  .color=green,
			  .num_bitmaps=2,
			  .width=4,
			  .height=4,
			  .bitmaps=z_bitmaps},
			 
			 {.name="s_block",
			  .color=magenta,
			  .num_bitmaps=2,
			  .width=4,
			  .height=4,
			  .bitmaps=s_bitmaps},
			 
			 {.name="i_block",
			  .color=red,
			  .num_bitmaps=2,
			  .width=4,
			  .height=4,
			  .bitmaps=i_bitmaps},
			 
			 {.name="o_block",
			  .color=bright_yellow,
			  .num_bitmaps=1,
			  .width=4,
			  .height=4,
			  .bitmaps=o_bitmaps}};

#endif /*TEXTRONOMOS_H*/
