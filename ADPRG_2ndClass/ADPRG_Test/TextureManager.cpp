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
    this->loadTexture("background", "../Media/Textures/background.png");
    this->loadTexture("blocks", "../Media/Textures/iceClimbBox.png");
    this->loadPlayer();
}

void TextureManager::loadPlayer() {
    //std::vector<sf::Texture*> vec;

    //sf::Texture* texture = new sf::Texture();
    //texture->loadFromFile("../Media/Textures/Player/Player-1.1.png"); // walking
    //vec.push_back(texture);
    //texture = new sf::Texture();
    //texture->loadFromFile("../Media/Textures/Player/Player-2.1.png"); // walking
    //vec.push_back(texture);
    //this->framesMap["player-walk"] = vec;

    //vec = std::vector<sf::Texture*>();

    //texture = new sf::Texture();
    //texture->loadFromFile("../Media/Textures/Player/Player-3.1.png"); // hitting
    //vec.push_back(texture);
    //texture = new sf::Texture();
    //texture->loadFromFile("../Media/Textures/Player/Player-4.1.png"); // hitting
    //vec.push_back(texture);

    //this->framesMap["player-hit"] = vec;
    this->loadTexture("Walker", "../Media/Textures/yeti.png");
    this->loadTexture("Hitbox", "../Media/Textures/hitboxTest.png");

    this->loadTexture("Player", "../Media/Textures/SpriteSheets/Player/Player.png");
    FileReader::getInstance()->loadFrames("Player", "../Media/Textures/SpriteSheets/Player/Player.json");
}

void TextureManager::loadEnemies() {
    this->loadTexture("Bird_1", "../Media/Textures/SpriteSheets/Enemies/Bird_1.png");
    FileReader::getInstance()->loadFrames("Bird_1", "../Media/Textures/SpriteSheets/Enemies/Bird_1.json");

    this->loadTexture("Seal", "../Media/Textures/SpriteSheets/Enemies/Seal.png");
    FileReader::getInstance()->loadFrames("Seal", "../Media/Textures/SpriteSheets/Enemies/Seal.json");
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

std::vector<sf::Texture*> TextureManager::getFrames(std::string key) {
    if (!this->framesMap[key].empty()) {
        //std::cout << "Texture found for " << key << std::endl;
        return this->framesMap[key];
    }
    else {
        std::cout << "No texture found for " << key << std::endl;
        return {};
    }
}

void TextureManager::loadTexture(std::string key, std::string path){
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(path);
    this->textureMap[key] = texture;
}
