#pragma once

#include <vector>
#include <SDL.h>
#include <memory>
#include "Segment.h"
#include "Head.h"
#include "Body.h"
#include "Tail.h"

struct Segments {
	Head head;
	std::vector<Body> body;
	Tail tail;

	Segments();
};

class Snake {
public:
	Snake();
	~Snake();
	void HandleEvent(SDL_Event &e); // Updates the heads velocity
	void Update();
	void Render();

private:
	int head_pos_{ 0 };
	//std::vector<std::unique_ptr<Segment>> segments_;
	Segments segments_;
};

