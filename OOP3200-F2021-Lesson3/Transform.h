#pragma once

#ifndef __TRANSFORM__
#define __TRANSFORM__

#include "Vector2D.h"

struct Transform
{
public:
	Vector2D position;
	float rotation;
	Vector2D scale;

	std::string ToString() const;
};

#endif /* defined (__TRANSFORM__) */

