#pragma once
#include "Headers/Entities/Pawn.h"
#include "Headers/SpriteAnimation.h"
#include "Companion.h"
#include "Missile.h"
#include "../include/glm/glm.hpp"
#include "../include/Box2D/box2d/box2d.h"

class Spaceship :
    public Pawn
{
public:
	Spaceship(Properties* props);
	//destructor

	virtual void Draw();
	virtual void Clean();
	virtual void Update(float deltaTime);

	//move
	//fire
	//collision detector

protected:

private:
	glm::vec2 position;
	int speed;
	//input?!
	glm::vec2 weaponPosition;
	b2Body* rigidBody2D;
	//collider
	//projectile status
	int currentHealth;
	const int maxHealth = 100;
	SpriteAnimation* m_animation;
	int numberOfCompanions;
	SDL_Texture* currentImage;
	int FrameWidth; int FrameHeight;
};

