#include "UIText.hpp"

UIText::UIText(std::string name, std::string fontTag, sf::Color colFil, sf::Color outFil) : AGameObject(name) {
	this->text = new sf::Text();
	this->font = FontManager::getInstance()->getFont(fontTag);
	this->text->setFillColor(colFil);
	this->text->setOutlineColor(outFil);
}

void UIText::initialize() {
	//this->font = FontManager::getInstance()->getFont("ice");
	this->text->setFont(*font);
	
	
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
	//std::cout << text << std::endl;
}





std::string UIText::getText() {
	return this->text->getString();
}
