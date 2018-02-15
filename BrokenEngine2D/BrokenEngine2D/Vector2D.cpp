#include "Vector2D.hpp"

namespace be
{
	template<typename T>
	inline Vector2D<T>::Vector2D() : x(0), y(0)
	{

	}

	template<typename T>
	inline Vector2D<T>::Vector2D(const T& t_x, const T& t_y) : x(t_x), y(t_y)
	{

	}

	template<typename T>
	inline Vector2D<T>::~Vector2D()
	{

	}

	template<typename T>
	inline Vector2D<T>& Vector2D<T>::add(const Vector2D& t_other)
	{
		x += t_other.x;
		y += t_other.y;
		return *this;
	}

	template<typename T>
	inline Vector2D<T>& Vector2D<T>::subtract(const Vector2D& t_other)
	{
		x -= t_other.x;
		y -= t_other.y;
		return *this;
	}

	template<typename T>
	inline Vector2D<T>& Vector2D<T>::multiply(const Vector2D& t_other)
	{
		x *= t_other.x;
		y *= t_other.y;
		return *this;
	}

	template<typename T>
	inline Vector2D<T>& Vector2D<T>::divide(const Vector2D& t_other)
	{
		x /= t_other.x;
		y /= t_other.y;
		return *this;
	}

	template<typename T>
	inline Vector2D<T>& Vector2D<T>::add(const T& t_other)
	{
		x += t_other;
		y += t_other;
		return *this;
	}

	template<typename T>
	inline Vector2D<T>& Vector2D<T>::subtract(const T& t_other)
	{
		x -= t_other;
		y -= t_other;
		return *this;
	}

	template<typename T>
	inline Vector2D<T>& Vector2D<T>::multiply(const T& t_other)
	{
		x *= t_other;
		y *= t_other;
		return *this;
	}

	template<typename T>
	inline Vector2D<T>& Vector2D<T>::divide(const T& t_other)
	{
		x /= t_other;
		y /= t_other;
		return *this;
	}

	template<typename T>
	inline T Vector2D<T>::X() const
	{
		return this->x;
	}

	template<typename T>
	inline T Vector2D<T>::Y() const
	{
		return this->y;
	}
}