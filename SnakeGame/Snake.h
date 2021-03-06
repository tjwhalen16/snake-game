#pragma once

#include <vector>
#include <SDL.h>
#include <memory>
#include <unordered_map>
#include "Segment.h"
#include "Head.h"
#include "Body.h"
#include "Tail.h"

struct Segments {
	Head head;
	std::list<Body> body;
	Tail tail;

	Segments();
};

class Snake {
public:
	Snake();
	const std::unordered_map<std::pair<int, int>, int, PairHash>& GetPositionMap();
	std::pair<int, int> GetHeadPosition() const;
	std::pair<int, int> GetNextHeadPosition() const;
	int GetNumberOfSegments() const;
	void HandleEvent(SDL_Event &e); // Updates the heads velocity
	void Update();
	void Grow();
	void Render();
private:
	void UpdateSegmentVelocities();

	Segments segments_;
	std::unordered_map<std::pair<int, int>, int, PairHash> position_map_;
};

