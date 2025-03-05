#pragma once
#include "AGameObject.hpp"
#include "ButtonListener.hpp"
#include "UIButtonInputController.hpp"

class UIButton : public AGameObject{
public:
	UIButton(std::string name,
			 sf::Texture* normalTexture,
			 sf::Texture* pressedTexture);
public:
	void initialize();
	void changeButtonToNormal();
	void changeButtonToPressed();
	sf::FloatRect getLocalBounds();
	sf::FloatRect getGlobalBounds();
	void setButtonListener(ButtonListener* listener);
private:
	sf::Texture* normalTexture;
	sf::Texture* pressedTexture;
	sf::Sprite* sprite;
	ButtonListener* listener;

};

