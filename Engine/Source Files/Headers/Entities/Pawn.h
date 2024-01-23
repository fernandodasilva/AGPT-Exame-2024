#pragma once
#include "../Entities/GameObject.h"
#include "../InputManager.h"

class Pawn : public GameObject
{
public:
	Pawn(Properties* props): GameObject(props) {}


	virtual void Draw() = 0;
	virtual void Clean() = 0;
	virtual void Update(float deltaTime) = 0;

protected:

private:
	//input manager?

};

