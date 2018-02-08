#include "Graphics.hpp"

Graphics::Graphics()
{
}

Graphics::~Graphics() {

}

void Graphics::Draw(float x, float y)
{
	int i = m_screenWidth * int(y + 0.5) + int(x + 0.5);
	m_bufScreen[i].Char.UnicodeChar = 0x2588;
	m_bufScreen[i].Attributes = 0x000F;
}

void Graphics::DrawLine(float x1, float y1, float x2, float y2)
{
}

void Graphics::DrawString(float x, float y, std::string str)
{
}

void Graphics::Fill(float x, float y, float width, float height)
{
	int a = m_screenWidth * int(y + 0.5) + int(x + 0.5);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			m_bufScreen[a+j].Char.UnicodeChar = 0x2588;
			m_bufScreen[a+j].Attributes = 0x000F;
		}
		a += m_screenWidth;
	}
}

void Graphics::Clear()
{
}

void Graphics::SetBuffer(CHAR_INFO *m_bufScreen, int m_screenWidth, int m_screenHeight)
{
	this->m_bufScreen = m_bufScreen;
	this->m_screenWidth = m_screenWidth;
	this->m_screenHeight = m_screenHeight;
}
