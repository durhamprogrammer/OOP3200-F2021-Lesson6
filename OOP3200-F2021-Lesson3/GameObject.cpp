#include "GameObject.h"

GameObject::GameObject(const std::string& name = "unset")
{
	setName(name);
	getTransform()->scale.Set(1.0f, 1.0f);
}

GameObject::~GameObject()
= default;

std::string GameObject::getName() const
{
	return m_name;
}

void GameObject::setName(const std::string& name)
{
	m_name = name;
}

/**
 * @return Transform
 */
Transform* GameObject::getTransform()
{
    return &m_transform;
}

/**
 * @param transform
 */
void GameObject::setTransform(const Transform& transform)
{
    m_transform = transform;
}

/**
 * @return void
 */
void GameObject::update()
{
    
}

/**
 * @return void
 */
void GameObject::draw()
{

}

/**
 * @return std::string
 */
std::string GameObject::ToString()
{
	std::string output_string;

	output_string += "GameObject Name: " + getName() + "\n";
	output_string += m_transform.ToString();

	return output_string;
}