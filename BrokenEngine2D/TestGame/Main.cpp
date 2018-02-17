#include "BrokenEngine2D.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include "Vector2D.hpp"
#include "Transform.hpp"

// Global function maybe not so good?? TODO:..
void wrapScreenCoords(float t_inX, float t_inY, float &t_outX, float &t_outY, int t_screenWidth, int t_screenHeight)
{
	t_outX = t_inX;
	t_outY = t_inY;

	if (t_inX < 0)
	{
		t_outX = t_inX + (float)t_screenWidth;
	}

	if (t_inX >= (float)t_screenWidth)
	{
		t_outX = t_inX - (float)t_screenWidth;
	}

	if (t_inY < 0)
	{
		t_outY = t_inY + (float)t_screenHeight;
	}

	if (t_inY >= (float)t_screenHeight)
	{
		t_outY = t_inY - (float)t_screenHeight;
	}
}

class testGameGraphics : public Graphics
{
public:
	void Draw(int t_x, int t_y, wchar_t t_char = BEPIXEL_SOLID, short t_color = BEFG_WHITE)
	{
		float x;
		float y;
		wrapScreenCoords(t_x, t_y, x, y, m_screenWidth, m_screenHeight);
		Graphics::Draw(x, y, t_char, BEFG_GREEN);
	}
};

class testGame : public BrokenEngine2D
{
public:
	// To get access to constructors.
	using BrokenEngine2D::BrokenEngine2D;
private:
	struct GameObject
	{
		Transform t;
		float velX;
		float velY;

		float& getPositionX()
		{
			return t.position.x;
		}

		float& getPositionY()
		{
			return t.position.y;
		}

		float& getAngle()
		{
			return t.rotation;
		}
	};

	std::vector<GameObject> m_balls;
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

		m_balls.push_back({ testTransform, 8.0f, -6.0f});

		return true;
	}

	virtual bool onUpdate(Input t_input, float t_elapsedTime)
	{

		if (t_input.getKey(VK_RIGHT).m_held)
		{
			m_player.getAngle() += 5.0f * t_elapsedTime;
		}

		if (t_input.getKey(VK_LEFT).m_held)
		{
			m_player.getAngle() -= 5.0f * t_elapsedTime;
		}

		if (t_input.getKey(VK_UP).m_held)
		{
			// Apply thrust depending on current angle.
			m_player.velX += sin(m_player.getAngle()) * 20.0f * t_elapsedTime;
			m_player.velY += -cos(m_player.getAngle()) * 20.0f * t_elapsedTime;
		}

		if (t_input.getKey(VK_SPACE).m_released || t_input.getMouseKey(0).m_pressed)
		{
			// Shoot misile.
			Transform misileTransform({ m_player.getPositionX(), m_player.getPositionY() }, m_player.getAngle(), { 0.0f, 0.0f });
			m_misiles.push_back({ misileTransform, 50.0f * sinf(m_player.getAngle()), -50.0f * cosf(m_player.getAngle()) });
		}
		
		// Update player based on velocity.
		m_player.getPositionX() += m_player.velX * t_elapsedTime;
		m_player.getPositionY() += m_player.velY * t_elapsedTime;
		wrapScreenCoords(m_player.getPositionX(), m_player.getPositionY(), m_player.getPositionX(), m_player.getPositionY(), m_screenWidth, m_screenHeight);

		// Update all game objects.
		for (auto &obj : m_balls)
		{
			obj.getPositionX() += obj.velX * t_elapsedTime;
			obj.getPositionY() += obj.velY * t_elapsedTime;

			wrapScreenCoords(obj.getPositionX(), obj.getPositionY(), obj.getPositionX(), obj.getPositionY(), m_screenWidth, m_screenHeight);
		}

		// Update every misile.
		for (auto &misile : m_misiles)
		{
			misile.getPositionX() += misile.velX * t_elapsedTime;
			misile.getPositionY() += misile.velY * t_elapsedTime;

			wrapScreenCoords(misile.getPositionX(), misile.getPositionY(), misile.getPositionX(), misile.getPositionY(), m_screenWidth, m_screenHeight);
		}

		// Remove misiles that are off the screen.
		if (m_misiles.size() > 0)
		{
			auto i = remove_if(m_misiles.begin(), m_misiles.end(), [&](GameObject obj) {
				return obj.getPositionX() < 1 || obj.getPositionX() >= m_screenWidth - 1 || obj.getPositionY() < 1 || obj.getPositionY() >= m_screenHeight - 1;
			});

			if (i != m_misiles.end())
			{
				m_misiles.erase(i);
			}
		}

		return true;
	}

	virtual bool onRender(Graphics& t_graphics)
	{
		t_graphics.Clear();

		// Draw balls 
		for (auto &obj : m_balls)
		{
			t_graphics.DrawWireframe(m_ballModel, obj.getPositionX(), obj.getPositionY(), obj.getAngle(), 10.0f);
		}

		// Draw misiles
		for (auto &misile : m_misiles)
		{
			t_graphics.Draw(misile.getPositionX(), misile.getPositionY());
		}

		// Draw player model
		t_graphics.DrawWireframe(m_playerModel, m_player.getPositionX(), m_player.getPositionY(), m_player.getAngle(), 1.0f);

		return true;
	}
};

int main()
{
	testGameGraphics* g = new testGameGraphics;
	testGame game(g);
	game.createWindow(160, 100, 8, 8);
	game.start();

	return 0;
}