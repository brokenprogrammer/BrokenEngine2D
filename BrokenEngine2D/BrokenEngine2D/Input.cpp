#include "Input.hpp"
#include <iostream>
#include <Windows.h>

Input::Input()
{
	std::memset(m_keyboardKeys, 0, 256*sizeof(KeyState));
	std::memset(m_oldKeyboardState, 0, 256 * sizeof(short));
	std::memset(m_newKeyboardState, 0, 256 * sizeof(short));


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
				m_keyboardKeys->m_pressed = m_keyboardKeys[i].m_held ? false : true;
				m_keyboardKeys->m_held = true;
			}
			else
			{
				m_keyboardKeys->m_released = true;
				m_keyboardKeys->m_held = false;
			}
		}

		m_oldKeyboardState[i] = m_newKeyboardState[i];
	}

	// Poll input for mouse.. TODO:
}