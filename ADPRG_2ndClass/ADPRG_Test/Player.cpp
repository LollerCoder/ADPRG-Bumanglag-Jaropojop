#include "Player.h"

Player::Player(std::string name) : AGameObject(name) {

}

void Player::initialize() {
	this->sprite = new sf::Sprite();
	//this->sprite->setTexture(*TextureManager::getInstance()->getTexture("player-1"));
	this->texFrames = TextureManager::getInstance()->getFrames("player");
	this->sprite->setTexture(*this->texFrames[0]);

	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable.setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);

	PlayerInputController* playerInput = new PlayerInputController("MyPlayerInput");
	this->attachComponent(playerInput);

	PlayerMovement* playerMovement = new PlayerMovement("MyPlayerMovement");
	this->attachComponent(playerMovement);

	Renderer* renderer = new Renderer("MyPlayerSprite");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);
}

void Player::processInput(sf::Event event) {
	AGameObject::processInput(event);
}

void Player::update(sf::Time deltaTime) {
	AGameObject::update(deltaTime);
}

void Player::incrementFrame() {
	int frame = this->currFrame + 1;
	if (!(frame >= this->texFrames.size() || frame < 0)) {
		this->currFrame = frame;
	}
	else {
		this->currFrame = 0;
	}
	this->sprite->setTexture(*this->texFrames[this->currFrame]);
}

void Player::setFrame(int frame) {
	if (!(frame >= this->texFrames.size() || frame < 0)) {
		this->currFrame = frame;
		this->sprite->setTexture(*this->texFrames[this->currFrame]);
	}
}



