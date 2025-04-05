#include "GameBG.h"

GameBG::GameBG(std::string name, Tag tag) : AGameObject(name, tag) {

}

void GameBG::initialize() {
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("background"));
	this->sprite->setScale(sf::Vector2f(1.02f, 1.f));

	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable.setPosition((Game::WINDOW_WIDTH / 2), (Game::WINDOW_HEIGHT / 2) - 850);

	Renderer* renderer = new Renderer("BackgroundSprite");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	this->getTransformable()->setScale(2.5f, 2.5f);
}

