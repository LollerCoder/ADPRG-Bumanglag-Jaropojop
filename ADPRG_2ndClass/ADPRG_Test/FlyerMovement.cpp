#include "FlyerMovement.hpp"

FlyerMovement::FlyerMovement(std::string name) : AbstractComponent(name, AbstractComponent::Script){

}

void FlyerMovement::perform() {
	Flyer* flyer = (Flyer*)this->getOwner();
	sf::Transformable* flyerTransform = flyer->getTransformable();
	Player* player = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");

	if (flyer == nullptr || flyerTransform == nullptr || player == nullptr) {
		std::cout << "Owner or Transform cannot be found" << std::endl;
		return;
	}

	// for animation of bird
	if (this->fAnimFreq >= this->fAnimThresh) {
		flyer->incrementFlyFrame();
		this->fAnimFreq = 0;
	}

	this->fAnimFreq += deltaTime.asSeconds();

	// to face on the right direction
	if (this->targetPos.x < 0.0f) {
		flyerTransform->setScale(0.7f, 0.7f);
	}
	else {
		flyerTransform->setScale(-0.7f, 0.7f);
	}

	// searches for the player when moving
	if (!this->moving) {
		pos = player->getPosition();
		sf::Vector2f dir = pos - flyerTransform->getPosition();

		float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);
		if (length != 0) {
			dir /= length;
			this->targetPos = dir;
			this->moving = true;
			this->timer = 0.0f;
		}
		this->moving = true;

		if (flyer->onSecond) {
			this->fastMode = true;
			flyer->onSecond = false;
		}
	}
	else { // delays the next find
		this->timer += deltaTime.asSeconds();
		if (this->timer >= this->findPlayerCD) {
			this->moving = false;
			this->timer = 0.0f;
			return;
		}
		sf::Vector2f diff = pos - flyerTransform->getPosition();
		float distance = std::sqrt(diff.x * diff.x + diff.y * diff.y);

		if (distance <= 3.0f) {
			return;
		}

		// mode for when moving
		if (this->fastMode) {
			std::cout << "flying" << std::endl;
			flyerTransform->move(this->targetPos * (this->SPEED_MULTIPLIER + 600) * this->deltaTime.asSeconds());
		}
		else {
			flyerTransform->move(this->targetPos * this->SPEED_MULTIPLIER * this->deltaTime.asSeconds());
		}
	}
	

}
