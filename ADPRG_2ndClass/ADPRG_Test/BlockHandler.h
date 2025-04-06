#pragma once
#include "AbstractComponent.hpp"
#include "GameObjectPool.hpp"
#include "Block.h"
#include "CameraManager.hpp"
class BlockHandler : public AbstractComponent {
public:
	BlockHandler(std::string name, GameObjectPool* blockPool);
public:
	void perform();
	void clearUnused();
	//block placer
	
	
private:
	GameObjectPool* blockPool;
	float count = 0;
	float x = 0;
	int flor = 0;
	float needed = 25;
	float sameCol = 0;
	float rep = 1;
	std::vector<AbstractPoolable*> blocksMade;
};








