#include <SDL.h>
#include <iostream>
#include "Sdl2SmartPointers.h"
#include "SnakeGame.h"

#define SCREEN_WIDTH 120
#define SCREEN_HEIGHT 120

int main(int argc, char* args[]) {
	{
		SnakeGame game(SCREEN_WIDTH, SCREEN_HEIGHT);
		game.Play();
	}

	std::cout << "Assert no non-renderer resources are deleted after this statement\n";
	return 0;
}