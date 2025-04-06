#pragma once
#include "AbstractComponent.hpp"
#include "GameObjectPool.hpp"
#include "Block.h"
#include "CameraManager.hpp"
class UIBoxMover : public AbstractComponent 
{
public:
	UIBoxMover(std::string name);

public:
	void perform();

};












