#pragma once

#include "Segment.h"
#include "Texture.h"

#define BODY_WIDTH 20
#define BODY_HEIGHT 20
#define BODY_IMAGE_PATH "body.bmp"

class Body : public Segment {
public:
	Body() = default;
	Body(Position, Velocity);
	Body(Body &&other);
	~Body();
	virtual void Render();
private:
	Texture texture_;
};

