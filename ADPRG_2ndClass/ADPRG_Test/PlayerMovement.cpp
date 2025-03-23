#include "PlayerMovement.hpp"

PlayerMovement::PlayerMovement(std::string name) : AbstractComponent(name, Script){

}

void PlayerMovement::perform(){
	Player* airplanePlayer = (Player*)this->getOwner();
	PlayerInputController* inputController = (PlayerInputController*)airplanePlayer->getComponentsOfType(ComponentType::Input)[0];
	sf::Transformable* playerTransformable = airplanePlayer->getTransformable();
	
	if (playerTransformable == nullptr || inputController == nullptr) {
		std::cout << "Controller or Transformable not found" << std::endl;
	}

	sf::Vector2f offset(0.0f, 0.0f);

	if (!(inputController->isRight() ||
		inputController->isLeft())) {
		airplanePlayer->setFrame(0);
		this->fAnimFreq = 0;
	}
	else {
		if (this->fAnimFreq >= this->fAnimThresh) {
			airplanePlayer->incrementFrame();
			this->fAnimFreq = 0;
		}

		this->fAnimFreq += this->deltaTime.asSeconds();
	}
	
	if (inputController->isUp()) {
		offset.y -= this->SPEED_MULTIPLIER;
	}
	if (inputController->isDown()) {
		offset.y += this->SPEED_MULTIPLIER;
	}
	if (inputController->isRight()) {
		offset.x += this->SPEED_MULTIPLIER;
		airplanePlayer->getSprite()->setScale(1.f,1.f);
	}
	if (inputController->isLeft()) {
		offset.x -= this->SPEED_MULTIPLIER;
		airplanePlayer->getSprite()->setScale(-1.f, 1.f);

	}



	playerTransformable->move(offset * deltaTime.asSeconds());

}
