#pragma once
#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include "Transform.h"

class GameObject
{
public:
	// CONSTRUCTORS
    GameObject(const std::string& name);
	
	// DESTRUCTOR
    ~GameObject();

	// Getters and Setters
	Transform* getTransform();
	void setTransform(const Transform& transform);
	std::string getName() const;
	void setName(const std::string& name);

	// Life Cycle Functions
	virtual void update();   
	virtual void draw();

	// Utility Functions
	virtual std::string ToString();

private:
	std::string m_name;
    Transform m_transform;
};

#endif /* defined (__GAME_OBJECT__) */