#include "Vector3D.h"

Vector3D::Vector3D(const float x = 0.0f, const float y = 0.0f, const float z = 0.0f)
{
	Set(x, y, z);
}

Vector3D::~Vector3D()
= default;

float Vector3D::GetZ() const
{
	return m_z;
}

void Vector3D::SetZ(const float z)
{
	m_z = z;
}

void Vector3D::Set(const float x, const float y, const float z)
{
	SetX(x);
	SetY(y);
	SetZ(z);
}

std::string Vector3D::ToString() const
{
	std::string output_string;
	output_string += "(" + std::to_string(GetX()) + ", " + std::to_string(GetY()) + ", " + std::to_string(GetZ()) + ")";
	return output_string;
}

Vector3D Vector3D::Zero()
{
	return Vector3D(0.0f, 0.0f, 0.0f);
}
