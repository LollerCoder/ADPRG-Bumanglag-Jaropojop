#include "BonusItem.hpp"
#include "PlayerScore.hpp"

BonusItem::BonusItem(std::string name) : AGameObject(name, Tag::ITEM), CollisionListener() {

}

void BonusItem::initialize() {
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("bonus_item"));
	this->frame = FileReader::getInstance()->getFrame("bonus_item", PlayerScore::Level % 2);

	this->sprite->setTextureRect(sf::IntRect(
												this->frame[0],
												this->frame[1],
												this->frame[2],
												this->frame[3]
											)
								);

	sf::IntRect frameRect = this->sprite->getTextureRect();
	this->sprite->setOrigin(frameRect.width / 2, frameRect.height / 2);
	this->transformable.setPosition(Game::WINDOW_WIDTH / 2, (Game::WINDOW_HEIGHT / 2));

	Renderer* renderer = new Renderer("ItemRenderer");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	this->getTransformable()->setScale(0.7f, 0.7f);

	this->collider = new Collider("ItemCollider");
	this->collider->setLocalBounds(sprite->getGlobalBounds());
	this->collider->setCollisionListener(this);
	this->attachComponent(this->collider);
}

void BonusItem::onCollisionEnter(AGameObject* gameObject) {
	this->setEnabled(false);
	PlayerScore::bonusScore = 100;
	SceneManager::getInstance()->loadScene(SceneManager::EVAL_SCENE_NAME);
}

void BonusItem::onCollisionExit(AGameObject* gameObject) {

}
