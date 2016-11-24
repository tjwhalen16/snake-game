#include "SnakeGame.h"
#include <iostream>

// Initialize static member variables
int SnakeGame::width_ = 0;
int SnakeGame::height_ = 0;
sdl2::renderer_ptr SnakeGame::renderer_ = nullptr;

SnakeGame::SnakeGame(int width, int height) {
	// Define the static member width & height to be the actual size
	width_ = width;
	height_ = height;
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
	snake_ = std::make_unique<Snake>();
	// Initialize the food
	food_ = std::make_unique<Food>();
	food_->SetRandomPosition();
	return true;
}

void SnakeGame::GameLoop() {
	bool quit = false;
	SDL_Event e;
	while (!quit) { // TODO instead of bool use enum... so while(PLAYING)
		// While there are events to be proccessed
		while (SDL_PollEvent(&e)) {
			// User pressed the red X
			if (e.type == SDL_QUIT) {
				quit = true;
			} else {
				snake_->HandleEvent(e);
			}			
		}
		if (!UpdateGameState()) { // TODO pass this gamestate enum  ref so it can update game state
			quit = true;
		}
		RedrawScreen();
		SDL_Delay(game_speed_);
	}
}

// Checks if the game is over.
// Tells the snake to grow if it should.
// Updates snake normally if it shouldn't grow.
// Tells the food to respawn if eaten.
bool SnakeGame::UpdateGameState() {
	if (!EatFood()) {
		// Update snake normally if food was not eaten
		snake_->Update();
	}
	if (IsGameOver()) {
		return false;
	}	
	return true;
}

// Handles food eating logic and grows snake
// Returns true if food was eaten, else false
bool SnakeGame::EatFood() {
	// Check if food should be eaten
	if (snake_->GetNextHeadPosition() == food_->get_position()) {
		// Food and snake's head are in the same spot
		snake_->Grow();
		// Move the food to a random position unoccupied by the snake
		std::pair<int, int> new_position;
		const auto position_map = snake_->GetPositionMap();
		do {
			new_position = food_->SetRandomPosition();
		} while (position_map.find(new_position) != position_map.end()); // Do it until food is not inside snake
		// Food was eaten
		return true;
	} else {
		return false;
	}
}

bool SnakeGame::IsGameOver() {
	// Game ends if the snake's head leaves the screen
	std::pair<int, int> pos = snake_->GetHeadPosition();
	if (pos.first >= SnakeGame::GetScreenWidth() || pos.first < 0) {
		return true; // Game over, snake is too far right or left
	}
	if (pos.second >= SnakeGame::GetScreenHeight() || pos.second < 0) {
		return true; // Game over, snake is too far down or up
	}
	// Game ends if the head touches any other segment of the snake
	// An int greater than 1 means more than 1 segment is occupying the same location = game over
	if (snake_->GetPositionMap().at(pos) > 1) {
		return true;
	}
	return false; // Game not over if made it here
}

void SnakeGame::RedrawScreen() {
	// Clear the screen
	SDL_SetRenderDrawColor(renderer_.get(), 0, 0, 0, 255);
	SDL_RenderClear(renderer_.get());
	// Render game objects
	snake_->Render();
	food_->Render();
	// Update the screen
	SDL_RenderPresent(renderer_.get());
}

int SnakeGame::GetScreenWidth() {
	return width_;
}
int SnakeGame::GetScreenHeight() {
	return height_;
}
SDL_Renderer* SnakeGame::GetRenderer() {
	return renderer_.get();
}