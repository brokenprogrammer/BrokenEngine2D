#include "SimpleGame.hpp"
#include <chrono>

SimpleGame::~SimpleGame()
{

}

void SimpleGame::gameLoop()
{
	if (!onCreate())
	{
		m_running = false;
	}

	auto t1 = std::chrono::system_clock::now();
	auto t2 = std::chrono::system_clock::now();

	while (m_running)
	{
		// Retrieve elapsed time duration.
		t2 = std::chrono::system_clock::now();
		std::chrono::duration<float> deltaTime = t2 - t1;
		t1 = t2;

		float elapsedTime = deltaTime.count();

		// Poll for input.
		m_input.poll();

		// Handle updates
		if (!onUpdate(this->m_input, elapsedTime))
		{
			m_running = false;
		}

		// Handle rendering
		if (!onRender(*m_graphics))
		{
			m_running = false;
		}

		// Render screen buffer..
		wchar_t s[256];
		swprintf_s(s, 256, L"BrokenEngine2D FPS: %3.2f MOUSEX: %i MOUSEY: %i ", (1.0f / elapsedTime), this->m_input.getMouseX(), this->m_input.getMouseY());
		SetConsoleTitle(s);
		WriteConsoleOutput(m_hConsole, m_bufScreen, { (short)m_screenWidth, (short)m_screenHeight }, { 0, 0 }, &m_rectWindow);
	}
}