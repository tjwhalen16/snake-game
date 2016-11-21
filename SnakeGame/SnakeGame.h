#pragma once

#include "Sdl2SmartPointers.h"
#include "Snake.h"

class SnakeGame {
public:
	SnakeGame(int width, int height);
	~SnakeGame();
	void Play();
	static int GetScreenWidth();
	static int GetScreenHeight();
	static SDL_Renderer* GetRenderer();

private:
	bool InitSdl();
	bool InitGame();
	void GameLoop();
	bool UpdateGameState();
	bool IsGameOver();
	void RedrawScreen();
	// TODO void ProccessEvent(SDL_Event &e);

	static int width_;
	static int height_;
	sdl2::window_ptr window_;
	sdl2::surface_ptr screen_;
	static sdl2::renderer_ptr renderer_;
	std::unique_ptr<Snake> snake_;
	int game_speed_{ 400 };
};

