#pragma once
#include "Headers/Entities/Pawn.h"
#include "Headers/SpriteAnimation.h"
#include "Companion.h"
#include "Missile.h"

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
	//position
	int speed;
	//input?!
	//position to fire projectiles?
	//collider
	//projectile status
	int currentHealth;
	const int maxHealth = 100;
	SpriteAnimation* m_animation;
	int numberOfCompanions;
	SDL_Texture* currentImage;

};

