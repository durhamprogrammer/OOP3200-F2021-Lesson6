/*
 * Author: Tom Tsiliopoulos
 * StudentID: 100100100
 *
 * Date: October 13, 2021
 * Description: Demo Project for OOP3200 - F2021 - Week 6
 * 
 */

#include <iostream>
#include <vector>

#include "Scene.h"

int main()
{
	auto mainScene = new Scene("Main");

	auto player = new DisplayObject("player");
	player->getTransform()->position.Set(10.0f, 20.0f);
	mainScene->addChild(player);

	auto enemy = new DisplayObject("enemy");
	enemy->getTransform()->position.Set(20.0f, 30.0f);
	mainScene->addChild(enemy);
	
	std::cout << "\n----------------------" << std::endl;
	std::cout << player->ToString() << std::endl;
	
	std::cout << "\n----------------------" << std::endl;
	std::cout << enemy->ToString() << std::endl;

	std::cout << "\n----------------------" << std::endl;
	std::cout << mainScene->ToString() << std::endl;

	mainScene->removeAllChildren();

	std::cout << player->ToString() << std::endl;
	std::cout << enemy->ToString() << std::endl;
}


