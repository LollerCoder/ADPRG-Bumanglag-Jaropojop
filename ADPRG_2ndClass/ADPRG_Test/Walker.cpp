#include "Walker.h"

Walker::Walker(std::string name, sf::Vector2f spawn) : AGameObject(name, Tag::ENEMY) {
	this->spawn = spawn;
}

void Walker::initialize() {
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Walker"));

	this->walkFrames.push_back(FileReader::getInstance()->getFrame("Walker", 0));
	this->walkFrames.push_back(FileReader::getInstance()->getFrame("Walker", 1));

	this->sprite->setTextureRect(sf::IntRect(
											this->walkFrames[0][0],
											this->walkFrames[0][1],
											this->walkFrames[0][2],
											this->walkFrames[0][3]
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

void Walker::processInput(sf::Event event) {
	AGameObject::processInput(event);
}

void Walker::update(sf::Time deltaTime) {
	if (!this->isEnabled()) {
		this->hidden = true;
		this->setEnabled(true);
	}

	if(this->hidden) {
		this->timer += deltaTime.asSeconds();
		if (this->timer >= this->respawnCD) {
			this->setEnabled(true);
			this->timer = 0.0f;
			this->hidden = false;
		}
	}
	else {
		AGameObject::update(deltaTime);

	}

}


void Walker::onCollisionExit(AGameObject* contact) {

}

void Walker::onCollisionEnter(AGameObject* contact) {

	//ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG)->releasePoolable((AbstractPoolable*)this);

}

void Walker::incrementWalkFrame() {
	int frame = this->currWalkFrame + 1;
	if (!(frame >= this->walkFrames.size() || frame < 0)) {
		this->currWalkFrame = frame;
	}
	else {
		this->currWalkFrame = 0;
	}
	this->sprite->setTextureRect(sf::IntRect(
												this->walkFrames[this->currWalkFrame][0],
												this->walkFrames[this->currWalkFrame][1],
												this->walkFrames[this->currWalkFrame][2],
												this->walkFrames[this->currWalkFrame][3]
											)
								);
}
