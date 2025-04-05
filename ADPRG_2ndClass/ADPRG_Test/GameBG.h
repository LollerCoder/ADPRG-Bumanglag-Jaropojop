#pragma once
#include <SFML/Graphics.hpp>
#include "AGameObject.hpp"
#include "TextureManager.hpp"
#include "Game.h"

class GameBG : public AGameObject {
public:
	GameBG(std::string name, Tag tag);
	virtual void initialize();
};

