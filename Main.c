// File Dependencies
#include "Definitions.h"

// Macros
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

// Instance Variables
int numberOfPlayers = 0;

// Method Declarations
int main(int ARGC, char** ARGV);
void gatherPlayerData();
void initialiseGame();
void runGameLoop();
void freeResources();

// Method Implementations
int main(int ARGC, char** ARGV) {

  // Gather player info (return a struct for game data?)
  gatherPlayerData();

  // Run game loop
  runGameLoop();

  // Free resources
  freeResources();

  exit(EXIT_SUCCESS);
}

// Request the data for the game from the players
void gatherPlayerData() {
  // Poll user for number of players

  // Poll user for player names

}

// Initialise the game
void initialiseGame() {

  // Randomise player order

  // Set up game state struct
}

// Run the game
void runGameLoop() {

  while (/*gameNotOver*/ 0) {
    // Spin for current player

    // Await success/fail response

    // Update scores

    // Move to next player

    // If current player is start player, show scores and increment round
  }
}

// Free all resources used by this program
// (valgrind --tool=memcheck  --leak-check=full --show-leak-kinds=all ....)
void freeResources() {
  // Free game status struct
}
