#pragma once

#include "Segment.h"

class Body : public Segment {
public:
	Body();
	~Body();
	virtual void Render();
};

