#ifndef GUI_H
#define GUI_H

// File Dependencies
#include "Definitions.h"

// Constant Values
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

// Method Declarations
void showMainMenu();
void showNameScreen(int n);
void showTargetSpinner(int option);
int showPassFail();
void showScoreboard(GameState_t *state);
int showEndScreen();
void closeWindow();

#endif
