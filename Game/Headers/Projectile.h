#pragma once
#include "../Engine/Source Files/Headers/Entities/GameObject.h"
class Projectile : public GameObject
{
public:
	Projectile();
	~Projectile();
	void Draw();
	void Update(float deltaTime);
	void Clean();
	virtual void OnHit() {};

private:
	//collider
	//position
	int speed;
	SDL_Texture* currentImage;

};

