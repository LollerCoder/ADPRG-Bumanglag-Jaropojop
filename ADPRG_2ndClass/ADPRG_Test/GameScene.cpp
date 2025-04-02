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
	Block* blocks = new Block("BlockStack");
	this->registerObject(blocks);
}

void GameScene::loadPlayer() {
	Player* player = new Player("Player");
	this->registerObject(player);
}

void GameScene::loadPoolables() {
	EmptyGameObject* poolableHolder = new EmptyGameObject("poolableHolder");
	GameObjectManager::getInstance()->addObject(poolableHolder);
	GameObjectPool* walkerPool;
	walkerPool = new GameObjectPool(ObjectPoolHolder::ENEMY_POOL_TAG,
		new Walker("walker_enemy"),
		10,
		poolableHolder
	);

	walkerPool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(walkerPool);
	walkerPool->requestPoolable();

}

void GameScene::loadUIButton() {
	std::cout << "HELLO" << std::endl;
}

void GameScene::loadPhysicsManager() {
	EmptyGameObject* physicsHolder = new EmptyGameObject("PhysicsManagerHolder");
	PhysicsManager::initialize("Physics Manager", physicsHolder);
	GameObjectManager::getInstance()->addObject(physicsHolder);
}


