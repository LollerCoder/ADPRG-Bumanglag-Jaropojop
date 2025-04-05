#include "WalkerMovement.hpp"

WalkerMovement::WalkerMovement(std::string name) : AbstractComponent(name, AbstractComponent::Script) {

}

void WalkerMovement::perform() {
	Walker* walker = (Walker*)this->getOwner();
	sf::Transformable* walkerTransformable = walker->getTransformable();

	if (walkerTransformable == nullptr) {
		std::cout << "Transformable not found" << std::endl;
	}

	if (!this->isGrounded) {
		this->velocity.y += GRAVITY_FORCE;
	}
	else {
		this->velocity.y = 0;
	}

	if (walker->getSpawnLoc().x < 0) {
		walker->getTransformable()->setScale(-0.7f, 0.7f);
		this->velocity.x = this->SPEED_MULTIPLIER;
	}
	if (walker->getSpawnLoc().x > 0) {
		walker->getTransformable()->setScale(0.7f, 0.7f);
		this->velocity.x = -this->SPEED_MULTIPLIER;
	}

	walkerTransformable->move(this->velocity * deltaTime.asSeconds());

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
}

void WalkerMovement::setGrounded(bool flag) {
	this->isGrounded = flag;
}
