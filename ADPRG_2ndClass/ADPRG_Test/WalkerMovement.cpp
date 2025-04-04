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

	walkerTransformable->move(this->velocity * deltaTime.asSeconds());

	if (walkerTransformable->getPosition().y >= 410) {
		this->isGrounded = true;

		walkerTransformable->setPosition(walkerTransformable->getPosition().x, 410);

	}
}
