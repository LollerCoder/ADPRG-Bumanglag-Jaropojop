#pragma once
#include "SFML/Graphics.hpp"

class ApplicationManager {
	enum GameState { Running = 0, Paused = 1 };
public:
	static void initialize(sf::RenderWindow* window);
	static ApplicationManager* getInstance();
public:
	void applicationQuit();
	void pauseApplication();
	void resumeApplication();
	bool isPaused();
private:
	ApplicationManager() {};
	~ApplicationManager();
	ApplicationManager(ApplicationManager const&) {};
	ApplicationManager& operator=(ApplicationManager const&) {};
private:
	static ApplicationManager* sharedInstance;
	sf::RenderWindow* window;
	GameState state;
};

