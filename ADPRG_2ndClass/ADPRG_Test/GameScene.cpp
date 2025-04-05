#include "GameScene.hpp"


GameScene::GameScene() : AbstractScene(SceneManager::GAME_SCENE_NAME) {

}

void GameScene::onLoadResources() {

}

void GameScene::onLoadObjects() {
	this->loadPhysicsManager();
	this->loadEnemies();
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

	Hitbox* hit = new Hitbox("FrontHitbox", 0.25,0.15);
	player->attachChild(hit);
	sf::IntRect playerBounds = player->getSprite()->getTextureRect();
	hit->setPosition(playerBounds.width/2 , 0);
	hit->setEnabled(false);

	BlockBreaker* hit2 = new BlockBreaker("TopHitbox", 0.1, 0.25);
	player->attachChild(hit2);
	sf::IntRect playerBounds2 = player->getSprite()->getTextureRect();
	hit2->setPosition(0, -playerBounds2.height/2 -10 );
	hit2->getSprite()->rotate(90.0f);
	hit2->setEnabled(false);
}

void GameScene::loadEnemies() {
	Walker* walker = new Walker("Walker", (sf::Vector2f(-50, 400)));
	this->registerObject(walker);
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


