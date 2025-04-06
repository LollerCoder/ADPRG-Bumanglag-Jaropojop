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
    this->loadTexture("eval_box", "../Media/Textures/eval_box.png");
    this->loadTexture("chili", "../Media/Textures/chili.png");

    
    //blocks
    this->loadTexture("block", "../Media/Textures/SpriteSheets/Blocks/blocks.png");
    FileReader::getInstance()->loadFrames("block", "../Media/Textures/SpriteSheets/Blocks/blocks.json");



    this->loadPlayer();
    this->loadEnemies();
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

    //UI
    this->loadTexture("sealSingle", "../Media/Textures/UI/SealLog.png");
    this->loadTexture("iceBg", "../Media/Textures/UI/IceBg.png");
   
    this->loadTexture("iceButton", "../Media/Textures/UI/IceButton.png");
    this->loadTexture("iceButtonPressed", "../Media/Textures/UI/IceButtonSelected.png");
  
    

   
    this->loadTexture("Player", "../Media/Textures/SpriteSheets/Player/Player.png");

    FileReader::getInstance()->loadFrames("Player", "../Media/Textures/SpriteSheets/Player/Player.json");
}

void TextureManager::loadEnemies() {
    this->loadTexture("Bird_1", "../Media/Textures/SpriteSheets/Enemies/Bird_1.png");
    FileReader::getInstance()->loadFrames("Bird_1", "../Media/Textures/SpriteSheets/Enemies/Bird_1.json");

    this->loadTexture("Walker", "../Media/Textures/SpriteSheets/Enemies/Seal.png");
    FileReader::getInstance()->loadFrames("Walker", "../Media/Textures/SpriteSheets/Enemies/Seal.json");
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
