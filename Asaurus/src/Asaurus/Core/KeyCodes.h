#pragma once

namespace Asaurus
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space		= 32,
		Apostrophe	= 39, /* ' */
		Comma		= 44, /* , */
		Minus		= 45, /* - */
		Period		= 46, /* . */
		Slash		= 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon	= 59, /* ; */
		Equal		= 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket		= 91,  /* [ */
		Backslash		= 92,  /* \ */
		RightBracket	= 93,  /* ] */
		GraveAccent		= 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape		= 256,
		Enter		= 257,
		Tab			= 258,
		Backspace	= 259,
		Insert		= 260,
		Delete		= 261,
		Right		= 262,
		Left		= 263,
		Down		= 264,
		Up			= 265,
		PageUp		= 266,
		PageDown	= 267,
		Home		= 268,
		End			= 269,
		CapsLock	= 280,
		ScrollLock	= 281,
		NumLock		= 282,
		PrintScreen = 283,
		Pause		= 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal	= 330,
		KPDivide	= 331,
		KPMultiply	= 332,
		KPSubtract	= 333,
		KPAdd		= 334,
		KPEnter		= 335,
		KPEqual		= 336,

		LeftShift	= 340,
		LeftControl = 341,
		LeftAlt		= 342,
		LeftSuper	= 343,
		RightShift	= 344,
		RightControl = 345,
		RightAlt	= 346,
		RightSuper	= 347,
		Menu		= 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define AS_KEY_SPACE           ::Asaurus::Key::Space
#define AS_KEY_APOSTROPHE      ::Asaurus::Key::Apostrophe    /* ' */
#define AS_KEY_COMMA           ::Asaurus::Key::Comma         /* , */
#define AS_KEY_MINUS           ::Asaurus::Key::Minus         /* - */
#define AS_KEY_PERIOD          ::Asaurus::Key::Period        /* . */
#define AS_KEY_SLASH           ::Asaurus::Key::Slash         /* / */
#define AS_KEY_0               ::Asaurus::Key::D0
#define AS_KEY_1               ::Asaurus::Key::D1
#define AS_KEY_2               ::Asaurus::Key::D2
#define AS_KEY_3               ::Asaurus::Key::D3
#define AS_KEY_4               ::Asaurus::Key::D4
#define AS_KEY_5               ::Asaurus::Key::D5
#define AS_KEY_6               ::Asaurus::Key::D6
#define AS_KEY_7               ::Asaurus::Key::D7
#define AS_KEY_8               ::Asaurus::Key::D8
#define AS_KEY_9               ::Asaurus::Key::D9
#define AS_KEY_SEMICOLON       ::Asaurus::Key::Semicolon     /* ; */
#define AS_KEY_EQUAL           ::Asaurus::Key::Equal         /* = */
#define AS_KEY_A               ::Asaurus::Key::A
#define AS_KEY_B               ::Asaurus::Key::B
#define AS_KEY_C               ::Asaurus::Key::C
#define AS_KEY_D               ::Asaurus::Key::D
#define AS_KEY_E               ::Asaurus::Key::E
#define AS_KEY_F               ::Asaurus::Key::F
#define AS_KEY_G               ::Asaurus::Key::G
#define AS_KEY_H               ::Asaurus::Key::H
#define AS_KEY_I               ::Asaurus::Key::I
#define AS_KEY_J               ::Asaurus::Key::J
#define AS_KEY_K               ::Asaurus::Key::K
#define AS_KEY_L               ::Asaurus::Key::L
#define AS_KEY_M               ::Asaurus::Key::M
#define AS_KEY_N               ::Asaurus::Key::N
#define AS_KEY_O               ::Asaurus::Key::O
#define AS_KEY_P               ::Asaurus::Key::P
#define AS_KEY_Q               ::Asaurus::Key::Q
#define AS_KEY_R               ::Asaurus::Key::R
#define AS_KEY_S               ::Asaurus::Key::S
#define AS_KEY_T               ::Asaurus::Key::T
#define AS_KEY_U               ::Asaurus::Key::U
#define AS_KEY_V               ::Asaurus::Key::V
#define AS_KEY_W               ::Asaurus::Key::W
#define AS_KEY_X               ::Asaurus::Key::X
#define AS_KEY_Y               ::Asaurus::Key::Y
#define AS_KEY_Z               ::Asaurus::Key::Z
#define AS_KEY_LEFT_BRACKET    ::Asaurus::Key::LeftBracket   /* [ */
#define AS_KEY_BACKSLASH       ::Asaurus::Key::Backslash     /* \ */
#define AS_KEY_RIGHT_BRACKET   ::Asaurus::Key::RightBracket  /* ] */
#define AS_KEY_GRAVE_ACCENT    ::Asaurus::Key::GraveAccent   /* ` */
#define AS_KEY_WORLD_1         ::Asaurus::Key::World1        /* non-US #1 */
#define AS_KEY_WORLD_2         ::Asaurus::Key::World2        /* non-US #2 */

