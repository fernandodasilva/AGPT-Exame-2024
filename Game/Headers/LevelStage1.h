#pragma once
#include "../Engine/Source Files/Headers/Entities/GameState.h"
#include "../include/Box2D/box2d/box2d.h"


const int HEIGHT = 480;

class LevelStage1 : public GameState
{
public:

	bool Enter();
	bool Exit();

	void HandleEvent(SDL_Event& ev);
	void Update();
	void Render();


private:
	const static int levelWidth = 3200; //get window width * 4 or 5 depending on how things go
	const static int levelHeight = 480; //get screen height

	static LevelStage1* level1instance;
	LevelStage1();

	SDL_Texture* backgroundTexture;
	SDL_Texture* background2Texture; //for parallax effect

	//game objects go here when they are done

protected:
	static b2World* m_world;
};

