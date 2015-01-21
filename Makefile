maCC=gcc
CFLAGS=-Wall -Werror -std=c99 -g
DEPS=
OBJ=main.o


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

textris: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o textris
