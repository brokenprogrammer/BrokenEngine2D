#include "BrokenEngine2D.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include "Vector2D.hpp"
#include "Transform.hpp"


class testGame : public BrokenEngine2D
{

public:
	testGame()
	{

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
		Transform t;
		float velX;
		float velY;
	};

	std::vector<GameObject> m_gameObjects;
	std::vector<GameObject> m_misiles;
	GameObject m_player;

	// Player Model
	std::vector<std::pair<float, float>> m_playerModel;

	// Ball Model
	std::vector<std::pair<float, float>> m_ballModel;

protected:
	virtual bool onCreate()
	{
		m_player.t.position.x = 50.0f;
		m_player.t.position.y = 50.0f;
		m_player.velX = 0.0f;
		m_player.velY = 0.0f;
		m_player.t.rotation = 0.0f;
		m_player.t.scale.x = 0.0f;
		m_player.t.scale.y = 0.0f;

		// Initialize player model.
		m_playerModel = 
		{
			{ 0.0f, -5.5f },
			{ -2.5f, 2.5f },
			{ 2.5f, 2.5f }
		};

		for (int i = 0; i < 20; i++)
		{
			m_ballModel.push_back(std::make_pair(sinf((float)i / 20.0f * 6.28318f),
				cosf((float)i / 20.0f * 6.28318f)));
		}

		Transform testTransform;
		testTransform.position.x = 10.0f;
		testTransform.position.y = 50.0f;
		testTransform.rotation = 0.0f;
		testTransform.scale.x = 2.0f;
		testTransform.scale.y = 2.0f;

		m_gameObjects.push_back({ testTransform, 8.0f, -6.0f});

		return true;
	}

	virtual bool onUpdate(Input t_input, float t_elapsedTime)
	{

		if (t_input.getKey(VK_RIGHT).m_held)
		{
			m_player.t.rotation += 5.0f * t_elapsedTime;
		}

		if (t_input.getKey(VK_LEFT).m_held)
		{
			m_player.t.rotation -= 5.0f * t_elapsedTime;
		}

		if (t_input.getKey(VK_UP).m_held)
		{
			// Apply thrust depending on current angle.
			m_player.velX += sin(m_player.t.rotation) * 20.0f * t_elapsedTime;
			m_player.velY += -cos(m_player.t.rotation) * 20.0f * t_elapsedTime;
		}

		if (t_input.getKey(VK_SPACE).m_released || t_input.getMouseKey(0).m_pressed)
		{
			// Shoot misile.
			Transform misileTransform({ m_player.t.position.x, m_player.t.position.y }, m_player.t.rotation, { 0.0f, 0.0f });
			m_misiles.push_back({ misileTransform, 50.0f * sinf(m_player.t.rotation), -50.0f * cosf(m_player.t.rotation) });
		}
		
		// Update player based on velocity.
		m_player.t.position.x += m_player.velX * t_elapsedTime;
		m_player.t.position.y += m_player.velY * t_elapsedTime;
		wrapScreenCoords(m_player.t.position.x, m_player.t.position.y, m_player.t.position.x, m_player.t.position.y);

		// Update all game objects.
		for (auto &obj : m_gameObjects)
		{
			obj.t.position.x += obj.velX * t_elapsedTime;
			obj.t.position.y += obj.velY * t_elapsedTime;

			wrapScreenCoords(obj.t.position.x, obj.t.position.y, obj.t.position.x, obj.t.position.y);
		}

		// Update every misile.
		for (auto &misile : m_misiles)
		{
			misile.t.position.x += misile.velX * t_elapsedTime;
			misile.t.position.y += misile.velY * t_elapsedTime;

			wrapScreenCoords(misile.t.position.x, misile.t.position.y, misile.t.position.x, misile.t.position.y);
		}

		// Remove misiles that are off the screen.
		if (m_misiles.size() > 0)
		{
			auto i = remove_if(m_misiles.begin(), m_misiles.end(), [&](GameObject obj) {
				return obj.t.position.x < 1 || obj.t.position.x >= m_screenWidth - 1 || obj.t.position.y < 1 || obj.t.position.y >= m_screenHeight - 1;
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
		/*for (auto &obj : m_gameObjects)
		{
			for (int x = 0; x < obj.t.scale.x; x++)
			{
				for (int y = 0; y < obj.t.scale.y; y++)
				{
					t_graphics.Draw(obj.t.position.x + x, obj.t.position.y + y);
				}
			}
		}*/

		t_graphics.DrawWireframe(m_ballModel, m_gameObjects.at(0).t.position.x, m_gameObjects.at(0).t.position.y, m_gameObjects.at(0).t.rotation, 10.0f, true);

		// Draw misiles
		for (auto &misile : m_misiles)
		{
			t_graphics.Draw(misile.t.position.x, misile.t.position.y);
		}

		// Draw player model
		t_graphics.DrawWireframe(m_playerModel, m_player.t.position.x, m_player.t.position.y, m_player.t.rotation, 1.0f, true);

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