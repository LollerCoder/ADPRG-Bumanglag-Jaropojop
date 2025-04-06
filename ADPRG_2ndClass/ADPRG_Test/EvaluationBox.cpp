#include "EvaluationBox.hpp"

EvaluationBox::EvaluationBox(std::string name) : AGameObject(name, Tag::BACKGROUND) {

}

void EvaluationBox::initialize() {
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("eval_box")); // set the sprite the the loaded texture from texturemanager

	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable.setPosition((Game::WINDOW_WIDTH / 2) - 150, (Game::WINDOW_HEIGHT / 2) - 3);

	Renderer* renderer = new Renderer("EvalBoxSprite"); // make a renderer component so it can display the gameeobject's sprite
	renderer->assignDrawable(this->sprite);
	this->attachComponent(renderer);
}

void EvaluationBox::processInput(sf::Event event) {
	switch (event.key.code) {
	case sf::Keyboard::Enter:
		SceneManager::getInstance()->loadScene(SceneManager::GAME_SCENE_NAME); // continue to next level after pressing enter
		break;
	default:
		break;
	}
}
