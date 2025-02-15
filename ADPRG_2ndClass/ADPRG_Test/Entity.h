#pragma once
#include <SFML/Graphics.hpp>
class Entity
{
public:
	Entity();
	void setTexture(sf::Texture texture);
	sf::Sprite* getSprite();
	

private:
	sf::Texture mTexture;
	sf::Sprite mSprite;

};

	