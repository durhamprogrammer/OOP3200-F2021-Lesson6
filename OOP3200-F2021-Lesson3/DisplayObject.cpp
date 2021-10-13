#include "DisplayObject.h"
#include "Scene.h"

DisplayObject::DisplayObject(const std::string& name): GameObject(name)
{
    setParent(nullptr);
}

DisplayObject::~DisplayObject()
= default;

/**
 * @return void
 */
void DisplayObject::update()
{

}

/**
 * @return void
 */
void DisplayObject::draw()
{

}

/**
 * @return std::string
 */
std::string DisplayObject::ToString()
{
    std::string output_string;

    output_string += "DisplayObject Name: " + getName() + "\n";
    output_string += getTransform()->ToString() + "\n";
    output_string += (m_pParent != nullptr) ? ("Parent Scene: " + getParent()->getName()) : "Parent Scene: None";
	
    return output_string;
}



/**
 * @return Scene
 */
Scene* DisplayObject::getParent() const
{
    return m_pParent;
}

/**
 * @param scene
 */
void DisplayObject::setParent(Scene* scene)
{
    m_pParent = scene;
}