#pragma once
#include "AGameObject.hpp"
#include "ButtonListener.hpp"
#include "UIButton.hpp"
#include <string>
class UIBox : public AGameObject, public ButtonListener
{
public:

	UIBox(std::string name);

	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);

	//when clicked and released just pass the events here(is this lazy? probably)
	void onOption1Button();
	void onOption2Button();

	void initialize();




};

