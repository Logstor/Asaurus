#pragma once

/*! @defgroup buttons Mouse buttons
 *  @brief Mouse button IDs.
 *
 *  See [mouse button input](@ref input_mouse_button) for how these are used.
 *
 *  @ingroup input
 *  @{ */

namespace Asaurus
{
	typedef enum class MouseCode : uint8_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define AS_MOUSE_BUTTON_0      ::Asaurus::Mouse::Button0
#define AS_MOUSE_BUTTON_1      ::Asaurus::Mouse::Button1
#define AS_MOUSE_BUTTON_2      ::Asaurus::Mouse::Button2
#define AS_MOUSE_BUTTON_3      ::Asaurus::Mouse::Button3
#define AS_MOUSE_BUTTON_4      ::Asaurus::Mouse::Button4
#define AS_MOUSE_BUTTON_5      ::Asaurus::Mouse::Button5
#define AS_MOUSE_BUTTON_6      ::Asaurus::Mouse::Button6
#define AS_MOUSE_BUTTON_7      ::Asaurus::Mouse::Button7
#define AS_MOUSE_BUTTON_LAST   ::Asaurus::Mouse::ButtonLast
#define AS_MOUSE_BUTTON_LEFT   ::Asaurus::Mouse::ButtonLeft
#define AS_MOUSE_BUTTON_RIGHT  ::Asaurus::Mouse::ButtonRight
#define AS_MOUSE_BUTTON_MIDDLE ::Asaurus::Mouse::ButtonMiddle