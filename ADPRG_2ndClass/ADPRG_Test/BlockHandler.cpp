#include "BlockHandler.h"

#include "CameraManager.hpp"

BlockHandler::BlockHandler(std::string name, GameObjectPool* blockPool) : AbstractComponent(name, Script) {
	this->blockPool = blockPool;
}

void BlockHandler::perform() {

	for (int i = 0; i < blockPool->getAvailableSize(); i++) {
		count++;

		Block* newBlock = (Block*)blockPool->requestPoolable();
		newBlock->setPosition(Game::WINDOW_WIDTH / 2 + 240 - (x * 19.6), (Game::WINDOW_HEIGHT / 2) + 80 - (120 * flor));
		blocksMade.push_back(newBlock);
		x++;
		std::cout << "spawn" << std::endl;
		if (count >= needed) {
			count = 0;
			x = 1;
			flor++;
			switch ((int)flor) {
			case 1:
				needed -= 2;
				break;
			case 4:
			case 5:
			case 6:
			case 7:
				needed -= 2;
				x = 2;
			}
			std::cout << "Flor: " << flor << " needed:  " << needed << std::endl;
		}
	}
	if (Game::camera) {
		clearUnused();
	}
}

void BlockHandler::clearUnused()
{
	std::cout << "Cleaning blocks" << std::endl;
	sf::View cam = CameraManager::getInstance()->getViewCamera();
	int cleaned = 0;
	for (int i = 0; i < this->blocksMade.size(); i++) {
		std::cout << "Block at: " << blocksMade[i]->getTransformable()->getPosition().y << std::endl;
		std::cout << "Cam was: " << cam.getCenter().y << std::endl;
		if (blocksMade[i]->getTransformable()->getPosition().y > cam.getCenter().y -160) {
			std::cout << "got cleaned" << std::endl;
			ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::BLOCK_POOL_TAG)->releasePoolable(blocksMade[i]);
			cleaned++;
		}
		
	}
	std::cout << cleaned << std::endl;
}




