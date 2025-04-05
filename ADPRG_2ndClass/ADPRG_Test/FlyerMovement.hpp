#pragma once
#include "AbstractComponent.hpp"
#include "Flyer.hpp"

class FlyerMovement : public AbstractComponent{
public:
	FlyerMovement(std::string name);
public:
	void perform();
private:
	float fAnimThresh = 0.2f;
	float fAnimFreq = 0;
	float fAnimTimer = 0;
};

