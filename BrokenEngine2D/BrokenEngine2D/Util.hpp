#ifndef UTIL_H
#define UTIL_H
#pragma once

namespace be
{
	void wrapScreenCoords(float t_inX, float t_inY, float &t_outX, float &t_outY, int t_screenW, int t_screenH)
	{
		t_outX = t_inX;
		t_outY = t_inY;

		if (t_inX < 0)
		{
			t_outX = t_inX + (float)t_screenW;
		}

		if (t_inX >= (float)t_screenW)
		{
			t_outX = t_inX - (float)t_screenW;
		}

		if (t_inY < 0)
		{
			t_outY = t_inY + (float)t_screenH;
		}

		if (t_inY >= (float)t_screenH)
		{
			t_outY = t_inY - (float)t_screenH;
		}
	}
}

#endif
