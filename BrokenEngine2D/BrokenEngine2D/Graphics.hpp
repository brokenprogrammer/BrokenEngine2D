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

	void SetBuffer(CHAR_INFO *t_bufScreen, int t_screenWidth, int t_screenHeight);

	void Draw(int t_x, int t_y, wchar_t t_char = 0x2588, short t_color = 0x000F); // Draws one pixel
	void DrawLine(int t_x1, int t_y1, int t_x2, int t_y2, wchar_t t_char = 0x2588, short t_color = 0x000F);
	void DrawString(int t_x, int t_y, std::string t_string, short t_color = 0x000F);
	void Fill(int t_x, int t_y, int t_width, int t_height, wchar_t t_char = 0x2588, short t_color = 0x000F);
	void Clear(short t_color = 0x0000);

private:
	CHAR_INFO *m_bufScreen;
	int m_screenWidth;
	int m_screenHeight;
};