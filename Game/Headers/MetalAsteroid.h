#pragma once
#include "../Engine/Source Files/Headers/Entities/GameObject.h"
class MetalAsteroid :
    public GameObject
{
public:
    void Draw();
    void Update(float deltaTime);
    void Clean();

private:
    //position
    //collider
    //size
};

