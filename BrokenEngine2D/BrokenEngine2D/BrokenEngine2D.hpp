#ifndef BROKENENGINE2D_H
#define BROKENENGINE2D_H
#pragma once

#include <Windows.h>

class BrokenEngine2D
{
public:
	BrokenEngine2D();
	BrokenEngine2D(const BrokenEngine2D&) = default;

	BrokenEngine2D& operator =(const BrokenEngine2D&) = default;

	~BrokenEngine2D();

	int createWindow(int t_width, int t_height, int t_pixelWidth, int t_pixelHeight);

	virtual bool onCreate() = 0;
	virtual bool onUpdate() = 0;
	virtual bool onRender() = 0;

protected:
	int m_screenWidth;
	int m_screenHeight;
	SMALL_RECT m_rectWindow;

	HANDLE m_hConsole;
};

#endif
