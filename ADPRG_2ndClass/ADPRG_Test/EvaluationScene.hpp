#pragma once
#include "AbstractScene.hpp"
#include "SceneManager.hpp"
#include "UIText.hpp"
#include "Game.h"
#include "FontManager.hpp"
#include "TextureManager.hpp"
#include "UIText.hpp"
#include "UIData.hpp"
#include "EvaluationBox.hpp"

class EvaluationScene : public AbstractScene {
public:
	EvaluationScene();
public:
	void onLoadResources();
	void onLoadObjects();

	void onUnloadResources();
private:
	void loadUI();
};

