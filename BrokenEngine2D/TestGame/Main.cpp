#include "BrokenEngine2D.hpp"
#include <string>

class testGame : public BrokenEngine2D
{
	int x = 0;
	int y = 0;

	virtual bool onCreate()
	{
		return true;
	}

	virtual bool onUpdate(Input input, float t_elapsedTime)
	{
		if (input.getKey(VK_LEFT).m_held)
		{
			x++;
		}

		if (input.getKey(VK_DOWN).m_held)
		{
			y++;
		}

		return true;
	}

	virtual bool onRender(Graphics g)
	{
		g.Clear();
		/*
		g.Fill(50, 40, 10, 10, 0x0001);
		g.DrawLine(20, 20, 30, 10, 0x0003);
		g.DrawLine(22, 22, 30, 40);
		g.DrawLine(10, 50, 30, 50);
		g.DrawLine(30, 55, 10, 55);
		g.DrawLine(34, 10, 24, 20);
		g.DrawLine(40, 10, 40, 20);
		g.DrawLine(50, 20, 50, 10);
		g.Draw(10, 48);
		g.Draw(30, 48);
		g.DrawString(40, 30, "Wow! BrokenEngine2D is such a cool program. I can make any game I want!", 0x0002);
		*/
		g.DrawLine(30, 60, 90, 30, 0x0101, 0x0002);
		g.DrawLine(90, 30, 30, 30, 0x2588, 0x0005);
		g.DrawLine(30, 30, 90, 60);
		g.DrawLine(90, 60, 60, 10);
		g.DrawLine(60, 10, 30, 60);
		g.Draw(18, 18, 0x0101, 0x0004);
		g.Draw(25, 18);
		return true;
	}
};

/*
	EXAMPLE OF DRAWING WHITE BOX TO THE SCREEN.				FORMAT: m_bufScreen[y * screenWidth + x] 
	m_bufScreen[0].Char.UnicodeChar = 0x2588;
	m_bufScreen[0].Attributes = 0x000F;

	m_bufScreen[10].Char.UnicodeChar = 0x2588;
	m_bufScreen[10].Attributes = 0x000F;

	m_bufScreen[40].Char.UnicodeChar = 0x2588;
	m_bufScreen[40].Attributes = 0x000F;

	m_bufScreen[60].Char.UnicodeChar = 0x2588;
	m_bufScreen[60].Attributes = 0x000F;
*/

int main()
{
	testGame g;
	g.createWindow(120, 80, 10, 10);
	g.start();

	return 0;
}