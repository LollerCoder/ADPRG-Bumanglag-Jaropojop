#pragma once
#include "AbstractComponent.hpp"
#include "Flyer.hpp"
#include "GameObjectManager.hpp"

// the movement component for the flyer (bird)

class FlyerMovement : public AbstractComponent{
public:
	FlyerMovement(std::string name);
public:
	void perform();
private:
	// for animation 
	float fAnimThresh = 0.2f;
	float fAnimFreq = 0;
	float fAnimTimer = 0;

	// delay for finding target
	float findPlayerCD = 5.0f;
	float timer = 0.0f;

	bool moving = false;
	bool fastMode = false;

	// speed value
	const float SPEED_MULTIPLIER = 50.0f;


	sf::Vector2f targetPos;
	sf::Vector2f pos;
};

