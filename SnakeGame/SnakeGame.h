#pragma once

#include "Sdl2SmartPointers.h"
#include "Snake.h"
#include "Food.h"

enum GameState {
	PLAYING,
	WON,
	LOST,
	QUIT
};

class SnakeGame {
public:
	SnakeGame(int width, int height);
	void Play();
	static int GetScreenWidth();
	static int GetScreenHeight();
	static SDL_Renderer* GetRenderer();

private:
	bool InitSdl();
	bool InitGame();
	void GameLoop();
	void UpdateGameState();
	void IsGameOver();
	bool EatFood();
	void RedrawScreen();
	void HandleGameOverState();
	// TODO void ProccessEvent(SDL_Event &e);

	static int width_;
	static int height_;
	sdl2::window_ptr window_;
	sdl2::surface_ptr screen_;
	static sdl2::renderer_ptr renderer_;
	std::unique_ptr<Snake> snake_;
	std::unique_ptr<Food> food_;
	int game_speed_{ 400 };
	GameState game_state_;
};

