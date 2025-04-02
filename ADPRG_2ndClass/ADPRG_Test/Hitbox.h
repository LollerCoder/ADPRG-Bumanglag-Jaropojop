#pragma once
#include "Game.h"
#include "AGameObject.hpp"
#include "TextureManager.hpp"
#include "PlayerInputController.hpp"
#include "PlayerMovement.hpp"
#include "Renderer.hpp"
#include "FileReader.hpp"
#include "CollisionListener.hpp"
#include "Collider.hpp"

class Hitbox : public AGameObject, public CollisionListener 
{

	public:
		Hitbox(std::string name,float width, float height);
	public:
		void initialize();
		
		//collision
		void onCollisionExit(AGameObject* contact);
		void onCollisionEnter(AGameObject* contact);

	public:
		float width;
		float height;
		Collider* collider;

};

