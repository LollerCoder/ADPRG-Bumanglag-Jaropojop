#include "SceneManager.hpp"
std::string SceneManager::MAIN_MENU_SCENE_NAME = "MainMenuScene";
std::string SceneManager::GAME_SCENE_NAME = "GameScene";
std::string SceneManager::EVAL_SCENE_NAME = "EvalScene";

SceneManager* SceneManager::sharedInstance = nullptr;

SceneManager* SceneManager::getInstance(){
	if (sharedInstance == nullptr) {
		sharedInstance = new SceneManager();
	}
	return sharedInstance;
}

void SceneManager::registerScene(AbstractScene* scene) {
	std::cout << scene->getSceneName() << " registered" << std::endl;
	this->storedScenes[scene->getSceneName()] = scene;
}

void SceneManager::loadScene(std::string name) {
	this->isLoading = true;
	this->toLoadSceneName = name;
}

void SceneManager::unloadScene() {
	if (this->activeScene != nullptr) {
		this->activeScene->onUnloadObjects();
		this->activeScene->onLoadResources();
	}
}

bool SceneManager::isSceneLoaded(std::string name) {

	return this->activeScene->getSceneName() == name;
}

void SceneManager::checkLoadScene() {
	if (this->isLoading) {
		this->unloadScene();
		this->activeScene = this->storedScenes[this->toLoadSceneName];
		this->activeScene->onLoadResources();
		this->activeScene->onLoadObjects();
		this->isLoading = false;
	}
}
