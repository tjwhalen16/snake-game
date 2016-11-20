#pragma once

#include <SDL.h>
#include <memory>
#include <iostream>

namespace sdl2 {
	struct Sdl_Deleter {
		// TODO remove cout statements after I know they all work
		void operator()(SDL_Surface* ptr) { if (ptr) { SDL_FreeSurface(ptr); std::cout << "deleted surface\n"; } }
		void operator()(SDL_Window* ptr) { if (ptr) {SDL_DestroyWindow(ptr); std::cout << "deleted window\n"; } }
		void operator()(SDL_Texture* ptr) { if (ptr) { SDL_DestroyTexture(ptr); std::cout << "deleted texture\n"; } }
		void operator()(SDL_Renderer* ptr) { if (ptr) { SDL_DestroyRenderer(ptr); std::cout << "deleted renderer\n"; } }
	};

	using surface_ptr = std::unique_ptr<SDL_Surface, Sdl_Deleter>;
	using window_ptr = std::unique_ptr<SDL_Window, Sdl_Deleter>;
	using texture_ptr = std::unique_ptr<SDL_Texture, Sdl_Deleter>;
	using renderer_ptr = std::unique_ptr<SDL_Renderer, Sdl_Deleter>;
}