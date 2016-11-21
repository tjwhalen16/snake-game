#include "SnakeGame.h"
#include "Snake.h"
#include "Head.h"
#include "Body.h"
#include "Tail.h"

#define VELOCITY 1 // The speed of the snake

// Initialize the starting snake which has a head, 1 body segment, and a tail
Segments::Segments() :
	// Position is the middle of the screen
	head(Position{ SnakeGame::GetScreenWidth() / 2, SnakeGame::GetScreenHeight() / 2 }, Velocity{ VELOCITY, 0 }),
	// Position is behind head segment and 1 body segment
	tail(Position{ SnakeGame::GetScreenWidth() / 2 - BODY_WIDTH - TAIL_WIDTH, SnakeGame::GetScreenHeight() / 2 }, Velocity{ VELOCITY, 0 })
{
	// Push 1 body segment into the body vector
	// Position is behind head and before tail
	body.emplace_back(Position{ head.GetPosition().x - BODY_WIDTH, SnakeGame::GetScreenHeight() / 2 }, Velocity{ VELOCITY, 0 });
}

// Updates the heads velocity based on key presses
void Snake::HandleEvent(SDL_Event &e) {
	// If key is pressed down for the first time, not held
	if (e.type = SDL_KEYDOWN && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
			case SDLK_UP:
				segments_.head.set_velocity(Velocity{ 0, -VELOCITY });
				break;
			case SDLK_DOWN:
				segments_.head.set_velocity(Velocity{ 0, VELOCITY });
				break;
			case SDLK_LEFT:
				segments_.head.set_velocity(Velocity{ -VELOCITY, 0 });
				break;
			case SDLK_RIGHT:
				segments_.head.set_velocity(Velocity{ VELOCITY, 0 });
				break;
			default:
				; // Do nothing for other keys
		}
	}
}

// Update the position for all of the snake's segments
void Snake::Update() {
	segments_.head.UpdatePosition();
	// Update the body's position
	for (Body &body : segments_.body) {
		body.UpdatePosition();
	}
	// Update the tail's position
	segments_.tail.UpdatePosition();

	// Set new velocites for each segment based on the next segment in the body
	UpdateSegmentVelocities();
}

// Render the snake to the screen
void Snake::Render() {
	// Render the head segment
	segments_.head.Render();
	// Render the body segments
	for (Body &body : segments_.body) {
		body.Render();
	}
	// Render the tail segment
	segments_.tail.Render();
}

// Each segment gets the velocity of the next segment.
// This is necessary to get segments following each other through turns.
// This function does not change the head's velocity, which is controlled by user input.
void Snake::UpdateSegmentVelocities() {
	// Set the tail's velocity to the velocity of the last segment in the body
	segments_.tail.set_velocity(segments_.body.back().get_velocity());
	// Set the velocity of each body segment to the velocity of the next body segment
	// Except for the front body segment, which gets the head's velocity
	for (int i = 0; i < segments_.body.size() - 1; ++i) {
		segments_.body[i].set_velocity(segments_.body[i + 1].get_velocity());
	}
	// Set the front body segment's velocity to the head's velocity
	segments_.body.front().set_velocity(segments_.head.get_velocity());
}