/* Function keys */
#define AS_KEY_ESCAPE          ::Asaurus::Key::Escape
#define AS_KEY_ENTER           ::Asaurus::Key::Enter
#define AS_KEY_TAB             ::Asaurus::Key::Tab
#define AS_KEY_BACKSPACE       ::Asaurus::Key::Backspace
#define AS_KEY_INSERT          ::Asaurus::Key::Insert
#define AS_KEY_DELETE          ::Asaurus::Key::Delete
#define AS_KEY_RIGHT           ::Asaurus::Key::Right
#define AS_KEY_LEFT            ::Asaurus::Key::Left
#define AS_KEY_DOWN            ::Asaurus::Key::Down
#define AS_KEY_UP              ::Asaurus::Key::Up
#define AS_KEY_PAGE_UP         ::Asaurus::Key::PageUp
#define AS_KEY_PAGE_DOWN       ::Asaurus::Key::PageDown
#define AS_KEY_HOME            ::Asaurus::Key::Home
#define AS_KEY_END             ::Asaurus::Key::End
#define AS_KEY_CAPS_LOCK       ::Asaurus::Key::CapsLock
#define AS_KEY_SCROLL_LOCK     ::Asaurus::Key::ScrollLock
#define AS_KEY_NUM_LOCK        ::Asaurus::Key::NumLock
#define AS_KEY_PRINT_SCREEN    ::Asaurus::Key::PrintScreen
#define AS_KEY_PAUSE           ::Asaurus::Key::Pause
#define AS_KEY_F1              ::Asaurus::Key::F1
#define AS_KEY_F2              ::Asaurus::Key::F2
#define AS_KEY_F3              ::Asaurus::Key::F3
#define AS_KEY_F4              ::Asaurus::Key::F4
#define AS_KEY_F5              ::Asaurus::Key::F5
#define AS_KEY_F6              ::Asaurus::Key::F6
#define AS_KEY_F7              ::Asaurus::Key::F7
#define AS_KEY_F8              ::Asaurus::Key::F8
#define AS_KEY_F9              ::Asaurus::Key::F9
#define AS_KEY_F10             ::Asaurus::Key::F10
#define AS_KEY_F11             ::Asaurus::Key::F11
#define AS_KEY_F12             ::Asaurus::Key::F12
#define AS_KEY_F13             ::Asaurus::Key::F13
#define AS_KEY_F14             ::Asaurus::Key::F14
#define AS_KEY_F15             ::Asaurus::Key::F15
#define AS_KEY_F16             ::Asaurus::Key::F16
#define AS_KEY_F17             ::Asaurus::Key::F17
#define AS_KEY_F18             ::Asaurus::Key::F18
#define AS_KEY_F19             ::Asaurus::Key::F19
#define AS_KEY_F20             ::Asaurus::Key::F20
#define AS_KEY_F21             ::Asaurus::Key::F21
#define AS_KEY_F22             ::Asaurus::Key::F22
#define AS_KEY_F23             ::Asaurus::Key::F23
#define AS_KEY_F24             ::Asaurus::Key::F24
#define AS_KEY_F25             ::Asaurus::Key::F25

/* Keypad */
#define AS_KEY_KP_0            ::Asaurus::Key::KP0
#define AS_KEY_KP_1            ::Asaurus::Key::KP1
#define AS_KEY_KP_2            ::Asaurus::Key::KP2
#define AS_KEY_KP_3            ::Asaurus::Key::KP3
#define AS_KEY_KP_4            ::Asaurus::Key::KP4
#define AS_KEY_KP_5            ::Asaurus::Key::KP5
#define AS_KEY_KP_6            ::Asaurus::Key::KP6
#define AS_KEY_KP_7            ::Asaurus::Key::KP7
#define AS_KEY_KP_8            ::Asaurus::Key::KP8
#define AS_KEY_KP_9            ::Asaurus::Key::KP9
#define AS_KEY_KP_DECIMAL      ::Asaurus::Key::KPDecimal
#define AS_KEY_KP_DIVIDE       ::Asaurus::Key::KPDivide
#define AS_KEY_KP_MULTIPLY     ::Asaurus::Key::KPMultiply
#define AS_KEY_KP_SUBTRACT     ::Asaurus::Key::KPSubtract
#define AS_KEY_KP_ADD          ::Asaurus::Key::KPAdd
#define AS_KEY_KP_ENTER        ::Asaurus::Key::KPEnter
#define AS_KEY_KP_EQUAL        ::Asaurus::Key::KPEqual

#define AS_KEY_LEFT_SHIFT      ::Asaurus::Key::LeftShift
#define AS_KEY_LEFT_CONTROL    ::Asaurus::Key::LeftControl
#define AS_KEY_LEFT_ALT        ::Asaurus::Key::LeftAlt
#define AS_KEY_LEFT_SUPER      ::Asaurus::Key::LeftSuper
#define AS_KEY_RIGHT_SHIFT     ::Asaurus::Key::RightShift
#define AS_KEY_RIGHT_CONTROL   ::Asaurus::Key::RightControl
#define AS_KEY_RIGHT_ALT       ::Asaurus::Key::RightAlt
#define AS_KEY_RIGHT_SUPER     ::Asaurus::Key::RightSuper
#define AS_KEY_MENU            ::Asaurus::Key::Menu