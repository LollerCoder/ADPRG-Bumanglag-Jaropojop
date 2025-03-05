#include "UIButtonInputController.hpp"

UIButtonInputController::UIButtonInputController(std::string name, ButtonListener* listener) : GenericInputController(name) {
	this->buttonListener = listener;
	this->pressed = false;
}

void UIButtonInputController::perform() {
	UIButton* button = (UIButton*)this->getOwner();

	if (button == nullptr) {
		std::cout << "Button not found" << std::endl;
		return;
	}

	if (this->event.type == sf::Event::MouseButtonReleased && 
		event.mouseButton.button == sf::Mouse::Left && 
		this->pressed) {
		this->pressed = false;
		button->changeButtonToNormal();
		this->buttonListener->onButtonReleased(button);
	}

	if (this->event.type == sf::Event::MouseButtonPressed &&
		this->event.mouseButton.button == sf::Mouse::Left) {

		sf::Vector2f mousePos(this->event.mouseButton.x, this->event.mouseButton.y);
		sf::FloatRect bounds = button->getGlobalBounds();

		if (bounds.contains(mousePos)) {
			this->pressed = true;
			button->changeButtonToPressed();
			this->buttonListener->onButtonClick(button);
		}
	}

}
