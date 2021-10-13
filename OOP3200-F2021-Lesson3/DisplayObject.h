#pragma once
#ifndef __DISPLAY_OBJECT__
#define __DISPLAY_OBJECT__

#include "GameObject.h"

class DisplayObject: public GameObject {
public:
	friend class Scene;
	// CONSTRUCTORS
	DisplayObject(const std::string& name);
	
	// DESTRUCTOR
	~DisplayObject();
	
    void update() override;
	void draw() override;
	std::string ToString() override;

	// Getters and Setters

	Scene* getParent() const;
	void setParent(Scene* scene);

private:
    Scene* m_pParent;
};

#endif /* defined (__DISPLAY_OBJECT__) */