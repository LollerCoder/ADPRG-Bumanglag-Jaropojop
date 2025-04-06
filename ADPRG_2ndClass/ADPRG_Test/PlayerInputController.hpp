#pragma once
#include <iostream>
#include "GenericInputController.hpp"
#include "UIBoxMover.hpp"

class PlayerInputController : public GenericInputController{
public:
	PlayerInputController(std::string name);
	~PlayerInputController();
public:
	void perform();
public:
	bool isLeft();
	bool isRight();
	bool isAttack();
	bool isJump();
	bool isPause();
private:
	bool moveLeft = false;
	bool moveRight = false;
	bool movePick = false;
	bool moveJump = false;
	bool Pause = false;
	
};

