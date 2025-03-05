#pragma once
#include "AGameObject.hpp"
#include "AbstractComponent.hpp"
#include <unordered_map>
#include <vector>
#include <iostream>
#include "Collider.hpp"

typedef std::vector<Collider*> CollisionList;

class PhysicsManager : public AbstractComponent {
public:
	static void initialize(std::string name, AGameObject* parent);
	static PhysicsManager* getInstance();

	void trackObject(Collider* object);
	void untrackObject(Collider* object);
	void perform();
private:
	PhysicsManager(std::string name) : AbstractComponent(name, Script) {};
	PhysicsManager(PhysicsManager const&) : AbstractComponent(name, Script) {};
	PhysicsManager& operator=(PhysicsManager const&) {};

	CollisionList trackedObjects;
	CollisionList forCleaningObjects;

	static PhysicsManager* sharedInstance;

	void cleanUpObjects();


};

