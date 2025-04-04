#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "FileReader.hpp"

class TextureManager{
public:
	static TextureManager* getInstance();
private:
	TextureManager() {};

	TextureManager(TextureManager const&) {};

	TextureManager& operator=(TextureManager const&) {};

	static TextureManager* sharedInstance;
public:
	void loadAll();
	void loadPlayer();
	void loadEnemies();
	sf::Texture* getTexture(std::string key);
	std::vector<sf::Texture*> getFrames(std::string key);
private:
	void loadTexture(std::string key, std::string path);
	std::unordered_map<std::string, sf::Texture*> textureMap;
	std::unordered_map<std::string, std::vector<sf::Texture*>> framesMap;

};

