#pragma once
#include "AbstractComponent.hpp"
#include "CollisionListener.hpp"
#include "AGameObject.hpp"
#include <unordered_set>

class Collider : public AbstractComponent {
public:
	Collider(std::string name);
public:
	void setCollisionListener(CollisionListener* listener);

	bool willCollide(Collider* another);
	bool hasCollisionWith(Collider* collider);
	void addCollision(Collider* collider);
	void removeCollision(Collider* collider);

	sf::FloatRect getGlobalBounds();
	void setLocalBounds(sf::FloatRect localBounds);
	void collisionEnter(AGameObject* gameObjects);
	void collisionExit(AGameObject* gameObjects);

	void perform();
	void clearCollisions();

private:
	bool checked = false;
	
	std::unordered_set<Collider*> collisions;
	sf::FloatRect localBounds;
	CollisionListener* listener;
};

