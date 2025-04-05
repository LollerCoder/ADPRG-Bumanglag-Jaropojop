#include "Hitbox.h"
#include "PlayerScore.hpp"

Hitbox::Hitbox(std::string name, float width, float height) : CollisionListener(), AGameObject(name, Tag::TOOL)
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

	//invisible sprite
	sf::Color invisible = sf::Color::Transparent;

	this->sprite->setColor(invisible);

	this->transformable.setPosition(0,0);

	Renderer* renderer = new Renderer("HitRenderer");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	this->getTransformable()->setScale(width, height);

	this->collider = new Collider("HitCollider");

	collider->setLocalBounds(sprite->getGlobalBounds());
	this->collider->setCollisionListener(this);
	this->attachComponent(this->collider);

	
}

void Hitbox::onCollisionExit(AGameObject* contact)
{

}

void Hitbox::onCollisionEnter(AGameObject* contact)
{
	std::cout << "BONK" << std::endl;
	//ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG)->releasePoolable((AbstractPoolable*)contact);
	if (contact->getTag() == Tag::ENEMY) {
		contact->setEnabled(false);
		contact->setPosition(contact->getSpawnLoc().x, contact->getSpawnLoc().y);
		PlayerScore::birdScore = 1;
		SceneManager::getInstance()->loadScene(SceneManager::EVAL_SCENE_NAME);
	}
}

void Hitbox::activate()
{

	this->setEnabled(true);
	PhysicsManager::getInstance()->trackObject(this->collider);
}

void Hitbox::deactivate()
{
	PhysicsManager::getInstance()->untrackObject(this->collider);
	this->setEnabled(false);
}
