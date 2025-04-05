#pragma once
#include <unordered_map>
#include "AbstractScene.hpp"

typedef std::unordered_map<std::string, AbstractScene*> SceneTable;
typedef std::vector<std::string> SceneList;

class SceneManager {
public:
	static std::string MAIN_MENU_SCENE_NAME;
	static std::string GAME_SCENE_NAME;
	static std::string EVAL_SCENE_NAME;
public:
	static SceneManager* getInstance();
	void registerScene(AbstractScene* scene);
	void loadScene(std::string name);
	void unloadScene();
	bool isSceneLoaded(std::string name);
	void checkLoadScene();
private:
	SceneManager() {};
	SceneManager(SceneManager const&) {};
	SceneManager& operator=(SceneManager const&) {};
	static SceneManager* sharedInstance;
private:
	SceneTable storedScenes;
	AbstractScene* activeScene;
	std::string toLoadSceneName;
	bool isLoading = false;
};

