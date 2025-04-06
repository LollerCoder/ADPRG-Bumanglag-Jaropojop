#include "BonusItem.hpp"

BonusItem::BonusItem(std::string name) : AGameObject(name, Tag::ITEM), CollisionListener() {

}

void BonusItem::initialize() {
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("bonus_item"));
	this->frame = FileReader::getInstance()->getFrame("bonus_item", );

	this->sprite->setTextureRect(sf::IntRect(
												this->frame[0],
												this->frame[1],
												this->frame[2],
												this->frame[3]
											)
								);

	sf::IntRect frameRect = this->sprite->getTextureRect();
	this->sprite->setOrigin(frameRect.width / 2, frameRect.height / 2);
	this->transformable.setPosition(Game::WINDOW_WIDTH / 2, (Game::WINDOW_HEIGHT / 2) + 20);

	GroundChecker* gr = new GroundChecker("GroundCheck", 0.2, 0.05);
	this->attachChild(gr);
	sf::IntRect playerBounds3 = this->getSprite()->getTextureRect();
	gr->setPosition(0, playerBounds3.height / 2);
	gr->getSprite()->rotate(90.0f);
	gr->setEnabled(true);

	Renderer* renderer = new Renderer("WalkerSprite");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	this->getTransformable()->setScale(0.7f, 0.7f);

	this->collider = new Collider("WalkerCollider");
	this->collider->setLocalBounds(sprite->getGlobalBounds());
	this->collider->setCollisionListener(this);
	this->attachComponent(this->collider);

	WalkerMovement* walkerMovement = new WalkerMovement("WalkerMovement");
	this->attachComponent(walkerMovement);

	this->setPosition(this->spawn.x, this->spawn.y);

	PhysicsManager::getInstance()->trackObject(this->collider);
}

void BonusItem::onCollisionEnter(AGameObject* gameObject) {

}

void BonusItem::onCollisionExit(AGameObject* gameObject) {

}
