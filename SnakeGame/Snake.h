#pragma once

#include <vector>
#include <SDL.h>
#include <memory>
#include "Segment.h"
#include "Head.h"

class Snake {
public:
	Snake(int width, int height, SDL_Renderer *renderer);
	~Snake();
	void HandleEvent(SDL_Event &e); // Updates the heads velocity
	void Update();
	void Render();

private:
	int head_pos_{ 0 };
	//std::vector<std::unique_ptr<Segment>> segments_;
	Head head_;
	int screen_width_;
	int screen_height_;
};

