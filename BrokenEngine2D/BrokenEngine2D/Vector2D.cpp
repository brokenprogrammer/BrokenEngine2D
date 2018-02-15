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
	inline Vector2D<T>& Vector2D<T>::operator +=(const Vector2D<T>& t_rhs)
	{
		return this->add(t_rhs);
	}

	template<typename T>
	inline Vector2D<T>& Vector2D<T>::operator +=(const T& t_rhs)
	{
		return this->add(t_rhs);
	}

	template<typename T>
	inline Vector2D<T>& Vector2D<T>::operator -=(const Vector2D<T>& t_rhs)
	{
		return this->subtract(t_rhs);
	}

	template<typename T>
	inline Vector2D<T>& Vector2D<T>::operator -=(const T& t_rhs)
	{
		return this->subtract(t_rhs);
	}

	template<typename T>
	inline Vector2D<T>& Vector2D<T>::operator *=(const Vector2D<T>& t_rhs)
	{
		return this->multiply(t_rhs);
	}

	template<typename T>
	inline Vector2D<T>& Vector2D<T>::operator *=(const T& t_rhs)
	{
		return this->multiply(t_rhs);
	}
	
	template<typename T>
	inline Vector2D<T>& Vector2D<T>::operator /=(const Vector2D<T>& t_rhs)
	{
		return this->divide(t_rhs);
	}

	template<typename T>
	inline Vector2D<T>& Vector2D<T>::operator /=(const T& t_rhs)
	{
		return this->divide(t_rhs);
	}

	template<typename T>
	inline Vector2D<T> operator -(const Vector2D<T>& t_rhs)
	{
		Vector2D<T> v(-t_rhs.x, -t_rhs.y);
		return v;
	}

	template<typename T>
	inline Vector2D<T> operator +(Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs)
	{
		Vector2D<T> v(t_lhs.x + t_rhs.x, t_lhs.y + t_rhs.y);
		return v;
	}

	template<typename T>
	inline Vector2D<T> operator -(Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs)
	{
		Vector2D<T> v(t_lhs.x - t_rhs.x, t_lhs.y - t_rhs.y);
		return v;
	}

	template<typename T>
	inline Vector2D<T> operator *(Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs)
	{
		Vector2D<T> v(t_lhs.x * t_rhs.x, t_lhs.y * t_rhs.y);
		return v;
	}

	template<typename T>
	inline Vector2D<T> operator /(Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs)
	{
		Vector2D<T> v(t_lhs.x / t_rhs.x, t_lhs.y / t_rhs.y);
		return v;
	}

	template<typename T>
	inline Vector2D<T> operator +(Vector2D<T>& t_lhs, const T& t_rhs)
	{
		Vector2D<T> v(t_lhs.x, t_lhs.y);
		v.add(t_rhs);
		return v;
	}

	template<typename T>
	inline Vector2D<T> operator +(T t_lhs, const Vector2D<T>& t_rhs)
	{
		Vector2D<T> v(t_rhs.x, t_rhs.y);
		v.add(t_lhs);
		return v;
	}

	template<typename T>
	inline Vector2D<T> operator -(Vector2D<T>& t_lhs, const T& t_rhs)
	{
		Vector2D<T> v(t_lhs.x, t_lhs.y);
		v.subtract(t_rhs);
		return v;
	}

	template<typename T>
	inline Vector2D<T> operator -(T t_lhs, const Vector2D<T>& t_rhs)
	{
		Vector2D<T> v(t_rhs.x, t_rhs.y);
		v.subtract(t_lhs);
		return v;
	}

	template<typename T>
	inline Vector2D<T> operator *(Vector2D<T>& t_lhs, const T& t_rhs)
	{
		Vector2D<T> v(t_lhs.x, t_lhs.y);
		v.multiply(t_rhs);
		return v;
	}

	template<typename T>
	inline Vector2D<T> operator *(T t_lhs, const Vector2D<T>& t_rhs)
	{
		Vector2D<T> v(t_rhs.x, t_rhs.y);
		v.multiply(t_lhs);
		return v;
	}

	template<typename T>
	inline Vector2D<T> operator /(Vector2D<T>& t_lhs, const T& t_rhs)
	{
		Vector2D<T> v(t_lhs.x, t_lhs.y);
		v.divide(t_rhs);
		return v;
	}

	template<typename T>
	inline Vector2D<T> operator /(T t_lhs, const Vector2D<T>& t_rhs)
	{
		Vector2D<T> v(t_rhs.x, t_rhs.y);
		v.divide(t_lhs);
		return v;
	}

	template<typename T>
	inline bool operator ==(const Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs)
	{
		return (t_lhs.x == t_rhs.x && t_lhs.y == t_rhs.y);
	}

	template<typename T>
	inline bool operator !=(const Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs)
	{
		return !operator==(t_lhs, t_rhs);
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