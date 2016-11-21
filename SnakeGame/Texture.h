#pragma once

#include "Sdl2SmartPointers.h"
#include <string>

class Texture
{
public:
	Texture(std::string path, SDL_Renderer *renderer);
	Texture(Texture &&other);
	bool LoadFromFile();
	//Renders texture at given point
	void Render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	std::string path_;
	sdl2::texture_ptr texture_;
	SDL_Renderer* renderer_; // This texture doesn't own the renderer, no need to clean up
	int width_;
	int height_;
};

