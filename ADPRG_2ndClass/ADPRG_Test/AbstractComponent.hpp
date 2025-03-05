#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class AGameObject;

class AbstractComponent{
public:
	enum ComponentType { NotSet = 1, Script = 0,
						 Renderer = 1, Input = 2,
						 Physics = 3};
public:
	AbstractComponent(std::string name, ComponentType type);
	virtual ~AbstractComponent();
public:
	void attachOwner(AGameObject* owner);
	void detachOwner();
	AGameObject* getOwner();
	ComponentType getType();
	std::string getName();

	void setDeltatime(sf::Time deltaTime);
	virtual void perform() = 0;
protected:
	AGameObject* owner;
	ComponentType type;
	std::string name;
	sf::Time deltaTime;
};

