#pragma once
#include "SFML/Graphics.hpp"
#include <unordered_map>
#include <iostream>

class FontManager {
public:
	 static FontManager* getInstance();
public:
	 void loadAll();
	 sf::Font* getFont(std::string key);
private:
	FontManager() {};
	FontManager(FontManager const&) {};
	FontManager& operator=(FontManager const&) {};
	static FontManager* sharedInstance;
private:
	void loadFont(std::string key, std::string path);
	std::unordered_map<std::string, sf::Font*> fontMap;
};

