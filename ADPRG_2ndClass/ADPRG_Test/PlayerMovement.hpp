#pragma once
#include "AbstractComponent.hpp"
#include "PlayerInputController.hpp"
#include "Player.h"

class PlayerMovement : public AbstractComponent{
public:
	PlayerMovement(std::string name);
public:
	void perform();
private:
	const float SPEED_MULTIPLIER = 300.0f;
	//const float BULLET_SPAWN_INTERVAL = 2.0f;
	const float BULLET_SPAWN_INTERVAL = 0.1f;
	float ticks = 0.0f;
	GameObjectPool* projectilePool;
};

