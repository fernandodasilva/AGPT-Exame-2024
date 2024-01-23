#pragma once
#include <string>

#include "../include/SDL2/SDL.h"

#define SCREEN_WIDTH 680
#define SCREEN_HEIGHT 480

class GameEngine
{
public:
	void init(std::string windowTitle, int windowWidth, int windowHeight);

	void start();
	~GameEngine();



	static GameEngine* GetEngineInstance()
	{ return st_engineInstance = (st_engineInstance != nullptr) ? st_engineInstance : new GameEngine(); } //SINGLETON

	bool Initialize();
	void Clean();
	void Quit();

	void Update();
	void Render();
	void Events();

	inline bool IsRunning() { return b_IsRunning; }
	inline SDL_Renderer* GetRenderer() { return m_renderer; }

private:
	class SDLWrapper* sdl;
	class Window* window;

	GameEngine();

private:
	static GameEngine* st_engineInstance;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

private:
	bool b_IsRunning;
};