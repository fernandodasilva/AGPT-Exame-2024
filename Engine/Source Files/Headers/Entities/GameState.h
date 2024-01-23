#pragma once
#include "../include/SDL2/SDL.h"

class GameState
{
public:
	//State Transitions
	virtual bool Enter() {};
	virtual bool Exit() {};

	//main loop functions
	virtual void HandleEvent(SDL_Event& e) {};
	virtual void Update() {};
	virtual void Render() {};

	//destructor
	virtual ~GameState() {};


};

