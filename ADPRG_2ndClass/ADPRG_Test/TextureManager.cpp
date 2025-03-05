#include "TextureManager.hpp"
TextureManager* TextureManager::sharedInstance = nullptr;

TextureManager* TextureManager::getInstance(){
    if (sharedInstance == nullptr) {
        sharedInstance = new TextureManager();
    }
    return sharedInstance;
}

void TextureManager::loadAll(){
    this->loadTexture("eagle", "../Media/Textures/Eagle.png");
}

sf::Texture* TextureManager::getTexture(std::string key){
    if (this->textureMap[key] != nullptr) {
        //std::cout << "Texture found for " << key << std::endl;
        return this->textureMap[key];
    }
    else {
        std::cout << "No texture found for " << key << std::endl;
        return nullptr;
    }
}

void TextureManager::loadTexture(std::string key, std::string path){
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(path);
    this->textureMap[key] = texture;
}
