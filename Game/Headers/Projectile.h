#pragma once
#include "../Engine/Source Files/Headers/Entities/GameObject.h"
#include "../include/Box2D/box2d/b2_body.h"

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

	glm::vec2 position;
	int speed;
	SDL_Texture* currentImage;

};

