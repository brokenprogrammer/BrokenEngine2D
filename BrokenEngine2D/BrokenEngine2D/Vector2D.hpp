#ifndef VECTOR2D_H
#define VECTOR2D_H
#pragma once

namespace be {
	template<typename T>
	class Vector2D
	{
	public:
		inline Vector2D<T>() : x(0), y(0) {}
		inline Vector2D<T>(const T& t_x, const T& t_y) : x(t_x), y(t_y) {}

		inline Vector2D<T>& operator =(const Vector2D<T>&) = default;

		inline ~Vector2D<T>() {}

		inline Vector2D<T>& add(const Vector2D<T>& t_other)
		{
			x += t_other.x;
			y += t_other.y;
			return *this;
		}

		inline Vector2D<T>& subtract(const Vector2D<T>& t_other)
		{
			x -= t_other.x;
			y -= t_other.y;
			return *this;
		}

		inline Vector2D<T>& multiply(const Vector2D<T>& t_other)
		{
			x *= t_other.x;
			y *= t_other.y;
			return *this;
		}

		inline Vector2D<T>& divide(const Vector2D<T>& t_other)
		{
			x /= t_other.x;
			y /= t_other.y;
			return *this;
		}

		inline Vector2D<T>& add(const T& t_other)
		{
			x += t_other;
			y += t_other;
			return *this;
		}

		inline Vector2D<T>& subtract(const T& t_other)
		{
			x -= t_other;
			y -= t_other;
			return *this;
		}

		inline Vector2D<T>& multiply(const T& t_other)
		{
			x *= t_other;
			y *= t_other;
			return *this;
		}

		inline Vector2D<T>& divide(const T& t_other)
		{
			x /= t_other;
			y /= t_other;
			return *this;
		}

		inline Vector2D<T>& operator +=(const Vector2D<T>& t_rhs)
		{
			return this->add(t_rhs);
		}

		inline Vector2D<T>& operator +=(const T& t_rhs)
		{
			return this->add(t_rhs);
		}

		inline Vector2D<T>& operator -=(const Vector2D<T>& t_rhs)
		{
			return this->subtract(t_rhs);
		}

		inline Vector2D<T>& operator -=(const T& t_rhs)
		{
			return this->subtract(t_rhs);
		}

		inline Vector2D<T>& operator *=(const Vector2D<T>& t_rhs)
		{
			return this->multiply(t_rhs);
		}

		inline Vector2D<T>& operator *=(const T& t_rhs)
		{
			return this->multiply(t_rhs);
		}

		inline Vector2D<T>& operator /=(const Vector2D<T>& t_rhs)
		{
			return this->divide(t_rhs);
		}

		inline Vector2D<T>& operator /=(const T& t_rhs)
		{
			return this->divide(t_rhs);
		}

		inline friend Vector2D<T> operator -(const Vector2D<T>& t_rhs)
		{
			Vector2D<T> v(-t_rhs.x, -t_rhs.y);
			return v;
		}

		inline friend Vector2D<T> operator +(Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs)
		{
			Vector2D<T> v(t_lhs.x + t_rhs.x, t_lhs.y + t_rhs.y);
			return v;
		}
		
		inline friend Vector2D<T> operator -(Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs)
		{
			Vector2D<T> v(t_lhs.x - t_rhs.x, t_lhs.y - t_rhs.y);
			return v;
		}
		
		inline friend Vector2D<T> operator *(Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs)
		{
			Vector2D<T> v(t_lhs.x * t_rhs.x, t_lhs.y * t_rhs.y);
			return v;
		}

		
		inline friend Vector2D<T> operator /(Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs)
		{
			Vector2D<T> v(t_lhs.x / t_rhs.x, t_lhs.y / t_rhs.y);
			return v;
		}

		inline friend Vector2D<T> operator +(Vector2D<T>& t_lhs, const T& t_rhs)
		{
			Vector2D<T> v(t_lhs.x, t_lhs.y);
			v.add(t_rhs);
			return v;
		}

		inline friend Vector2D<T> operator +(T t_lhs, const Vector2D<T>& t_rhs)
		{
			Vector2D<T> v(t_rhs.x, t_rhs.y);
			v.add(t_lhs);
			return v;
		}
		
		inline friend Vector2D<T> operator -(Vector2D<T>& t_lhs, const T& t_rhs)
		{
			Vector2D<T> v(t_lhs.x, t_lhs.y);
			v.subtract(t_rhs);
			return v;
		}
		
		inline friend Vector2D<T> operator -(T t_lhs, const Vector2D<T>& t_rhs)
		{
			Vector2D<T> v(t_rhs.x, t_rhs.y);
			v.subtract(t_lhs);
			return v;
		}
		
		inline friend Vector2D<T> operator *(Vector2D<T>& t_lhs, const T& t_rhs)
		{
			Vector2D<T> v(t_lhs.x, t_lhs.y);
			v.multiply(t_rhs);
			return v;
		}
		
		inline friend Vector2D<T> operator *(T t_lhs, const Vector2D<T>& t_rhs)
		{
			Vector2D<T> v(t_rhs.x, t_rhs.y);
			v.multiply(t_lhs);
			return v;
		}
		
		inline friend Vector2D<T> operator /(Vector2D<T>& t_lhs, const T& t_rhs)
		{
			Vector2D<T> v(t_lhs.x, t_lhs.y);
			v.divide(t_rhs);
			return v;
		}
		
		inline friend Vector2D<T> operator /(T t_lhs, const Vector2D<T>& t_rhs)
		{
			Vector2D<T> v(t_rhs.x, t_rhs.y);
			v.divide(t_lhs);
			return v;
		}

		inline friend bool operator ==(const Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs)
		{
			return (t_lhs.x == t_rhs.x && t_lhs.y == t_rhs.y);
		}
		
		inline friend bool operator !=(const Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs)
		{
			return !operator==(t_lhs, t_rhs);
		}

		inline T X() const
		{
			return this->x;
		}

		inline T Y() const
		{
			return this->y;
		}

		T x;
		T y;
	};

	typedef Vector2D<int> Vector2Di;
	typedef Vector2D<float> Vector2Df;
}

#endif
