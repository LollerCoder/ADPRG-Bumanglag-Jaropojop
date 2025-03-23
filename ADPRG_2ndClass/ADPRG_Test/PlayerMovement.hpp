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
	const float SPEED_MULTIPLIER = 200.0f;
	float fAnimThresh = 0.1f;
	float fAnimFreq = 0;
};

