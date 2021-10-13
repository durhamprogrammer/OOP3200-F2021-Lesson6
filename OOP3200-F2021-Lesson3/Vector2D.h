#pragma once
#ifndef __VECTOR_2D__
#define __VECTOR_2D__

#include <string>
#include <iostream>

template <class T>
class Vector2D
{
public:
	// CONSTRUCTOR(S)
	Vector2D();
	Vector2D(T value);
	Vector2D(T x, T y);

	// COPY CONSTRUCTOR
	Vector2D(const Vector2D& vector_2d);

	// DESTRUCTOR
	~Vector2D();

	// OPERATOR OVERRIDES
	Vector2D operator=(const Vector2D& rhs_vector);
	Vector2D operator+(const Vector2D& rhs_vector) const;
	Vector2D operator-(const Vector2D& rhs_vector) const;

	Vector2D operator*(const Vector2D& rhs_vector) const;
	Vector2D operator*(const T rhs_scalar) const;

	// FRIEND OVERLOADS
	friend Vector2D operator*(const T lhs_scalar, const Vector2D& rhs_vector)
	{
		Vector2D<T> temp_vector;
		temp_vector.SetX(lhs_scalar * rhs_vector.GetX());
		temp_vector.SetY(lhs_scalar * rhs_vector.GetY());
		return temp_vector;
	}

	friend std::ostream& operator<<(std::ostream& out, const Vector2D& rhs_vector)
	{
		out << rhs_vector.ToString();
		return out;
	}
	
	friend std::istream& operator>>(std::istream& in, Vector2D& rhs_vector)
	{
		std::cout << "X: ";
		in >> rhs_vector.m_x;
		in.ignore();
		std::cout << "Y: ";
		in >> rhs_vector.m_y;
		return in;
	}


	// GETTERS (Accessors)
	T GetX() const;
	T GetY() const;

	// SETTERS (Mutators)
	void SetX(T x);
	void SetY(T y);
	void Set(T x, T y);

	// PUBLIC METHODS (Public Class Functions)
	virtual std::string ToString() const;

	// PUBLIC STATIC METHODS (Public Class Functions that are Static)
	static T Distance(const Vector2D& lhs, const Vector2D& rhs);

	// Static Utility functions
	static Vector2D Zero();
	static Vector2D One();
	static Vector2D Right();
	static Vector2D Left();
	static Vector2D Up();
	static Vector2D Down();

private:
	// INSTANCE VARIABLES (Class Member Variables)
	T m_x;
	T m_y;

	// PRIVATE METHODS (Private Class Functions)
};

template <class T>
Vector2D<T>::Vector2D()
{
	Set(static_cast<T>(0.0f), static_cast<T>(0.0f));
}

template <class T>
Vector2D<T>::Vector2D(const T value)
{
	Set(value, value);
}

template <class T>
Vector2D<T>::Vector2D(const T x, const T y)
{
	Set(x, y);
}

template <class T>
Vector2D<T>::Vector2D(const Vector2D& vector_2d)
{
	SetX(vector_2d.GetX());
	SetY(vector_2d.GetY());
}

template <class T>
Vector2D<T>::~Vector2D()
= default;

template <class T>
Vector2D<T> Vector2D<T>::operator=(const Vector2D& rhs_vector)
{
	Set(rhs_vector.GetX(), rhs_vector.GetY());
	return *this;
}

template <class T>
Vector2D<T> Vector2D<T>::operator+(const Vector2D& rhs_vector) const
{
	Vector2D<T> temp_vector;
	temp_vector.SetX((*this).GetX() + rhs_vector.GetX());
	temp_vector.SetY((*this).GetY() + rhs_vector.GetY());
	return temp_vector;
}

template <class T>
Vector2D<T> Vector2D<T>::operator-(const Vector2D& rhs_vector) const
{
	Vector2D<T> temp_vector;
	temp_vector.SetX((*this).GetX() - rhs_vector.GetX());
	temp_vector.SetY((*this).GetY() - rhs_vector.GetY());
	return temp_vector;
}

template <class T>
Vector2D<T> Vector2D<T>::operator*(const Vector2D& rhs_vector) const
{
	Vector2D<T> temp_vector;
	temp_vector.SetX((*this).GetX() * rhs_vector.GetX());
	temp_vector.SetY((*this).GetY() * rhs_vector.GetY());
	return temp_vector;
}

template <class T>
Vector2D<T> Vector2D<T>::operator*(const T rhs_scalar) const
{
	Vector2D<T> temp_vector;
	temp_vector.SetX((*this).GetX() * rhs_scalar);
	temp_vector.SetY((*this).GetY() * rhs_scalar);
	return temp_vector;
}

template <class T>
T Vector2D<T>::GetX() const
{
	return m_x;
}

template <class T>
T Vector2D<T>::GetY() const
{
	return m_y;
}

template <class T>
void Vector2D<T>::SetX(const T x)
{
	m_x = x;
}

template <class T>
void Vector2D<T>::SetY(const T y)
{
	m_y = y;
}

template <class T>
void Vector2D<T>::Set(const T x, const T y)
{
	SetX(x);
	SetY(y);
}

template <class T>
std::string Vector2D<T>::ToString() const
{
	std::string output_string;
	output_string += "(" + std::to_string(GetX()) + ", " + std::to_string(GetY()) + ")";
	return output_string;
}

template <class T>
T Vector2D<T>::Distance(const Vector2D & lhs, const Vector2D & rhs)
{
	// difference between x values
	const float delta_x = rhs.GetX() - lhs.GetX();
	// difference between y values
	const float delta_y = rhs.GetY() - lhs.GetY();

	// return the result of the pythagorean formula
	return sqrt((delta_x * delta_x) + (delta_y * delta_y));
}

template <class T>
Vector2D<T> Vector2D<T>::Zero()
{
	return Vector2D(0.0f, 0.0f);
}

template <class T>
Vector2D<T> Vector2D<T>::One()
{
	return Vector2D(1.0f, 1.0f);
}

template <class T>
Vector2D<T> Vector2D<T>::Right()
{
	return Vector2D(1.0f, 0.0f);
}

template <class T>
Vector2D<T> Vector2D<T>::Left()
{
	return Vector2D(-1.0f, 0.0f);
}

template <class T>
Vector2D<T> Vector2D<T>::Up()
{
	return Vector2D(0.0f, -1.0f);
}

template <class T>
Vector2D<T> Vector2D<T>::Down()
{
	return Vector2D(0.0f, 1.0f);
}

#endif /* defined (__VECTOR_2D__) */