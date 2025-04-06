#include "SFXManager.hpp"
SFXManager* SFXManager::sharedInstance = nullptr;

SFXManager* SFXManager::getInstance(){
	if (sharedInstance == nullptr) {
		sharedInstance = new SFXManager();
	}
	return sharedInstance;
}

void SFXManager::loadAll(){
	this->loadSound("stage", "../Media/Sounds/iceclimber_stage.wav");
	this->loadSound("title", "../Media/Sounds/iceclimber_title.wav");
}

sf::Sound* SFXManager::getSound(std::string key){
	if (this->soundMap[key] != nullptr) {
		return this->soundMap[key];
	}
	else {
		std::cout << "No sound found for " << key << std::endl;
		return nullptr;
	}
}

void SFXManager::loadSound(std::string key, std::string path) {
	sf::SoundBuffer* buffer = new sf::SoundBuffer();
	sf::Sound* sound = new sf::Sound();

	buffer->loadFromFile(path);
	sound->setBuffer(*buffer);

	this->soundMap[key] = sound;
}
