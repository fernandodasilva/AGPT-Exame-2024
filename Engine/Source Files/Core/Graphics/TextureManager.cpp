#include "../Engine/Source Files/Headers/TextureManager.h"
#include "../Engine/Source Files/Headers/GameEngine.h"
#include <iostream>

TextureManager* TextureManager::s_instance = nullptr;

bool TextureManager::LoadTexture(std::string id, std::string filename)
{

	SDL_Surface* surface = SDL_LoadBMP(filename.c_str());
	if (surface == nullptr)
	{
		SDL_Log("Failed to load texture: %s", filename.c_str(), SDL_GetError());
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(GameEngine::GetEngineInstance()->GetRenderer(), surface);
	if (texture == nullptr)
	{
		SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
		return false;
	}

	m_TextureMap[id] = texture;
	return true;
}

SDL_Texture* TextureManager::LoadImage(std::string filePath, SDL_Renderer* renderTarget)
{
	SDL_Texture* texture = nullptr;
	SDL_Surface* surface = SDL_LoadBMP(filePath.c_str());

	if (surface == nullptr)
	{
		SDL_Log("Failed to load image: %s ", filePath.c_str(), SDL_GetError());
	}
	else
	{
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, redKey, greenKey, blueKey));
		texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		if (texture == nullptr)
		{
			SDL_Log("Failed to create texture: %s", SDL_GetError());
		}
	}
	SDL_FreeSurface(surface);
	return texture;
}

void TextureManager::DropTexture(std::string id)
{
	SDL_DestroyTexture(m_TextureMap[id]);
	m_TextureMap.erase(id);
}

void TextureManager::Clean()
{
	std::map<std::string, SDL_Texture*>::iterator it;
	for (it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
		SDL_DestroyTexture(it->second);

	m_TextureMap.clear();

	SDL_Log("Texture map cleaned");
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
	SDL_Rect sourceRect = { 0, 0, width, height };
	SDL_Rect destinationRect = { x, y, width, height };
//permite que você rode o objeto e tudo
	SDL_RenderCopyEx(GameEngine::GetEngineInstance()->GetRenderer(), m_TextureMap[id], &sourceRect, &destinationRect,
		0, nullptr, flip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{
	SDL_Rect sourceRect = { width * frame, height * row, width, height };
	SDL_Rect destinationRect = { x, y, width, height };
	SDL_RenderCopyEx(GameEngine::GetEngineInstance()->GetRenderer(), m_TextureMap[id], &sourceRect, &destinationRect, 0, nullptr, flip);
}
