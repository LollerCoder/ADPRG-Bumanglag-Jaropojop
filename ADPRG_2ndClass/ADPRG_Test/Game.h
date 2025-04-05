#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "TextureManager.hpp"
#include "SFXManager.hpp"
#include "GameObjectManager.hpp"
#include "FontManager.hpp"
#include "ApplicationManager.hpp"
#include "SceneManager.hpp"
#include "MainMenuScene.hpp"
#include "GameScene.hpp"
#include "EvaluationScene.hpp"

class Game
{
public:
	Game();
	void run();
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	static const int WINDOW_WIDTH = 640;
	static const int WINDOW_HEIGHT = 480;
private:
	void processEvents();
	void update(sf::Time);
	void render();

private:
	sf::RenderWindow mWindow;

};

