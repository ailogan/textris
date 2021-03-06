CC=gcc
CFLAGS=-Wall -Werror -std=c99 -g -D_BSD_SOURCE
DEPS=color_utils.h playfield.h sprite.h piece.h ansi_screen.h
OBJ=main.o color_utils.o sprite.o playfield.o ansi_screen.o


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

textris: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o textris
