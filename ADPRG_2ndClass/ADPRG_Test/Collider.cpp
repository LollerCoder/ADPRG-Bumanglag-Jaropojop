#include "Collider.hpp"

Collider::Collider(std::string name) : AbstractComponent(name, AbstractComponent::Physics) {

}

void Collider::setCollisionListener(CollisionListener* listener) {
	this->listener = listener;
}

bool Collider::willCollide(Collider* another) {
	sf::FloatRect A = this->getGlobalBounds();
	sf::FloatRect B = another->getGlobalBounds();

	return A.intersects(B);
}

bool Collider::hasCollisionWith(Collider* collider){

	return this->collisions.find(collider) != this->collisions.end();
}

void Collider::addCollision(Collider* collider){
	this->collisions.insert(collider);
}

void Collider::removeCollision(Collider* collider) {
	this->collisions.erase(collider);
}


sf::FloatRect Collider::getGlobalBounds() {
	AGameObject* owner = this->getOwner();
	return owner->getGlobalTransform().transformRect(this->localBounds);
}

void Collider::setLocalBounds(sf::FloatRect localBounds) {
	this->localBounds = localBounds;
}

void Collider::collisionEnter(AGameObject* gameObjects) {
	if (this->listener != nullptr) {
		this->listener->onCollisionEnter(gameObjects);
	}
}

void Collider::collisionExit(AGameObject* gameObjects) {
	if (this->listener != nullptr) {
		this->listener->onCollisionExit(gameObjects);
	}
}

void Collider::perform() {

}

void Collider::clearCollisions() {
	for (Collider* collider : this->collisions) {
		collider->collisionExit(this->getOwner());
		this->collisionExit(collider->getOwner());
		collider->removeCollision(this);
	}
	
	this->collisions.clear();
}


