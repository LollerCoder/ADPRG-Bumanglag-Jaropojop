#include "PlayerMovement.hpp"
#include "CameraManager.hpp"
#include "GameValue.hpp"

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

	//if (inputController->isJump()) {
	//	this->velocity.y = -this->SPEED_MULTIPLIER - 100;
	//}
	//else {
	//	this->velocity.y = 0;
	//}

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

	float dir = 0.0f;
	
	if (inputController->isJump() && this->isGrounded) {
		this->velocity.y = -JUMP_FORCE; 


		isGrounded = false; 
		player->setJumpFrame(0);


		isGrounded = false;  
		Hitbox* hit = (Hitbox*)player->findChild("TopHitbox");
		hit->activate();



	}
	if (inputController->isRight()) {
		dir = 1.0f;
		//player->getSprite()->setScale(1.f, 1.f);
		player->getTransformable()->setScale(1.f, 1.f);
	}
	else if (inputController->isLeft()) {
		dir = -1.f;
		//player->getSprite()->setScale(-1.f, 1.f);
		player->getTransformable()->setScale(-1.f, 1.f);
	}
	else {
		this->velocity.x = 0; 
	}

	if (!this->isGrounded) {
		this->velocity.x = dir * this->SPEED_MULTIPLIER * this->AIR_SPEED_MULTIPLIER;
	}
	else {
		this->velocity.x = dir * this->SPEED_MULTIPLIER;
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
		BlockBreaker* hit = (BlockBreaker*)player->findChild("TopHitbox");
		hit->deactivate();
		//hitbox temp

		playerTransformable->setPosition(playerTransformable->getPosition().x, 400);
	}

	//std::cout << playerTransformable->getPosition().y << std::endl;

	if (playerTransformable->getPosition().y <= 40.0f && !GameInfo::cp1 && !this->isGrounded && GameInfo::currCP == -1) {
		GameInfo::cp1 = true;
		GameInfo::currCP += 1;
		ApplicationManager::getInstance()->pauseApplication();
		GameInfo::cameraMoving = true;
	}
	if (playerTransformable->getPosition().y <= -315.0f && !GameInfo::cp2 && !this->isGrounded && GameInfo::currCP == 0) {
		GameInfo::cp2 = true;
		GameInfo::currCP += 1;
		ApplicationManager::getInstance()->pauseApplication();
		GameInfo::cameraMoving = true;
	}
	if (playerTransformable->getPosition().y <= -560.0f && !GameInfo::cp3 && !this->isGrounded && GameInfo::currCP == 1) {
		GameInfo::cp3 = true;
		GameInfo::currCP += 1;
		ApplicationManager::getInstance()->pauseApplication();
		GameInfo::cameraMoving = true;
	}
	//if (playerTransformable->getPosition().y <= -885.0f && !Game::cp4 && !this->isGrounded) {
	//	ApplicationManager::getInstance()->pauseApplication();
	//	Game::camera = true;
	//}
	//if (playerTransformable->getPosition().y <= -1180.0f && !Game::cp5 && !this->isGrounded) {
	//	ApplicationManager::getInstance()->pauseApplication();
	//	Game::camera = true;
	//}
	//if (playerTransformable->getPosition().y <= -1360.0f && !Game::cp6 && !this->isGrounded) {
	//	ApplicationManager::getInstance()->pauseApplication();
	//	Game::camera = true;
	//}

	sf::View view = CameraManager::getInstance()->getViewCamera();

	sf::Vector2f center = view.getCenter();
	sf::Vector2f size = view.getSize();

	float left = center.x - size.x / 2.f;
	float right = center.x + size.x / 2.f;
	float top = center.y - size.y / 2.f;
	float bottom = center.y + size.y / 2.f;

	sf::FloatRect cameraBounds(left, top, size.x, size.y);

	center = player->getTransformable()->getPosition();

	left = center.x - player->getSprite()->getGlobalBounds().width / 2.f;
	right = center.x + player->getSprite()->getGlobalBounds().width / 2.f;
	top = center.y - player->getSprite()->getGlobalBounds().height / 2.f;
	bottom = center.y + player->getSprite()->getGlobalBounds().height / 2.f;

	sf::FloatRect playerBounds(left, top, right - left, bottom - top);

	if (!playerBounds.intersects(cameraBounds)) {
		SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE_NAME);
	}

	if (this->velocity.y >= 0) {
		BlockBreaker* hit = (BlockBreaker*)player->findChild("TopHitbox");
		hit->deactivate();
	}
	//std::cout << playerTransformable->getPosition().x << "," << playerTransformable->getPosition().y << std::endl;

}

void PlayerMovement::setGrounded(bool flag)
{
	this->isGrounded = flag;
}

void PlayerMovement::setVelocity(sf::Vector2f newVel)
{
	this->velocity = newVel;
}
