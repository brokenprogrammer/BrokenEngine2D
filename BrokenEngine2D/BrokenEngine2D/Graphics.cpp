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

void Graphics::DrawWrapped(int t_x, int t_y, wchar_t t_char, short t_color)
{
	int x;
	int y;
	wrapScreenCoords(t_x, t_y, x, y);
	Draw(x, y, t_char, t_color);
}

//TODO: Move calculation into private function..
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

		Draw(x, y, t_char, t_color);

		length += increment;
	}
}

//TODO: Move calculation into private function..
void Graphics::DrawLineWrapped(int t_x1, int t_y1, int t_x2, int t_y2, wchar_t t_char, short t_color)
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

		DrawWrapped(x, y, t_char, t_color);

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

void Graphics::DrawWireframe(const std::vector<std::pair<float, float>> &t_wireframeModel,
	float t_x, float t_y, float t_angle, float t_scale, wchar_t t_char, short t_color)
{
	std::vector<std::pair<float, float>> transformedModel = 
		transformWireframe(t_wireframeModel, t_x, t_y, t_angle, t_scale);
	int vertices = transformedModel.size();

	// Draw
	for (int i = 0; i < vertices + 1; i++)
	{
		int j = i + 1;
		DrawLine(transformedModel[i % vertices].first, transformedModel[i % vertices].second,
			transformedModel[j % vertices].first, transformedModel[j % vertices].second,
			t_char, t_color);
	}
}

void Graphics::DrawWireframeWrapped(const std::vector<std::pair<float, float>> &t_wireframeModel,
	float t_x, float t_y, float t_angle, float t_scale, wchar_t t_char, short t_color)
{
	std::vector<std::pair<float, float>> transformedModel = 
		transformWireframe(t_wireframeModel, t_x, t_y, t_angle, t_scale);
	int vertices = transformedModel.size();

	// Draw with wrapped cordinates
	for (int i = 0; i < vertices + 1; i++)
	{
		int j = i + 1;
		DrawLineWrapped(transformedModel[i % vertices].first, transformedModel[i % vertices].second,
			transformedModel[j % vertices].first, transformedModel[j % vertices].second,
			t_char, t_color);
	}
}

void Graphics::Fill(int t_x, int t_y, int t_width, int t_height, wchar_t t_char, short t_color)
{
	int a = m_screenWidth * t_y + t_x;
	for (int i = 0; i < t_height; i++) {
		for (int j = 0; j < t_width; j++) {
			Draw(j, i, t_char, t_color);
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

std::vector<std::pair<float, float>> Graphics::transformWireframe(const std::vector<std::pair<float, float>> &t_wireframeModel,
	float t_x, float t_y, float t_angle, float t_scale)
{
	std::vector<std::pair<float, float>> transformedModel;
	int vertices = t_wireframeModel.size();
	transformedModel.resize(vertices);

	// Rotate, based on the rotation matrix
	// x1 = x * cos 0 - y * sin 0
	// y1 = x * sin 0 + y * cos 0
	for (int i = 0; i < vertices; i++)
	{
		transformedModel[i].first = t_wireframeModel[i].first * cosf(t_angle) - t_wireframeModel[i].second * sinf(t_angle);
		transformedModel[i].second = t_wireframeModel[i].first * sinf(t_angle) + t_wireframeModel[i].second * cosf(t_angle);
	}

	// Scale
	for (int i = 0; i < vertices; i++)
	{
		transformedModel[i].first = transformedModel[i].first * t_scale;
		transformedModel[i].second = transformedModel[i].second * t_scale;
	}

	// Translate position
	for (int i = 0; i < vertices; i++)
	{
		transformedModel[i].first = transformedModel[i].first + t_x;
		transformedModel[i].second = transformedModel[i].second + t_y;
	}

	return transformedModel;
}

void Graphics::wrapScreenCoords(int t_inX, int t_inY, int &t_outX, int &t_outY)
{
	t_outX = t_inX;
	t_outY = t_inY;

	if (t_inX < 0)
	{
		t_outX = t_inX + (float)m_screenWidth;
	}

	if (t_inX >= (float)m_screenWidth)
	{
		t_outX = t_inX - (float)m_screenWidth;
	}

	if (t_inY < 0)
	{
		t_outY = t_inY + (float)m_screenHeight;
	}

	if (t_inY >= (float)m_screenHeight)
	{
		t_outY = t_inY - (float)m_screenHeight;
	}
}