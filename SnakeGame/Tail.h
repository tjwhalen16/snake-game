#pragma once
#include "Segment.h"
#include "Texture.h"


#define TAIL_WIDTH 20
#define TAIL_HEIGHT 20
#define TAIL_IMAGE_PATH "tail.bmp"

class Tail : public Segment {
public:
	Tail(std::pair<int, int>, std::pair<int, int>);
	virtual void Render();
private:
	Texture texture_;
};

