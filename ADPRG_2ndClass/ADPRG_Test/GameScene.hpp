#pragma once
//// 
#include "PhysicsManager.hpp"
#include "GameObjectManager.hpp"
#include "SceneManager.hpp"
//// 
#include "AbstractScene.hpp"
#include "EmptyGameObject.hpp"
#include "ObjectPoolHolder.hpp"
////
#include "UIData.hpp"
#include "UIManager.hpp"
#include "Player.h"
#include "GameBG.h"
#include "Block.h"
#include "Walker.h"
#include "Hitbox.h"
#include "GroundChecker.h"
#include "BlockBreaker.h"
#include "Flyer.hpp"
#include "BlockHandler.h"
#include "BonusItem.hpp"

class GameScene : public AbstractScene{
public:
	GameScene();
public:
	void onLoadResources();
	void onLoadObjects();
	void onUnloadObjects();
	void onUnloadResources();
private:
	void loadBG(); // loads background image
	void loadPlayer(); 	// loads player object and hitboxes for colliding
	void loadEnemies(); // loads the walker and flyer enemies
	void loadPoolables(); // loads the poolable blocks as well as the bonus item
	void loadPhysicsManager();
	void loadUI();
private:
	sf::Sound* bgm = nullptr;
};

