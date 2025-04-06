#pragma once
#include "GenericInputController.hpp"
#include "CameraManager.hpp"
#include "UIButton.hpp"
#include "ButtonListener.hpp"
#include <iostream>
#include <string>

class UIButtonInputController : public GenericInputController {
public:
	UIButtonInputController(std::string name, ButtonListener* listener);
public:
	void perform();
private:
	bool pressed;
	ButtonListener* buttonListener;
};

