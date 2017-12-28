// File Dependencies
#include "GUI.h"

// Instance Variables
SDL_Window *window = NULL;
SDL_Surface *screenSurface = NULL;

// Method Implementations
// Display the main menu and respond to user selection
void showMainMenu() {

}

// Display a name input screen for the nth player
void showNameScreen(int n) {

}

// Display spinner and the option given
// TODO: Make the param an enum?
void showTargetSpinner(int option) {

}

// Display pass/fail screen and forward the response to the caller
int showPassFail() {
  return 0;
}

// Display scoreboard
void showScoreboard(GameState_t *state) {

}

// Display endscreen with option to replay (returning a 1 for a new game)
int showEndScreen() {
  return 0;
}

// Wrapper method to destroy window (Main.c doesn't have access to the window)
void closeWindow() {
  SDL_DestroyWindow(window);
}
