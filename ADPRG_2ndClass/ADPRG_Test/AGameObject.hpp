#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "AbstractComponent.hpp"
#include "GenericInputController.hpp"
#include "Renderer.hpp"

class AGameObject {
public:
	AGameObject(std::string name); //constructor
	virtual ~AGameObject(); //deconstructor
public:
	virtual void initialize() = 0; // pure virtual
	virtual void processInput(sf::Event event);
	virtual void update(sf::Time deltaTime);
	virtual void draw(sf::RenderWindow* targetWindow, 
					  sf::RenderStates renderStates);
public:
	std::string getName();

	void attachChild(AGameObject* child);
	void detachCild(AGameObject* child);
	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	sf::Transformable* getTransformable();
	sf::Sprite* getSprite();
	sf::Transform getGlobalTransform();
public:
	void attachComponent(AbstractComponent* component);
	void detachComponent(AbstractComponent* _component);
	AbstractComponent* findComponentByName(std::string name);
	AbstractComponent* findComponentOfType(AbstractComponent::ComponentType type, std::string name);
	std::vector<AbstractComponent*> getComponentsOfType(AbstractComponent::ComponentType type);
	//std::vector<AbstractComponent*> getComponentsOfTypeRecursive(AbstractComponent::ComponentType type);
	AGameObject* getParent();
protected:
	sf::Transformable transformable;
	std::string name;
	sf::Sprite* sprite;
	sf::Texture* texture;
	std::vector<AGameObject*> childList;
	std::vector<AbstractComponent*> componentList;
protected:
	void setParent(AGameObject* parent);
private:
	//std::vector<AbstractComponent*> getComponentRecursiveProper(
	//	AGameObject* object, AbstractComponent::ComponentType type,
	//	std::vector<AbstractComponent*> foundList);
private:
	bool enabled = true;
	AGameObject* mParent;
public:
	void setEnabled(bool flag);
	bool isEnabled();
};

