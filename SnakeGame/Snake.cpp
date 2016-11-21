#include "SnakeGame.h"
#include "Snake.h"
#include "Head.h"
#include "Body.h"
#include "Tail.h"

#define VELOCITY 1

Segments::Segments() :
	head(Position{ SnakeGame::GetScreenWidth() / 2, SnakeGame::GetScreenHeight() / 2 }, Velocity{ VELOCITY, 0 }),
	tail(Position{ SnakeGame::GetScreenWidth() / 2 - BODY_WIDTH - TAIL_WIDTH, SnakeGame::GetScreenHeight() / 2 }, Velocity{ VELOCITY, 0 })
{
	//Body body_to_add(Position{ head.GetPosition().x - BODY_WIDTH, SnakeGame::GetScreenHeight() / 2 }, Velocity{ VELOCITY, 0 });
	//body.push_back(body_to_add);
	body.emplace_back(Position{ head.GetPosition().x - BODY_WIDTH, SnakeGame::GetScreenHeight() / 2 }, Velocity{ VELOCITY, 0 });
}

Snake::Snake() {
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

void Snake::Update() {
	segments_.head.UpdatePosition();
	// Render the body
	for (Body &body : segments_.body) {
		body.UpdatePosition();
	}
	// Render the tail
	segments_.tail.UpdatePosition();
}

void Snake::Render() {
	segments_.head.Render();
	// Render the body
	for (Body &body : segments_.body) {
		body.Render();
	}
	// Render the tail
	segments_.tail.Render();
}
