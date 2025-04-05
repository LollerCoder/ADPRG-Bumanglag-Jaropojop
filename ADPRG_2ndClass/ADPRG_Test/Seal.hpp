#pragma once
#include <SFML/Graphics.hpp>
#include "AGameObject.hpp"
#include "TextureManager.hpp"
#include "Game.h"

class Seal : public AGameObject
{
public:
	Seal(std::string name, Tag tag);
	virtual void initialize();

private:
};