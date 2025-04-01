#pragma once
#include <SFML/Graphics.hpp>
#include "AGameObject.hpp"
#include "TextureManager.hpp"
#include "Game.h"

class Entity : public AGameObject
{
public:
	Entity(std::string name);
	virtual void initialize();

private:


};

	