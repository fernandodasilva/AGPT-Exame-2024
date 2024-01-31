#include "../Game/Headers/LevelStage1.h"


void LevelStage1::Update()
{

	m_world->Step(1.0/60.0, 10, 5); //physics update (time step, velocity iterations, position iterations)
}

LevelStage1::LevelStage1()
{
	
	m_world = new b2World(b2Vec2(0.0f, 9.8f));

}