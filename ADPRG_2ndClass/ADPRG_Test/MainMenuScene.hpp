#pragma once
#include "AbstractScene.hpp"
#include "SceneManager.hpp"
#include "UIText.hpp"
#include "Game.h"
#include "Seal.hpp"
#include "MainMenuScreen.h"
#include "UIBox.h"

class MainMenuScene : public AbstractScene{
public:
	MainMenuScene();
public:
	void onLoadResources();
	void onLoadObjects();
	void LoadUI();

	void onUnloadObjects();
	void onUnloadResources();
private:
	sf::Sound* bgm = nullptr;

};

