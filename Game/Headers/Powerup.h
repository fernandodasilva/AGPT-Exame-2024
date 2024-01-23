#pragma once
#include "../Engine/Source Files/Headers/Entities/GameObject.h"
#include "../Engine/Source Files/Headers/SpriteAnimation.h"
#include "../include/SDL2/SDL.h"
class Powerup : public GameObject
{
public:
	virtual void OnCollect() {};
	void Draw();
	void Update(float deltaTime);
	void Clean();
private:
	//collider
	SDL_Texture* currentImage;
	SpriteAnimation* animation;
};