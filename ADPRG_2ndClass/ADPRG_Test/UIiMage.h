#pragma once
#include "AGameObject.hpp"
#include "TextureManager.hpp"
#include "Game.h"

class UIiMage : public AGameObject {
public:
	UIiMage(std::string name);
	void initialize();
};

