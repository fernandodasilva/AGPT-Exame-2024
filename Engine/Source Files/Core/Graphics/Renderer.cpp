#include "../Engine/Source Files/Headers/Renderer.h"


SDL_Renderer* renderTarget = nullptr;

Renderer::Renderer()
{
	renderTarget = SDL_CreateRenderer(Window::Get_Window_Instance(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Renderer::~Renderer()
{
//	SDL_DestroyRenderer();
}
