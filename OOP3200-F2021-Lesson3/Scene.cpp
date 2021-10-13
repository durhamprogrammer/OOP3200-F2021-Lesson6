#include "Scene.h"

#include <iostream>

Scene::Scene(const std::string& name)
{
    setName(name);
}

Scene::~Scene()
= default;

std::string Scene::getName() const
{
    return m_name;
}

void Scene::setName(const std::string& name)
{
    m_name = name;
}

/**
 * @return void
 */
void Scene::draw()
{
    drawDisplayList();
}

/**
 * @return void
 */
void Scene::update()
{
    updateDisplayList();
}

/**
 * @param child
 * @return void
 */
void Scene::addChild(DisplayObject* child)
{
    child->setParent(this);
    m_pDisplayList.push_back(child);
}

/**
 * @param child
 * @return void
 */
void Scene::removeChild(DisplayObject* child)
{
    //delete child;
    m_pDisplayList.erase(std::remove(m_pDisplayList.begin(), m_pDisplayList.end(), child), m_pDisplayList.end());
    child->setParent(nullptr);
}

/**
 * @return void
 */
void Scene::removeAllChildren()
{
	for (auto display_object : m_pDisplayList)
	{
        display_object->setParent(nullptr);
	}
	
    m_pDisplayList.clear();
}

std::string Scene::ToString()
{
    std::string output_string;
    output_string += "The " + getName() + " scene contains: \n";
    output_string += "=========================================\n";
    for (auto display_object : m_pDisplayList)
    {
        output_string += display_object->getName() + "\n";
    }

    return output_string;
}

/**
 * @return void
 */
void Scene::updateDisplayList()
{
	for (auto display_object : m_pDisplayList)
	{
        display_object->update();
	}
}

/**
 * @return void
 */
void Scene::drawDisplayList()
{
    for (auto display_object : m_pDisplayList)
    {
        display_object->draw();
    }
}