#ifndef BROKENENGINE2D_H
#define BROKENENGINE2D_H
#pragma once

#include <Windows.h>
#include <atomic>
#include "Graphics.hpp"

class BrokenEngine2D
{
public:
	BrokenEngine2D();
	BrokenEngine2D(const BrokenEngine2D&) = default;

	BrokenEngine2D& operator =(const BrokenEngine2D&) = default;

	~BrokenEngine2D();

	int createWindow(int t_width, int t_height, int t_pixelWidth, int t_pixelHeight);
	void start();

	virtual bool onCreate() = 0;
	virtual bool onUpdate() = 0;
	virtual bool onRender(Graphics g) = 0;

private:
	void gameLoop();

protected:
	int m_screenWidth;
	int m_screenHeight;
	SMALL_RECT m_rectWindow;

	HANDLE m_hConsole;
	HANDLE m_hConsoleIn;

	CHAR_INFO *m_bufScreen;

	Graphics g;

	std::atomic<bool> m_running;
};

#endif
