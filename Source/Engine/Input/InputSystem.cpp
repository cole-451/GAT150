#include "InputSystem.h"


bool parabellum::InputSystem::initialize()
{
	int num_keys;
	const bool* keyboardstate = SDL_GetKeyboardState(&num_keys);
	keyboard_state.resize(num_keys);
	std::copy(keyboardstate, keyboardstate + num_keys, keyboard_state.begin()); // copies the data from the SDL keyboard state to our keyboard_state vector
	prev_keyboard_state = keyboard_state; // Initialize previous keyboard state to current state


	SDL_GetMouseState(&mouse_position.x, &mouse_position.y);
	prev_mouse_position = mouse_position;

	return true; 
}

void parabellum::InputSystem::GTFO()
{
	// nothing here.
}
void parabellum::InputSystem::Update(float dt)
{
	//keyboard shit
	prev_keyboard_state = keyboard_state;
	const bool* keyboardstate = SDL_GetKeyboardState(nullptr);
	std::copy(keyboardstate, keyboardstate + keyboard_state.size(), keyboard_state.begin()); // copies the data from the SDL keyboard state to our keyboard_state vector

	//mouse shit

	prev_mouse_position = mouse_position;
	uint32_t mouseButtonState = SDL_GetMouseState(&mouse_position.x, &mouse_position.y);

	prev_mousebutton_state = mousebutton_state;
	mousebutton_state[(uint8_t)MouseButton::MOUSE_LEFT] = mouseButtonState & SDL_BUTTON_LMASK;
	mousebutton_state[(uint8_t)MouseButton::MOUSE_MIDDLE] = mouseButtonState & SDL_BUTTON_MMASK;
	mousebutton_state[(uint8_t)MouseButton::MOUSE_RIGHT] = mouseButtonState & SDL_BUTTON_RMASK;

}


