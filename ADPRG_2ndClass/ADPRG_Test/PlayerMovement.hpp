#pragma once
#include "AbstractComponent.hpp"
#include "PlayerInputController.hpp"
#include "Player.h"

class PlayerMovement : public AbstractComponent{
public:
	PlayerMovement(std::string name);
public:
	void perform();
	void setGrounded(bool flag);
private:
	const float SPEED_MULTIPLIER = 150.0f;
	const float AIR_SPEED_MULTIPLIER = 0.5f;
	float fAnimThresh = 0.1f;
	float fAnimFreq = 0;
	float fAnimSwing = 0.2f;
	float fAnimTimer = 0;
	bool isSwinging = false;
	bool isGrounded = false;
	const float GRAVITY_FORCE = 20.0f;
	const float JUMP_FORCE = 535.0f; 
	sf::Vector2f velocity = sf::Vector2f(0.0f, 0.0f);
};

