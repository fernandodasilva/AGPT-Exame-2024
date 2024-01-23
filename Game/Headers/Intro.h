#pragma once
#include "Headers/Entities/GameState.h"
#include "../include/SDL2/SDL.h"

class Intro : public GameState
{
public:
	//singleton
	static Intro* getIntro() { return s_Intro = (s_Intro != nullptr) ? s_Intro : new Intro(); }

	//Transitions
	bool Enter();
	bool Exit();
	void HandleEvent(SDL_Event& ev);

	//Main loop functions

private:
	static Intro* s_Intro;
	SDL_Texture* introLogo;
	Intro();

};

