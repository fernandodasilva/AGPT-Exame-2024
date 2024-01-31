#include "../Game/Headers/Spaceship.h"
#include "../Engine/Source Files/Headers/TextureManager.h"
#include "../include/SDL2/SDL.h"
#include "../Engine/Source Files/Headers/Entities/GameState.h"


Spaceship::Spaceship(Properties* props): Pawn(props)
{
	m_animation = new SpriteAnimation();
	m_animation->SetProperties(m_textureID, 1, 7, 80, SDL_FLIP_NONE);
	TextureManager::GetInstance()->LoadImage("Assets/graphics/Ship1.bmp", SDL_GetRenderTarget());

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

b2Body* AddRigidbody(int x, int y, int width, int height, bool isDynamic = true)
{
	b2BodyDef bodyDef;
	bodyDef.position.Set(x, y);
	if (isDynamic)
	{
		bodyDef.type = b2_dynamicBody;
	}
	b2Body* body = GameState::GetWorldInstance()->CreateBody(&bodyDef);
}
