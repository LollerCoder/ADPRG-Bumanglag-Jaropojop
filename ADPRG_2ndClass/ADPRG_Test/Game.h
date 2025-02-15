#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
class Game
{
public:
	Game();
	void run();
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

private:
	void processEvents();
	void update(sf::Time);
	void render();
	void handlePlayerInput(sf::Keyboard::Key, bool);
	void handleMouseInput(sf::Mouse::Button, bool);

private:

	sf::RenderWindow mWindow;
	sf::Font primaryTextFont;
	Entity mSampleEntity;

	//assignment
	sf::Text fpsCounter;
	sf::Text timePerUpdateCounter;


	

	bool mIsMovingUp = false;
	bool mIsMovingDown = false;
	bool mIsMovingLeft = false;
	bool mIsMovingRight = false;

	bool mMouseMovement = false;

	float playerSpeed = 300.0f;

};

