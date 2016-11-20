#include "Snake.h"
#include "Head.h"
#include "Body.h"
#include "Tail.h"

#define VELOCITY 1

Snake::Snake(int width, int height, SDL_Renderer *renderer) : screen_width_(width), screen_height_(height),
	head_(HEAD_WIDTH, HEAD_HEIGHT, Position{ screen_width_ / 2, screen_height_ / 2 }, Velocity{ VELOCITY, 0 }, renderer){
	// Set up intial snake
	//int middle_y = screen_height_ / 2; // Snakes starts horizontal in middle of the screen
	//int middle_x = screen_width_ / 2;

	//Head head(HEAD_WIDTH, HEAD_HEIGHT, Position{ middle_x, middle_y }, Velocity{ VELOCITY, 0 });
	//head_ = head;
	//segments_.push_back(head);
}


Snake::~Snake()
{
}



void Snake::Render() {
	//segments_[head_pos_]->Render();
	head_.Render();
}
