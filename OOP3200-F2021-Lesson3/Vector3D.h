#pragma once

#ifndef __VECTOR_3D__
#define __VECTOR_3D__

#include "Vector2D.h"
class Vector3D :  public Vector2D
{
public:
	Vector3D(float x, float y, float z);
	~Vector3D();

	float GetZ() const;
	void SetZ(float z);
	void Set(float x, float y, float z);

	std::string ToString() const override;

	static Vector3D Zero();

private:
	float m_z;
};

#endif /* defined (__VECTOR_3D__) */

