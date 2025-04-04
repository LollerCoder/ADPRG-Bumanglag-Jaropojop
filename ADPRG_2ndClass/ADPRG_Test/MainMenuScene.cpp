#include "MainMenuScene.hpp"

MainMenuScene::MainMenuScene() : AbstractScene(SceneManager::MAIN_MENU_SCENE_NAME) {

}

void MainMenuScene::onLoadResources() {
	
}

void MainMenuScene::onLoadObjects() {

	UIText* titleText = new UIText("title_Text1", "ice", sf::Color(70, 177, 201) , sf::Color(37, 50, 35));
	titleText->setPosition(Game::WINDOW_WIDTH/2, Game::WINDOW_HEIGHT / 2 - 150);
	

	this->registerObject(titleText);
	titleText->setSize(50);
	titleText->setText("Seal \n RIZZler");

	UIText* startText = new UIText("startGame_Text", "nes", sf::Color::White, sf::Color::Black);
	startText->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2 - 20);
	

	this->registerObject(startText);
	startText->setSize(30);
	startText->setText("Start");

	UIText* quitText = new UIText("quit_Text" , "nes", sf::Color::White, sf::Color::Black);
	quitText->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2 + 60 );
	

	this->registerObject(quitText);
	quitText->setSize(30);
	quitText->setText("Quit");

	UIText* nikText = new UIText("nikos_Text", "nes", sf::Color(7, 42, 200), sf::Color(255, 165, 0));
	this->registerObject(nikText);
	nikText->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2 + 160);
	nikText->setSize(20);
	nikText->setText("Nikos Bumanglag");

	UIText* jaiText = new UIText("jai_Text", "nes", sf::Color(0, 200, 0), sf::Color(9, 82, 86));
	this->registerObject(jaiText);
	jaiText->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2 + 200);
	jaiText->setSize(20);
	jaiText->setText("Jairo Jaropojop");
	




}

void MainMenuScene::onUnloadResources() {

}
