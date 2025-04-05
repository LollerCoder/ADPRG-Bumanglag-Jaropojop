#pragma once
#include "AGameObject.hpp"
#include "TextureManager.hpp"
#include "Game.h"

class EvaluationBox : public AGameObject{
public:
	EvaluationBox(std::string name);
public:
	void initialize();
	void processInput(sf::Event event);
};

