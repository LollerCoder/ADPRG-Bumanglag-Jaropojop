#pragma once
#include "AGameObject.hpp"

class AbstractPoolable : public AGameObject{
public:
	AbstractPoolable(std::string name, Tag tag);
public:
	virtual void initialize() = 0;
	virtual void onRelease() = 0;
	virtual void onActivate() = 0;
	virtual AbstractPoolable* clone() = 0;

};

