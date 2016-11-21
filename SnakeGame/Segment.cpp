#include "Segment.h"
#include "SnakeGame.h"

Segment::Segment(int width, int height, std::pair<int, int> position, std::pair<int, int> velocity) : segment_width_(width), segment_height_(height),
	position_(position), velocity_(velocity)
{}

std::pair<int, int> Segment::get_velocity() const { return velocity_; }

void Segment::set_velocity(const std::pair<int, int> &velocity) {
	velocity_.first = velocity.first;
	velocity_.second = velocity.second;
}

std::pair<int, int> Segment::GetPosition() const {
	return position_;
}

void Segment::UpdatePosition() {
	position_.first += velocity_.first * segment_width_;
	position_.second += velocity_.second * segment_height_;
	// Check if this segment went off the screen
	if (position_.first >= SnakeGame::GetScreenWidth()) {
		position_.first -= SnakeGame::GetScreenWidth(); // Reset this segment's x position
	}
	if (position_.second >= SnakeGame::GetScreenHeight()) {
		position_.second -= SnakeGame::GetScreenHeight(); // Reset this segment's y position
	}
}

double Segment::GetAngleBasedOnVelocity() {
	double angle{ 0 };
	if (velocity_.first > 0) {
		angle = 0; // point image right
	} else if (velocity_.first < 0) {
		angle = 180; // point image to the left
	} else if (velocity_.second > 0) {
		angle = 90; // point the image down
	} else if (velocity_.second < 0) {
		angle = 270; // point the image up
	}
	return angle;
}


