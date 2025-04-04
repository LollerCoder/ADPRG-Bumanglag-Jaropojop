#pragma once
#include "AbstractScene.hpp"
#include "SceneManager.hpp"
#include "UIText.hpp"
#include "Game.h"


class MainMenuScene : public AbstractScene{
public:
	MainMenuScene();
public:
	void onLoadResources();
	void onLoadObjects();

	void onUnloadResources();

};

