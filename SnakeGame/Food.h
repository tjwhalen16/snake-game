#pragma once

#include "PositionAndVelocity.h"
#include "Texture.h"
#include <random>

#define WIDTH 20
#define HEIGHT 20
#define FOOD_IMAGE_PATH "food.bmp"

class Food
{
public:
	Food();
	std::pair<int, int> get_position() const;
	std::pair<int, int> SetRandomPosition();
	void Render();
private:
	std::pair<int, int> position_;
	Texture texture_;
	std::default_random_engine e_;
	std::uniform_int_distribution<int> d_;
};

