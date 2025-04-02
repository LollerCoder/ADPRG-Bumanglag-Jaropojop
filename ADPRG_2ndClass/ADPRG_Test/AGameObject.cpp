#include "AGameObject.hpp"

AGameObject::AGameObject(std::string name){
	this->name = name;
}

AGameObject::~AGameObject(){ // when a gameobject is destroyed, destroy its component and children
	if (this->sprite != NULL) {
		delete this->sprite;
		this->sprite = nullptr;	
	}

	for (AbstractComponent* component : this->componentList) {
		//if (dynamic_cast<Renderer*>(component)) { // check if the object has a renderer, if so update the drawable since we deleted the sprite already
		//	((Renderer*)component)->assignDrawable(this->sprite);
		//}
		std::cout << "deleting " << component->getName() << " component" << std::endl;
		delete component;
	}
	for (AGameObject* child : this->childList) {
		std::cout << "deleting " << child->getName() << " child" << std::endl;
		delete child;
	}
}

void AGameObject::processInput(sf::Event event){
	if (!this->enabled) {
		return;
	}

	std::vector<AbstractComponent*> componentList = this->getComponentsOfType(AbstractComponent::ComponentType::Input);

	for (AbstractComponent* component : componentList) {
		((GenericInputController*)component)->assignEvent(event);
		component->perform();
	}

	for (AGameObject* child : this->childList) {
		child->processInput(event);
	}
}

void AGameObject::update(sf::Time deltaTime){
	if (!this->enabled) {
		return;
	}

	std::vector<AbstractComponent*> componentList = this->getComponentsOfType(AbstractComponent::ComponentType::Script);

	for (AbstractComponent* component : componentList) {
		component->setDeltatime(deltaTime);
		component->perform();
	}

	for (AGameObject* child : this->childList) {
		child->update(deltaTime);
	}
}

void AGameObject::draw(sf::RenderWindow* targetWindow, sf::RenderStates renderStates){
	if (!this->enabled) {
		return;
	}
	renderStates.transform = renderStates.transform * this->transformable.getTransform();
	
	//targetWindow->draw(*this->sprite, renderStates);
	std::vector<AbstractComponent*> componentList = this->getComponentsOfType(AbstractComponent::ComponentType::Renderer);
	
	for (AbstractComponent* component : componentList) {
		Renderer* renderer = (Renderer*)component;
		renderer->assignTargetWindow(targetWindow);
		renderer->setRenderStates(renderStates);
		renderer->perform();
	}

	for(AGameObject* child : this->childList) {
		child->draw(targetWindow, renderStates);
	}
}

std::string AGameObject::getName(){
	return this->name;
}

void AGameObject::attachChild(AGameObject* child){
	this->childList.push_back(child);
	child->setParent(this);
	child->initialize();
}

void AGameObject::detachCild(AGameObject* child) {
	int j = -1;

	for (int i = 0; i < this->childList.size(); i++) {
		if (this->childList[i] == child) {
			j = i;
		}
	}

	if (j != -1) {
		this->childList.erase(this->childList.begin() + j);
		this->childList.shrink_to_fit();
	}
}

void AGameObject::setPosition(float x, float y){
	this->transformable.setPosition(x, y);
}

sf::Vector2f AGameObject::getPosition(){
	return this->transformable.getPosition();
}

sf::Transformable* AGameObject::getTransformable(){
	return &this->transformable;
}

sf::Sprite* AGameObject::getSprite(){
	return this->sprite;
}

sf::Transform AGameObject::getGlobalTransform() {
	AGameObject* parentObj = this;
	std::vector<AGameObject*> parentList;

	while (parentObj != nullptr) {
		parentList.push_back(parentObj);
		parentObj = parentObj->getParent();
	}

	sf::Transform transform = sf::Transform::Identity;
	int startIdx = parentList.size() - 1;
	for (int i = startIdx; i >= 0; i--) {
		transform = transform * parentList[i]->getTransformable()->getTransform();
	}

	return transform;
}

void AGameObject::attachComponent(AbstractComponent* component){
	//std::cout << component->getName() << std::endl;
	this->componentList.push_back(component);
	component->attachOwner(this);

}

void AGameObject::detachComponent(AbstractComponent* _component){
	int index = -1;

	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i] == _component) {
			index = i;
			this->componentList[i]->detachOwner();
			break;
		}
	}

	if (index != -1) {
		this->componentList.erase(this->componentList.begin() + index);
	}

}

AbstractComponent* AGameObject::findComponentByName(std::string name){
	for (AbstractComponent* component : this->componentList) {
		if (component->getName() == name) {
			return component;
		}
	}
	return NULL;
}

AbstractComponent* AGameObject::findComponentOfType(AbstractComponent::ComponentType type, std::string name){
	for (AbstractComponent* component : this->componentList) {
		if (component->getName() == name && component->getType() == type) {
			return component;
		}
	}
	return NULL;
}

std::vector<AbstractComponent*> AGameObject::getComponentsOfType(AbstractComponent::ComponentType type){
	std::vector<AbstractComponent*> foundList;

	for (AbstractComponent* component : this->componentList) {
		if (component->getType() == type) {
			foundList.push_back(component);
		}
	}
	return foundList;
}

AGameObject* AGameObject::getParent() {
	return this->mParent;
}

//std::vector<AbstractComponent*> AGameObject::getComponentsOfTypeRecursive(AbstractComponent::ComponentType type){
//	std::vector<AbstractComponent*> foundList;
//	for (AbstractComponent* component : this->componentList) {
//		if (component->getType() == type) {
//			foundList.push_back(component);
//		}
//	}
//
//	for (AGameObject* child : this->childList) {
//		foundList = this->getComponentRecursiveProper(child, type, foundList);
//	}
//
//	return foundList;
//}

//std::vector<AbstractComponent*> AGameObject::getComponentRecursiveProper(AGameObject* object, 
//																		AbstractComponent::ComponentType type, 
//																		std::vector<AbstractComponent*> foundList){
//
//	return std::vector<AbstractComponent*>();
//}

void AGameObject::setParent(AGameObject* parent){
	
	this->mParent = parent;
	
	
}

void AGameObject::setEnabled(bool flag) {
	this->enabled = flag;
}

bool AGameObject::isEnabled() {
	return this->enabled;
}
