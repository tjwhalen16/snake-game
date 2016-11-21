#include "Texture.h"
#include <SDL_image.h>

Texture::Texture(std::string path, SDL_Renderer *renderer) : path_(path), renderer_(renderer)
{ }

Texture::Texture(Texture &&other) {
	texture_.reset(other.texture_.release());
}

// TODO do I need the stuff I commented out?
bool Texture::LoadFromFile() {
	//The final texture
	sdl2::texture_ptr new_texture;
	//Load image at specified path
	sdl2::surface_ptr loaded_surface(IMG_Load(path_.c_str()));
	if (!loaded_surface) {
		printf("Unable to load image %s! SDL_image Error: %s\n", path_.c_str(), IMG_GetError());
	} else {
		//Color key image
		//SDL_SetColorKey(loadedSurface.get(), SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		//Create texture from surface pixels
		new_texture.reset(SDL_CreateTextureFromSurface(renderer_, loaded_surface.get()));
		if (!new_texture) {
			printf("Unable to create texture from %s! SDL Error: %s\n", path_.c_str(), SDL_GetError());
		} else {
			//Get image dimensions
			width_ = loaded_surface->w;
			height_ = loaded_surface->h;
		}
	}
	//Return success
	texture_.reset(new_texture.release()); // TODO check out what happens here
	return texture_ != nullptr;
}

void Texture::Render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, width_, height_ };
	//Set clip rendering dimensions
	if (clip) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	//Render to screen
	SDL_RenderCopyEx(renderer_, texture_.get(), clip, &renderQuad, angle, center, flip);
}