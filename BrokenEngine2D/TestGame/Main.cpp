#include "BrokenEngine2D.hpp"
#include <string>
#include <vector>

class testGame : public BrokenEngine2D
{

public:
	testGame()
	{
		// Constructor
	}

private:
	struct GameObject
	{
		float x;
		float y;

		float velX;
		float velY;

		int size;
	};

	GameObject m_player;

	std::vector<GameObject> m_gameObjects;

protected:
	virtual bool onCreate()
	{
		m_player = { 0.0f, 50.0f, 8.0f, -6.0f, 1 };

		m_gameObjects.push_back(m_player);

		return true;
	}

	virtual bool onUpdate(Input t_input, float t_elapsedTime)
	{

		if (t_input.getKey(VK_RIGHT).m_held)
		{
			m_player.x += 8.0f * t_elapsedTime;
		}

		if (t_input.getKey(VK_LEFT).m_held)
		{
			m_player.x -= 8.0f * t_elapsedTime;
		}

		if (t_input.getKey(VK_UP).m_held)
		{
			m_player.y -= 8.0f * t_elapsedTime;
		}

		if (t_input.getKey(VK_DOWN).m_held)
		{
			m_player.y += 8.0f * t_elapsedTime;
		}

		//m_player.x += m_player.velX * t_elapsedTime;
		//m_player.y += m_player.velY * t_elapsedTime;

		return true;
	}

	virtual bool onRender(Graphics t_graphics)
	{
		t_graphics.Clear();

		// Breaks when drawing something outside of the screen..
		for (int x = 0; x < m_player.size; x++)
		{
			for (int y = 0; y < m_player.size; y++)
			{
				t_graphics.Draw(m_player.x + x, m_player.y + y);
			}
		}

		return true;
	}
};


int main()
{
	testGame game;
	game.createWindow(120, 80, 10, 10);
	game.start();

	return 0;
}