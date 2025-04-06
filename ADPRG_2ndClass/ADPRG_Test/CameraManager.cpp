#include "CameraManager.hpp"
#include "ApplicationManager.hpp"
#include "Gamevalue.hpp"

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

    if (currentCenter.y > this->cameraPosTarget[GameInfo::currCP]) {
        float speed = 300.f;
        float delta = speed * deltaTime.asSeconds();

        currentCenter.y -= delta;
        
        if (currentCenter.y <= this->cameraPosTarget[GameInfo::currCP]) {
            currentCenter.y = this->cameraPosTarget[GameInfo::currCP];
            GameInfo::cameraMoving = false;

            switch (GameInfo::currCP) {
            case 0: GameInfo::cp1 = false;
                break;
            case 1:GameInfo::cp2 = false;
                break;
            case 2:GameInfo::cp3 = false;
                break;
            }

            ApplicationManager::getInstance()->resumeApplication();
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
}

sf::RenderWindow* CameraManager::getWindow()
{
    return this->window;
}

sf::View CameraManager::getViewCamera()
{
    return this->window->getView();
}

