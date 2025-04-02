#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "AGameObject.hpp"
#include "TextureManager.hpp"
#include "AbstractPoolable.hpp"
#include "Game.h"
#include "Collider.hpp"
#include "CollisionListener.hpp"
class Walker : public AbstractPoolable , public CollisionListener
{
public:
	Walker(std::string name);

	virtual void initialize();

	void onActivate();
	void onRelease();
	AbstractPoolable* clone();

	//collision
	void onCollisionExit(AGameObject* contact);
	void onCollisionEnter(AGameObject* contact);

	Collider* collider;
};

