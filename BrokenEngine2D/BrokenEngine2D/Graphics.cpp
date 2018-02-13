#include "Graphics.hpp"
#include <math.h>
#include <stdio.h>

Graphics::Graphics()
{
}

Graphics::~Graphics() {

}

void Graphics::Draw(int t_x, int t_y, wchar_t t_char, short t_color)
{
	if (t_x >= 0 && t_x < m_screenWidth && t_y >= 0 && t_y < m_screenHeight)
	{
		int i = m_screenWidth * t_y + t_x;
		m_bufScreen[i].Char.UnicodeChar = t_char;
		m_bufScreen[i].Attributes = t_color;
	}
}

void Graphics::DrawLine(int t_x1, int t_y1, int t_x2, int t_y2, wchar_t t_char, short t_color)
{
	// Swap points if x1 is to the right of x2.
	if (t_x1 > t_x2) {
		int tempx = t_x2;
		t_x2 = t_x1;
		t_x1 = tempx;
		int tempy = t_y2;
		t_y2 = t_y1;
		t_y1 = tempy;
	}

	float k; // coefficient value
	if (t_x2 - t_x1 == 0) {
		k = 10000; // Instead of infinity.
		if (t_y2 - t_y1 < 0) {
			k = k * -1;
		}
	}
	else {
		k = float(t_y2 - t_y1) / float(t_x2 - t_x1);
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

	float totLength = std::sqrt((t_x2 - t_x1) * (t_x2 - t_x1) + (t_y2 - t_y1) * (t_y2 - t_y1)); // Total length of the line.
	float length = 0;
	float increment = std::sqrt(kx * kx + ky * ky); // Line growth after every iteration of drawing it.

	// Draw loop.
	for (int i = 0; length < totLength + 0.5; i++) {
		float x = t_x1 + kx * i;
		float y = t_y1 + ky * i;
		int a = m_screenWidth * int(y + 0.5) + int(x + 0.5);

		m_bufScreen[a].Char.UnicodeChar = t_char;
		m_bufScreen[a].Attributes = t_color;

		length += increment;
	}
}

void Graphics::DrawString(int t_x, int t_y, std::string t_string, short t_color)
{
	int a = m_screenWidth * t_y + t_x;
	for (int i = 0; i < t_string.length(); i++) {
		char c = t_string.at(i);
		m_bufScreen[a + i].Char.UnicodeChar = c;
		m_bufScreen[a + i].Attributes = t_color;
	}
}

void Graphics::Fill(int t_x, int t_y, int t_width, int t_height, wchar_t t_char, short t_color)
{
	int a = m_screenWidth * t_y + t_x;
	for (int i = 0; i < t_height; i++) {
		for (int j = 0; j < t_width; j++) {
			m_bufScreen[a+j].Char.UnicodeChar = t_char;
			m_bufScreen[a+j].Attributes = t_color;
		}
		a += m_screenWidth;
	}
}

void Graphics::Clear(short t_color)
{
	Fill(0, 0, m_screenWidth, m_screenHeight, t_color);
}

void Graphics::SetBuffer(CHAR_INFO *m_bufScreen, int m_screenWidth, int m_screenHeight)
{
	this->m_bufScreen = m_bufScreen;
	this->m_screenWidth = m_screenWidth;
	this->m_screenHeight = m_screenHeight;
}
