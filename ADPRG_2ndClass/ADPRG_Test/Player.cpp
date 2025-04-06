#include "Player.h"

Player::Player(std::string name) : AGameObject(name, Tag::PLAYER), CollisionListener() {

}

void Player::initialize() {
	this->sprite = new sf::Sprite();
	//this->walkFrames = TextureManager::getInstance()->getFrames("player-walk");
	//this->hitFrames = TextureManager::getInstance()->getFrames("player-hit");
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Player"));
	
	this->walkFrames.push_back(FileReader::getInstance()->getFrame("Player", 0));
	this->walkFrames.push_back(FileReader::getInstance()->getFrame("Player", 1));
	
	this->hitFrames.push_back(FileReader::getInstance()->getFrame("Player", 2));
	this->hitFrames.push_back(FileReader::getInstance()->getFrame("Player", 3));

	this->sprite->setTextureRect(sf::IntRect(
											this->walkFrames[0][0],
											this->walkFrames[0][1],
											this->walkFrames[0][2],
											this->walkFrames[0][3]
											)
								);

	this->getTransformable()->setScale(1.0f, 1.0f);

	sf::IntRect frameRect = this->sprite->getTextureRect();
	this->sprite->setOrigin(frameRect.width / 2, frameRect.height / 2);
	this->transformable.setPosition(Game::WINDOW_WIDTH / 2, (Game::WINDOW_HEIGHT / 2) + 200);

	GroundChecker* gr = new GroundChecker("GroundCheck", 0.05, 0.015);
	this->attachChild(gr);
	sf::IntRect playerBounds3 = this->getSprite()->getTextureRect();
	gr->setPosition(0, +playerBounds3.height / 2 -3);
	gr->getSprite()->rotate(90.0f);
	gr->setEnabled(true);

	PlayerInputController* playerInput = new PlayerInputController("MyPlayerInput");
	this->attachComponent(playerInput);

	PlayerMovement* playerMovement = new PlayerMovement("MyPlayerMovement");
	this->attachComponent(playerMovement);

	Renderer* renderer = new Renderer("MyPlayerSprite");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	this->collider = new Collider("PlayerCollider");

	collider->setLocalBounds(sprite->getGlobalBounds());
	this->collider->setCollisionListener(this);
	this->attachComponent(this->collider);

	PhysicsManager::getInstance()->trackObject(this->collider);

}

void Player::processInput(sf::Event event) {
	AGameObject::processInput(event);
}

void Player::update(sf::Time deltaTime) {
	AGameObject::update(deltaTime);
}

void Player::incrementWalkFrame() {
	int frame = this->currWalkFrame + 1;
	if (!(frame >= this->walkFrames.size() || frame < 0)) {
		this->currWalkFrame = frame;
	}
	else {
		this->currWalkFrame = 0;
	}
	//this->sprite->setTexture(*this->walkFrames[this->currWalkFrame]);
	this->sprite->setTextureRect(sf::IntRect(
											this->walkFrames[this->currWalkFrame][0],
											this->walkFrames[this->currWalkFrame][1],
											this->walkFrames[this->currWalkFrame][2],
											this->walkFrames[this->currWalkFrame][3]
											)
								);
}

void Player::incrementHitFrame() {
	std::cout << this->currHitFrame;
	if (this->currHitFrame + 1 >= this->hitFrames.size() || this->currHitFrame < 0) {
		this->currHitFrame = 0;
	}
	else {
		this->currHitFrame++;
	}
	//this->sprite->setTexture(*this->hitFrames[this->currHitFrame]);
	this->sprite->setTextureRect(sf::IntRect(
											this->hitFrames[this->currHitFrame][0],
											this->hitFrames[this->currHitFrame][1],
											this->hitFrames[this->currHitFrame][2],
											this->hitFrames[this->currHitFrame][3]
											)
								);
}

void Player::setWalkFrame(int frame) {
	if (!(frame >= this->walkFrames.size() || frame < 0)) {
		this->currWalkFrame = frame;
		//this->sprite->setTexture(*this->walkFrames[this->currWalkFrame]);
		this->sprite->setTextureRect(sf::IntRect(
												this->walkFrames[this->currWalkFrame][0],
												this->walkFrames[this->currWalkFrame][1],
												this->walkFrames[this->currWalkFrame][2],
												this->walkFrames[this->currWalkFrame][3]
											)
									);
	}
}

void Player::setJumpFrame(int frame) {
	if (!(frame >= this->walkFrames.size() || frame < 0)) {
		this->currWalkFrame = frame;
		this->sprite->setTextureRect(sf::IntRect(
												this->hitFrames[this->currWalkFrame][0],
												this->hitFrames[this->currWalkFrame][1],
												this->hitFrames[this->currWalkFrame][2],
												this->hitFrames[this->currWalkFrame][3]
												)
									);
	}
}

void Player::onCollisionExit(AGameObject* contact)
{
	
	
}

void Player::onCollisionEnter(AGameObject* contact)
{
	
	//this->setPosition(this->getPosition().x, contact->getTransformable()->getPosition().y );
	std::cout << contact->getTransformable()->getPosition().y << std::endl;
}



