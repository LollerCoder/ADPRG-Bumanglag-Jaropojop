#include "Renderer.hpp"

Renderer::Renderer(std::string name) : AbstractComponent(name, ComponentType::Renderer) {
	this->renderStates = sf::RenderStates::Default;
	this->drawable = nullptr;
	this->targetWindow = nullptr;
}

Renderer::~Renderer(){
	//if (this->drawable != nullptr) {
		//std::cout << this->getName() << " " << this->drawable << std::endl;
	//	delete this->drawable;
	//}
	AbstractComponent::~AbstractComponent();
}

void Renderer::perform(){
	this->targetWindow->draw(*this->drawable, this->renderStates);
}

void Renderer::assignTargetWindow(sf::RenderWindow* targetWindow){
	this->targetWindow = targetWindow;
}

void Renderer::assignDrawable(sf::Drawable* drawable){
	this->drawable = drawable;
}

void Renderer::setRenderStates(sf::RenderStates renderStates){
	this->renderStates = renderStates;
}
//
//Renderer* Renderer::CreateSprite(std::string name, std::string resourceName){
//	return new SpriteRenderer(name, resourceName);
//}


