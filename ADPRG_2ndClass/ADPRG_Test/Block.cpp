#include "Block.h"


Block::Block(std::string name) : AGameObject(name) {

}

void Block::initialize() {
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("blocks"));

	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable.setPosition((Game::WINDOW_WIDTH / 2)+150, (Game::WINDOW_HEIGHT / 2) +170 );

	Renderer* renderer = new Renderer("BlockSprite");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	this->getTransformable()->setScale(1.0f, 1.0f);

	this->collider = new Collider("BlockCollider");

	collider->setLocalBounds(sprite->getGlobalBounds());
	this->collider->setCollisionListener(this);
	this->attachComponent(this->collider);

	PhysicsManager::getInstance()->trackObject(this->collider);
}

void Block::onCollisionExit(AGameObject* contact)
{
}

void Block::onCollisionEnter(AGameObject* contact)
{
	if (contact->getName() == "TopHitbox") {
		//this->setEnabled(false);
	}

}

