// File Dependencies
#include "Definitions.h"

// Macros
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

// Instance Variables
GameState_t *state = NULL;
int numberOfPlayers = 0;

// Method Declarations
int main(int ARGC, char** ARGV);
void gatherPlayerData();
int *calculatePlayOrder();
void runGameLoop();
int printInstruction(int target);
void freeResources();
void displayResults();

// Method Implementations
int main(int ARGC, char** ARGV) {

  // Gather player info (return a struct for game data?)
  gatherPlayerData();

  // Run game loop
  runGameLoop();

  // Free resources
  freeResources();

  printf("\nQuitting...\n\n");

  exit(EXIT_SUCCESS);
}

// Request the data for the game from the players and initialise game
void gatherPlayerData() {
  // Build game state struct
  state = calloc(1, sizeof(GameState_t));

  // Initialise rand()
  srand(time(NULL));

  // Poll user for number of players
  numberOfPlayers = 0;
  while (numberOfPlayers <= 0) {
    printf("Please enter the number of players (one or more):\n");
    scanf("%d", &numberOfPlayers);
  }

  state->numberOfPlayers = numberOfPlayers;
  state->names = calloc(numberOfPlayers, sizeof(char*));
  state->scores = calloc(numberOfPlayers, sizeof(int));

  // Poll user for player names
  for (int i = 0; i < numberOfPlayers; i++) {
    (state->names)[i] = calloc(256, sizeof(char));

    printf("Please enter player %d's name:\n", i);
    scanf("%s", (state->names)[i]);

    (state->scores)[i] = 0;
  }

  // Randomise play order
  state->playOrder = calculatePlayOrder();
}

// Ramdomly arrange the numbers from 0 to numberOfPlayers
// Add players to resulting order by stepping over unoccupied (-1) spaces
// a random number of times
int *calculatePlayOrder() {
  int *result = calloc(numberOfPlayers, sizeof(int));

  // Initialise all entries to -1
  for (int i = 0; i < numberOfPlayers; i++) {
    result[i] = -1;
  }

  int currentIndex = 0;
  for (int i = 0; i < numberOfPlayers - 1; i++) {

    int hops = rand() % RANDOMNESS_CAP;
    while (hops >= 0) {
      currentIndex = (currentIndex + 1) % numberOfPlayers;

      if (result[currentIndex] == -1) {
        // There is not a number in place so decrement hops
        hops--;
      }
    }

    result[currentIndex] = i;
  }

  // Add last
  currentIndex = 0;
  while (result[currentIndex] > -1) {
    currentIndex++;
  }
  result[currentIndex] = numberOfPlayers - 1;

  return result;
}

// Run the game
void runGameLoop() {
  printf("The play order is:\n");

  for (int i = 0; i < numberOfPlayers; i++) {
    printf("\t(%d) %s\n", i, (state->names)[(state->playOrder)[i]]);
  }

  printf("\nLet's begin!\n\n");

  int numberOfAlivePlayers = numberOfPlayers;
  int currentPlayer = 0;
  int roundNumber = 1;

  while (numberOfAlivePlayers) {
    printf("------------------------ Round %d ------------------------\n", roundNumber);

    for (int i = 0; i < numberOfPlayers; i++) {
      int currentPlayerIndex = (state->playOrder)[currentPlayer];

      if (currentPlayerIndex > -1) {
        // Player is alive
        printf("\n%s, it's your turn to go!\n",
                (state->names)[currentPlayerIndex]);

        // Spin for current player
        int target = rand() % RANDOMNESS_CAP;
        int score = printInstruction(target);

        // Await success/fail response
        char res;
        do {
          printf("Please enter 'y' for success and 'n' for failure:\n> ");
          scanf(" %c", &res);
        } while (res != 'y' && res != 'n');

        // Update scores
        if (res == 'y') {
          // Successful move
          (state->scores)[currentPlayerIndex] += score;
        } else {
          // Unsuccessful move
          (state->playOrder)[currentPlayer] = -1;
          numberOfAlivePlayers--;
        }

      } else {
        // Player is dead
          // Do nothing
      }

      currentPlayer = (currentPlayer + 1) % numberOfPlayers;
    }

    printf("\nThats the end of round %d, here are the scores...\n", roundNumber);
    for (int i = 0; i < numberOfPlayers; i++) {
      char *name = (state->names)[i];
      int score = (state->scores)[i];
      printf("\t%s has %d points\n", name, score);
    }

    printf("---------------------------------------------------------\n\n");

    roundNumber++;
  }

  printf("\nGame over! Let's have a look at the scores...\n");
  displayResults();
}

// Display the results *at the end of the game* i.e show winner(s) too
void displayResults() {
  char *winnerName = NULL;
  int winnerScore = 0;
  int gameTied = 0;

  for (int i = 0; i < numberOfPlayers; i++) {
    char *name = (state->names)[i];
    int score = (state->scores)[i];

    if (winnerName == NULL || score > winnerScore) {
      winnerName = name;
      winnerScore = score;
    } else if (score == winnerScore) {
      gameTied = 1;
    }

    printf("\t%s scored %d points\n", name, score);
  }

  if (gameTied) {
    printf("\nThere are no winners today, you're all losers!\n");
    printf("However these people lost less than the others...\n");

    for (int i = 0; i < numberOfPlayers; i++) {
      if ((state->scores)[i] == winnerScore) {
        printf("\t%s\n", (state->names)[i]);
      }
    }

  } else {
    printf("\nCongratulations to %s, who won with %d points!\n",
            winnerName, winnerScore);
  }
}

// TODO: abstract
int printInstruction(int target) {

  switch (target) {
    case 0:
      printf("Get his FACE\n");
      return 25;
    case 1:
      printf("Get his HEAD\n");
      return 20;
    case 2:
      printf("Get his HAND\n");
      return 18;
    case 3:
      printf("Get his FOOT\n");
      return 15;
    case 4:
      printf("Get his ARM\n");
      return 12;
    case 5:
      printf("Get his LEG\n");
      return 10;
    case 6:
      printf("Get his TORSO\n");
      return 7;
    default:
      printf("Case error (%d) @ printInstruction\n", target);
      return 0;
  }
}


// Free all resources used by this program
// (valgrind --tool=memcheck  --leak-check=full --show-leak-kinds=all ....)
void freeResources() {
  // Free game status struct
  for (int i = 0; i < numberOfPlayers; i++) {
    free((state->names)[i]);
  }

  free(state->names);
  free(state->scores);
  free(state->playOrder);

  free(state);
}
