#pragma once
#include "AGameObject.hpp"
#include "ButtonListener.hpp"
#include "UIButton.hpp"
#include <string>
class MainMenuScreen : public AGameObject, public ButtonListener
{

public:

	MainMenuScreen(std::string name);

	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);

	//when clicked and released just pass the events here(is this lazy? probably)
	void onYesButton();
	void onNoButton();

	void initialize();

};

