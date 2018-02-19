#include "StateBasedGame.hpp"
#include <chrono>

StateBasedGame::~StateBasedGame()
{

}

void StateBasedGame::addState(std::string t_name, GameState *t_state)
{
	//TODO: check if already exists? idk if needed..
	m_gamestates[t_name] = t_state;

	if (this->m_activeState == nullptr)
	{
		enterState(t_name);
	}
}

void StateBasedGame::enterState(std::string t_name)
{
	// TODO: Check if state exists..
	m_activeState = this->m_gamestates[t_name];
}

void StateBasedGame::gameLoop()
{
	if (!this->m_activeState->onCreate())
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
		if (!this->m_activeState->onUpdate(this->m_input, *this, elapsedTime))
		{
			m_running = false;
		}

		// Handle rendering
		if (!this->m_activeState->onRender(*m_graphics))
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



// enterstate
// game.enterState(menuState)
// game.enterState(0);
// game.enterState("MainMenu");


// onUpdate(Input t_input, float t_elapsedTime, void (*enterState)())
//{
// enterState("MainMenu);
//}