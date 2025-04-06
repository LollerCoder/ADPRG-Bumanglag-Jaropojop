#include "CameraManager.hpp"
#include "Game.h"

CameraManager* CameraManager::sharedInstance = nullptr;

CameraManager* CameraManager::getInstance() {
	if (sharedInstance == nullptr) {
		sharedInstance = new CameraManager();
	}
	return sharedInstance;
}

void CameraManager::setUpCamera(sf::RenderWindow* window) {
    CameraManager* instance = getInstance();
    instance->view = window->getDefaultView();
    instance->window = window;
    instance->originalPos = instance->view.getCenter();
    window->setView(view);

    this->cameraPosTarget.push_back(-150);
    this->cameraPosTarget.push_back(-510);
    this->cameraPosTarget.push_back(-750);
    this->cameraPosTarget.push_back(-1050);
    this->cameraPosTarget.push_back(-1270);
    this->cameraPosTarget.push_back(-1450);
}

void CameraManager::updateCamera(sf::Time deltaTime) {
    
    sf::Vector2f currentCenter = this->view.getCenter();
    if (currentCenter.y > this->cameraPosTarget[this->currCheckP]) {
        float speed = 300.f;
        float delta = speed * deltaTime.asSeconds();

        currentCenter.y -= delta;

        if (currentCenter.y <= this->cameraPosTarget[this->currCheckP]) {
            currentCenter.y = this->cameraPosTarget[this->currCheckP];
            Game::camera = false;
            ApplicationManager::getInstance()->resumeApplication();
            switch (this->currCheckP) {
            case 0: Game::cp1 = true;
                break;
            case 1: Game::cp2 = true;
                break;
            case 2: Game::cp3 = true;
                break;
            case 3: Game::cp4 = true;
                break;
            case 4: Game::cp5 = true;
                break;
            case 5: Game::cp6 = true;
                break;
            }
            this->currCheckP++;
        }

       /* sf::View lookingView(sf::FloatRect(0.0f, -800.0f, 700.0f, 1200.0f));
        this->window->setView(lookingView);*/

        this->view.setCenter(currentCenter);
        this->window->setView(this->view);
    }
}

void CameraManager::resetCamera() {
    this->view.setCenter(this->originalPos);
    this->window->setView(this->view);
    this->currCheckP = 0;
}

sf::View CameraManager::getViewCamera()
{
    return this->view;
}
