#include "../Headers/SpriteAnimation.h"
#include "../Headers/TextureManager.h"
#include "../include/SDL2/SDL.h"

void SpriteAnimation::Update()
{
	m_spriteFrame = (SDL_GetTicks() / m_animationSpeed) % m_frameCount;
}

void SpriteAnimation::Draw(float x, float y, int spriteWidth, int spriteHeight)
{
	TextureManager::GetInstance()->DrawFrame(m_textureID, x ,y, spriteWidth, spriteHeight, m_spriteRow, m_spriteFrame, m_flip);
}

void SpriteAnimation::SetProperties(std::string textureID, int spriteRow, int frameCount, int animationSpeed, SDL_RendererFlip flip)
{
	m_textureID = textureID;
	m_spriteRow = spriteRow;
	m_frameCount = frameCount;
	m_animationSpeed = animationSpeed;
	m_flip = flip;
}
