#pragma once

#include "PositionAndVelocity.h"
#include <utility>

class Segment {
public:
	Segment(int width, int height, std::pair<int, int>, std::pair<int, int>);
	Segment(const Segment &other) = default;
	std::pair<int, int> get_velocity() const;
	void set_velocity(const std::pair<int, int> &velocity);
	std::pair<int, int> GetPosition() const;
	virtual void UpdatePosition();
		
	virtual void Render() = 0; // Pure virtual
protected:
	int segment_width_;
	int segment_height_;
	std::pair<int, int> position_;
	std::pair<int, int> velocity_;

	double GetAngleBasedOnVelocity();
private:
	// TODO need this? virtual void LoadImage() = 0; // Pure virtual
};
