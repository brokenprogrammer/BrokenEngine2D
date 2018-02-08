#include "BrokenEngine2D.hpp"

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

	virtual bool onRender()
	{
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