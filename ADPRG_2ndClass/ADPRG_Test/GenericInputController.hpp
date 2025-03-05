#pragma once
#include "AbstractComponent.hpp"

class GenericInputController : public AbstractComponent{
public:
	GenericInputController(std::string name);
	~GenericInputController();
public:
	void perform();
	void assignEvent(sf::Event event);
protected:
	sf::Event event;
};

