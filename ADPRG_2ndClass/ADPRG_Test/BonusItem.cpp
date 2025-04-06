#include "BonusItem.hpp"
#include "GameValue.hpp"

BonusItem::BonusItem(std::string name) : AGameObject(name, Tag::ITEM), CollisionListener() {

}

void BonusItem::initialize() {
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("bonus_item"));
	Frame frame = FileReader::getInstance()->getFrame("bonus_item", PlayerScore::Level % 2);

	this->sprite->setTextureRect(sf::IntRect(
												frame[0],
												frame[1],
												frame[2],
												frame[3]
											)
								);

	sf::IntRect frameRect = this->sprite->getTextureRect();
	this->sprite->setOrigin(frameRect.width / 2, frameRect.height / 2);
	this->transformable.setPosition((Game::WINDOW_WIDTH / 2), -680.0f);

	Renderer* renderer = new Renderer("ItemRenderer");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	this->getTransformable()->setScale(0.7f, 0.7f);

	this->collider = new Collider("ItemCollider");
	this->collider->setLocalBounds(sprite->getGlobalBounds());
	this->collider->setCollisionListener(this);
	this->attachComponent(this->collider);
	PhysicsManager::getInstance()->trackObject(this->collider);
}

void BonusItem::onCollisionEnter(AGameObject* gameObject) {
	this->setEnabled(false);
	PlayerScore::bonusScore = 100;
	SceneManager::getInstance()->loadScene(SceneManager::EVAL_SCENE_NAME);
}

void BonusItem::onCollisionExit(AGameObject* gameObject) {

}
