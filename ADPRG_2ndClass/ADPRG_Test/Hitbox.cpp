#include "Hitbox.h"

Hitbox::Hitbox(std::string name, float width, float height) : CollisionListener(), AGameObject(name)
{
	this->width = width;
	this->height = height;
}

void Hitbox::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Hitbox"));

	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable.setPosition(0,0);

	Renderer* renderer = new Renderer("HitRenderer");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	this->getTransformable()->setScale(width, height);

	this->collider = new Collider("HitCollider");

	collider->setLocalBounds(sprite->getGlobalBounds());
	this->collider->setCollisionListener(this);
	this->attachComponent(this->collider);

	PhysicsManager::getInstance()->trackObject(this->collider);
}

void Hitbox::onCollisionExit(AGameObject* contact)
{

}

void Hitbox::onCollisionEnter(AGameObject* contact)
{
}
