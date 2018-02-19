#include "StateBasedGame.hpp"
#include "GameState.hpp"
#include "Input.hpp"
#include "Graphics.hpp"

class MainMenuState : public GameState
{
public:
	virtual bool onCreate()
	{
		m_menuOptions[0] = "Play";
		m_menuOptions[1] = "Settings";
		m_menuOptions[2] = "Quit";

		m_selectedOption = 0;

		return true;
	}

	virtual bool onUpdate(Input t_input, StateBasedGame& t_game, float t_elapsedTime)
	{
		if (t_input.getKey(VK_SPACE).m_pressed)
		{
			switch (m_selectedOption)
			{
				case 0: // Play
				{
					t_game.enterState("Game");
				}break;

				case 1: // Settings
				{
				}break;
				
				case 2: // Quit
				{
					return false;
				}break;
			}
		}

		if (t_input.getKey(VK_DOWN).m_pressed)
		{
			m_selectedOption++;

			if (m_selectedOption > 2)
			{
				m_selectedOption = 0;
			}
		}

		if (t_input.getKey(VK_UP).m_pressed)
		{
			m_selectedOption--;

			if (m_selectedOption < 0)
			{
				m_selectedOption = 2;
			}
		}

		return true;
	}

	virtual bool onRender(Graphics& t_graphics)
	{
		t_graphics.Clear();

		t_graphics.DrawString(75, 20, "MAIN MENU");

		for (int i = 0; i < 3; i++)
		{
			short color = BEFG_WHITE;
			if (i == m_selectedOption)
			{
				color = BEFG_YELLOW;
			}

			t_graphics.DrawString(75, 30 + (i * 5), m_menuOptions[i], color);
		}

		return true;
	}

private:
	std::string m_menuOptions[3];
	int m_selectedOption;
};

class PlayingState : public GameState
{
public:
	virtual bool onCreate()
	{
		return true;
	}

	virtual bool onUpdate(Input t_input, StateBasedGame& t_game, float t_elapsedTime)
	{
		if (t_input.getKey(VK_SPACE).m_pressed)
		{
			t_game.enterState("MainMenu");
		}

		return true;
	}

	virtual bool onRender(Graphics& t_graphics)
	{
		t_graphics.Clear();

		t_graphics.DrawString(75, 20, "Game STATE");
		t_graphics.DrawString(75, 30, "You win!");
		return true;
	}
};

int main()
{
	StateBasedGame game;
	MainMenuState *menu = new MainMenuState;
	PlayingState *playing = new PlayingState;
	game.addState("MainMenu", menu);			// First added state will be the active one
	game.addState("Game", playing);
	game.createWindow(160, 100, 8, 8);
	game.start();
	
	return 0;
}