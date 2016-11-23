#include "Food.h"
#include "SnakeGame.h"

Food::Food() : texture_(FOOD_IMAGE_PATH, SnakeGame::GetRenderer()), e_(),
	d_(0, (SnakeGame::GetScreenWidth()/ WIDTH) *(SnakeGame::GetScreenHeight()/ HEIGHT) - 1 )
{
	if (!texture_.LoadFromFile()) {
		throw "Failed to load food texture from file\n";
	}
}

std::pair<int, int> Food::get_position() const {
	return position_;
}

std::pair<int, int> Food::SetRandomPosition() {
	int flat_position = d_(e_);
	// Convert number into (x,y) position
	position_ = std::make_pair<int, int>((flat_position % (SnakeGame::GetScreenWidth()/ WIDTH)) * WIDTH, (flat_position / (SnakeGame::GetScreenWidth()/ WIDTH)) * HEIGHT);
	return position_;
}

void Food::Render() {
	texture_.Render(position_.first, position_.second);
}

