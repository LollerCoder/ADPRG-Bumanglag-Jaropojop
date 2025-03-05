#pragma once
#include "AbstractScene.hpp"
#include "SceneManager.hpp"

class MainMenuScene : public AbstractScene{
public:
	MainMenuScene();
public:
	void onLoadResources();
	void onLoadObjects();

	void onUnloadResources();

};

