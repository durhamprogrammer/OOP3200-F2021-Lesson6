#include "Vector2D.h"

#include <sstream>
#include <cmath>
#include <iostream>

Vector2D::Vector2D()
{
	Set(0.0f, 0.0f);
}

Vector2D::Vector2D(const float value)
{
	Set(value, value);
}

Vector2D::Vector2D(const float x, const float y)
{
	Set(x, y);
}

Vector2D::Vector2D(const Vector2D& vector_2d)
{
	SetX(vector_2d.GetX());
	SetY(vector_2d.GetY());
}

Vector2D::~Vector2D()
= default;

Vector2D Vector2D::operator=(const Vector2D& rhs_vector)
{
	Set(rhs_vector.GetX(), rhs_vector.GetY());
	return *this;
}

Vector2D Vector2D::operator+(const Vector2D& rhs_vector) const
{
	Vector2D temp_vector;
	temp_vector.SetX((*this).GetX() + rhs_vector.GetX());
	temp_vector.SetY((*this).GetY() + rhs_vector.GetY());
	return temp_vector;
}

Vector2D Vector2D::operator-(const Vector2D& rhs_vector) const
{
	Vector2D temp_vector;
	temp_vector.SetX((*this).GetX() - rhs_vector.GetX());
	temp_vector.SetY((*this).GetY() - rhs_vector.GetY());
	return temp_vector;
}

Vector2D Vector2D::operator*(const Vector2D& rhs_vector) const
{
	Vector2D temp_vector;
	temp_vector.SetX((*this).GetX() * rhs_vector.GetX());
	temp_vector.SetY((*this).GetY() * rhs_vector.GetY());
	return temp_vector;
}

Vector2D Vector2D::operator*(const float rhs_scalar) const
{
	Vector2D temp_vector;
	temp_vector.SetX((*this).GetX() * rhs_scalar);
	temp_vector.SetY((*this).GetY() * rhs_scalar);
	return temp_vector;
}

Vector2D operator*(const float lhs_scalar, const Vector2D& rhs_vector)
{
	Vector2D temp_vector;
	temp_vector.SetX(lhs_scalar * rhs_vector.GetX());
	temp_vector.SetY(lhs_scalar * rhs_vector.GetY());
	return temp_vector;
}

std::ostream& operator<<(std::ostream& out, const Vector2D& rhs_vector)
{
	out << rhs_vector.ToString();
	return out;
}

std::istream& operator>>(std::istream& in, Vector2D& rhs_vector)
{
	std::cout << "X: ";
	in >> rhs_vector.m_x;
	in.ignore();
	std::cout << "Y: ";
	in >> rhs_vector.m_y;
	return in;
}

float Vector2D::GetX() const
{
	return m_x;
}

float Vector2D::GetY() const
{
	return m_y;
}

void Vector2D::SetX(const float x = 0.0f)
{
	m_x = x;
}

void Vector2D::SetY(const float y = 0.0f)
{
	m_y = y;
}

void Vector2D::Set(const float x = 0.0f, const float y = 0.0f)
{
	SetX(x);
	SetY(y);
}

std::string Vector2D::ToString() const
{
	std::string output_string;
	output_string+= "(" + std::to_string(GetX()) + ", " + std::to_string(GetY()) + ")";
	return output_string;
}

float Vector2D::Distance(const Vector2D& lhs, const Vector2D& rhs)
{
	// difference between x values
	const float delta_x = rhs.GetX() - lhs.GetX();
	// difference between y values
	const float delta_y = rhs.GetY() - lhs.GetY();

	// return the result of the pythagorean formula
	return sqrt((delta_x * delta_x) + (delta_y * delta_y));
}

Vector2D Vector2D::Zero()
{
	return Vector2D(0.0f, 0.0f);
}

Vector2D Vector2D::One()
{
	return Vector2D(1.0f, 1.0f);
}

Vector2D Vector2D::Right()
{
	return Vector2D(1.0f, 0.0f);
}

Vector2D Vector2D::Left()
{
	return Vector2D(-1.0f, 0.0f);
}

Vector2D Vector2D::Up()
{
	return Vector2D(0.0f, -1.0f);
}

Vector2D Vector2D::Down()
{
	return Vector2D(0.0f, 1.0f);
}


