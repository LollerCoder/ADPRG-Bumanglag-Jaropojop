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
#include "Entity.h"
#include "Block.h"
#include "Walker.h"
#include "Hitbox.h"

class GameScene : public AbstractScene{
public:
	GameScene();
public:
	void onLoadResources();
	void onLoadObjects();

	void onUnloadResources();
private:
	void loadBG();
	void loadPlayer();
	void loadPoolables();
	void loadUIButton();
	void loadPhysicsManager();
};

