#ifndef GRAPHICS_H
#define GRAPHICS_H
#pragma once

#include <Windows.h>
#include <string>
#include <vector>

enum Color
{
	BEFG_BLACK			= 0x0000,
	BEFG_DARK_BLUE		= 0x0001,
	BEFG_DARK_GREEN		= 0x0002,
	BEFG_DARK_CYAN		= 0x0003,
	BEFG_DARK_RED		= 0x0004,
	BEFG_DARK_MAGENTA	= 0x0005,
	BEFG_DARK_YELLOW	= 0x0006,
	BEFG_GREY			= 0x0007,
	BEFG_DARK_GREY		= 0x0008,
	BEFG_BLUE			= 0x0009,
	BEFG_GREEN			= 0x000A,
	BEFG_CYAN			= 0x000B,
	BEFG_RED			= 0x000C,
	BEFG_MAGENTA		= 0x000D,
	BEFG_YELLOW			= 0x000E,
	BEFG_WHITE			= 0x000F,
	BEBG_BLACK			= 0x0000,
	BEBG_DARK_BLUE		= 0x0010,
	BEBG_DARK_GREEN		= 0x0020,
	BEBG_DARK_CYAN		= 0x0030,
	BEBG_DARK_RED		= 0x0040,
	BEBG_DARK_MAGENTA	= 0x0050,
	BEBG_DARK_YELLOW	= 0x0060,
	BEBG_GREY			= 0x0070,
	BEBG_DARK_GREY		= 0x0080,
	BEBG_BLUE			= 0x0090,
	BEBG_GREEN			= 0x00A0,
	BEBG_CYAN			= 0x00B0,
	BEBG_RED			= 0x00C0,
	BEBG_MAGENTA		= 0x00D0,
	BEBG_YELLOW			= 0x00E0,
	BEBG_WHITE			= 0x00F0,
};

enum PixelType
{
	BEPIXEL_SOLID			= 0x2588,
	BEPIXEL_DARK_SHADE		= 0x2593,
	BEPIXEL_MEDIUM_SHADE	= 0x2592,
	BEPIXEL_LIGHT_SHADE		= 0x2591,
};

class Graphics
{
public:
	Graphics();
	Graphics(const Graphics&) = default;

	Graphics& operator =(const Graphics&) = default;

	~Graphics();

	void SetBuffer(CHAR_INFO *t_bufScreen, int t_screenWidth, int t_screenHeight);

	virtual void Draw(int t_x, int t_y, wchar_t t_char = BEPIXEL_SOLID, short t_color = BEFG_WHITE);
	void DrawLine(int t_x1, int t_y1, int t_x2, int t_y2, wchar_t t_char = BEPIXEL_SOLID, short t_color = BEFG_WHITE);
	void DrawString(int t_x, int t_y, std::string t_string, short t_color = BEFG_WHITE);
	
	void DrawWireframe(const std::vector<std::pair<float, float>> &t_wireframeModel, 
		float t_x, float t_y, float t_angle, float t_scale, wchar_t t_char = BEPIXEL_SOLID, short t_color = BEFG_WHITE);
	
	void Fill(int t_x, int t_y, int t_width, int t_height, wchar_t t_char = BEPIXEL_SOLID, short t_color = BEFG_WHITE);
	void Clear(short t_color = BEFG_BLACK);

private:
	std::vector<std::pair<float, float>> transformWireframe(const std::vector<std::pair<float, float>> &t_wireframeModel,
		float t_x, float t_y, float t_angle, float t_scale);

protected:
	CHAR_INFO *m_bufScreen;
	int m_screenWidth;
	int m_screenHeight;
};

#endif