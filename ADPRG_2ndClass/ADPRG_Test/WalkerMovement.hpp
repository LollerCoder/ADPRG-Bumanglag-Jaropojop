#pragma once
#include "AbstractComponent.hpp"
#include "Walker.h"

class WalkerMovement : public AbstractComponent {
public:
	WalkerMovement(std::string name);
public:
	void perform();
	// sets grounded value
	void setGrounded(bool flag);

private:
	const float SPEED_MULTIPLIER = 80.0f; // speed value
	const float GRAVITY_FORCE = 9.80f; // gravity value
	sf::Vector2f velocity = sf::Vector2f(0.0f, 0.0f); // velocity value
	bool isGrounded = true; // grounded flag

	// for animation timer
	float fAnimThresh = 0.1f;
	float fAnimFreq = 0;
	float fAnimTimer = 0;
};

