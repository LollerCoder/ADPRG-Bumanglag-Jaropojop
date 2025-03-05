#pragma once
#include <iostream>
#include "GenericInputController.hpp"
class PlayerInputController : public GenericInputController{
public:
	PlayerInputController(std::string name);
	~PlayerInputController();
public:
	void perform();
public:
	bool isUp();
	bool isDown();
	bool isLeft();
	bool isRight();
private:
	const float SPEED_MULTIPLIER = 300.0f;
	bool moveUp = false;
	bool moveDown = false;
	bool moveLeft = false;
	bool moveRight = false;
};

