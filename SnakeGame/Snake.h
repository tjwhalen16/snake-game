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
	void HandleEvent(SDL_Event &e); // Updates the heads velocity
	void Update();
	void Render();
private:
	void UpdateSegmentVelocities();

	Segments segments_;
};

