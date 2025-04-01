#pragma once
#include <SFML/Graphics.hpp>
#include "AGameObject.hpp"
#include "TextureManager.hpp"
#include "Game.h"
class Block : public AGameObject
{



public:
	Block(std::string name);
	virtual void initialize();

private:





};

