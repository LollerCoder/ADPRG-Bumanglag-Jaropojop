#pragma once
#include "Game.h"
#include "AGameObject.hpp"
#include "TextureManager.hpp"
#include "PlayerInputController.hpp"
#include "PlayerMovement.hpp"
#include "Renderer.hpp"
#include "FileReader.hpp"
#include "CollisionListener.hpp"
#include "Collider.hpp"


class Player : public AGameObject, public CollisionListener {
public:
	Player(std::string name);
public:
	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);
	void incrementWalkFrame();
	void incrementHitFrame();
	void setWalkFrame(int frame);
	void setJumpFrame(int frame);

	//collision
	void onCollisionExit(AGameObject* contact);
	void onCollisionEnter(AGameObject* contact);

public:
	std::vector<Frame> walkFrames;
	std::vector<Frame> hitFrames;
	int currWalkFrame = -1;
	int currHitFrame = -1;
	Collider* collider;
};