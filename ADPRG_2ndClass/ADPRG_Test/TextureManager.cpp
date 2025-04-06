#include "TextureManager.hpp"
TextureManager* TextureManager::sharedInstance = nullptr;

TextureManager* TextureManager::getInstance(){
    if (sharedInstance == nullptr) {
        sharedInstance = new TextureManager();
    }
    return sharedInstance;
}

// executes every load texture functions for the entire game
void TextureManager::loadAll(){
    this->loadTexture("background", "../Media/Textures/background_1.png");
    this->loadTexture("blocks", "../Media/Textures/iceClimbBox.png");
    this->loadTexture("eval_box", "../Media/Textures/eval_box_edited.png");
    this->loadTexture("Hitbox", "../Media/Textures/hitboxTest.png");

    // the two bonus item
    // load its corresponding json file
    // load the spritesheet 
    // its the same for every loaded spritesheet
    this->loadTexture("bonus_item", "../Media/Textures/SpriteSheets/BonusItems/bonus_item.png"); 
    FileReader::getInstance()->loadFrames("bonus_item", "../Media/Textures/SpriteSheets/BonusItems/bonus_item.json"); 
    
    //blocks
    this->loadTexture("block", "../Media/Textures/SpriteSheets/Blocks/blocks.png");
    FileReader::getInstance()->loadFrames("block", "../Media/Textures/SpriteSheets/Blocks/blocks.json");

    this->loadPlayer();
    this->loadEnemies();
    this->loadUI();
}

void TextureManager::loadPlayer() {   
    this->loadTexture("Player", "../Media/Textures/SpriteSheets/Player/Player.png");
    FileReader::getInstance()->loadFrames("Player", "../Media/Textures/SpriteSheets/Player/Player.json");
}

void TextureManager::loadEnemies() {
    this->loadTexture("Bird_1", "../Media/Textures/SpriteSheets/Enemies/Bird_1.png");
    FileReader::getInstance()->loadFrames("Bird_1", "../Media/Textures/SpriteSheets/Enemies/Bird_1.json");

    this->loadTexture("Walker", "../Media/Textures/SpriteSheets/Enemies/Seal.png");
    FileReader::getInstance()->loadFrames("Walker", "../Media/Textures/SpriteSheets/Enemies/Seal.json");
}

void TextureManager::loadUI() {
    //UI
    this->loadTexture("sealSingle", "../Media/Textures/UI/SealLog.png");
    this->loadTexture("iceBg", "../Media/Textures/UI/IceBg.png");

    this->loadTexture("iceButton", "../Media/Textures/UI/IceButton.png");
    this->loadTexture("iceButtonPressed", "../Media/Textures/UI/IceButtonSelected.png");
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
