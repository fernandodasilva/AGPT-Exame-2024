#include "../Headers/Renderer.h"
#include "../Headers/Window.h"

SDL_Renderer* renderTarget = nullptr;

Renderer::Renderer()
{
	SDL_CreateRenderer(Window::Get_Window_Instance(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Renderer::~Renderer()
{
//	SDL_DestroyRenderer();
}
