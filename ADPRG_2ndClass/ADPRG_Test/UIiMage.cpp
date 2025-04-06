#include "UIiMage.h"
#include "GameValue.hpp"

UIiMage::UIiMage(std::string name) : AGameObject(name, Tag::UI){

}

void UIiMage::initialize() {
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("bonus_item"));
	Frame frame = FileReader::getInstance()->getFrame("bonus_item", PlayerScore::Level % 2);

	this->sprite->setTextureRect(sf::IntRect(
											frame[0],
											frame[1],
											frame[2],
											frame[3]
										)
								);

	sf::IntRect frameRect = this->sprite->getTextureRect();
	this->sprite->setOrigin(frameRect.width / 2, frameRect.height / 2);
	this->transformable.setPosition(-70.f, -70.0f);

	Renderer* renderer = new Renderer("ItemRenderer");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	this->getTransformable()->setScale(0.8f, 0.8f);
}
