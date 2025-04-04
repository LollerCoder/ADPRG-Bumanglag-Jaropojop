#pragma once
#include "AGameObject.hpp"
#include "FontManager.hpp"
#include "Renderer.hpp"


class UIText : public AGameObject {
public:
	UIText(std::string name, std::string fontTag, sf::Color colFil, sf::Color outFil);
public:
	void initialize();
	void setSize(unsigned int size);
	void setText(std::string text);
	
	

	std::string getText();
private:
	sf::Text* text;
	sf::Font* font;
};

