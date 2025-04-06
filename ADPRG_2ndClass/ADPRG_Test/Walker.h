#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "AGameObject.hpp"
#include "TextureManager.hpp"
#include "Game.h"
#include "Collider.hpp"
#include "CollisionListener.hpp"
#include "WalkerMovement.hpp"

class Walker : public AGameObject , public CollisionListener
{
public:
	Walker(std::string name, sf::Vector2f spawn);

	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);

	//collision
	void onCollisionExit(AGameObject* contact);
	void onCollisionEnter(AGameObject* contact);

	Collider* collider;
public:
	// increments throught the walking frames
	void incrementWalkFrame();
private:
	// stores walking frames for animation
	std::vector<Frame> walkFrames;
	int currWalkFrame = -1;

	// toggle for when player is on final checkpoint
	bool onFinal = false;

	// flag for when it was despawned
	bool hidden = false;
	
	// timer/cooldown
	float timer = 0.0f;
	float respawnCD = 1.5f;
};

