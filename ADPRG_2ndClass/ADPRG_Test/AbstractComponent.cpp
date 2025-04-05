#include "AbstractComponent.hpp"

AbstractComponent::AbstractComponent(std::string name, ComponentType type){
	this->name = name;
	this->owner = nullptr;
	this->type = type;
}

AbstractComponent::~AbstractComponent(){
	this->owner = nullptr;
	this->type = NotSet;
}

void AbstractComponent::attachOwner(AGameObject* owner){
	this->owner = owner;
}

void AbstractComponent::detachOwner(){
	delete this;
}

AGameObject* AbstractComponent::getOwner(){
	return this->owner;
}

AbstractComponent::ComponentType AbstractComponent::getType(){
	return this->type;
}

std::string AbstractComponent::getName(){
	return this->name;
}

void AbstractComponent::setDeltatime(sf::Time deltaTime){
	this->deltaTime = deltaTime;
}




