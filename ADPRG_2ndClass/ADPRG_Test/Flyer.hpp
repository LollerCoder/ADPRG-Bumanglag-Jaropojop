#pragma once
#include "AGameObject.hpp"
#include "TextureManager.hpp"
#include "FileReader.hpp"
#include "Game.h"
#include "Collider.hpp"
#include "CollisionListener.hpp"
#include "FlyerMovement.hpp"

class Flyer : public AGameObject, public CollisionListener {
public:
	Flyer(std::string name, sf::Vector2f spawn);
public:
	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);

	void onCollisionExit(AGameObject* contact);
	void onCollisionEnter(AGameObject* contact);
	void incrementFlyFrame();
private:
	std::vector<Frame> flyFrames;
	int currWalkFrame = -1;

	bool onFinal = false;
	bool hidden = false;
	float timer = 0.0f;
	const float RESPAWN_TIMER = 1.5f;

	Collider* collider;
};

