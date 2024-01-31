#pragma once
#include "../Interfaces/Object.h"
#include <string>
#include "../include/SDL2/SDL.h"
#include "../include/glm/glm.hpp"
#include "../include/glm/gtc/matrix_transform.hpp"
#include "../include/Box2D/box2d/box2d.h"

struct Properties
{
public:
	Properties(std::string textureID, int x, int y, int width, int height, SDL_RendererFlip flip)
	{
		X = x;
		Y = y;
		Flip = flip;
		Width = width;
		Height = height;
		TextureID = textureID;
	}

public:
	std::string TextureID;
	int Width, Height;
	int X, Y;
	SDL_RendererFlip Flip;
};

class GameObject : public Object
{
public:
	GameObject(Properties* objectProperties) :
		m_textureID(objectProperties->TextureID),
		m_width(objectProperties->Width), m_height(objectProperties->Height), m_Flip(objectProperties->Flip) 
	{

		m_transform.x = objectProperties->X;
		m_transform.y = objectProperties->Y;
		m_transform.w = objectProperties->Width;
		m_transform.h = objectProperties->Height;
		TRANSFORM.x = objectProperties->X;
		TRANSFORM.y = objectProperties->Y;
	}

	virtual void Draw() = 0;
	virtual void Clean() = 0;
	virtual void Update(float deltaTime) = 0;
	b2Body* AddRigidbody(int x, int y, int width, int height, bool isDynamic = true);

	void RotateAndTranslate(b2Vec2& vector, b2Vec2& center, float angle);


protected:

	SDL_Rect m_transform;
	int m_width{ 0 }; int m_height{0};
	std::string m_textureID;
	SDL_RendererFlip m_Flip;
	virtual ~GameObject() {}
	SDL_Texture* currentImage = nullptr;
	glm::vec2 TRANSFORM;
	int frameWidth; int frameHeight;
};