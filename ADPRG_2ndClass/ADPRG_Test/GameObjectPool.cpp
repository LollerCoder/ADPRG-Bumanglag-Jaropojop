#include "GameObjectPool.hpp"

GameObjectPool::GameObjectPool(std::string tag, AbstractPoolable* poolableCopy, int poolableSize, AGameObject* parent) {
	this->tag = tag;
	this->poolableCopy = poolableCopy;
	this->maxPoolSize = poolableSize;
	this->parent = parent;
}

GameObjectPool::~GameObjectPool() {
	delete this->poolableCopy;
	this->poolableCopy = nullptr;
	this->parent = nullptr;
}

void GameObjectPool::initialize() {
	for (int i = 0; i < this->maxPoolSize; i++) {
		AbstractPoolable* poolableObject = this->poolableCopy->clone();

		if (this->parent != nullptr) {
			this->parent->attachChild(poolableObject);
		}
		else {
			GameObjectManager::getInstance()->addObject(poolableObject);
		}

		poolableObject->setEnabled(false);
		this->availableObjects.push_back(poolableObject);
	}
}

bool GameObjectPool::hasObjectAvailable(int requestSize) {
	return requestSize <= this->availableObjects.size();
}

AbstractPoolable* GameObjectPool::requestPoolable() {
	if (this->hasObjectAvailable(1)) {
		//std::cout << this->getTag() << std::endl;
		AbstractPoolable* poolableObject = this->availableObjects[this->availableObjects.size() - 1];
		this->availableObjects.erase(this->availableObjects.begin() + this->availableObjects.size() - 1);
		this->usedObjects.push_back(poolableObject);

		//std::cout << "Requested object. Available: " << this->availableObjects.size() 
				  //<< "\nUsed: " << this->usedObjects.size() << std::endl;
		
		this->setEnabled(poolableObject, true);
		return poolableObject;
	}
	else {
		//std::cerr << "No more poolable " << this->poolableCopy->getName() << " available!" << std::endl;
		return NULL;
	}
}

std::vector<AbstractPoolable*> GameObjectPool::requestPoolableBatch(int size) {
	std::vector<AbstractPoolable*> returnList;
	if (this->hasObjectAvailable(size)) {
		for (int i = 0; i < size; i++) {
			returnList.push_back(this->requestPoolable());
		}
	}
	else {
		//std::cerr << "Insufficient " << this->poolableCopy->getName() << " available in pool."
			//<< "Count is: " << this->availableObjects.size() << " while request is " << size << std::endl;
	}
	return returnList;
}

void GameObjectPool::releasePoolable(AbstractPoolable* poolableObject) {

	int index = -1;

	for (int i = 0; i < this->usedObjects.size() && index == -1; i++) {
		if (poolableObject == this->usedObjects[i]) {
			index = i;
		}
	}

	if (index != -1) {
		this->availableObjects.push_back(poolableObject);
		this->usedObjects.erase(this->usedObjects.begin() + index);
		this->setEnabled(poolableObject, false);
	}
}

void GameObjectPool::releasePoolableBatch(std::vector<AbstractPoolable*> objectList) {
	std::vector<int> objectIndex;
	for (int i = 0; i < this->usedObjects.size(); i++) {
		bool found = false;
		for (int j = 0; j < objectList.size() && !found; j++) {
			if (this->usedObjects[i] == objectList[j]) {
				objectIndex.push_back(i);
				found = true;
			}
		}
	}

	if (objectIndex.size() > 0) {
		AbstractPoolable* poolable;
		int index;
		for (int i = objectIndex.size(); i >= 0; i--) {
			index = objectIndex[i];
			poolable = this->usedObjects[index];

			this->availableObjects.push_back(poolable);
			this->usedObjects.erase(this->usedObjects.begin() + index);
			this->setEnabled(poolable, false);
		}
	}
}

std::string GameObjectPool::getTag() {
	return this->tag;
}

float GameObjectPool::getAvailableSize()
{
	
	return this->maxPoolSize;
}

void GameObjectPool::setEnabled(AbstractPoolable* poolableObject, bool flag) {
	if (flag) {
		poolableObject->setEnabled(true);
		poolableObject->onActivate();
	}
	else {
		poolableObject->setEnabled(false);
		poolableObject->onRelease();
	}
}


