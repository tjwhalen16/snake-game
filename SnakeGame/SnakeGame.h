#pragma once

#include "Sdl2SmartPointers.h"
#include "Snake.h"

class SnakeGame {
public:
	SnakeGame(int width, int height);
	~SnakeGame();
	void Play();

private:
	bool InitSdl();
	bool InitGame();
	void GameLoop();
	void ProccessEvent(SDL_Event &e);

	int width_;
	int height_;
	sdl2::window_ptr window_;
	sdl2::surface_ptr screen_;
	sdl2::renderer_ptr renderer_;
	std::unique_ptr<Snake> snake_;
};

