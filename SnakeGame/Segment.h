#pragma once

#include "PositionAndVelocity.h"

class Segment {
public:
	Segment(int width, int height, Position, Velocity);
	Segment(const Segment &other) = default;
	Velocity get_velocity() const;
	void set_velocity(const Velocity &velocity);
	Position GetPosition() const;
	virtual void UpdatePosition();
		
	virtual void Render() = 0; // Pure virtual
protected:
	int segment_width_;
	int segment_height_;
	Position position_;
	Velocity velocity_;

	double GetAngleBasedOnVelocity();
private:
	// TODO need this? virtual void LoadImage() = 0; // Pure virtual
};
