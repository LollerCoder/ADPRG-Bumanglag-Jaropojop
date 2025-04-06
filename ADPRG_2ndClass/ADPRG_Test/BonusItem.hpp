#pragma once
#include "AGameObject.hpp"
#include "Collider.hpp"
#include "CollisionListener.hpp"
#include "TextureManager.hpp"
#include "FileReader.hpp"
#include "Game.h"

class BonusItem : public AGameObject, public CollisionListener{
public:
	BonusItem(std::string name);
public:
	void initialize();
	void onCollisionEnter(AGameObject* gameObject);
	void onCollisionExit(AGameObject* gameObject);
private:
	Collider* collider;
	Frame frame;
};

