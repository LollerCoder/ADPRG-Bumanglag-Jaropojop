#pragma once
#include "AGameObject.hpp"
#include "GameObjectManager.hpp"

class AbstractScene {
public:
	AbstractScene(std::string sceneName);
public:
	virtual void onLoadResources() = 0;
	virtual void onLoadObjects() = 0;
	virtual void onUnloadResources() = 0;
	virtual void onUnloadObjects();
	
	std::string getSceneName();
protected:
	void registerObject(AGameObject* object);
	std::string sceneName;
};

