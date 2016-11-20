#include "SnakeGame.h"
#include <iostream>

SnakeGame::SnakeGame(int width, int height) : width_(width), height_(height)
{ }


SnakeGame::~SnakeGame()
{
}

void SnakeGame::Play() {
	if (!InitSdl()) {
		std::cout << "SDL initialization failed, exiting...\n";
	}
	if (!InitGame()) {
		std::cout << "Game initialization failed, exiting...\n";
	}
	GameLoop();
}


bool SnakeGame::InitSdl() {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Failed to initialize SDL\n";
		return false;
	}
	// Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		std::cout << "Failed to set texture filtering to linear\n";
		return false;
	}
	// Create window
	window_.reset(SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width_, height_, SDL_WINDOW_SHOWN));
	if (!window_) {
		std::cout << "Failed to initialize the window\n";
		return false;
	}
	// Create vsynced renderer for the window
	renderer_.reset(SDL_CreateRenderer(window_.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
	if (!renderer_) {
		std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << '\n';
		return false;
	}
	// TODO may need to initialize png loading
	return true; // Making it here means success
}

bool SnakeGame::InitGame() {
	// Initialize the snake
	//snake_ = Snake(width_, height_, renderer_.get());
	snake_ = std::make_unique<Snake>(width_, height_, renderer_.get());
	return true;
}

void SnakeGame::GameLoop() {
	bool quit = false;
	SDL_Event e;
	while (!quit) {
		// While there are events to be proccessed
		while (SDL_PollEvent(&e)) {
			// User wants to quit
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			// Let the snake handle input
			// TODO call this: snake_.HandleEvent(e);
		}
		// Redraw the screen
		// Update the snake's position
		// Clear the screen
		SDL_SetRenderDrawColor(renderer_.get(), 0, 0, 0, 255);
		SDL_RenderClear(renderer_.get());
		// Render the snake
		snake_->Render();
		// Update the screen
		SDL_RenderPresent(renderer_.get());
	}
}