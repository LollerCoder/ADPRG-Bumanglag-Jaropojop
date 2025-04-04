#pragma once
#include <SFML/Graphics.hpp>
#include "AGameObject.hpp"
#include "TextureManager.hpp"
#include "Game.h"
class Block : public AGameObject, public CollisionListener
{



public:
	Block(std::string name);
	virtual void initialize();
	//collision
	void onCollisionExit(AGameObject* contact);
	void onCollisionEnter(AGameObject* contact);

	Collider* collider;

private:





};

