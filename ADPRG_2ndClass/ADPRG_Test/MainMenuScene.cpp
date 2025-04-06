#include "MainMenuScene.hpp"
#include "CameraManager.hpp"

MainMenuScene::MainMenuScene() : AbstractScene(SceneManager::MAIN_MENU_SCENE_NAME) {

}

void MainMenuScene::onLoadResources() {
	
}
// executes everything needed for this scene
void MainMenuScene::onLoadObjects() {
	CameraManager::getInstance()->resetCamera();
	this->LoadUI();

	// gets the sound from sfxmanager
	if (this->bgm == nullptr) {
		this->bgm = SFXManager::getInstance()->getSound("title");
		this->bgm->setVolume(40);
	}
	this->bgm->play();
}

void MainMenuScene::LoadUI()
{
	MainMenuScreen* menuScreen = new MainMenuScreen("MainMenuScreen");
	this->registerObject(menuScreen);

	UIBox* uibox = new UIBox("ConfirmScreen");
	uibox->setEnabled(false);
	this->registerObject(uibox);

}

// unloads objects and stops music
void MainMenuScene::onUnloadObjects() {
	this->bgm->stop();
	AbstractScene::onUnloadObjects();
}

void MainMenuScene::onUnloadResources() {

}
