#pragma once
#include "Segment.h"
#include "Texture.h"


#define TAIL_WIDTH 20
#define TAIL_HEIGHT 20
#define TAIL_IMAGE_PATH "tail.bmp"

class Tail : public Segment {
public:
	Tail(Position, Velocity);
	~Tail();
	virtual void Render();
private:
	Texture texture_;
};

