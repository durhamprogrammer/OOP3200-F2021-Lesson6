#pragma once

#ifndef __TRANSFORM__
#define __TRANSFORM__

#include "Vector2D.h"

template <class T>
struct Transform
{
public:
	Vector2D<T> position;
	T rotation = static_cast<T>(0.0f);
	Vector2D<T> scale;

	std::string ToString() const;
};

template <class T>
std::string Transform<T>::ToString() const
{
	std::string output_string;

	output_string += "Position  : " + position.ToString() + "\n";
	output_string += "Z Rotation: " + std::to_string(rotation) + "\n";
	output_string += "Scale     : " + scale.ToString();

	return output_string;
}


#endif /* defined (__TRANSFORM__) */

