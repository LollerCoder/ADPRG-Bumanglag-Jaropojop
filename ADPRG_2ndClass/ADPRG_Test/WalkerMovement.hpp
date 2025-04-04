#pragma once
#include "AbstractComponent.hpp"
#include "Walker.h"

class WalkerMovement : public AbstractComponent {
public:
	WalkerMovement(std::string name);
public:
	void perform();
private:
	const float SPEED_MULTIPLIER = 50.0f;
	const float GRAVITY_FORCE = 9.80f;
	sf::Vector2f velocity = sf::Vector2f(0.0f, 0.0f);
};

