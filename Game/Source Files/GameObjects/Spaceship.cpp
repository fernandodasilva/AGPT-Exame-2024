#include "../Game/Headers/Spaceship.h"
#include "../Engine/Source Files/Headers/TextureManager.h"
#include "../include/SDL2/SDL.h"



Spaceship::Spaceship(Properties* props): Pawn(props)
{
	m_animation = new SpriteAnimation();
	m_animation->SetProperties(m_textureID, 1, 7, 80, SDL_FLIP_NONE);
	TextureManager::GetInstance()->LoadTexture("spaceship", "Assets/graphics/Ship1.bmp");

}

void Spaceship::Draw()
{
	m_animation->Draw(m_transform.x, m_transform.y, m_width, m_height);

}

void Spaceship::Clean()
{
	TextureManager::GetInstance()->Clean();
}

void Spaceship::Update(float deltaTime)
{

	m_animation->Update();
}
