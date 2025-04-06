#include "GameObjectManager.hpp"
GameObjectManager* GameObjectManager::sharedInstance = nullptr;

GameObjectManager* GameObjectManager::getInstance() {
    if (sharedInstance == nullptr) {
        sharedInstance = new GameObjectManager();
    }
    return sharedInstance;
}

AGameObject* GameObjectManager::findObjectByName(std::string name) {
    if (this->mGameObjectMap[name] != nullptr) {
        return this->mGameObjectMap[name];
    }
    else {
        std::cout << "Object" << name << " not found." << std::endl;
        return nullptr;
    }
}

std::vector<AGameObject*> GameObjectManager::getAllObjects() {
    return this->mGameObjectList;
}

int GameObjectManager::activeObjcet() {
    return mGameObjectList.size();
}

void GameObjectManager::processInput(sf::Event event) {
    for (AGameObject* gameObject : this->mGameObjectList) {
        gameObject->processInput(event);
    }
}

void GameObjectManager::update(sf::Time deltaTime) {
    for (AGameObject* gameObject : this->mGameObjectList) {
        gameObject->update(deltaTime);
    }
}

void GameObjectManager::draw(sf::RenderWindow* targetWindow) {
    for (AGameObject* gameObject : this->mGameObjectList) {
        gameObject->draw(targetWindow, sf::RenderStates::Default);
    }
}

void GameObjectManager::addObject(AGameObject* gameObject) {
    if (gameObject == nullptr) {
        std::cout << "In GOM::addObject" << std::endl;
        std::cout << "gameObject null" << std::endl;
    }
    else {
        std::string name = gameObject->getName();
        if (name.empty()) {
            std::cout << "In GOM::addObject" << std::endl;
            std::cout << "gameObject name empty" << std::endl;
        }
    }

    this->mGameObjectMap[gameObject->getName()] = gameObject;
    this->mGameObjectList.push_back(gameObject);
    gameObject->initialize();
}

void GameObjectManager::deleteObject(AGameObject* gameObject) {
    std::string name = gameObject->getName();
    delete gameObject;

    this->mGameObjectMap.erase(name);
    this->mGameObjectList.erase(std::remove(this->mGameObjectList.begin(),
                                this->mGameObjectList.end(),
                                gameObject));

    this->mGameObjectList.shrink_to_fit();
}

void GameObjectManager::deleteObjectByName(std::string name) {
    AGameObject* gameObject = this->findObjectByName(name);

    if (gameObject != nullptr) {
        this->deleteObject(gameObject);
    }
}

void GameObjectManager::deleteAllObjectsInScene() {
    for (AGameObject* object : this->mGameObjectList) {
        delete object;
    }

    this->mGameObjectList.clear();
    this->mGameObjectList.shrink_to_fit();
    this->mGameObjectMap.clear();
}

AGameObject* GameObjectManager::findObjectByTag(Tag tag) {
    AGameObject* object;
    int index = -1;
    for (int i = 0; i < this->mGameObjectList.size() && index == -1; i++) {
        object = this->mGameObjectList[i];
        if (object->getTag() == tag) {
            index = i;
        }
    }

    return this->mGameObjectList[index];
}




