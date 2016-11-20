#include <SDL.h>
#include <iostream>
#include "Sdl2SmartPointers.h"
#include "SnakeGame.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char* args[]) {
	SnakeGame game(SCREEN_WIDTH, SCREEN_HEIGHT);
	game.Play();

	return 0;
}