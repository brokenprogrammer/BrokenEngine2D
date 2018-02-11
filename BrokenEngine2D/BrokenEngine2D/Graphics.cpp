#include "Graphics.hpp"
#include <math.h>
#include <stdio.h>

Graphics::Graphics()
{
}

Graphics::~Graphics() {

}

void Graphics::Draw(float x, float y, int c, short color)
{
	int i = m_screenWidth * int(y + 0.5) + int(x + 0.5);
	m_bufScreen[i].Char.UnicodeChar = c;
	m_bufScreen[i].Attributes = color;
}

void Graphics::DrawLine(float x1, float y1, float x2, float y2, short color)
{
	// Swap points if x1 is to the right of x2.
	if (x1 > x2) {
		float tempx = x2;
		x2 = x1;
		x1 = tempx;
		float tempy = y2;
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
		k = (y2 - y1) / (x2 - x1);
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

		m_bufScreen[a].Char.UnicodeChar = 0x2588;
		m_bufScreen[a].Attributes = color;

		length += increment;
	}
}

void Graphics::DrawString(float x, float y, std::string str, short color)
{
	int a = m_screenWidth * int(y + 0.5) + int(x + 0.5);
	for (int i = 0; i < str.length(); i++) {
		char c = str.at(i);
		m_bufScreen[a + i].Char.UnicodeChar = c;
		m_bufScreen[a + i].Attributes = color;
	}
}

void Graphics::Fill(float x, float y, float width, float height, short color)
{
	int a = m_screenWidth * int(y + 0.5) + int(x + 0.5);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			m_bufScreen[a+j].Char.UnicodeChar = 0x2588;
			m_bufScreen[a+j].Attributes = color;
		}
		a += m_screenWidth;
	}
}

void Graphics::Clear(short color)
{
	for (int i = 0; i < m_screenWidth * m_screenHeight; i++) {
		m_bufScreen[i].Char.UnicodeChar = 0x2588;
		m_bufScreen[i].Attributes = color;
	}
}

void Graphics::SetBuffer(CHAR_INFO *m_bufScreen, int m_screenWidth, int m_screenHeight)
{
	this->m_bufScreen = m_bufScreen;
	this->m_screenWidth = m_screenWidth;
	this->m_screenHeight = m_screenHeight;
}
