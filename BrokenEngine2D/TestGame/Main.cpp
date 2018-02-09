#include "BrokenEngine2D.hpp"
#include <string>

class testGame : public BrokenEngine2D
{
	virtual bool onCreate()
	{
		return true;
	}

	virtual bool onUpdate()
	{
		return true;
	}

	virtual bool onRender(Graphics g)
	{
		g.Draw(18, 18);
		g.Fill(50, 40, 10, 10);
		g.DrawLine(20, 20, 30, 10);
		g.DrawLine(22, 22, 30, 40);
		g.DrawLine(10, 50, 30, 50);
		g.DrawLine(30, 55, 10, 55);
		g.DrawLine(34, 10, 24, 20);
		g.DrawLine(40, 10, 40, 20);
		g.DrawLine(50, 20, 50, 10);
		g.Draw(10, 48);
		g.Draw(30, 48);
		g.DrawString(40, 30, "Wow! BrokenEngine2D is such a cool program. I can make any game I want!");
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