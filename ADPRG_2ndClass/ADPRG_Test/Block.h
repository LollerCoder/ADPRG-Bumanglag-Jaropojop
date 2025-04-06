#pragma once
#include <SFML/Graphics.hpp>
#include "AGameObject.hpp"
#include "TextureManager.hpp"
#include "CollisionListener.hpp"
#include "Game.h"
#include "Collider.hpp"
class Block : public AbstractPoolable, public CollisionListener
{



public:
	Block(std::string name, float x, float y);
	virtual void initialize();
	//collision
	void onCollisionExit(AGameObject* contact);
	void onCollisionEnter(AGameObject* contact);

	void setPos(float x, float y);
	void setColCheck(int col);
	void setInvincibility(bool invinc);
	bool getInvi();
	Collider* collider;

	void onActivate();
	void onRelease();
	AbstractPoolable* clone();

private:
	bool isInvincible = false;
	Frame frame;
	int colCheck;



};

