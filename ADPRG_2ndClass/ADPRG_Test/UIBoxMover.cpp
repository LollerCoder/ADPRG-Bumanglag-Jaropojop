#include "UIBoxMover.hpp"


UIBoxMover::UIBoxMover(std::string name) : AbstractComponent(name, Script) {
	
}

void UIBoxMover::perform() {

	this->getOwner()->getTransformable()->setPosition(CameraManager::getInstance()->getViewCamera().getCenter().x, CameraManager::getInstance()->getViewCamera().getCenter().y);
	
}







