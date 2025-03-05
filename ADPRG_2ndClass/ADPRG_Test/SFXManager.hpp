#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <unordered_map>

class SFXManager{
public:
	static SFXManager* getInstance();
private:
	SFXManager() {};

	SFXManager(SFXManager const&) {};

	SFXManager& operator=(SFXManager const&) {};

	static SFXManager* sharedInstance;
public:
	void loadAll();
	sf::Sound* getSound(std::string key);
private:
	void loadSound(std::string key, std::string path);
	std::unordered_map<std::string, sf::Sound*> soundMap;
	
};

