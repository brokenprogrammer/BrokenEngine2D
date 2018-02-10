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

	void Draw(float x, float y, int c = 0x2588, int color = 0x000F); // Draws one pixel
	void DrawLine(float x1, float y1, float x2, float y2, int color = 0x000F);
	void DrawString(float x, float y, std::string str, int color = 0x000F);
	void Fill(float x, float y, float width, float height, int color = 0x000F);
	void Clear(int color = 0x0000);

private:
	CHAR_INFO *m_bufScreen;
	int m_screenWidth;
	int m_screenHeight;
};