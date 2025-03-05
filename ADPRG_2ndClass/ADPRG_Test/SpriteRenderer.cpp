#include "SpriteRenderer.hpp"

SpriteRenderer::SpriteRenderer(std::string name, std::string textureName) : Renderer(name){
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture(textureName));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->assignDrawable(sprite);
}
