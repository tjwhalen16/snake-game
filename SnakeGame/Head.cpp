#include "Head.h"
#include "SnakeGame.h"

Head::Head(Position pos, Velocity vel) : Segment(HEAD_WIDTH, HEAD_HEIGHT, pos, vel), texture_(HEAD_IMAGE_PATH, SnakeGame::GetRenderer()) {
	if (!texture_.LoadFromFile()) {
		throw "Failed to load head texture from file\n";
	}
}


Head::~Head()
{
}

void Head::Render() {
	texture_.Render(position_.x, position_.y);
}