#pragma once
#include "Enemy.h"
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

