#include "Flyer.hpp"
#include "GameValue.hpp"

Flyer::Flyer(std::string name, sf::Vector2f spawn) : AGameObject(name, Tag::ENEMY), CollisionListener(){
	this->spawn = spawn;
}

void Flyer::initialize() {
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Bird_1"));

	this->flyFrames.push_back(FileReader::getInstance()->getFrame("Bird_1", 0)); // grabs the first frame info for flying animation
	this->flyFrames.push_back(FileReader::getInstance()->getFrame("Bird_1", 1)); // grabs the second frame info

	// sets to the texture to the first frame
	this->sprite->setTextureRect(sf::IntRect(
												this->flyFrames[0][0],
												this->flyFrames[0][1],
												this->flyFrames[0][2],
												this->flyFrames[0][3]
											)
								);

	sf::IntRect frameRect = this->sprite->getTextureRect();
	this->sprite->setOrigin(frameRect.width / 2, frameRect.height / 2);
	this->transformable.setPosition(Game::WINDOW_WIDTH / 2, (Game::WINDOW_HEIGHT / 2) + 20);

	Renderer* renderer = new Renderer("FlyerSprite");
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);

	this->getTransformable()->setScale(0.7f, 0.7f);

	this->collider = new Collider("FlyerCollider");
	this->collider->setLocalBounds(sprite->getGlobalBounds());
	this->collider->setCollisionListener(this);
	this->attachComponent(this->collider);

	FlyerMovement* flyerMovement = new FlyerMovement("FlyerMovement");
	this->attachComponent(flyerMovement);

	this->setPosition(this->spawn.x, this->spawn.y);

	PhysicsManager::getInstance()->trackObject(this->collider);
}

void Flyer::processInput(sf::Event event) {
	AGameObject::processInput(event);
	// changes the spawn point after level progression in the game
	if (GameInfo::cp1 && GameInfo::currCP == 0 && !this->hidden) {
		this->setSpawnLoc(this->spawn.x, this->spawn.y - 355);
		this->hidden = true;
		this->setEnabled(false);
	}
	if (GameInfo::cp2 && GameInfo::currCP == 1 && !this->hidden) {
		this->setSpawnLoc(this->spawn.x, this->spawn.y - 250);
		this->hidden = true;
		this->setEnabled(false);
		this->onSecond = true;
	}
	if (GameInfo::cp3 && GameInfo::currCP == 2 && !this->hidden) {
		this->setSpawnLoc(this->spawn.x, this->spawn.y);
		this->setEnabled(false);
		this->onFinal = true;
	}
}

void Flyer::update(sf::Time deltaTime) {
	// first check if dead or despawned
	if (!this->isEnabled() && !this->onFinal) {
		this->hidden = true;
		this->setPosition(this->spawn.x, this->spawn.y);
		this->setEnabled(true);
	}

	// timer for when to move again
	if (this->hidden) {
		this->timer += deltaTime.asSeconds();
		if (this->timer >= this->RESPAWN_TIMER) {
			this->setEnabled(true);
			this->timer = 0.0f;
			this->hidden = false;
		}
	}
	else {
		AGameObject::update(deltaTime);
	}
}

void Flyer::onCollisionExit(AGameObject* contact) {

}

void Flyer::onCollisionEnter(AGameObject* contact) {

}

 // increments through fly frames for animation
void Flyer::incrementFlyFrame() {
	int frame = this->currWalkFrame + 1;
	if (!(frame >= this->flyFrames.size() || frame < 0)) {
		this->currWalkFrame = frame;
	}
	else {
		this->currWalkFrame = 0;
	}
	this->sprite->setTextureRect(sf::IntRect(
		this->flyFrames[this->currWalkFrame][0],
		this->flyFrames[this->currWalkFrame][1],
		this->flyFrames[this->currWalkFrame][2],
		this->flyFrames[this->currWalkFrame][3]
	)
	);
}
