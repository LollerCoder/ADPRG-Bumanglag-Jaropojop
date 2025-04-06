#include "BlockHandler.h"
#include <random>
#include "CameraManager.hpp"
#include "GameValue.hpp"

BlockHandler::BlockHandler(std::string name, GameObjectPool* blockPool) : AbstractComponent(name, Script) {
	this->blockPool = blockPool;
}

void BlockHandler::perform() {
	/*
		What is inside is a very rushed but FUNCTIONAL implementation of THE BLOCKS
		This here causes most of the lag problems, a necessary evil that is trying to 

		1: Avoid errors
		2. Fill the space with blocks

		It could be better. But as IECMPTK Once said:

		Efficiency
		Useability
		Elegance 
		Readabilty

		And this code checks none of those... We'll try to make it make sense.

		essentially this makes blocks BY FLOOR.

		For loops that have 1 digit numbers are for the caves. Used by the seal's so they can actually walk before becoming LITERAL TORPEDO'S
		Otherwise, they are used to actually POPULATE THE PLATFORMS A PLAYER CAN USE.

		Random is there to cut down the number of objects.
		Poolables are released depending on the camera.
		
		Everything here was made to avoid lag...but even in that sense, we're based on luck.
	*/
	Block* unBreakBlock;
	

	switch ((int)flor) {
	case 0:
		if (blockPool->getAvailableSize() >= 3) {
			for (int i = 0; i < 3; i++) {
				unBreakBlock = (Block*)blockPool->requestPoolable();
				unBreakBlock->setPosition(Game::WINDOW_WIDTH / 2 + 259.6 + (x * 19.6), (Game::WINDOW_HEIGHT / 2) + 80);
				unBreakBlock->setColCheck(2);
				unBreakBlock->setInvincibility(true);
				blocksMade.push_back(unBreakBlock);
				x++;
			}
		}
		
		x = 0;
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
			//std::cout << "notEnough for floor: " << flor << std::endl;
		}
		
		
		
		break;
	case 1:
		
		x = 1;
		if (blockPool->getAvailableSize() >= 23) {
			
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
			if (blockPool->getAvailableSize() >= 5) {
				for (int i = 0; i < 5; i++) {
					unBreakBlock = (Block*)blockPool->requestPoolable();
					unBreakBlock->setPosition(Game::WINDOW_WIDTH / 2 + 240 - (x * 19.6), (Game::WINDOW_HEIGHT / 2) + 80 - (120 * flor));
					unBreakBlock->setColCheck(1);
					unBreakBlock->setInvincibility(true);
					blocksMade.push_back(unBreakBlock);
					x++;
				}
			}
			
			flor++;
		}
		else {
			//std::cout << "notEnough for floor: " << flor << std::endl;
		}
		break;
	case 2:
		x = 1;
	
		if (blockPool->getAvailableSize() >= 23) {
			
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
			if (blockPool->getAvailableSize() >= 5){
				for (int i = 0; i < 5; i++) {
					unBreakBlock = (Block*)blockPool->requestPoolable();
					unBreakBlock->setPosition(Game::WINDOW_WIDTH / 2 + 240 - (x * 19.6), (Game::WINDOW_HEIGHT / 2) + 80 - (120 * flor));
					unBreakBlock->setColCheck(1);
					unBreakBlock->setInvincibility(true);
					blocksMade.push_back(unBreakBlock);
					x++;
				}
			}
			
			flor++;
		}

		else {
			//std::cout << "notEnough for floor: " << flor << std::endl;
		}
		break;
	case 3:
		x = 1;
		if(blockPool->getAvailableSize() >= 4) {
			for (int i = 0; i < 4; i++) {
				unBreakBlock = (Block*)blockPool->requestPoolable();
				unBreakBlock->setPosition(Game::WINDOW_WIDTH / 2 + 220.4 + (x * 19.6), (Game::WINDOW_HEIGHT / 2) + 80 - (120 * flor));
				unBreakBlock->setColCheck(1);
				unBreakBlock->setInvincibility(true);
				blocksMade.push_back(unBreakBlock);
				x++;
			}
		}
		
		
		x = 1;
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
			//std::cout << "notEnough for floor: " << flor << std::endl;
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
			if (blockPool->getAvailableSize() >= 5) {
				for (int i = 0; i < 5; i++) {
					unBreakBlock = (Block*)blockPool->requestPoolable();
					unBreakBlock->setPosition(Game::WINDOW_WIDTH / 2 + 240 - (x * 19.6), (Game::WINDOW_HEIGHT / 2) + 80 - (120 * flor));
					unBreakBlock->setColCheck(0);
					unBreakBlock->setInvincibility(true);
					blocksMade.push_back(unBreakBlock);
					x++;
				}
			}
			flor++;
		}
		else {
			//std::cout << "notEnough for floor: " << flor << std::endl;
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
			//std::cout << "notEnough for floor: " << flor << std::endl;
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
			//std::cout << "notEnough for floor: " << flor << std::endl;
		}
		
		break;
	case 7:
		if (blockPool->getAvailableSize() >= 17) {
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
			//std::cout << "notEnough for floor: " << flor << std::endl;
		}

		break;
	case 8:
		if (blockPool->getAvailableSize() >= 17) {
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
			//std::cout << "notEnough for floor: " << flor << std::endl;
		}

		break;
	
	}
	//if camera has been moved CLEAR SPACE
	if (GameInfo::cameraMoving) {
		clearUnused();
	}
}


void BlockHandler::clearUnused()
{
	if (flor <= 6) {
		sf::View cam = CameraManager::getInstance()->getViewCamera();
		int cleaned = 0;
		for (int i = 0; i < this->blocksMade.size(); i++) {
			std::cout << "Block at: " << blocksMade[i]->getTransformable()->getPosition().y << std::endl;
			std::cout << "Cam was: " << cam.getCenter().y - 60 << std::endl;
			if (blocksMade[i]->getTransformable()->getPosition().y > cam.getCenter().y - 60) {
				std::cout << "got cleaned" << std::endl;
				ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::BLOCK_POOL_TAG)->releasePoolable(blocksMade[i]);
				cleaned++;
			}

		}
		std::cout << cleaned << std::endl;
	}
	//std::cout << "Cleaning blocks" << std::endl;
	
}

float BlockHandler::generateRandom()
{
	//rng
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_real_distribution<> prob(0.f, 100.0f);

	return prob(gen);
	
}




