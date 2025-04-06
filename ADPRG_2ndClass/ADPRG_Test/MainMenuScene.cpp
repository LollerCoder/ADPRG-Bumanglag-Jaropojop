#include "MainMenuScene.hpp"
#include "CameraManager.hpp"

MainMenuScene::MainMenuScene() : AbstractScene(SceneManager::MAIN_MENU_SCENE_NAME) {

}

void MainMenuScene::onLoadResources() {
	
}

void MainMenuScene::onLoadObjects() {

	CameraManager::getInstance()->resetCamera();
	this->LoadUI();

	

}

void MainMenuScene::LoadUI()
{
	MainMenuScreen* menuScreen = new MainMenuScreen("MainMenuScreen");
	this->registerObject(menuScreen);

	UIBox* uibox = new UIBox("ConfirmScreen");
	uibox->setEnabled(false);
	this->registerObject(uibox);

}

void MainMenuScene::onUnloadResources() {

}
