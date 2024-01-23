#pragma once
#include <string>
#include "../include/SDL2/SDL.h"
#include "../Headers/TextureManager.h"

class SpriteAnimation
{
public:
	SpriteAnimation() {};
	void Update();
	void Draw(float x, float y, int spriteWidth, int spriteHeight);
	void SetProperties(std::string textureID, int spriteRow, int frameCount, int animationSpeed, SDL_RendererFlip flip = SDL_FLIP_NONE);


private:
	int m_spriteRow, m_spriteFrame;
	int m_animationSpeed, m_frameCount;

	std::string m_textureID;
	SDL_RendererFlip m_flip;
};

