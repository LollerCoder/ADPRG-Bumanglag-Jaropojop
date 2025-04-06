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
	void incrementWalkFrame();
private:
	std::vector<Frame> walkFrames;
	int currWalkFrame = -1;

	bool onFinal = false;
	bool hidden = false;
	float timer = 0.0f;
	float respawnCD = 1.5f;
};

