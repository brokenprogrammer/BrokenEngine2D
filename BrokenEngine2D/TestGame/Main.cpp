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
	void wrapScreenCoords(float t_inX, float t_inY, float &t_outX, float &t_outY)
	{
		t_outX = t_inX;
		t_outY = t_inY;

		if (t_inX < 0)
		{
			t_outX = t_inX + (float)m_screenWidth;
		}

		if (t_inX >= (float)m_screenWidth)
		{
			t_outX = t_inX - (float)m_screenWidth;
		}

		if (t_inY < 0)
		{
			t_outY = t_inY + (float)m_screenHeight;
		}

		if (t_inY >= (float)m_screenHeight)
		{
			t_outY = t_inY - (float)m_screenHeight;
		}
	}

	struct GameObject
	{
		float x;
		float y;

		float velX;
		float velY;

		int size;
	};

	std::vector<GameObject> m_gameObjects;
	GameObject m_player;

protected:
	virtual bool onCreate()
	{
		m_player = { 0.0f, 50.0f, 8.0f, -6.0f, 1 };

		m_gameObjects.push_back({ 10.0f, 50.0f, 8.0f, -6.0f, (int)1 });
		m_gameObjects.push_back({ 20.0f, 40.0f, 8.0f, -6.0f, (int)1 });

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

		wrapScreenCoords(m_player.x, m_player.y, m_player.x, m_player.y);

		for (auto &obj : m_gameObjects)
		{
			obj.x += obj.velX * t_elapsedTime;
			obj.y += obj.velY * t_elapsedTime;

			wrapScreenCoords(obj.x, obj.y, obj.x, obj.y);
		}

		return true;
	}

	virtual bool onRender(Graphics t_graphics)
	{
		t_graphics.Clear();

		// Draw game objects 
		for (auto &obj : m_gameObjects)
		{
			for (int x = 0; x < obj.size; x++)
			{
				for (int y = 0; y < obj.size; y++)
				{
					t_graphics.Draw(obj.x + x, obj.y + y);
				}
			}
		}

		// Draw Player
		for (int x = 0; x < m_player.size; x++)
		{
			for (int y = 0; y < m_player.size; y++)
			{
				t_graphics.Draw(m_player.x + x, m_player.y + y, BEPIXEL_DARK_SHADE, BEBG_CYAN | BEFG_DARK_MAGENTA);
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