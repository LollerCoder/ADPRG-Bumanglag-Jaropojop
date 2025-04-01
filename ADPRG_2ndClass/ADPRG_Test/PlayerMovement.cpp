#include "PlayerMovement.hpp"

PlayerMovement::PlayerMovement(std::string name) : AbstractComponent(name, Script){

}

void PlayerMovement::perform(){
	Player* airplanePlayer = (Player*)this->getOwner();
	PlayerInputController* inputController = (PlayerInputController*)airplanePlayer->getComponentsOfType(ComponentType::Input)[0];
	sf::Transformable* playerTransformable = airplanePlayer->getTransformable();

	if (playerTransformable == nullptr || inputController == nullptr) {
		std::cout << "Controller or Transformable not found" << std::endl;
	}

	static float hitAnimTimer = 0.0f; 
	static float frameTimer = 0.0f;    
	static bool isHitting = false;    

	if (!this->isGrounded) {
		this->velocity.y += GRAVITY_FORCE;
	}
	else {
		this->velocity.y = 0; 
	}

	if (isHitting) {
		hitAnimTimer -= this->deltaTime.asSeconds();
		frameTimer += this->deltaTime.asSeconds();

		if (frameTimer >= 0.1f) {
			airplanePlayer->incrementHitFrame();
			frameTimer = 0.0f;
		}

		if (hitAnimTimer <= 0.0f) {
			isHitting = false;
		}
		return; 
	}

	if (inputController->isAttack() && !isHitting && this->isGrounded) {
		isHitting = true;
		hitAnimTimer = 0.2f;
		frameTimer = 0.0f;
		airplanePlayer->incrementHitFrame();
		this->fAnimFreq = 0;
		return; 
	}

	if (!(inputController->isRight() ||
		inputController->isLeft())) {
		airplanePlayer->setWalkFrame(0);
		this->fAnimFreq = 0;
	}
	else{
		if (this->fAnimFreq >= this->fAnimThresh && this->isGrounded) {
			airplanePlayer->incrementWalkFrame();
			this->fAnimFreq = 0;
		}

		this->fAnimFreq += this->deltaTime.asSeconds();
	}
	
	if (inputController->isJump() && this->isGrounded) {
		this->velocity.y = -JUMP_FORCE; 
		isGrounded = false; 
	}
	else if (inputController->isRight()) {
		this->velocity.x = this->SPEED_MULTIPLIER;
		//airplanePlayer->getSprite()->setScale(1.f, 1.f);
		airplanePlayer->getTransformable()->setScale(0.75f, 0.75f);
	}
	else if (inputController->isLeft()) {
		this->velocity.x = -this->SPEED_MULTIPLIER;
		//airplanePlayer->getSprite()->setScale(-1.f, 1.f);
		airplanePlayer->getTransformable()->setScale(-0.75f, 0.75f);
	}
	else {
		this->velocity.x = 0; 
	}

	playerTransformable->move(this->velocity * deltaTime.asSeconds());

	if (playerTransformable->getPosition().y >= 410) {
		this->isGrounded = true;
		playerTransformable->setPosition(playerTransformable->getPosition().x, 410);
	}

}
