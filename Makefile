# Define the compiler
CC = gcc

# Define the compilation flags (-g -O0 are for Valgrind)
CFLAGS = -c -g -O0 -Wall -Werror -pedantic -std=c99

# Define linking flags (-lSDL2 is for the graphics library, SDL)
LFLAGS = -lSDL2 -lSDL2_image -lm

all: liol

liol: main.o GUI.o
	$(CC) $^ $(LFLAGS) -o $@

main.o: Main.c Definitions.h GUI.h
	$(CC) $(CFLAGS) Main.c -o $@

gui.o: GUI.h GUI.c Definitions.h
	$(CC) $(CFLAGS) GUI.c -o $@


clean:
	rm -rf *.o
	rm -rf liol
