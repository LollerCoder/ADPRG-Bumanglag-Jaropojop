#include "Player.h"

Player::Player(std::string name) : AGameObject(name) {

}

void Player::initialize() {
	this->sprite = new sf::Sprite();
	//this->sprite->setTexture(*TextureManager::getInstance()->getTexture("player-1"));
	this->walkFrames = TextureManager::getInstance()->getFrames("player-walk");
	this->hitFrames = TextureManager::getInstance()->getFrames("player-hit");
	this->sprite->setTexture(*this->walkFrames[0]);

	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable.setPosition(Game::WINDOW_WIDTH / 2, (Game::WINDOW_HEIGHT / 2) + 20);

	PlayerInputController* playerInput = new PlayerInputController("MyPlayerInput");
	this->attachComponent(playerInput);

	PlayerMovement* playerMovement = new PlayerMovement("MyPlayerMovement");
	this->attachComponent(playerMovement);

	Renderer* renderer = new Renderer("MyPlayerSprite");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	this->getTransformable()->setScale(0.75f, 0.75f);
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
	this->sprite->setTexture(*this->walkFrames[this->currWalkFrame]);
}

void Player::incrementHitFrame() {
	std::cout << this->currHitFrame;
	if (this->currHitFrame + 1 >= this->hitFrames.size() || this->currHitFrame < 0) {
		this->currHitFrame = 0;
	}
	else {
		this->currHitFrame++;
	}
	this->sprite->setTexture(*this->hitFrames[this->currHitFrame]);
}

void Player::setWalkFrame(int frame) {
	if (!(frame >= this->walkFrames.size() || frame < 0)) {
		this->currWalkFrame = frame;
		this->sprite->setTexture(*this->walkFrames[this->currWalkFrame]);
	}
}



