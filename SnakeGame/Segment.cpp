#include "Segment.h"

Segment::Segment(int width, int height, Position pos, Velocity vel) : position_(pos), velocity_(vel)
{}

Velocity Segment::get_velocity() const { return velocity_; }

void Segment::set_velocity(const Velocity &velocity) {
	velocity_ = velocity;
}

void Segment::UpdatePosition(int screen_width, int screen_height) {
	position_.x += velocity_.x;
	position_.y += velocity_.y;
	// Check if this segment went off the screen
	if (position_.x >= screen_width) {
		position_.x -= screen_width; // Reset this segment's x position
	}
	if (position_.y >= screen_height) {
		position_.y -= screen_height; // Reset this segment's y position
	}
}


