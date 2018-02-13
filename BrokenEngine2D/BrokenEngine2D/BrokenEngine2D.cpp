#include "BrokenEngine2D.hpp"
#include <thread>
#include <chrono>

BrokenEngine2D::BrokenEngine2D() : m_screenWidth(80), m_screenHeight(30), 
	m_hConsole(GetStdHandle(STD_OUTPUT_HANDLE)), m_hConsoleIn(GetStdHandle(STD_INPUT_HANDLE)), 
	m_input(m_hConsoleIn)
{
}

BrokenEngine2D::~BrokenEngine2D()
{
	delete[] m_bufScreen;
}

int BrokenEngine2D::createWindow(int t_width, int t_height, int t_pixelWidth, int t_pixelHeight)
{
	if (this->m_hConsole == INVALID_HANDLE_VALUE)
	{
		return ERROR("BAD HANDLE");
	}

	this->m_screenWidth = t_width;
	this->m_screenHeight = t_height;

	this->m_rectWindow = { 0, 0, 1, 1 };
	SetConsoleWindowInfo(this->m_hConsole, TRUE, &this->m_rectWindow);

	COORD screenSize = { (short)m_screenWidth, (short)m_screenHeight };

	if (!SetConsoleScreenBufferSize(this->m_hConsole, screenSize))
	{
		return ERROR("Invalid Buffer Size");
	}

	if (!SetConsoleActiveScreenBuffer(this->m_hConsole))
	{
		return ERROR("Invalid Buffer Size");
	}

	//TODO: SET FONT SIZE, SET TO THE FONT I WANT
	// Set the font size now that the screen buffer has been assigned to the console
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = t_pixelWidth;
	cfi.dwFontSize.Y = t_pixelHeight;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");
	if (!SetCurrentConsoleFontEx(m_hConsole, false, &cfi))
	{
		return ERROR(L"SetCurrentConsoleFontEx");
	}

	// Get screen buffer info & check if window size exceeds max etc.. TODO: BETTER DOCS
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	
	if (!GetConsoleScreenBufferInfo(m_hConsole, &csbi))
	{
		return ERROR(L"GetConsoleScreenBufferInfo");
	}

	if (m_screenHeight > csbi.dwMaximumWindowSize.Y)
	{
		return ERROR(L"Screen Height / Font Height Too Big");
	}

	if (m_screenWidth > csbi.dwMaximumWindowSize.X)
	{
		return ERROR(L"Screen Width / Font Width Too Big");
	}

	// Set physical console size..
	this->m_rectWindow = { 0, 0, (short)m_screenWidth - 1, (short)m_screenHeight - 1 };
	if (!SetConsoleWindowInfo(this->m_hConsole, TRUE, &this->m_rectWindow))
	{
		return ERROR(L"SetConsoleWindowInfo");
	}

	// Set flags to allow mouse input		
	if (!SetConsoleMode(m_hConsoleIn, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT))
	{
		return ERROR(L"SetConsoleMode");
	}
  
	// allocate memory for screen buffer
	m_bufScreen = new CHAR_INFO[m_screenWidth*m_screenHeight];
	memset(m_bufScreen, 0, sizeof(CHAR_INFO) * m_screenWidth * m_screenHeight);

	return 0;
}

void BrokenEngine2D::start()
{
	m_running = true;

	// Set screen buffer for Graphics.
	g.SetBuffer(m_bufScreen, m_screenWidth, m_screenHeight);

	// Start game thread
	std::thread t = std::thread(&BrokenEngine2D::gameLoop, this);

	// Wait for thread to finish
	t.join();
}

void BrokenEngine2D::gameLoop()
{
	if (!onCreate())
	{
		m_running = false;
	}

	auto t1 = std::chrono::system_clock::now();
	auto t2 = std::chrono::system_clock::now();

	while (m_running)
	{
		// Retrieve elapsed time duration.
		t2 = std::chrono::system_clock::now();
		std::chrono::duration<float> deltaTime = t2 - t1;
		t1 = t2;

		float elapsedTime = deltaTime.count();

		// Poll for input.
		m_input.poll();

		// Handle updates
		if (!onUpdate(this->m_input, elapsedTime))
		{
			m_running = false;
		}

		// Handle rendering
		if (!onRender(g))
		{
			m_running = false;
		}

		// Render screen buffer..
		wchar_t s[256];
		swprintf_s(s, 256, L"BrokenEngine2D FPS: %3.2f MOUSEX: %i MOUSEY: %i ", (1.0f / elapsedTime), this->m_input.getMouseX(), this->m_input.getMouseY());
		SetConsoleTitle(s);
		WriteConsoleOutput(m_hConsole, m_bufScreen, {(short)m_screenWidth, (short)m_screenHeight}, {0, 0}, &m_rectWindow);
	}
}