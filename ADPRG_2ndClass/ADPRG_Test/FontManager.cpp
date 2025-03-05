#include "FontManager.hpp"

FontManager* FontManager::sharedInstance = nullptr;

FontManager* FontManager::getInstance() {
    if(sharedInstance == nullptr){
        sharedInstance = new FontManager();
    }
    return sharedInstance;
}

void FontManager::loadAll() {
    this->loadFont("default", "../Media/Font/Sansation.ttf");
}

sf::Font* FontManager::getFont(std::string key) {
    if (this->fontMap[key] != NULL) {
        return this->fontMap[key];
        std::cout << "Font found for " << key << std::endl;;
    }
    else {
        std::cout << "No font found for " << key << std::endl;
        return NULL;
    }
}

void FontManager::loadFont(std::string key, std::string path) {
    sf::Font* font = new sf::Font();
    font->loadFromFile(path);
    this->fontMap[key] = font;
}
