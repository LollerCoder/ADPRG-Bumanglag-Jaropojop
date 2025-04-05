#include "FlyerMovement.hpp"

FlyerMovement::FlyerMovement(std::string name) : AbstractComponent(name, AbstractComponent::Script){

}

void FlyerMovement::perform() {
	Flyer* flyer = (Flyer*)this->getOwner();
	sf::Transformable* flyerTransform = flyer->getTransformable();
	if (flyer == nullptr || flyerTransform == nullptr) {
		std::cout << "Owner or Transform cannot be found" << std::endl;
		return;
	}

	if (this->fAnimFreq >= this->fAnimThresh) {
		flyer->incrementFlyFrame();
		this->fAnimFreq = 0;
	}

	this->fAnimFreq += deltaTime.asSeconds();
}
