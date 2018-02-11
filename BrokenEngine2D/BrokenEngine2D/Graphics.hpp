#pragma once

#include <Windows.h>
#include <string>

class Graphics
{
public:
	Graphics();
	Graphics(const Graphics&) = default;

	Graphics& operator =(const Graphics&) = default;

	~Graphics();

	void SetBuffer(CHAR_INFO *m_bufScreen, int m_screenWidth, int m_screenHeight);

	void Draw(int x, int y, wchar_t c = 0x2588, short color = 0x000F); // Draws one pixel
	void DrawLine(int x1, int y1, int x2, int y2, short color = 0x000F);
	void DrawString(int x, int y, std::string str, short color = 0x000F);
	void Fill(int x, int y, int width, int height, short color = 0x000F);
	void Clear(short color = 0x0000);

private:
	CHAR_INFO *m_bufScreen;
	int m_screenWidth;
	int m_screenHeight;
};