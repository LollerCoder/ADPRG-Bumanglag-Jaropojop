#pragma once
#include <unordered_map>
#include "UIText.hpp"
#include "UIButton.hpp"
#include "UIData.hpp"

typedef std::unordered_map<std::string, UIData*> DataTable;

class UIManager {
public:
	static const std::string SCORE_UI_KEY;

	static UIManager* getInstance();

	UIData* getUIData(std::string name);
	UIData* storeData(std::string name);
	void removeData(std::string name);
private:
	UIManager() {};
	UIManager(UIManager const&) {};
	UIManager& operator=(UIManager const&) {};
	static UIManager* sharedInstance;

	DataTable dataTable;
};

