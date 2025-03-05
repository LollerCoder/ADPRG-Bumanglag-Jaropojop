#include "PhysicsManager.hpp"

PhysicsManager* PhysicsManager::sharedInstance = nullptr;

void PhysicsManager::initialize(std::string name, AGameObject* parent) {
	sharedInstance = new PhysicsManager(name);
	parent->attachComponent(sharedInstance);
}

PhysicsManager* PhysicsManager::getInstance() {
	return sharedInstance;
}

void PhysicsManager::trackObject(Collider* object) {
	this->trackedObjects.push_back(object);
}

void PhysicsManager::untrackObject(Collider* object) {
	this->forCleaningObjects.push_back(object);
}

void PhysicsManager::perform() {
	for (int i = 0; i < this->trackedObjects.size(); i++) {
		for (int j = i + 1; j < this->trackedObjects.size(); j++) {
			if (this->trackedObjects[i]->getOwner()->isEnabled() && 
				this->trackedObjects[j]->getOwner()->isEnabled()) {
				// check the collision between two objects
				if (this->trackedObjects[i]->willCollide(this->trackedObjects[j])) {
					// call collisionEnter for each one
					if (!this->trackedObjects[i]->hasCollisionWith(this->trackedObjects[j])) {
						this->trackedObjects[i]->addCollision(this->trackedObjects[j]);
						this->trackedObjects[i]->collisionEnter(this->trackedObjects[j]->getOwner());

					}
					if (!this->trackedObjects[j]->hasCollisionWith(this->trackedObjects[i])) {
						this->trackedObjects[j]->addCollision(this->trackedObjects[i]);
						this->trackedObjects[j]->collisionEnter(this->trackedObjects[i]->getOwner());
					}
				}
				else { 
					// call collisionExit if not colliding for each one
					if (this->trackedObjects[i]->hasCollisionWith(this->trackedObjects[j])) {
						this->trackedObjects[i]->collisionExit(this->trackedObjects[j]->getOwner());
						this->trackedObjects[i]->removeCollision(this->trackedObjects[j]);
					}
					if (this->trackedObjects[j]->hasCollisionWith(this->trackedObjects[i])) {
						this->trackedObjects[j]->collisionExit(this->trackedObjects[i]->getOwner());
						this->trackedObjects[j]->removeCollision(this->trackedObjects[i]);
					}
				}
			}
		}

		this->cleanUpObjects();
	}
}

void PhysicsManager::cleanUpObjects() {
	for (int i = 0; i < this->forCleaningObjects.size(); i++) {
		for (int j = 0; j < this->trackedObjects.size(); j++) {
			if (this->forCleaningObjects[i] == this->trackedObjects[j]) {
				this->trackedObjects.erase(this->trackedObjects.begin() + j);
			}
		}
	}

	this->forCleaningObjects.clear();
}
