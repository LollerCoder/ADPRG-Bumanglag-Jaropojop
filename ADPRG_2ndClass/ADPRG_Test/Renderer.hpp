#pragma once
#include "AbstractComponent.hpp"
//#include "SpriteRenderer.hpp"
class SpriteRenderer;

class Renderer : public AbstractComponent{
public:
	Renderer(std::string name);
	~Renderer();
public:
	void perform();
public:
	void assignTargetWindow(sf::RenderWindow* targetWindow);
	void assignDrawable(sf::Drawable* drawable);
	void setRenderStates(sf::RenderStates renderStates);

	//static Renderer* CreateSprite(std::string name, std::string resourceName);
private:
	sf::RenderWindow* targetWindow;
	sf::Drawable* drawable;
	sf::RenderStates renderStates;
};

