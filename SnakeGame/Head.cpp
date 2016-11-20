#include "Head.h"

Head::Head(int width, int height, Position pos, Velocity vel, SDL_Renderer *renderer) : Segment(width, height, pos, vel), texture_(HEAD_IMAGE_PATH, renderer) {
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