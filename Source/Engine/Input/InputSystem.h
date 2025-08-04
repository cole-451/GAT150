#pragma once
#include <vector>
#include "../Math/Vector2.h"
#include <array>

namespace parabellum
{
	class InputSystem
	{
	public:
		enum class MouseButton : uint8_t {
			MOUSE_LEFT,
			MOUSE_MIDDLE,
			MOUSE_RIGHT
		};

		
	public:
		InputSystem() = default;

		bool initialize();

		void GTFO();

		void Update(float dt); // changed recently. come back if error


		//KEYBOARD INPUTS:
		bool getKeyDown(uint8_t key) { return keyboard_state[key]; }
		bool getPrevKeyDown(uint8_t key) { return prev_keyboard_state[key]; }
		bool getKeyPressed(uint8_t key) { return !prev_keyboard_state[key] && keyboard_state[key]; }

		const vec2& getMousePos() const { return mouse_position; }
		const vec2& getPrevMousePos() const { return prev_mouse_position; }

		//MOUSE INPUT:

		bool GetMouseButtonDown(MouseButton button) { return mousebutton_state[(uint8_t)button]; }
		bool GetPrevMouseButtonDown(MouseButton button) { return prev_mousebutton_state[(uint8_t)button]; }
		bool GetMouseButtonPressed(MouseButton button) {
			return !prev_mousebutton_state[(uint8_t)button] && mousebutton_state[(uint8_t)button];
		}

	private:
		std::vector<bool> keyboard_state;
		std::vector<bool> prev_keyboard_state;

		vec2 mouse_position = { 0,0 };
		vec2 prev_mouse_position = { 0,0 };

		std::array<bool, 3> mousebutton_state { false, false, false };
		std::array<bool, 3> prev_mousebutton_state{ false, false, false };



	};

}