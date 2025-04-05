#include "MainMenuScreen.h"
#include "TextureManager.hpp"
#include "Renderer.hpp"
#include "Game.h"
#include "UIButton.hpp"
#include "UIText.hpp"
#include <iostream>
#include "ApplicationManager.hpp"
#include "GameObjectManager.hpp"
#include "SceneManager.hpp"
#include "Seal.hpp"


MainMenuScreen::MainMenuScreen(std::string name) : AGameObject(name,Tag::UI), ButtonListener()
{
}

void MainMenuScreen::onButtonClick(UIButton* button)
{
	//std::cout << button->getName() <<std::endl;
}
	
void MainMenuScreen::onButtonReleased(UIButton* button)
{
	//this->findComponentOfType(AComponent::ComponentType::Renderer, "MainMenuScreen")->getOwner()->setEnabled(false);

	if (button->getName() == "button_1") this->onYesButton();
	else if (button->getName() == "button_2") this->onNoButton();
	
}

void MainMenuScreen::onYesButton()
{
	
	SceneManager::getInstance()->loadScene(SceneManager::GAME_SCENE_NAME);
}

void MainMenuScreen::onNoButton()
{
	GameObjectManager::getInstance()->findObjectByName("ConfirmScreen")->setEnabled(true);
	
}



void MainMenuScreen::initialize()
{
	Seal* seal = new Seal("seal", Tag::UI);
	this->attachChild(seal);

	

	sf::Texture* btnNormal = TextureManager::getInstance()->getTexture("iceButton");
	sf::Texture* btnPressed = TextureManager::getInstance()->getTexture("iceButtonPressed");


	/*UIText* menu_Text = new UIText("menu_text_1");
	this->attachChild(menu_Text);
	menu_Text->setSize(40);
	menu_Text->setPosition(0, -70);
	menu_Text->setText("    Are you sure \n you wanna quit?");*/



	
	//UIText* button_1Text = new UIText("text_1");
	//button1->attachChild(button_1Text);
	//button_1Text->setPosition(0, -20);
	//button_1Text->setSize(100);
	//button_1Text->setText("Play Game");


	

	//UIText* button_2Text = new UIText("text_2");
	//button2->attachChild(button_2Text);
	//button_2Text->setPosition(0, -20);
	//button_2Text->setSize(100);
	//button_2Text->setText("Quit");


	//////
	UIText* titleText = new UIText("title_Text1", "ice", sf::Color(70, 177, 201), sf::Color(37, 50, 35));
	titleText->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2 - 150);
	this->attachChild(titleText);
	

	//this->registerObject(titleText);
	titleText->setSize(50);
	titleText->setText("Seal \n RIZZler");


	UIButton* button1 = new UIButton("button_1", btnNormal, btnPressed);
	this->attachChild(button1);
	button1->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2 - 20);
	button1->getTransformable()->setScale(1.0f, 1.0f);
	button1->setButtonListener(this);


	UIText* startText = new UIText("startGame_Text", "nes", sf::Color::White, sf::Color::Black);
	startText->setPosition(0,0);
	button1->attachChild(startText);

	//this->registerObject(startText);
	startText->setSize(30);
	startText->setText("Start");


	UIButton* button2 = new UIButton("button_2", btnNormal, btnPressed);
	this->attachChild(button2);
	button2->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2 + 80);
	button2->getTransformable()->setScale(1.0f, 1.0f);
	button2->setButtonListener(this);

	UIText* quitText = new UIText("quit_Text", "nes", sf::Color::White, sf::Color::Black);
	quitText->setPosition(0,0);
	button2->attachChild(quitText);

	//this->registerObject(quitText);
	quitText->setSize(30);
	quitText->setText("Quit");

	UIText* nikText = new UIText("nikos_Text", "nes", sf::Color(7, 42, 200), sf::Color(255, 165, 0));
	this->attachChild(nikText);
	//this->registerObject(nikText);
	nikText->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2 + 160);
	nikText->setSize(20);
	nikText->setText("Nikos Bumanglag");

	UIText* jaiText = new UIText("jai_Text", "nes", sf::Color(0, 200, 0), sf::Color(9, 82, 86));
	this->attachChild(jaiText);
	//this->registerObject(jaiText);
	jaiText->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2 + 200);
	jaiText->setSize(20);
	jaiText->setText("Jairo Jaropojop");
}


