#pragma once
#include "../Engine/Source Files/Headers/Entities/GameState.h"
#include "../include/SDL2/SDL.h"

class Title : public GameState
{
public:
	bool Enter();
	bool Exit();
	void HandleEvent(SDL_Event& ev);

private:
	static Title* s_title; //static instance
	Title(); //private constructor
	SDL_Texture* backgroundTexture;
	SDL_Texture* gameLogo;

};

