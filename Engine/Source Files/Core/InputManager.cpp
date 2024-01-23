#include "../Headers/InputManager.h"
#include "../Headers/GameEngine.h"

InputManager* InputManager::s_instance = nullptr;

InputManager::InputManager()
{
	m_keystates = SDL_GetKeyboardState(nullptr);
}

void InputManager::Listen()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT: GameEngine::GetEngineInstance()->Quit();
			break;
		case SDL_KEYDOWN: KeyDown();
			break;
		case SDL_KEYUP: KeyUp();
			break;
		}
	}
}

bool InputManager::GetKeyDown(SDL_Scancode key)
{
	if (m_keystates[key] == 1)
		return true;
	return false;
}

void InputManager::KeyUp()
{
	m_keystates = SDL_GetKeyboardState(nullptr);
}

void InputManager::KeyDown()
{
	m_keystates = SDL_GetKeyboardState(nullptr);
}