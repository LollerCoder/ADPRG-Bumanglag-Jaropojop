#include "GroundChecker.h"


GroundChecker::GroundChecker(std::string name, float width, float height) : CollisionListener(), AGameObject(name, Tag::TOOL)
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

	//Renderer* renderer = new Renderer("HitRenderer");
	//renderer->assignDrawable(this->sprite);
	//this->attachComponent(renderer);

	this->getTransformable()->setScale(width, height);

	this->collider = new Collider("HitCollider");

	collider->setLocalBounds(sprite->getGlobalBounds());
	this->collider->setCollisionListener(this);
	this->attachComponent(this->collider);
	PhysicsManager::getInstance()->trackObject(this->collider);

}

void GroundChecker::onCollisionExit(AGameObject* contact)
{
	/*
		Ground Checker is used by both Player AND the seals so it checks which one it is and toggles accordingly.
	*/
	PlayerMovement* pm = nullptr;
	WalkerMovement* wm = nullptr;
	//std::cout << contact->getName() << std::endl;
	for (int i = 0; i < this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script).size(); i++) {
		if (this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script)[i]->getName() == "MyPlayerMovement") {
			//std::cout << "pm found" << std::endl;
			pm = (PlayerMovement*)this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script)[i];
		}
		if (this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script)[i]->getName() == "WalkerMovement") {
			wm = (WalkerMovement*)this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script)[i];
			//std::cout << "pm found" << std::endl;
		}
	}
	/*
		This bit of code just ensures that there's something keeping it 'Grounded' otherwise, DROP EM.
	*/
	if (contact->getTag() == Tag::BLOCK) {
		inside--;
	}
	if (inside == 0) {
		if (pm != nullptr) {
			pm->setGrounded(false);
		}
		if (wm != nullptr) {
			wm->setGrounded(false);
		}
	}
	
}

void GroundChecker::onCollisionEnter(AGameObject* contact)
{
	//check if YOU CAN WALK ON IT.	
	if (contact->getTag() == Tag::BLOCK) {
		if (this->getParent()->getName() == "Player") {
			//std::cout << "BlockFound" << std::endl;
		}
		
		inside++;
		PlayerMovement* pm = nullptr;
		
		for (int i = 0; i < this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script).size(); i++) {
			if (this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script)[i]->getName() == "MyPlayerMovement") {
				pm = (PlayerMovement*)this->getParent()->getComponentsOfType(AbstractComponent::ComponentType::Script)[i];
				
				
			}
		}
		if (pm == nullptr) {
			//std::cout << "noPm" << std::endl;
		}
		else {
			/*
			* The main function of this cpp is here. It checks THE TOP OF A BLOCK and says if its close? You are now on me. The -/+ 20 is the leeway. This is 
			* sadly increasing the leeway seems to do nothing to prevent TORPEDO SEALS. It does help the player land below when they miss a jump.
			*/
			

			float contPos = contact->getTransformable()->getPosition().y;
			float aug = contact->getSprite()->getGlobalBounds().height/2;

			


			if (contPos - aug -20 <= this->getGlobalTransform().transformPoint(0, 0).y && this->getGlobalTransform().transformPoint(0, 0).y <= contPos - aug + 20) {
				if (this->getParent()->getName() == "Player") {
	
					
				}
				pm->setVelocity(sf::Vector2f(0, 0));
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
