#include <iostream>
#include <SDL.h>
#include <vector>

#undef main

SDL_Texture* LoadTexture(std::string filePath, SDL_Renderer* renderTarget)
{
	SDL_Texture* texture = nullptr;
	SDL_Surface* surface = SDL_LoadBMP(filePath.c_str());
	if (surface == nullptr)
	{
		std::cout << "Error loading image: " << filePath << std::endl;
	}
	else
	{
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 0, 255));
		texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		if (texture == nullptr)
		{
			std::cout << "Error creating texture: " << std::endl;
		}
	}
	SDL_FreeSurface(surface);
	return texture;
}

SDL_Surface* OptimizedSurface(std::string filePath, SDL_Surface* windowSurface)
{
	SDL_Surface* optimizedSurface = nullptr;
	SDL_Surface* surface = SDL_LoadBMP(filePath.c_str());
	if (surface == nullptr)
	{
		std::cout << "Error loading image: " << filePath << std::endl;
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface(surface, windowSurface->format, 0);
		if (optimizedSurface == nullptr)
		{
			std::cout << "Error optimizing surface: " << filePath << std::endl;
		}
	}
	SDL_FreeSurface(surface);
	return optimizedSurface;
}


int main()
{
	//Initializing and loading variables
	SDL_Window* window = nullptr;
	SDL_Texture* currentImage = nullptr;
	SDL_Texture* background = nullptr;
	SDL_Renderer* renderTarget = nullptr;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("SetupSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	int textureWidth = 0;
	int textureHeight = 0;
	int frameWidth;
	int frameHeight;
	SDL_Rect playerRect;

	currentImage = LoadTexture("Resources/graphics/drone.bmp", renderTarget);
	background = LoadTexture("Resources/graphics/galaxy2.bmp", renderTarget);
	SDL_QueryTexture(currentImage, NULL, NULL, &textureWidth, &textureHeight);

	frameWidth = textureWidth / 8;
	frameHeight = textureHeight / 2;

	//std::vector<float> playerPositionVector;
	//float playerX = 0.f;
	//float playerY = 0.f;
	//playerPositionVector.push_back(playerX);
	//playerPositionVector.push_back(playerY);


	playerRect.x = playerRect.y = 0;
	playerRect.w = frameWidth;
	playerRect.h = frameHeight;

	SDL_Rect playerPosition;
	playerPosition.x = playerPosition.y = 0;
	playerPosition.w = playerPosition.h = 32;


	SDL_SetRenderDrawColor(renderTarget, 0xFF, 0, 0xFF, 0xFF);


	float frameTime = 0;
	int prevTime = 0;
	int currentTime = 0;
	float deltaTime = 0;

	float moveSpeed = 300.0f;
	const Uint8* keyState;

	bool isRunning = true;
	SDL_Event event;

	while (isRunning)
	{
		//game loop
		prevTime = currentTime;
		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - prevTime) / 1000.0f;

		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				isRunning = false;
			}

			keyState = SDL_GetKeyboardState(NULL);
			if ((keyState[SDL_SCANCODE_RIGHT] || keyState[SDL_SCANCODE_D] || keyState[SDL_SCANCODE_KP_6]) && playerPosition.x <= 608)
				playerPosition.x += moveSpeed * deltaTime;
			if ((keyState[SDL_SCANCODE_LEFT] || keyState[SDL_SCANCODE_A] || keyState[SDL_SCANCODE_KP_4]) && playerPosition.x >= 0)
				playerPosition.x -= moveSpeed * deltaTime;
			if ((keyState[SDL_SCANCODE_UP] || keyState[SDL_SCANCODE_W] || keyState[SDL_SCANCODE_KP_8]) && playerPosition.y >= 0)
				playerPosition.y -= moveSpeed * deltaTime;
			if ((keyState[SDL_SCANCODE_DOWN] || keyState[SDL_SCANCODE_S] || keyState[SDL_SCANCODE_KP_2]) && playerPosition.y <= 448)
				playerPosition.y += moveSpeed * deltaTime;
		}

		frameTime += deltaTime;
		if (frameTime >= 0.125f)
		{
			frameTime = 0;
			playerRect.x += frameWidth;
			if (playerRect.x >= textureWidth)
			{
				playerRect.x = 0;
				playerRect.y += frameHeight;
				if (playerRect.y >= textureHeight)
				{
					playerRect.y = 0;
				}
			}
		}

		SDL_RenderClear(renderTarget);
		SDL_RenderCopy(renderTarget, background, NULL, NULL);
		SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition);
		SDL_RenderPresent(renderTarget);
	}

	//std::cout << SDL_NumJoysticks() << std::endl;
	//SDL_Joystick* joystick = SDL_JoystickOpen(0);
	//if (joystick == NULL)
	//{
	//	std::cout << "Unable to find any Gamepad" << SDL_GetError() << std::endl;
	//}
	//else
	//{

	//}

	SDL_DestroyWindow(window);
	SDL_DestroyTexture(currentImage);
	SDL_DestroyTexture(background);
	SDL_DestroyRenderer(renderTarget);
	currentImage = nullptr;
	renderTarget = nullptr;
	window = nullptr;
	SDL_Quit();
	return 0;
}