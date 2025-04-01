#include "GameScene.hpp"

GameScene::GameScene() : AbstractScene(SceneManager::GAME_SCENE_NAME) {

}

void GameScene::onLoadResources() {

}

void GameScene::onLoadObjects() {
	this->loadPhysicsManager();
	this->loadBG();
	this->loadPlayer();
	this->loadPoolables();
	this->loadUIButton();
}

void GameScene::onUnloadResources() {

}

void GameScene::loadBG() {
	Entity* entity = new Entity("Background");
	this->registerObject(entity);
}

void GameScene::loadPlayer() {
	Player* player = new Player("Player");
	this->registerObject(player);
}

void GameScene::loadPoolables() {

}

void GameScene::loadUIButton() {
	std::cout << "HELLO" << std::endl;
}

void GameScene::loadPhysicsManager() {
	EmptyGameObject* physicsHolder = new EmptyGameObject("PhysicsManagerHolder");
	PhysicsManager::initialize("Physics Manager", physicsHolder);
	GameObjectManager::getInstance()->addObject(physicsHolder);
}


