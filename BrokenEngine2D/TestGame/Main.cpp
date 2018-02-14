#include "BrokenEngine2D.hpp"
#include <string>
#include <vector>
#include <algorithm>

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

		float angle;
	};

	std::vector<GameObject> m_gameObjects;
	std::vector<GameObject> m_misiles;
	GameObject m_player;

	// Player Model
	std::vector<std::pair<float, float>> m_playerModel;

protected:
	virtual bool onCreate()
	{
		m_player = { 50.0f, 50.0f, 0.0f, 0.0f, 1, 0.0f };

		// Initialize player model.
		m_playerModel = 
		{
			{ 0.0f, -5.5f },
			{ -2.5f, 2.5f },
			{ 2.5f, 2.5f }
		};

		m_gameObjects.push_back({ 10.0f, 50.0f, 8.0f, -6.0f, (int)1, 0.0f });
		m_gameObjects.push_back({ 20.0f, 40.0f, 8.0f, -6.0f, (int)1, 0.0f });

		return true;
	}

	virtual bool onUpdate(Input t_input, float t_elapsedTime)
	{

		if (t_input.getKey(VK_RIGHT).m_held)
		{
			m_player.angle += 5.0f * t_elapsedTime;
		}

		if (t_input.getKey(VK_LEFT).m_held)
		{
			m_player.angle -= 5.0f * t_elapsedTime;
		}

		if (t_input.getKey(VK_UP).m_held)
		{
			// Apply thrust depending on current angle.
			m_player.velX += sin(m_player.angle) * 20.0f * t_elapsedTime;
			m_player.velY += -cos(m_player.angle) * 20.0f * t_elapsedTime;
		}

		if (t_input.getKey(VK_SPACE).m_released || t_input.getMouseKey(0).m_pressed)
		{
			// Shoot misile.
			m_misiles.push_back({ m_player.x, m_player.y, 50.0f * sinf(m_player.angle), -50.0f * cosf(m_player.angle), (int)1, m_player.angle });
		}
		
		// Update player based on velocity.
		m_player.x += m_player.velX * t_elapsedTime;
		m_player.y += m_player.velY * t_elapsedTime;
		wrapScreenCoords(m_player.x, m_player.y, m_player.x, m_player.y);

		// Update all game objects.
		for (auto &obj : m_gameObjects)
		{
			obj.x += obj.velX * t_elapsedTime;
			obj.y += obj.velY * t_elapsedTime;

			wrapScreenCoords(obj.x, obj.y, obj.x, obj.y);
		}

		// Update every misile.
		for (auto &misile : m_misiles)
		{
			misile.x += misile.velX * t_elapsedTime;
			misile.y += misile.velY * t_elapsedTime;

			wrapScreenCoords(misile.x, misile.y, misile.x, misile.y);
		}

		// Remove misiles that are off the screen.
		if (m_misiles.size() > 0)
		{
			auto i = remove_if(m_misiles.begin(), m_misiles.end(), [&](GameObject obj) {
				return obj.x < 1 || obj.x >= m_screenWidth - 1 || obj.y < 1 || obj.y >= m_screenHeight - 1;
			});

			if (i != m_misiles.end())
			{
				m_misiles.erase(i);
			}
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

		// Draw misiles
		for (auto &misile : m_misiles)
		{
			t_graphics.Draw(misile.x, misile.y);
		}

		// Draw player model
		t_graphics.DrawWireframe(m_playerModel, m_player.x, m_player.y, m_player.angle, 1.0f);

		return true;
	}
};

int main()
{
	testGame game;
	game.createWindow(160, 100, 8, 8);
	game.start();

	return 0;
}