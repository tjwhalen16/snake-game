#include "Body.h"
#include "SnakeGame.h"


Body::Body(Position pos, Velocity vel) : Segment(BODY_WIDTH, BODY_HEIGHT, pos, vel), texture_(BODY_IMAGE_PATH, SnakeGame::GetRenderer()) {
	if (!texture_.LoadFromFile()) {
		throw "Failed to load head texture from file\n";
	}
}

Body::Body(Body &&other) : Segment(other.segment_width_, other.segment_height_, other.position_, other.velocity_),
	texture_(std::move(other.texture_)) {

}

Body::~Body()
{
}

void Body::Render() {
	texture_.Render(position_.x, position_.y);
}