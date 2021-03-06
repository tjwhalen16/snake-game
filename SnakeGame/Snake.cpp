#include "SnakeGame.h"
#include "Snake.h"
#include "Head.h"
#include "Body.h"
#include "Tail.h"

#define VELOCITY 1 // The speed of the snake

// Initialize the starting snake which has a head, 1 body segment, and a tail
Segments::Segments() :
	// Position is the middle of the screen
	head(std::pair<int, int>{ (SnakeGame::GetScreenWidth() / HEAD_WIDTH / 2) * HEAD_WIDTH, (SnakeGame::GetScreenHeight() / HEAD_HEIGHT / 2) * HEAD_HEIGHT }, std::pair<int, int>{ VELOCITY, 0 }),
	// Position is behind head segment and 1 body segment
	tail(std::pair<int, int>{ (SnakeGame::GetScreenWidth() / HEAD_WIDTH / 2) * HEAD_WIDTH - BODY_WIDTH - TAIL_WIDTH, (SnakeGame::GetScreenHeight() / HEAD_HEIGHT / 2) * HEAD_HEIGHT }, std::pair<int, int>{ VELOCITY, 0 })
{
	// Push 1 body segment into the body vector
	// Position is behind head and before tail
	body.emplace_back(std::pair<int, int>{ head.GetPosition().first - BODY_WIDTH, (SnakeGame::GetScreenHeight() / HEAD_HEIGHT / 2) * HEAD_HEIGHT }, std::pair<int, int>{ VELOCITY, 0 });
}

// Fill position map with intial snake
Snake::Snake() : position_map_{ {segments_.head.GetPosition(), 1}, {segments_.body.front().GetPosition(), 1}, {segments_.tail.GetPosition(), 1} } 
{ }

const std::unordered_map<std::pair<int, int>, int, PairHash>& Snake::GetPositionMap() {
	return position_map_;
}

std::pair<int, int> Snake::GetHeadPosition() const {
	return segments_.head.GetPosition();
}

std::pair<int, int> Snake::GetNextHeadPosition() const {
	std::pair<int, int> pos = segments_.head.GetPosition();
	std::pair<int, int> vel = segments_.head.get_velocity();
	int new_x = pos.first + vel.first * HEAD_WIDTH;
	int new_y = pos.second + vel.second * HEAD_HEIGHT;
	return std::make_pair(new_x, new_y);
}

int Snake::GetNumberOfSegments() const {
	int count = 2; // +1 for head, and +1 for tail
	count += segments_.body.size();
	return count;
}

// Updates the heads velocity based on key presses
void Snake::HandleEvent(SDL_Event &e) {
	// If key is pressed down for the first time, not held
	if (e.type = SDL_KEYDOWN && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
			case SDLK_UP:
				segments_.head.set_velocity(std::pair<int, int>{ 0, -VELOCITY });
				break;
			case SDLK_DOWN:
				segments_.head.set_velocity(std::pair<int, int>{ 0, VELOCITY });
				break;
			case SDLK_LEFT:
				segments_.head.set_velocity(std::pair<int, int>{ -VELOCITY, 0 });
				break;
			case SDLK_RIGHT:
				segments_.head.set_velocity(std::pair<int, int>{ VELOCITY, 0 });
				break;
			default:
				; // Do nothing for other keys
		}
	}
}

// Update the position for all of the snake's segments
void Snake::Update() {
	segments_.head.UpdatePosition();
	// Add the head's position to the positon map after its update
	++position_map_[segments_.head.GetPosition()];
	// Update the body's position
	for (Body &body : segments_.body) {
		body.UpdatePosition();
	}
	// Remove the tail's position to the position map before its update
	--position_map_[segments_.tail.GetPosition()];
	// Update the tail's position
	segments_.tail.UpdatePosition();
	// Set new velocites for each segment based on the next segment in the body
	UpdateSegmentVelocities();
}

// Add a body segment to the end of the snake's body
void Snake::Grow() {
	// Put body segment at front of body with same position & velocity as head
	segments_.body.emplace_front(segments_.head.GetPosition(), segments_.head.get_velocity());
	// Move head up
	segments_.head.UpdatePosition();
	++position_map_[segments_.head.GetPosition()];
}

// Render the snake to the screen
void Snake::Render() {
	segments_.head.Render();
	// Render the body segments
	for (Body &body : segments_.body) {
		body.Render();
	}
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
	for (auto i = ++segments_.body.rbegin(), j = segments_.body.rbegin(); i != segments_.body.rend(); ++i, ++j) {
		j->set_velocity(i->get_velocity());
	}
	// Set the front body segment's velocity to the head's velocity
	segments_.body.front().set_velocity(segments_.head.get_velocity());
}
