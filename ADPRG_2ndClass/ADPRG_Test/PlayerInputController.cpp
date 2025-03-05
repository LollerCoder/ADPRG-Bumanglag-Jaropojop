#include "PlayerInputController.hpp"

PlayerInputController::PlayerInputController(std::string name) : GenericInputController(name) {

}

PlayerInputController::~PlayerInputController() {
	GenericInputController::~GenericInputController();
}

void PlayerInputController::perform(){
	bool isPressed = false;

	if (this->event.type == sf::Event::KeyPressed) {
		isPressed = true;
	}
	else if (this->event.type == sf::Event::KeyReleased) {
		isPressed = false;
	}

	switch (this->event.key.code) {
	case sf::Keyboard::W:
		this->moveUp = isPressed;
		break;
	case sf::Keyboard::A:
		this->moveLeft = isPressed;
		break;
	case sf::Keyboard::S:
		this->moveDown = isPressed;
		break;
	case sf::Keyboard::D:
		this->moveRight = isPressed;
		break;
	}
}

bool PlayerInputController::isUp() {
	return this->moveUp;
}

bool PlayerInputController::isDown() {
	return this->moveDown;
}

bool PlayerInputController::isLeft() {
	return this->moveLeft;
}

bool PlayerInputController::isRight() {
	return this->moveRight;
}
