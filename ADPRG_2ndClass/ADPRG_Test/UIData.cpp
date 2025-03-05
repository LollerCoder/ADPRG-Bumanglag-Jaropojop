#include "UIData.hpp"

UIData::~UIData() { 
	this->textTable.clear();
}

void UIData::putInt(std::string key, int value) {
	this->intTable[key] = value;
}

void UIData::putFloat(std::string key, float value) {
	this->floatTable[key] = value;
}

int UIData::getInt(std::string key, int defaltValue) {
	if (this->intTable.count(key) != 0) {
		return this->intTable[key];
	}
	else {
		return defaltValue;
	}
}

float UIData::getFloat(std::string key, float defaltValue) {
	if (this->floatTable.count(key) != 0) {
		return this->floatTable[key];
	}
	else {
		return defaltValue;
	}
}

void UIData::bindUIText(UIText* uiText) {
	this->textTable[uiText->getName()] = uiText;
}

void UIData::refreshTextFromData(std::string objectName, std::string key, std::string prefix) {
	std::string newText = prefix + std::to_string(this->getInt(key, -1));
	this->textTable[objectName]->setText(newText);
}
