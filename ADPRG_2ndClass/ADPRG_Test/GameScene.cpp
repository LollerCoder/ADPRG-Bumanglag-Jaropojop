#include "GameScene.hpp"
#include "PlayerScore.hpp"

GameScene::GameScene() : AbstractScene(SceneManager::GAME_SCENE_NAME) {

}

void GameScene::onLoadResources() {

}

void GameScene::onLoadObjects() {
	this->loadPhysicsManager();
	//this->loadEnemies();
	this->loadBG();
	this->loadPlayer();
	this->loadPoolables();
	this->loadUIButton();
	this->loadUI();
	PlayerScore::resetScore();
}

void GameScene::onUnloadResources() {

}

void GameScene::loadBG() {

	GameBG* bg = new GameBG("Background", Tag::BACKGROUND);
	this->registerObject(bg);



}

void GameScene::loadPlayer() {
	Player* player = new Player("Player");
	this->registerObject(player);

	Hitbox* hit = new Hitbox("FrontHitbox", 0.25,0.15);
	player->attachChild(hit);
	sf::IntRect playerBounds = player->getSprite()->getTextureRect();
	hit->setPosition(playerBounds.width/2 , 0);
	hit->setEnabled(false);

	BlockBreaker* hit2 = new BlockBreaker("TopHitbox", 0.05, 0.05);
	player->attachChild(hit2);
	sf::IntRect playerBounds2 = player->getSprite()->getTextureRect();
	hit2->setPosition(0, -playerBounds2.height/2 -5 );
	hit2->getSprite()->rotate(90.0f);
	hit2->setEnabled(false);
}

void GameScene::loadEnemies() {
	Walker* walker = new Walker("Walker-1", (sf::Vector2f(-60, 400)));
	this->registerObject(walker);

	walker = new Walker("Walker-2", (sf::Vector2f(660, 290)));
	this->registerObject(walker);

	//walker = new Walker("Walker-3", (sf::Vector2f(-60, 165)));
	//this->registerObject(walker);

	//walker = new Walker("Walker-4", (sf::Vector2f(660, 45)));
	//this->registerObject(walker);

	Flyer* flyer = new Flyer("Flyer-1", sf::Vector2f(0, 30));
	this->registerObject(flyer);
}

void GameScene::loadPoolables() {
	EmptyGameObject* poolableHolder = new EmptyGameObject("poolableHolder",Tag::TOOL);
	this->registerObject(poolableHolder);
	GameObjectPool* blockPool;
	blockPool = new GameObjectPool(ObjectPoolHolder::BLOCK_POOL_TAG,
		new Block("Block", Game::WINDOW_WIDTH / 2 + 240, (Game::WINDOW_HEIGHT / 2) + 80),
		71,
		poolableHolder
	);

	blockPool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(blockPool);

	BlockHandler* blockHandle = new BlockHandler("blockHandler",blockPool);
	poolableHolder->attachComponent(blockHandle);
	//blockPool->requestPoolable();

	
}

void GameScene::loadUIButton() {
	std::cout << "HELLO" << std::endl;
}

void GameScene::loadPhysicsManager() {
	EmptyGameObject* physicsHolder = new EmptyGameObject("PhysicsManagerHolder", Tag::TOOL);
	PhysicsManager::initialize("Physics Manager", physicsHolder);
	GameObjectManager::getInstance()->addObject(physicsHolder);
}

void GameScene::loadUI()
{
	UIBox* uiBox = new UIBox("UIBoxGame");
	uiBox->setEnabled(false);
	this->registerObject(uiBox);
}


