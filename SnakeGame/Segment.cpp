#include "Segment.h"
#include "SnakeGame.h"

Segment::Segment(int width, int height, Position pos, Velocity vel) : position_(pos), velocity_(vel)
{}

Velocity Segment::get_velocity() const { return velocity_; }

void Segment::set_velocity(const Velocity &velocity) {
	velocity_ = velocity;
}

Position Segment::GetPosition() const {
	return position_;
}

void Segment::UpdatePosition() {
	position_.x += velocity_.x;
	position_.y += velocity_.y;
	// Check if this segment went off the screen
	if (position_.x >= SnakeGame::GetScreenWidth()) {
		position_.x -= SnakeGame::GetScreenWidth(); // Reset this segment's x position
	}
	if (position_.y >= SnakeGame::GetScreenHeight()) {
		position_.y -= SnakeGame::GetScreenHeight(); // Reset this segment's y position
	}
}


