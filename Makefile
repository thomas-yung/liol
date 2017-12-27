# Define the compiler
CC = gcc

# Define the compilation flags
CFLAGS = -std=c99 -Wall -Werror -pedantic

# Define linking flags
LFLAGS =

all: liol

liol: Main.c
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm -rf *.o
	rm -rf liol
