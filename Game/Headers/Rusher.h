#pragma once
#include "../Headers/Enemy.h"
class Rusher :
    public Enemy
{
public:
    void Draw();
    void Update(float deltaTime);
    void Clean();

private:
    int speed;
    int health;
    SDL_Texture* currentImage;
    //animation
};

