#pragma once
#ifndef __VECTOR_2D__
#define __VECTOR_2D__

#include <string>

class Vector2D
{
public:
	// CONSTRUCTOR(S)
	Vector2D();
	Vector2D(float value);
	Vector2D(float x, float y);

	// COPY CONSTRUCTOR
	Vector2D(const Vector2D& vector_2d);

	// DESTRUCTOR
	~Vector2D();

	// OPERATOR OVERRIDES
	Vector2D operator=(const Vector2D& rhs_vector);
	Vector2D operator+(const Vector2D& rhs_vector) const;
	Vector2D operator-(const Vector2D& rhs_vector) const;

	Vector2D operator*(const Vector2D& rhs_vector) const;
	Vector2D operator*(const float rhs_scalar) const;

	// FRIEND OVERLOADS
	friend Vector2D operator*(const float lhs_scalar, const Vector2D& rhs_vector);

	friend std::ostream& operator<<(std::ostream& out, const Vector2D& rhs_vector);
	friend std::istream& operator>>(std::istream& in, Vector2D& rhs_vector);

	// GETTERS (Accessors)
	float GetX() const;
	float GetY() const;

	// SETTERS (Mutators)
	void SetX(float x);
	void SetY(float y);
	void Set(float x, float y);

	// PUBLIC METHODS (Public Class Functions)
	virtual std::string ToString() const;

	// PUBLIC STATIC METHODS (Public Class Functions that are Static)
	static float Distance(const Vector2D& lhs, const Vector2D& rhs);

	// Static Utility functions
	static Vector2D Zero();
	static Vector2D One();
	static Vector2D Right();
	static Vector2D Left();
	static Vector2D Up();
	static Vector2D Down();

private:
	// INSTANCE VARIABLES (Class Member Variables)
	float m_x;
	float m_y;

	// PRIVATE METHODS (Private Class Functions)
};

#endif /* defined (__VECTOR_2D__) */