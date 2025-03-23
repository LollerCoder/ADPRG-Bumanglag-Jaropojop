#pragma once
#include "Game.h"
#include "AGameObject.hpp"
#include "TextureManager.hpp"
#include "PlayerInputController.hpp"
#include "PlayerMovement.hpp"
#include "Renderer.hpp"

class Player : public AGameObject {
public:
	Player(std::string name);
public:
	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);
	void incrementWalkFrame();
	void incrementHitFrame();
	void setWalkFrame(int frame);
public:
	std::vector<sf::Texture*> walkFrames;
	std::vector<sf::Texture*> hitFrames;
	int currWalkFrame = -1;
	int currHitFrame = -1;
};