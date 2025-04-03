#include "Walker.h"

Walker::Walker(std::string name) : AbstractPoolable(name)
{

}

void Walker::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Walker"));

	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable.setPosition((Game::WINDOW_WIDTH / 2)+50, (Game::WINDOW_HEIGHT / 2) + 200);

	Renderer* renderer = new Renderer("WalkerSprite");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	this->getTransformable()->setScale(1.0f, 1.0f);

	this->collider = new Collider("WalkerCollider");

	collider->setLocalBounds(sprite->getGlobalBounds());
	this->collider->setCollisionListener(this);
	this->attachComponent(this->collider);
}

void Walker::onActivate()
{
	PhysicsManager::getInstance()->trackObject(this->collider);

}

void Walker::onRelease()
{
	PhysicsManager::getInstance()->untrackObject(this->collider);
}

AbstractPoolable* Walker::clone()
{
	AbstractPoolable* cloned = new Walker(this->name);
	return cloned;
}

void Walker::onCollisionExit(AGameObject* contact)
{
}

void Walker::onCollisionEnter(AGameObject* contact)
{
	//ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG)->releasePoolable((AbstractPoolable*)this);

}
