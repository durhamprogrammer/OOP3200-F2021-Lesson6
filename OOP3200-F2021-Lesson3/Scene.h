#pragma once
#ifndef __SCENE__
#define __SCENE__

#include <string>
#include <vector>

#include "DisplayObject.h"


class Scene
{
public:
	
	// CONSTRUCTORS
	Scene(const std::string& name);

	// DESTRUCTOR
	~Scene();

    // Scene Life Cycle Functions
	void draw();
	void update();

	// Getters and Setters
	std::string getName() const;
	void setName(const std::string& name);
	    
	// Display List Utility Functions
	void addChild(DisplayObject* child);
	void removeChild(DisplayObject* child);  
	void removeAllChildren();
	std::string ToString();

private:
	std::string m_name;
	std::vector<DisplayObject*> m_pDisplayList;
	
	// Scene Management Functions
	void updateDisplayList();
	void drawDisplayList();
};

#endif /* defined (__SCENE__) */