#include "PlayerMovement.hpp"

PlayerMovement::PlayerMovement(std::string name) : AbstractComponent(name, Script){

}

void PlayerMovement::perform(){
	Player* player = (Player*)this->getOwner();
	PlayerInputController* inputController = (PlayerInputController*)player->getComponentsOfType(ComponentType::Input)[0];
	sf::Transformable* playerTransformable = player->getTransformable();

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
			player->incrementHitFrame();
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
		player->incrementHitFrame();
		this->fAnimFreq = 0;

		Hitbox* hit = (Hitbox*)player->findChild("FrontHitbox");
		hit->activate();
		return; 
	}
	else {
		Hitbox* hit = (Hitbox*)player->findChild("FrontHitbox");
		hit->deactivate();
	}

	if (!(inputController->isRight() ||
		inputController->isLeft()) && this->isGrounded) {
		player->setWalkFrame(0);
		this->fAnimFreq = 0;
	}
	else{
		if (this->fAnimFreq >= this->fAnimThresh && this->isGrounded) {
			player->incrementWalkFrame();
			this->fAnimFreq = 0;
		}

		this->fAnimFreq += this->deltaTime.asSeconds();
	}
	
	if (inputController->isJump() && this->isGrounded) {
		this->velocity.y = -JUMP_FORCE; 


		isGrounded = false; 
		player->setJumpFrame(0);

		isGrounded = false;  
		Hitbox* hit = (Hitbox*)player->findChild("TopHitbox");
		hit->activate();

	}
	else if (inputController->isRight()) {
		this->velocity.x = this->SPEED_MULTIPLIER;
		//player->getSprite()->setScale(1.f, 1.f);
		player->getTransformable()->setScale(1.f, 1.f);
	}
	else if (inputController->isLeft()) {
		this->velocity.x = -this->SPEED_MULTIPLIER;
		//player->getSprite()->setScale(-1.f, 1.f);
		player->getTransformable()->setScale(-1.f, 1.f);
	}
	else {
		this->velocity.x = 0; 
	}

	playerTransformable->move(this->velocity * deltaTime.asSeconds());

	if (playerTransformable->getPosition().x < -25.0f) {
		playerTransformable->setPosition(680.0f, playerTransformable->getPosition().y);
	}
	if (playerTransformable->getPosition().x > 680.0f) {
		playerTransformable->setPosition(-25.0f, playerTransformable->getPosition().y);
	}

	if (playerTransformable->getPosition().y >= 400) {
		this->isGrounded = true;


		//hitbox temp
		Hitbox* hit = (Hitbox*)player->findChild("TopHitbox");
		hit->deactivate();
		//hitbox temp

		playerTransformable->setPosition(playerTransformable->getPosition().x, 400);
		
	}
	//std::cout << playerTransformable->getPosition().x << "," << playerTransformable->getPosition().y << std::endl;
}

//void PlayerMovement::setGrounded(bool flag)
//{
//	this->isGrounded = flag;
//}
