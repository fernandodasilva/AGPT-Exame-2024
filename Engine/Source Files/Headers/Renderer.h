#pragma once
#include "../include/SDL2/SDL.h"
#include "../Engine/Source Files/Headers/Window.h"
#include "../Engine/Source Files/Headers/Entities/Camera.h"
//#include "../Engine/Source Files/Headers/"

class Renderer
{
public:
	~Renderer();

	static Renderer* GetRendererInstance()
	{
		return rendererInstance = (rendererInstance != nullptr) ? rendererInstance : new Renderer();
	} //SINGLETON

	static SDL_Renderer* GetSDLRenderer()
	{
		return sdlrendererinstance = (sdlrendererinstance != nullptr) ? sdlrendererinstance = SDL_CreateRenderer(Window::Get_Window_Instance(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}


private:
	Renderer();
	static Renderer* rendererInstance;
	static SDL_Renderer* sdlrendererinstance;

private:
	struct SceneData
	{
		glm::mat4 ViewProjectionMatrix;
	};

};

