#pragma once
#include <string>
#include "../include/SDL2/SDL.h"
#include <map>

class TextureManager
{
public:

	virtual ~TextureManager() {};
	//SINGLETON
	static TextureManager* GetInstance() { return s_instance = (s_instance != nullptr) ? s_instance : new TextureManager(); }

	bool LoadTexture(std::string id, std::string filename);
	SDL_Texture* LoadImage(std::string filePath, SDL_Renderer* renderTarget);


	void DropTexture(std::string id);
	void Clean();

	void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);

protected:


private:
	TextureManager() {};
	std::map<std::string, SDL_Texture*> m_TextureMap;
	static TextureManager* s_instance;
	int redKey = 255; int greenKey = 0; int blueKey = 255;
};

