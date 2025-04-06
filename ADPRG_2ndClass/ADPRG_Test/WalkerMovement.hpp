#pragma once
#include "AbstractComponent.hpp"
#include "Walker.h"

class WalkerMovement : public AbstractComponent {
public:
	WalkerMovement(std::string name);
public:
	void perform();

	void setGrounded(bool flag);

private:
	const float SPEED_MULTIPLIER = 80.0f;
	const float GRAVITY_FORCE = 9.80f;
	sf::Vector2f velocity = sf::Vector2f(0.0f, 0.0f);
	bool isGrounded = true;

	float fAnimThresh = 0.1f;
	float fAnimFreq = 0;
	float fAnimTimer = 0;
	bool updatedCP = false;
public:
	bool isMoving = false;
};

