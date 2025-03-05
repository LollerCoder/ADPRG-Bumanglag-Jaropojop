#include "Game.h"



Game::Game() : mWindow(sf::VideoMode(640,480), "SFML Application"){
    TextureManager::getInstance()->loadAll();
    FontManager::getInstance()->loadAll();
    ApplicationManager::getInstance()->initialize(&mWindow);

    //SceneManager::getInstance()->registerScene(new MainMenuScene());
    SceneManager::getInstance()->registerScene(new GameScene());
    SceneManager::getInstance()->loadScene(SceneManager::GAME_SCENE_NAME);
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen())
    {
        processEvents();
        sf::Time deltaTime = clock.restart();
        
        timeSinceLastUpdate += deltaTime;

        //everything update is here so for the assignment place everything here and remove for the next module
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate += clock.restart();
            this->processEvents();
            while (timeSinceLastUpdate > this->TimePerFrame) {
                timeSinceLastUpdate -= this->TimePerFrame;
                this->processEvents();
                this->update(this->TimePerFrame);
            }
            this->render();
            SceneManager::getInstance()->checkLoadScene();
        }
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type) {
        case sf::Event::Closed:
            mWindow.close();
            break;
        default:
            GameObjectManager::getInstance()->processInput(event);
            break;
        }
        
    }
}

void Game::update(sf::Time deltaTime) {
    if (!ApplicationManager::getInstance()->isPaused()) {
        GameObjectManager::getInstance()->update(deltaTime);
    }
}
void Game::render() {
    mWindow.clear();
    GameObjectManager::getInstance()->draw(&this->mWindow);
    mWindow.display();

}
