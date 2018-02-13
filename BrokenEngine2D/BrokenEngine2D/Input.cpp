#include "Input.hpp"
#include <iostream>

/*
	If dwEventFlags is zero it indicates that a mouse button is being pressed.
	https://docs.microsoft.com/en-us/windows/console/mouse-event-record-str
*/
#define MOUSE_CLICKED 0

Input::Input(HANDLE t_hConsoleIn) : m_hConsoleIn(t_hConsoleIn)
{
	std::memset(m_keyboardKeys, 0, 256*sizeof(KeyState));
	std::memset(m_oldKeyboardState, 0, 256 * sizeof(short));
	std::memset(m_newKeyboardState, 0, 256 * sizeof(short));

	std::memset(m_mouseKeys, 0, 5 * sizeof(KeyState));
	std::memset(m_oldMouseState, 0, 5 * sizeof(short));
	std::memset(m_newMouseState, 0, 5 * sizeof(short));

	m_mouseX = 0;
	m_mouseY = 0;
}

Input::~Input()
{

}

void Input::poll()
{
	// Poll input for every single key.
	for (int i = 0; i < 256; i++)
	{
		m_newKeyboardState[i] = GetAsyncKeyState(i);

		m_keyboardKeys[i].m_pressed = false;
		m_keyboardKeys[i].m_released = false;

		if (m_newKeyboardState[i] != m_oldKeyboardState[i])
		{
			// Check most significant bit from call to GetAsyncKeyState
			if (m_newKeyboardState[i] & 0x8000)
			{
				// If key is already held then pressed is false, otherwise true.
				m_keyboardKeys[i].m_pressed = m_keyboardKeys[i].m_held ? false : true;
				m_keyboardKeys[i].m_held = true;
			}
			else
			{
				m_keyboardKeys[i].m_released = true;
				m_keyboardKeys[i].m_held = false;
			}
		}

		m_oldKeyboardState[i] = m_newKeyboardState[i];
	}

	// View windows events to retrieve mouse input
	INPUT_RECORD inputBuffer[32];
	DWORD numberEvents = 0;
	GetNumberOfConsoleInputEvents(this->m_hConsoleIn, &numberEvents);

	if (numberEvents > 0)
	{
		ReadConsoleInput(this->m_hConsoleIn, inputBuffer, numberEvents, &numberEvents);
	}

	// Handle retrieved windows events
	for (DWORD i = 0; i < numberEvents; i++)
	{
		switch (inputBuffer[i].EventType)
		{
			case MOUSE_EVENT:
			{
				switch (inputBuffer[i].Event.MouseEvent.dwEventFlags)
				{
				case MOUSE_MOVED:
				{
					this->m_mouseX = inputBuffer[i].Event.MouseEvent.dwMousePosition.X;
					this->m_mouseY = inputBuffer[i].Event.MouseEvent.dwMousePosition.Y;
				} break;

				case MOUSE_CLICKED:
				{
					for (int j = 0; j < 5; j++)
					{
						m_newMouseState[j] = (inputBuffer[i].Event.MouseEvent.dwButtonState & (1 << j)) > 0;
					}
				} break;

				default:
				{
				} break;
				}
			} break;

			default:
			{
			} break;
		}
	}

	// Poll input for every mouse key
	for (int i = 0; i < 5; i++) {
		
		m_mouseKeys[i].m_pressed = false;
		m_mouseKeys[i].m_released = false;

		if (m_newMouseState[i] != m_oldMouseState[i])
		{
			if (m_newMouseState[i])
			{
				m_mouseKeys[i].m_pressed = true;
				m_mouseKeys[i].m_held = true;
			}
			else
			{
				m_mouseKeys[i].m_released = true;
				m_mouseKeys[i].m_held = false;
			}
		}

		m_oldMouseState[i] = m_newMouseState[i];
	}
}