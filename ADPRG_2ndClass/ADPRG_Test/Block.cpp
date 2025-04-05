#include "Block.h"


Block::Block(std::string name, float x, float y) :AbstractPoolable(name, Tag::BLOCK) {
	this->transformable.setPosition(x, y);
}

void Block::initialize() {
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("block"));

	this->frame = FileReader::getInstance()->getFrame("block", 2);
	

	this->sprite->setTextureRect(sf::IntRect(
		this->frame[0],
		this->frame[1],
		this->frame[2],
		this->frame[3]
	)
	);



	sf::IntRect frameRect = this->sprite->getTextureRect();
	this->sprite->setOrigin(frameRect.width / 2, frameRect.height / 2);
	this->transformable.setScale(0.45f, 0.45f);

	this->collider = new Collider("BlockCollider");

	collider->setLocalBounds(sprite->getGlobalBounds());
	this->collider->setCollisionListener(this);
	this->attachComponent(this->collider);

	Renderer* renderer = new Renderer("BlockSprite");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	PhysicsManager::getInstance()->trackObject(this->collider);
	//std::cout << "IM BLOCK" << std::endl;
}

void Block::onCollisionExit(AGameObject* contact)
{
}

void Block::onCollisionEnter(AGameObject* contact)
{
	

}

void Block::setPos(float x, float y)
{
	this->transformable.setPosition(x, y);
}

void Block::onActivate()
{
}

void Block::onRelease()
{
}

AbstractPoolable* Block::clone()
{
	AbstractPoolable* cloned = new Block(this->name, Game::WINDOW_WIDTH / 2 + 240, (Game::WINDOW_HEIGHT / 2) + 80);
	return cloned;
}

