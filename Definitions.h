#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// File Dependencies
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Macros
#define RANDOMNESS_CAP 7

// Game state struct
typedef struct GameState {
  int numberOfPlayers;
  char **names;
  int *scores;
  int *playOrder;
} GameState_t;


#endif
