#pragma once
#include "AGameObject.hpp"

class EmptyGameObject : public AGameObject {
public:
	EmptyGameObject(std::string name, Tag tag);
public:
	void initialize();
};

