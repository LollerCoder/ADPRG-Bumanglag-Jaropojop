#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "AGameObject.hpp"

class GameObjectManager{
public:
	static GameObjectManager* getInstance();
	AGameObject* findObjectByName(std::string name);
	std::vector<AGameObject*> getAllObjects();
	int activeObjcet();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);
	void draw(sf::RenderWindow* targetWindow);
	void addObject(AGameObject* gameObject);
	void deleteObject(AGameObject* gameObject);
	void deleteObjectByName(std::string name);
	void deleteAllObjectsInScene();
	AGameObject* findObjectByTag(Tag tag);
private:
	GameObjectManager() {};

	GameObjectManager(GameObjectManager const&) {};

	GameObjectManager& operator=(GameObjectManager const&) {};

	static GameObjectManager* sharedInstance;

private:
	std::unordered_map<std::string, AGameObject*> mGameObjectMap;
	std::vector<AGameObject*> mGameObjectList;
};

