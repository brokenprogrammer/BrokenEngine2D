#ifndef BROKENENGINE2D_H
#define BROKENENGINE2D_H
#pragma once

#include <Windows.h>
#include <atomic>
#include "Input.hpp"
#include "Graphics.hpp"

class BrokenEngine2D
{
public:
	BrokenEngine2D();
	BrokenEngine2D(Graphics* t_graphics);
	BrokenEngine2D(const BrokenEngine2D&) = default;

	BrokenEngine2D& operator =(const BrokenEngine2D&) = default;

	~BrokenEngine2D();

	int createWindow(int t_width, int t_height, int t_pixelWidth, int t_pixelHeight);
	void start();

private:
	virtual void gameLoop() = 0;

protected:
	int m_screenWidth;
	int m_screenHeight;
	SMALL_RECT m_rectWindow;

	HANDLE m_hConsole;
	HANDLE m_hConsoleIn;

	CHAR_INFO *m_bufScreen;

	Input m_input;
	Graphics *m_graphics;

	std::atomic<bool> m_running;
};

#endif
