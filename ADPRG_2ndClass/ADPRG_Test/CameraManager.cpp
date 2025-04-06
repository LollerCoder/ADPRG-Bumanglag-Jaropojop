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

// initialize view and window and also checkpoint coords on y
void CameraManager::setUpCamera(sf::RenderWindow* window) {
    CameraManager* instance = getInstance();
    instance->view = window->getDefaultView();
    instance->window = window;
    instance->originalPos = instance->view.getCenter();
    window->setView(view);

    this->cameraPosTarget.push_back(-150);
    this->cameraPosTarget.push_back(-510);
    this->cameraPosTarget.push_back(-750);
}

// moves the camera when certain levels reached
void CameraManager::updateCamera(sf::Time deltaTime) {
    
    sf::Vector2f currentCenter = this->view.getCenter();

    // if the camera is below the target pos, move upwards
    if (currentCenter.y > this->cameraPosTarget[GameInfo::currCP]) {
        float speed = 300.f;
        float delta = speed * deltaTime.asSeconds();

        currentCenter.y -= delta;
        
        // locks the camera in position to be sure
        if (currentCenter.y <= this->cameraPosTarget[GameInfo::currCP]) {
            currentCenter.y = this->cameraPosTarget[GameInfo::currCP];

            // toggle off cameraMoving for update in Game class
            GameInfo::cameraMoving = false;

            // changes the checkpoint toggles back to false
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
        
        // set view after updating
        this->view.setCenter(currentCenter);
        this->window->setView(this->view);
    }
}

// resets camera position 
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

