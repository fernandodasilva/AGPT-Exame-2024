#pragma once
#include "../Headers/Enemy.h"
#include "../Headers/LonerProjectile.h"

class Loner : public Enemy
{
public:
	void Shoot();

	void Draw();
	void Update(float deltaTime);
	void Clean();

private:
	int speed;
	int health;
	SDL_Texture* currentImage;
};

