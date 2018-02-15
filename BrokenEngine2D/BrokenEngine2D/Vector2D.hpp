#ifndef VECTOR2D_H
#define VECTOR2D_H
#pragma once

namespace be
{

	template<typename T>
	class Vector2D
	{
	public:
		Vector2D();
		Vector2D(const T& t_x, const T& t_y);

		Vector2D& operator =(const Vector2D&) = default;

		~Vector2D();

		Vector2D& add(const Vector2D& t_other);
		Vector2D& subtract(const Vector2D& t_other);
		Vector2D& multiply(const Vector2D& t_other);
		Vector2D& divide(const Vector2D& t_other);

		Vector2D& add(const T& t_other);
		Vector2D& subtract(const T& t_other);
		Vector2D& multiply(const T& t_other);
		Vector2D& divide(const T& t_other);

		T X() const;
		T Y() const;

		T x;
		T y;
	};

	template<typename T>
	Vector2D<T> operator +(Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);
	
	template<typename T>
	Vector2D<T> operator -(Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);
	
	template<typename T>
	Vector2D<T> operator *(Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);
	
	template<typename T>
	Vector2D<T> operator /(Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);

	template<typename T>
	bool operator ==(const Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);
	
	template<typename T>
	bool operator !=(const Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);

	template<typename T>
	Vector2D<T> operator +(const Vector2D<T>& t_lhs, const T& t_rhs);
	
	template<typename T>
	Vector2D<T> operator +(const T& t_rhs, const Vector2D<T>& t_lhs);

	template<typename T>
	Vector2D<T> operator -(const Vector2D<T>& t_lhs, const T& t_rhs);
	
	template<typename T>
	Vector2D<T> operator -(const T& t_rhs, const Vector2D<T>& t_lhs);

	template<typename T>
	Vector2D<T> operator *(const Vector2D<T>& t_lhs, const T& t_rhs);
	
	template<typename T>
	Vector2D<T> operator *(const T& t_rhs, const Vector2D<T>& t_lhs);

	template<typename T>
	Vector2D<T> operator /(const Vector2D<T>& t_lhs, const T& t_rhs);
	
	template<typename T>
	Vector2D<T> operator /(const T& t_rhs, const Vector2D<T>& t_lhs);

	template<typename T>
	Vector2D<T>& operator +=(const Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);

	template<typename T>
	Vector2D<T>& operator +=(const Vector2D<T>& t_lhs, const T& t_rhs);
	
	template<typename T>
	Vector2D<T>& operator -=(const Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);

	template<typename T>
	Vector2D<T>& operator -=(const Vector2D<T>& t_lhs, const T& t_rhs);
	
	template<typename T>
	Vector2D<T>& operator *=(const Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);

	template<typename T>
	Vector2D<T>& operator *=(const Vector2D<T>& t_lhs, const T& t_rhs);
	
	template<typename T>
	Vector2D<T>& operator /=(const Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);

	template<typename T>
	Vector2D<T>& operator /=(const Vector2D<T>& t_lhs, const T& t_rhs);

	template<typename T>
	T Dot(const Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);
	
	template<typename T>
	T Cross(const Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);

	typedef Vector2D<int> Vector2Di;
	typedef Vector2D<float> Vector2Df;
}

#endif
