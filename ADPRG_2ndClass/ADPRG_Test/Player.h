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
};