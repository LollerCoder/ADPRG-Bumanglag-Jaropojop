#include "Block.h"


Block::Block(std::string name, float x, float y) : AbstractPoolable(name, Tag::BLOCK) {
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

	std::cout << "IM BLOCK" << std::endl;
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

void Block::setColCheck(int col)
{
	this->colCheck = col;
	this->frame = FileReader::getInstance()->getFrame("block", colCheck);
	this->sprite->setTextureRect(sf::IntRect(
		this->frame[0],
		this->frame[1],
		this->frame[2],
		this->frame[3]
	)
	);
}

void Block::setInvincibility(bool invinc)
{
	this->isInvincible = invinc;

	if (isInvincible) {
		switch (this->colCheck) {
		case 0:
			this->frame = FileReader::getInstance()->getFrame("block", 3);
			break;
		case 1:
			this->frame = FileReader::getInstance()->getFrame("block", 4);
			break;
		case 2:
			this->frame = FileReader::getInstance()->getFrame("block", 5);
			break;
		}
	}
	this->sprite->setTextureRect(sf::IntRect(
		this->frame[0],
		this->frame[1],
		this->frame[2],
		this->frame[3]
	)
	);
}

bool Block::getInvi()
{
	return this->isInvincible;
}


void Block::onActivate()
{

	PhysicsManager::getInstance()->trackObject(this->collider);
}

void Block::onRelease()
{
	PhysicsManager::getInstance()->untrackObject(this->collider);
}

AbstractPoolable* Block::clone()
{
	AbstractPoolable* cloned = new Block(this->name, Game::WINDOW_WIDTH / 2 + 240, (Game::WINDOW_HEIGHT / 2) + 80);
	return cloned;
}

