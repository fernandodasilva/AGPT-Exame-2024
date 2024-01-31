#pragma once
#include "Enemy.h"
#include "../include/Box2D/box2d/box2d.h"
class Drone :
    public Enemy
{
public:
    void Draw();
    void Update(float deltaTime);
    void Clean();

private:
    int speed;
    int health;

    //collider
    SDL_Texture* currentImage;
    // sprite "drone.bmp"
    //position (y = y * sin * deltatime?)

};

