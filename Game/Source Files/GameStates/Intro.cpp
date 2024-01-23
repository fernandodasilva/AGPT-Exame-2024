#include "../Game/Headers/Intro.h"
#include "../Engine/Source Files/Headers/TextureManager.h"
#include "../Engine/Source Files/Headers/Renderer.h"

bool Intro::Enter()
{
	//flag
	bool success = true;

	//load background
	//if (!TextureManager::GetInstance()->LoadImage("", Renderer::GetRendererInstance()))
	//{
	//	SDL_Log("Failed to load the intro logo");
	//	success = false;
	//}

	return true;
}

bool Intro::Exit()
{
	SDL_DestroyTexture(introLogo);

	return true;
}
