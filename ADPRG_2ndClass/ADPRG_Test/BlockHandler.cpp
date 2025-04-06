#include "BlockHandler.h"
#include <random>
#include "CameraManager.hpp"

BlockHandler::BlockHandler(std::string name, GameObjectPool* blockPool) : AbstractComponent(name, Script) {
	this->blockPool = blockPool;
}

void BlockHandler::perform() {
	
	

	switch ((int)flor) {
	case 0:
		
		if (blockPool->getAvailableSize() >= 25) {
			for (int i = 0; i < 25; i++) {
				float rng = this->generateRandom();
				if (rng < chance) {
					Block* newBlock = (Block*)blockPool->requestPoolable();
					newBlock->setPosition(Game::WINDOW_WIDTH / 2 + 240 - (x * 19.6), (Game::WINDOW_HEIGHT / 2) + 80 - (120 * flor));
					newBlock->setColCheck(2);
					blocksMade.push_back(newBlock);

				}
				
				x++;
			}
			flor++;
		}
		else {
			std::cout << "notEnough for floor: " << flor << std::endl;
		}
		break;
	case 1:
		if (blockPool->getAvailableSize() >= 23) {
			x = 1;
			for (int i = 0; i < 23; i++) {
				float rng = this->generateRandom();
				if (rng < chance){
					Block* newBlock = (Block*)blockPool->requestPoolable();
					newBlock->setPosition(Game::WINDOW_WIDTH / 2 + 240 - (x * 19.6), (Game::WINDOW_HEIGHT / 2) + 80 - (120 * flor));
					newBlock->setColCheck(1);
					blocksMade.push_back(newBlock);
				}
				x++;
			}
			flor++;
		}
		else {
			std::cout << "notEnough for floor: " << flor << std::endl;
		}
		break;
	case 2:
		if (blockPool->getAvailableSize() >= 23) {
			x = 1;
			for (int i = 0; i < 23; i++) {
				float rng = this->generateRandom();
				if (rng < chance) {
					Block* newBlock = (Block*)blockPool->requestPoolable();
					newBlock->setPosition(Game::WINDOW_WIDTH / 2 + 240 - (x * 19.6), (Game::WINDOW_HEIGHT / 2) + 80 - (120 * flor));
					newBlock->setColCheck(1);
					blocksMade.push_back(newBlock);
				}
				x++;
			}
			flor++;
		}
		else {
			std::cout << "notEnough for floor: " << flor << std::endl;
		}
		break;
	case 3:
		if (blockPool->getAvailableSize() >= 23){
			x = 1;
			for (int i = 0; i < 23; i++) {
				float rng = this->generateRandom();
				if (rng < chance) {
					Block* newBlock = (Block*)blockPool->requestPoolable();
					newBlock->setPosition(Game::WINDOW_WIDTH / 2 + 240 - (x * 19.6), (Game::WINDOW_HEIGHT / 2) + 80 - (120 * flor));
					newBlock->setColCheck(1);
					blocksMade.push_back(newBlock);
				}
				x++;
			}
			flor++;
		}
		else {
			std::cout << "notEnough for floor: " << flor << std::endl;
		}
		break;
	case 4:
		if (blockPool->getAvailableSize() >= 21) {
			x = 2;
			for (int i = 0; i < 21; i++) {
				float rng = this->generateRandom();
				if (rng < chance) {
					Block* newBlock = (Block*)blockPool->requestPoolable();
					newBlock->setPosition(Game::WINDOW_WIDTH / 2 + 240 - (x * 19.6), (Game::WINDOW_HEIGHT / 2) + 80 - (120 * flor));
					newBlock->setColCheck(0);
					blocksMade.push_back(newBlock);
				}
				x++;
			}
			flor++;
		}
		else {
			std::cout << "notEnough for floor: " << flor << std::endl;
		}
		break;
	case 5:
		if (blockPool->getAvailableSize() >= 21) {
			x = 2;
			for (int i = 0; i < 21; i++) {
				float rng = this->generateRandom();
				if (rng < chance) {
					Block* newBlock = (Block*)blockPool->requestPoolable();
					newBlock->setPosition(Game::WINDOW_WIDTH / 2 + 240 - (x * 19.6), (Game::WINDOW_HEIGHT / 2) + 80 - (120 * flor));
					newBlock->setColCheck(0);
					blocksMade.push_back(newBlock);
				}
				x++;
			}
			flor++;
		}
		else {
			std::cout << "notEnough for floor: " << flor << std::endl;
		}
		
		break;
	case 6:
		if (blockPool->getAvailableSize() >= 21) {
			x = 2;
			for (int i = 0; i < 21; i++) {
				float rng = this->generateRandom();
				if (rng < chance) {
					Block* newBlock = (Block*)blockPool->requestPoolable();
					newBlock->setPosition(Game::WINDOW_WIDTH / 2 + 240 - (x * 19.6), (Game::WINDOW_HEIGHT / 2) + 80 - (120 * flor));
					newBlock->setColCheck(0);
					
					blocksMade.push_back(newBlock);
					
				}
				x++;
			}
			flor++;
		}
		else {
			std::cout << "notEnough for floor: " << flor << std::endl;
		}
		
		break;
	case 7:
		if (blockPool->getAvailableSize() >= 21) {
			x = 2;
			for (int i = 0; i < 21; i++) {
				float rng = this->generateRandom();
				if (rng < chance) {
					Block* newBlock = (Block*)blockPool->requestPoolable();
					newBlock->setPosition(Game::WINDOW_WIDTH / 2 + 240 - (x * 19.6), (Game::WINDOW_HEIGHT / 2) + 80 - (120 * flor));
					newBlock->setColCheck(0);
					newBlock->setInvincibility(true);
					blocksMade.push_back(newBlock);

				}
				x++;
			}
			flor++;
		}
		else {
			std::cout << "notEnough for floor: " << flor << std::endl;
		}

		break;
	
	}
	//for (int i = 0; i < blockPool->getAvailableSize(); i++) {
	//	count++;

	//	Block* newBlock = (Block*)blockPool->requestPoolable();
	//	newBlock->setPosition(Game::WINDOW_WIDTH / 2 + 240 - (x * 19.6), (Game::WINDOW_HEIGHT / 2) + 80 - (120 * flor));	
	//	blocksMade.push_back(newBlock);
	//	x++;
	//	//std::cout << "spawn" << std::endl;
	//	if (count >= needed) {
	//		count = 0;
	//		x = 1;
	//		flor++;
	//		switch ((int)flor) {
	//		case 1:
	//			needed -= 2;
	//			break;
	//		case 4:
	//		case 5:
	//		case 6:
	//		case 7:
	//			needed -= 2;
	//			x = 2;
	//		}
	//		//std::cout << "Flor: " << flor << " needed:  " << needed << std::endl;
	//	}
	//}
	if (Game::camera) {
		clearUnused();
	}
}


void BlockHandler::clearUnused()
{
	//std::cout << "Cleaning blocks" << std::endl;
	sf::View cam = CameraManager::getInstance()->getViewCamera();
	int cleaned = 0;
	for (int i = 0; i < this->blocksMade.size(); i++) {
		std::cout << "Block at: " << blocksMade[i]->getTransformable()->getPosition().y << std::endl;
		std::cout << "Cam was: " << cam.getCenter().y + Game::WINDOW_HEIGHT / 2 << std::endl;
		if (blocksMade[i]->getTransformable()->getPosition().y > cam.getCenter().y - 120) {
			//std::cout << "got cleaned" << std::endl;
			ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::BLOCK_POOL_TAG)->releasePoolable(blocksMade[i]);
			cleaned++;
		}
		
	}
	std::cout << cleaned << std::endl;
}

float BlockHandler::generateRandom()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_real_distribution<> prob(0.f, 100.0f);

	return prob(gen);
	
}




