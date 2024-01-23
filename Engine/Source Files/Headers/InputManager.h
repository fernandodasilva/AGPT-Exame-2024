#pragma once
#include "../include/SDL2/SDL.h"

class InputManager
{

public:
	//SINGLETON
	static InputManager* GetInstance() { return s_instance = (s_instance != nullptr) ? s_instance : new InputManager(); }

	void Listen();
	bool GetKeyDown(SDL_Scancode key);


private:
	InputManager();
	static InputManager* s_instance;


	const Uint8* m_keystates;

private:
	void KeyUp();
	void KeyDown();

};