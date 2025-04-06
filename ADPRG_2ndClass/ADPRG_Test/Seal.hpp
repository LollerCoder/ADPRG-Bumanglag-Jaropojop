#pragma once
#include <SFML/Graphics.hpp>
#include "AGameObject.hpp"
#include "TextureManager.hpp"
#include "Game.h"


//Made only for the Seal on the Main Menu...what? Its cute.
class Seal : public AGameObject
{
public:
	Seal(std::string name, Tag tag);
	virtual void initialize();

private:
};