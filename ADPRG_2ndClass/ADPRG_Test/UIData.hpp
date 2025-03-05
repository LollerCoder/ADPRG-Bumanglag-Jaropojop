#pragma once
#include <unordered_map>
#include <string>
#include "UIButton.hpp"
#include "UIText.hpp"

typedef std::unordered_map<std::string, int> IntTable;
typedef std::unordered_map<std::string, float> FloatTable;

typedef std::unordered_map<std::string, UIText*> TextTable;
typedef std::unordered_map<std::string, UIButton*> ButtonTable;

class UIData {
public:
	~UIData();
public:
	void putInt(std::string key, int value);
	void putFloat(std::string key, float value);

	int getInt(std::string key, int defaltValue);
	float getFloat(std::string key, float defaltValue);
public:
	void bindUIText(UIText* uiText);
	void refreshTextFromData(std::string objectName, std::string key, std::string prefix = "");
private:
	IntTable intTable;
	FloatTable floatTable;
	TextTable textTable;

};

