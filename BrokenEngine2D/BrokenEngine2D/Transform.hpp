#ifndef TRANSFORM_H 
#define TRANSFORM_H 
#pragma once 

#include "Vector2D.hpp"

class Transform
{
public:
	Transform() : position(0.0f, 0.0f), rotation(0), scale(0.0f, 0.0f) {}
	Transform(be::Vector2D<float> pos, float rot, be::Vector2D<float> scal) : position(pos), rotation(rot), scale(scal) {}

	be::Vector2D<float> position;
	float rotation;
	be::Vector2D<float> scale;

	inline float X() const
	{
		return position.x;
	}

	inline float Y() const
	{
		return position.y;
	}

	inline float Rotation() const
	{
		return rotation;
	}
	
	inline float ScaleX() const
	{
		return scale.x;
	}

	inline float ScaleY() const
	{
		return scale.y;
	}
};

#endif