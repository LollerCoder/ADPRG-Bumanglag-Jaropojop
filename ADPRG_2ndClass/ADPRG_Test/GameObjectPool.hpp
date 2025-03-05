#pragma once
#include "AbstractPoolable.hpp"
#include "GameObjectManager.hpp"

class GameObjectPool {
public:
	GameObjectPool(std::string tag,
				   AbstractPoolable* poolableCopy,
				   int poolableSize,
				   AGameObject* parent);
	~GameObjectPool();
public:
	void initialize();
	bool hasObjectAvailable(int requestSize);
	AbstractPoolable* requestPoolable();
	std::vector<AbstractPoolable*>requestPoolableBatch(int size);

	void releasePoolable(AbstractPoolable* poolableObject);
	void releasePoolableBatch(std::vector<AbstractPoolable*> objectList);

	std::string getTag();
private:
	std::string tag;
	AbstractPoolable* poolableCopy = NULL;
	AGameObject* parent = NULL;
	int maxPoolSize = 20;
	std::vector<AbstractPoolable*> availableObjects;
	std::vector<AbstractPoolable*> usedObjects;
private:
	void setEnabled(AbstractPoolable* poolableObject, bool flag);
};

