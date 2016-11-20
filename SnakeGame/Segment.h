#pragma once

#include "PositionAndVelocity.h"

class Segment {
public:
	Segment() = default; // TODO remove after implementing Tail & Body
	Segment(int width, int height, Position, Velocity);
	Velocity get_velocity() const;
	void set_velocity(const Velocity &velocity);

	virtual void UpdatePosition(int screen_width, int screen_height);
		
	virtual void Render() = 0; // Pure virtual
protected:
	int segment_width_;
	int segment_height_;
	Position position_;
	Velocity velocity_;
private:
	// TODO need this? virtual void LoadImage() = 0; // Pure virtual
};
