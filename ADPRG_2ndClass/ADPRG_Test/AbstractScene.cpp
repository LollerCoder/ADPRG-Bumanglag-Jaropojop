#include "AbstractScene.hpp"

AbstractScene::AbstractScene(std::string sceneName) {
	this->sceneName = sceneName;
}

void AbstractScene::onUnloadObjects(){
	GameObjectManager::getInstance()->deleteAllObjectsInScene();
}

std::string AbstractScene::getSceneName() {
	return this->sceneName;
}

void AbstractScene::registerObject(AGameObject* object) {
	GameObjectManager::getInstance()->addObject(object);
}
