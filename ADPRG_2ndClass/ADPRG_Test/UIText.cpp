#include "UIText.hpp"

UIText::UIText(std::string name) : AGameObject(name){
	this->text = new sf::Text();
}

void UIText::initialize() {
	sf::Font* font = FontManager::getInstance()->getFont("default");
	this->text->setFont(*font);
	this->text->setFillColor(sf::Color::White);
	this->text->setOutlineColor(sf::Color::Black);
	this->text->setOutlineThickness(4.0f);
	this->setSize(40);
	this->setText("<Using placeholder!>");

	Renderer* renderer = new Renderer("TextSprite");
	renderer->assignDrawable(text);
	this->attachComponent(renderer);
}

void UIText::setSize(unsigned int size) {
	this->text->setCharacterSize(size);
}

void UIText::setText(std::string text) {
	this->text->setString(text);
	sf::FloatRect bounds = this->text->getLocalBounds();
	this->text->setOrigin(bounds.width / 2, bounds.height / 2);
}

std::string UIText::getText() {
	return this->text->getString();
}
