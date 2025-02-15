#include "Entity.h"


Entity::Entity() {

}
void Entity::setTexture(sf::Texture texture) {
	mTexture = texture;
	mSprite.setTexture(mTexture);
}

sf::Sprite* Entity::getSprite() {
	return &mSprite;
}

