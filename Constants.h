#ifndef CONSTANTS
#define CONSTANTS

#include <Gamebuino-Meta.h>

const int WIDTH_BLOCK = 8;
const int HEIGHT_BLOCK = 8;

//BUTTON_DOWN, BUTTON_LEFT, BUTTON_RIGHT, BUTTON_UP, BUTTON_A, BUTTON_B, BUTTON_MENU, BUTTON_HOME
const int DIRECTION_X[4] = {0, -1, 1, 0};
const int DIRECTION_Y[4] = {1, 0, 0, -1};

const float SPEED = 0.125f;

#endif
