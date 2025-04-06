#include "Game.h"

bool Game::camera = false;
bool Game::cp1 = false;
bool Game::cp2 = false;
bool Game::cp3 = false;
bool Game::cp4 = false;
bool Game::cp5 = false;
bool Game::cp6 = false;

Game::Game() : mWindow(sf::VideoMode(640,480), "SFML Application"){
    TextureManager::getInstance()->loadAll();
    FontManager::getInstance()->loadAll();
    ApplicationManager::getInstance()->initialize(&mWindow);

    CameraManager::getInstance()->setUpCamera(&mWindow);
    
    SceneManager::getInstance()->registerScene(new GameScene());
    SceneManager::getInstance()->registerScene(new MainMenuScene());
    SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE_NAME);
    SceneManager::getInstance()->registerScene(new EvaluationScene());
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
    
    if (Game::camera) {
        CameraManager::getInstance()->updateCamera(deltaTime);
    }
}
void Game::render() {
    mWindow.clear();
    GameObjectManager::getInstance()->draw(&this->mWindow);
    mWindow.display();

}
