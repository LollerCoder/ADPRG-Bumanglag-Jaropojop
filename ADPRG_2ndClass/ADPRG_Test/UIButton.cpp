#include "UIButton.hpp"

UIButton::UIButton(std::string name, sf::Texture* normalTexture, sf::Texture* pressedTexture) : AGameObject(name, Tag::UI){
	this->normalTexture = normalTexture;
	this->pressedTexture = pressedTexture;
	this->listener = nullptr;
	this->sprite = nullptr;
}

void UIButton::initialize() {
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*this->normalTexture);
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	Renderer* renderer = new Renderer("ButtonSprite");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);
}

void UIButton::changeButtonToNormal() {
	this->sprite->setTexture(*this->normalTexture);
}

void UIButton::changeButtonToPressed() {
	this->sprite->setTexture(*this->pressedTexture);
}

sf::FloatRect UIButton::getLocalBounds() {
	return this->sprite->getLocalBounds();
}

sf::FloatRect UIButton::getGlobalBounds() {
	sf::FloatRect bounds = this->sprite->getGlobalBounds();

	bounds = this->getGlobalTransform().transformRect(bounds);

	return bounds;
}

void UIButton::setButtonListener(ButtonListener* listener) {
	this->listener = listener;
	UIButtonInputController* inputController = new UIButtonInputController("UI_InputController", this->listener);
	this->attachComponent(inputController);
}


