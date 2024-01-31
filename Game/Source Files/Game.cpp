// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "../Engine/Source Files/Headers/GameEngine.h"
#include "../Game/Headers/Spaceship.h"
#include "../Engine/Source Files/Headers/Entities/GameState.h"

#include <../include/glm/gtc/matrix_transform.hpp>
#include <../include/glm/gtc/type_ptr.hpp>
#include "../include/SDL2/SDL.h"


GameState* currentState = nullptr;
GameState* nextState = nullptr;
Spaceship* player = nullptr;

int main(int argc, char** argv)
{
	GameEngine::GetEngineInstance()->Initialize();

	SDL_ShowCursor(SDL_DISABLE);

	player = new Spaceship(new Properties("Ship1.bmp", 100, 200, 448, 64, SDL_FLIP_NONE));

	while (GameEngine::GetEngineInstance()->IsRunning())
	{
		GameEngine::GetEngineInstance()->Events();
		GameEngine::GetEngineInstance()->Update();
		GameEngine::GetEngineInstance()->Render();
	}

	GameEngine::GetEngineInstance()->Clean();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
