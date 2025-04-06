#pragma once
#include "SFML/Graphics.hpp"
#include <unordered_map>
#include <iostream>

class CameraManager {
public:
	static CameraManager* getInstance();
public:
	void setUpCamera(sf::RenderWindow* window);
	void updateCamera(sf::Time deltaTime);
	void resetCamera();
	sf::RenderWindow* getWindow();
	sf::View getViewCamera();
private:
	CameraManager() {};
	CameraManager(CameraManager const&) {};
	CameraManager& operator=(CameraManager const&) {};
	static CameraManager* sharedInstance;
private:
	sf::View view;
	sf::Vector2f originalPos;
	std::vector<float> cameraPosTarget;
	sf::RenderWindow* window;

};