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
	
	if (inputController->isUp()) {
		offset.y -= this->SPEED_MULTIPLIER;
	}
	if (inputController->isDown()) {
		offset.y += this->SPEED_MULTIPLIER;
	}
	if (inputController->isRight()) {
		offset.x += this->SPEED_MULTIPLIER;
	}
	if (inputController->isLeft()) {
		offset.x -= this->SPEED_MULTIPLIER;
	}

	this->ticks += this->deltaTime.asSeconds();

	playerTransformable->move(offset * deltaTime.asSeconds());

}
