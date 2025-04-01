#include "Block.h"


Block::Block(std::string name) : AGameObject(name) {

}

void Block::initialize() {
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("blocks"));

	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable.setPosition((Game::WINDOW_WIDTH / 2), (Game::WINDOW_HEIGHT / 2) - 100);

	Renderer* renderer = new Renderer("BlockSprite");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	this->getTransformable()->setScale(2.5f, 2.5f);
}

