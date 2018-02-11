#include "Graphics.hpp"
#include <math.h>
#include <stdio.h>

Graphics::Graphics()
{
}

Graphics::~Graphics() {

}

void Graphics::Draw(int x, int y, wchar_t c, short color)
{
	int i = m_screenWidth * y + x;
	m_bufScreen[i].Char.UnicodeChar = c;
	m_bufScreen[i].Attributes = color;
}

void Graphics::DrawLine(int x1, int y1, int x2, int y2, wchar_t c, short color)
{
	// Swap points if x1 is to the right of x2.
	if (x1 > x2) {
		int tempx = x2;
		x2 = x1;
		x1 = tempx;
		int tempy = y2;
		y2 = y1;
		y1 = tempy;
	}

	float k; // coefficient value
	if (x2 - x1 == 0) {
		k = 10000; // Instead of infinity.
		if (y2 - y1 < 0) {
			k = k * -1;
		}
	}
	else {
		k = float(y2 - y1) / float(x2 - x1);
	}
	
	float kx;
	float ky;

	// Calculating how much x and y will increase each iteration of drawing the line.
	if (k < 0) {
		kx = 1 / (-1 + k) * -1;
		ky = k / (-1 + k) * -1;
	}
	else {
		kx = 1 / (1 + k);
		ky = k / (1 + k);
	}
	kx *= 1.00001;
	ky *= 1.00001;

	float totLength = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); // Total length of the line.
	float length = 0;
	float increment = std::sqrt(kx * kx + ky * ky); // Line growth after every iteration of drawing it.

	// Draw loop.
	for (int i = 0; length < totLength + 0.5; i++) {
		float x = x1 + kx * i;
		float y = y1 + ky * i;
		int a = m_screenWidth * int(y + 0.5) + int(x + 0.5);

		m_bufScreen[a].Char.UnicodeChar = c;
		m_bufScreen[a].Attributes = color;

		length += increment;
	}
}

void Graphics::DrawString(int x, int y, std::string str, short color)
{
	int a = m_screenWidth * y + x;
	for (int i = 0; i < str.length(); i++) {
		char c = str.at(i);
		m_bufScreen[a + i].Char.UnicodeChar = c;
		m_bufScreen[a + i].Attributes = color;
	}
}

void Graphics::Fill(int x, int y, int width, int height, wchar_t c, short color)
{
	int a = m_screenWidth * y + x;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			m_bufScreen[a+j].Char.UnicodeChar = c;
			m_bufScreen[a+j].Attributes = color;
		}
		a += m_screenWidth;
	}
}

void Graphics::Clear(short color)
{
	Fill(0, 0, m_screenWidth, m_screenHeight, color);
}

void Graphics::SetBuffer(CHAR_INFO *m_bufScreen, int m_screenWidth, int m_screenHeight)
{
	this->m_bufScreen = m_bufScreen;
	this->m_screenWidth = m_screenWidth;
	this->m_screenHeight = m_screenHeight;
}
