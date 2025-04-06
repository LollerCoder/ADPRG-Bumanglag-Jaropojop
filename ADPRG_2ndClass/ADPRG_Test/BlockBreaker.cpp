#include "BlockBreaker.h"
#include "PlayerScore.hpp"


BlockBreaker::BlockBreaker(std::string name, float width, float height) : CollisionListener(), AGameObject(name, Tag::TOOL)
{
	this->width = width;
	this->height = height;
}

void BlockBreaker::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Hitbox"));

	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	//invisible sprite
	sf::Color invisible = sf::Color::Transparent;

	//this->sprite->setColor(invisible);

	//this->transformable.setPosition(0, 0);

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

void BlockBreaker::onCollisionExit(AGameObject* contact)
{

}

void BlockBreaker::onCollisionEnter(AGameObject* contact)
{
	if (contact->getName() == "Block") {
		 contact->setEnabled(false);
		 PlayerScore::blockScore += 1;

		
			 PlayerMovement* pm = nullptr;
			 //::cout << contact->getName() << std::endl;
			 for (int i = 0; i < this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script).size(); i++) {
				 if (this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script)[i]->getName() == "MyPlayerMovement") {
					 pm = (PlayerMovement*)this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script)[i];

					 //std::cout << "pm found" << std::endl;
				 }
			 }
			 if (pm == nullptr) {
				 //std::cout << " PAKC" << std::endl;
			 }
			 else {
				 pm->setVelocity(sf::Vector2f(15.0f, 0.0f));
				 this->deactivate();


			 }


		 
	}
}

void BlockBreaker::activate()
{

	this->setEnabled(true);
	PhysicsManager::getInstance()->trackObject(this->collider);
}

void BlockBreaker::deactivate()
{
	PhysicsManager::getInstance()->untrackObject(this->collider);
	this->setEnabled(false);
}

