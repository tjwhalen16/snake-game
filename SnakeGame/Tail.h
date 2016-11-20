#pragma once
#include "Segment.h"

class Tail : public Segment {
public:
	Tail();
	~Tail();
	virtual void Render();
};

