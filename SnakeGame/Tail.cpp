#include "Tail.h"
#include "SnakeGame.h"

Tail::Tail(std::pair<int, int> pos, std::pair<int, int> vel) : Segment(TAIL_WIDTH, TAIL_HEIGHT, pos, vel), texture_(TAIL_IMAGE_PATH, SnakeGame::GetRenderer()) {
	if (!texture_.LoadFromFile()) {
		throw "Failed to load tail texture from file\n";
	}
}

void Tail::Render() {
	texture_.Render(position_.first, position_.second, nullptr, GetAngleBasedOnVelocity(), nullptr);
}
