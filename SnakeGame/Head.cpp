#include "Head.h"
#include "SnakeGame.h"

Head::Head(std::pair<int, int> pos, std::pair<int, int> vel) : Segment(HEAD_WIDTH, HEAD_HEIGHT, pos, vel), texture_(HEAD_IMAGE_PATH, SnakeGame::GetRenderer()) {
	if (!texture_.LoadFromFile()) {
		throw "Failed to load head texture from file\n";
	}
}


Head::~Head()
{
}

void Head::Render() {
	texture_.Render(position_.first, position_.second, nullptr, GetAngleBasedOnVelocity(), nullptr);
}