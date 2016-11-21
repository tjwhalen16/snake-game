#pragma once

#include "Segment.h"
#include "Texture.h"

#define HEAD_WIDTH 20
#define HEAD_HEIGHT 20
#define HEAD_IMAGE_PATH "head.bmp"

class Head : public Segment {
public:
	Head(std::pair<int, int>, std::pair<int, int>);
	~Head();
	virtual void Render();
private:
	Texture texture_;
};

