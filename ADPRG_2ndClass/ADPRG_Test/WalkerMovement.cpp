#include "WalkerMovement.hpp"

WalkerMovement::WalkerMovement(std::string name) : AbstractComponent(name, AbstractComponent::Script) {

}

void WalkerMovement::perform() {
	Walker* walker = (Walker*)this->getOwner();
	sf::Transformable* walkerTransformable = walker->getTransformable();

	if (walkerTransformable == nullptr) {
		std::cout << "Transformable not found" << std::endl;
	}

	// gravity 
	if (!this->isGrounded) {
		this->velocity.y += GRAVITY_FORCE;
	}
	else {
		this->velocity.y = 0;
	}

	if (this->fAnimFreq >= this->fAnimThresh) {
		walker->incrementWalkFrame();
		this->fAnimFreq = 0;
	}

	this->fAnimFreq += deltaTime.asSeconds();

	// sets orientation based on where it spawned 

	if (walker->getSpawnLoc().x < 0) {
		walker->getTransformable()->setScale(-0.7f, 0.7f);
		this->velocity.x = this->SPEED_MULTIPLIER;
	}
	if (walker->getSpawnLoc().x > 0) {
		walker->getTransformable()->setScale(0.7f, 0.7f);
		this->velocity.x = -this->SPEED_MULTIPLIER;
	}

	walkerTransformable->move(this->velocity * deltaTime.asSeconds());

	// teleport to other side
	
	if (walkerTransformable->getPosition().x < -30.0f) {
		walkerTransformable->setPosition(700, walkerTransformable->getPosition().y);
	}
	if (walkerTransformable->getPosition().x > 700.0f) {
		walkerTransformable->setPosition(-30.0f, walkerTransformable->getPosition().y);
	}

	if (walkerTransformable->getPosition().y >= 400) {
		this->isGrounded = true;

		walkerTransformable->setPosition(walkerTransformable->getPosition().x, 410);

	}
	//std::cout << walkerTransformable->getPosition().y << std::endl;

	sf::View view = CameraManager::getInstance()->getViewCamera();

	sf::Vector2f center = view.getCenter();
	sf::Vector2f size = view.getSize();

	float left = center.x - size.x / 2.f;
	float right = center.x + size.x / 2.f;
	float top = center.y - size.y / 2.f;
	float bottom = center.y + size.y / 2.f;

	sf::FloatRect cameraBounds(left, top, size.x, size.y);

	center = walker->getTransformable()->getPosition();

	left = center.x - walker->getSprite()->getGlobalBounds().width / 2.f;
	right = center.x + walker->getSprite()->getGlobalBounds().width / 2.f;
	top = center.y - walker->getSprite()->getGlobalBounds().height / 2.f;
	bottom = center.y + walker->getSprite()->getGlobalBounds().height / 2.f;



	sf::FloatRect walkerBounds(left, top, right - left, bottom - top);

	if (!walkerBounds.intersects(cameraBounds)) {
		walker->setEnabled(false);
	}
}

void WalkerMovement::setGrounded(bool flag) {
	this->isGrounded = flag;
}
