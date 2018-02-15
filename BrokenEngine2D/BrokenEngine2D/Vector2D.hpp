#ifndef VECTOR2D_H
#define VECTOR2D_H
#pragma once

namespace be {
	template<typename T>
	class Vector2D
	{
	public:
		Vector2D<T>();
		Vector2D<T>(const T& t_x, const T& t_y);

		Vector2D<T>& operator =(const Vector2D<T>&) = default;

		~Vector2D<T>();

		Vector2D<T>& add(const Vector2D<T>& t_other);
		Vector2D<T>& subtract(const Vector2D<T>& t_other);
		Vector2D<T>& multiply(const Vector2D<T>& t_other);
		Vector2D<T>& divide(const Vector2D<T>& t_other);

		Vector2D<T>& add(const T& t_other);
		Vector2D<T>& subtract(const T& t_other);
		Vector2D<T>& multiply(const T& t_other);
		Vector2D<T>& divide(const T& t_other);

		Vector2D<T>& operator +=(const Vector2D<T>& t_rhs);
		Vector2D<T>& operator +=(const T& t_rhs);

		Vector2D<T>& operator -=(const Vector2D<T>& t_rhs);
		Vector2D<T>& operator -=(const T& t_rhs);

		Vector2D<T>& operator *=(const Vector2D<T>& t_rhs);
		Vector2D<T>& operator *=(const T& t_rhs);

		Vector2D<T>& operator /=(const Vector2D<T>& t_rhs);
		Vector2D<T>& operator /=(const T& t_rhs);

		template<typename T>
		friend Vector2D<T> operator -(const Vector2D<T>& t_rhs);

		template<typename T>
		friend Vector2D<T> operator +(Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);
		
		template<typename T>
		friend Vector2D<T> operator -(Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);
		
		template<typename T>
		friend Vector2D<T> operator *(Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);
		
		template<typename T>
		friend Vector2D<T> operator /(Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);

		template<typename T>
		friend Vector2D<T> operator +(Vector2D<T>& t_lhs, const T& t_rhs);

		template<typename T>
		friend Vector2D<T> operator +(T t_lhs, const Vector2D<T>& t_rhs);
		
		template<typename T>
		friend Vector2D<T> operator -(Vector2D<T>& t_lhs, const T& t_rhs);
		
		template<typename T>
		friend Vector2D<T> operator -(T t_lhs, const Vector2D<T>& t_rhs);
		
		template<typename T>
		friend Vector2D<T> operator *(Vector2D<T>& t_lhs, const T& t_rhs);
		
		template<typename T>
		friend Vector2D<T> operator *(T t_lhs, const Vector2D<T>& t_rhs);
		
		template<typename T>
		friend Vector2D<T> operator /(Vector2D<T>& t_lhs, const T& t_rhs);
		
		template<typename T>
		friend Vector2D<T> operator /(T t_lhs, const Vector2D<T>& t_rhs);// Implemented til here

		template<typename T>
		friend bool operator ==(const Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);
		
		template<typename T>
		friend bool operator !=(const Vector2D<T>& t_lhs, const Vector2D<T>& t_rhs);

		T X() const;
		T Y() const;

		T x;
		T y;
	};

	typedef Vector2D<int> Vector2Di;
	typedef Vector2D<float> Vector2Df;
}

#endif
