#include "PlayerInputController.hpp"
#include "GameObjectManager.hpp"
#include "ApplicationManager.hpp"

PlayerInputController::PlayerInputController(std::string name) : GenericInputController(name) {

}

PlayerInputController::~PlayerInputController() {
	GenericInputController::~GenericInputController();
}

void PlayerInputController::perform(){
	bool isPressed = false;

	if (this->event.type == sf::Event::KeyPressed) {
		isPressed = true;
		if (this->event.key.code == sf::Keyboard::P) { //just finds the ui box, moves it(if necessary and then makes it SEEN
			if (this->Pause == false) {
				AGameObject* uiGameBox = GameObjectManager::getInstance()->findObjectByName("UIBoxGame");
				uiGameBox->setEnabled(true);
				UIBoxMover* uimove = (UIBoxMover*)uiGameBox->findComponentByName("uiMover");
				uimove->perform();
				ApplicationManager::getInstance()->pauseApplication();
			}
			else ApplicationManager::getInstance()->resumeApplication();
		}
	}
	else if (this->event.type == sf::Event::KeyReleased) {
		isPressed = false;
	}

	switch (this->event.key.code) {
	case sf::Keyboard::K:
		this->movePick = isPressed;
		break;
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
	case sf::Keyboard::Space:
		this->moveJump = isPressed;
	


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

bool PlayerInputController::isAttack(){
	return this->movePick;
}

bool PlayerInputController::isJump() {
	return this->moveJump;
}

bool PlayerInputController::isPause()
{
	return this->Pause;
}

