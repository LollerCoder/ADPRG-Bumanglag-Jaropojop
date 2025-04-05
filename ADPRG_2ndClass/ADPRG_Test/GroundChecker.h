#pragma once
#include "Game.h"
#include "AGameObject.hpp"
#include "TextureManager.hpp"
#include "PlayerInputController.hpp"
#include "PlayerMovement.hpp"
#include "Renderer.hpp"
#include "FileReader.hpp"
#include "CollisionListener.hpp"
#include "Collider.hpp"
#include "WalkerMovement.hpp"


class GroundChecker : public AGameObject, public CollisionListener
{
public:

	GroundChecker(std::string name, float width, float height);
public:
	void initialize();

	//collision
	void onCollisionExit(AGameObject* contact);
	void onCollisionEnter(AGameObject* contact);

	//onOff
	void activate();
	void deactivate();

public:
	float inside = 0;
	float width;
	float height;
	Collider* collider;

};

