#include "GroundChecker.h"


GroundChecker::GroundChecker(std::string name, float width, float height) : CollisionListener(), AGameObject(name)
{
	this->width = width;
	this->height = height;
}

void GroundChecker::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Hitbox"));

	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	//invisible sprite
	sf::Color invisible = sf::Color::Transparent;

	this->sprite->setColor(invisible);

	this->transformable.setPosition(0, 0);

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

void GroundChecker::onCollisionExit(AGameObject* contact)
{
	AbstractComponent* pm = nullptr;
	//std::cout << contact->getName() << std::endl;
	for (int i = 0; i < this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script).size(); i++) {
		if (this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script)[i]->getName() == "MyPlayerMovement") {
			//std::cout << "pm found" << std::endl;
			pm = this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script)[i];

		}
		if (this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script)[i]->getName() == "WalkerMovement") {
			pm = (WalkerMovement*)this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script)[i];
			//std::cout << "pm found" << std::endl;
		}
	}
	if (pm == nullptr) {
		std::cout << "NULL" << std::endl;
	}
	else {
		pm->setGrounded(false);
	}

}

void GroundChecker::onCollisionEnter(AGameObject* contact)
{
	
	if (contact->getName() != "Player") {
		PlayerMovement* pm = nullptr;
		//::cout << contact->getName() << std::endl;
		for (int i = 0; i < this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script).size(); i++) {
			if (this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script)[i]->getName() == "MyPlayerMovement") {
				pm = (PlayerMovement*)this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script)[i];
				
				//std::cout << "pm found" << std::endl;
			}
		}
		if (pm == nullptr) {
			std::cout << " PAKC" << std::endl;
		}
		else {
			float contPos = contact->getTransformable()->getPosition().y;
			float aug = contact->getSprite()->getGlobalBounds().height/2;

			std::cout << "ToCheck: " << contPos - aug << std::endl;
			std::cout << "curr pos: "  << this->getGlobalTransform().transformPoint(0,0).y << std::endl;


			if (contPos - aug -5 <= this->getGlobalTransform().transformPoint(0, 0).y && this->getGlobalTransform().transformPoint(0, 0).y <= contPos - aug + 5) {
				pm->setGrounded(true);
				this->getParent()->findChild("TopHitbox")->setEnabled(false);
			}

			

		}


		this->getParent()->setPosition(this->getParent()->getPosition().x, this->getParent()->getPosition().y);
	}
	
}

void GroundChecker::activate()
{

	this->setEnabled(true);
	PhysicsManager::getInstance()->trackObject(this->collider);
}

void GroundChecker::deactivate()
{
	PhysicsManager::getInstance()->untrackObject(this->collider);
	this->setEnabled(false);
}
