# Define the compiler
CC = gcc

# Define the compilation flags (-g -O0 are for Valgrind)
CFLAGS = -std=c99 -Wall -Werror -pedantic -g -O0

# Define linking flags (-lSDL2 is for the graphics library, SDL)
LFLAGS = -lSDL2 -lSDL2_image -lm

all: liol

liol: Main.c Definitions.h
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm -rf *.o
	rm -rf liol
