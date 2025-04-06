#include "UIBox.h"
#include "TextureManager.hpp"
#include "Renderer.hpp"
#include "Game.h"
#include "UIButton.hpp"
#include "UIText.hpp"
#include <iostream>
#include "ApplicationManager.hpp"
#include "SceneManager.hpp"

UIBox::UIBox(std::string name) : AGameObject(name,Tag::UI), ButtonListener()
{

}

void UIBox::onButtonClick(UIButton* button)
{

}

void UIBox::onButtonReleased(UIButton* button)
{
	if (button->getName() == "button_1") this->onOption1Button();
	else if (button->getName() == "button_2") this->onOption2Button();
}

void UIBox::onOption1Button()
{
	if (this->getName() == "UIBoxGame") {
		SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE_NAME);
		
		ApplicationManager::getInstance()->resumeApplication();
	}
	else {
		ApplicationManager::getInstance()->applicationQuit();
	}
	
}

void UIBox::onOption2Button()
{
	this->setEnabled(false);
	ApplicationManager::getInstance()->resumeApplication();
}

void UIBox::initialize()
{
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("iceBg"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	sprite->setScale(3.0f, 1.8f);

	Renderer* renderer = new Renderer("UiBox");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	float posX = Game::WINDOW_WIDTH / 2;
	float posY = Game::WINDOW_HEIGHT / 2;
	this->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);
	this->transformable.setScale(sf::Vector2f(0.6f, 0.6f));

	sf::Texture* btnNormal = TextureManager::getInstance()->getTexture("iceButton");
	sf::Texture* btnPressed = TextureManager::getInstance()->getTexture("iceButtonPressed");


	UIText* menu_Text = new UIText("menu_text_1", "nes", sf::Color::White, sf::Color::Black);
	this->attachChild(menu_Text);
	menu_Text->setSize(40);
	menu_Text->setPosition(0, -70);
	menu_Text->setText("   Are you sure \n you wanna quit?");


	UIButton* button1 = new UIButton("button_1", btnNormal, btnPressed);
	this->attachChild(button1);
	button1->setPosition(-150, 150);
	button1->getTransformable()->setScale(0.3f, 0.3f);
	button1->setButtonListener(this);

	UIText* button_1Text = new UIText("text_1", "nes", sf::Color::White, sf::Color::Black);
	button1->attachChild(button_1Text);
	button_1Text->setPosition(0, -20);
	button_1Text->setSize(100);
	button_1Text->setText("YES");


	UIButton* button2 = new UIButton("button_2", btnNormal, btnPressed);
	this->attachChild(button2);
	button2->setPosition(150, 150);
	button2->getTransformable()->setScale(0.3f, 0.3f);
	button2->setButtonListener(this);

	UIText* button_2Text = new UIText("text_2", "nes", sf::Color::White, sf::Color::Black);
	button2->attachChild(button_2Text);
	button_2Text->setPosition(0, -20);
	button_2Text->setSize(100);
	button_2Text->setText("NO");

	UIBoxMover* uiMove = new UIBoxMover("uiMover");
	this->attachComponent(uiMove);
	std::cout << "uimover added" << std::endl;

}

void UIBox::updateCollider()
{
}


