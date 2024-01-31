#include "../Headers/SDLWrapper.h"
#include "../Headers/Window.h"
#include "../Headers/GameEngine.h"
#include "../Headers/TextureManager.h"
#include "../Headers/InputManager.h"
#include <iostream>
#include <vector>

GameEngine* GameEngine::st_engineInstance = nullptr;

void GameEngine::init(std::string windowTitle, int windowWidth, int windowHeight)
{
	sdl = new SDLWrapper(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	window = new Window(windowTitle, windowWidth, windowHeight);
}

void GameEngine::start()
{
	bool isRunning = true;
	SDL_Event ev;

	while (isRunning)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_QUIT)
				isRunning = false;
		}
		window->updateSurface();
	}
}

GameEngine::~GameEngine()
{
	delete window;
	delete sdl;
}

bool GameEngine::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("Failed to initialise SDL: %s", SDL_GetError());
		return false;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	m_window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (m_window == nullptr)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	SDL_GLContext context = SDL_GL_CreateContext(m_window);

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == nullptr)
	{
		SDL_Log("Failed to create renderer : % s", SDL_GetError());
		return false;
	}
	return b_IsRunning = true;
}

void GameEngine::Clean()
{
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void GameEngine::Quit()
{
	b_IsRunning = false;
}

void GameEngine::Update()
{
		SDL_Log("Updating");

		if (InputManager::GetInstance()->GetKeyDown(SDL_SCANCODE_A))
		{
			SDL_Log("Key A pressed");
		}
}

void GameEngine::Render()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 128, 0, 255);
	SDL_RenderClear(m_renderer);


	TextureManager::GetInstance()->Draw("logo", 210, 160, 72, 109, SDL_FLIP_NONE);
	SDL_RenderPresent(m_renderer);

}

void GameEngine::Events()
{
	InputManager::GetInstance()->Listen();
}
