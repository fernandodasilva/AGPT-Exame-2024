#pragma once
#include "../include/SDL2/SDL.h"
#include "../include/Box2D/box2d/box2d.h"

class GameState
{
public:
	//State Transitions
	virtual bool Enter() {};
	virtual bool Exit() {};

	void AddObject();

	b2World* GetWorld() { return m_world; }
	static b2World* GetWorldInstance()
	{
		return m_world = (m_world != nullptr) ? m_world : new b2World(b2Vec2(0.0f, 9.8f));
	} //SINGLETON


	//main loop functions
	virtual void HandleEvent(SDL_Event& e) {};
	virtual void Update() {};
	virtual void Render() {};

	//destructor
	virtual ~GameState() {};

protected:
	static b2World* m_world;


};

