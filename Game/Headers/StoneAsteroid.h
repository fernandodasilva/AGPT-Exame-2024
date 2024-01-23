#pragma once
#include "../Engine/Source Files/Headers/Entities/GameObject.h"
class StoneAsteroid :
    public GameObject
{
    //constructor
    //split
    //destructor
    //on collision
    ~StoneAsteroid();
    virtual void Draw();
    virtual void Clean();
    virtual void Update(float deltaTime);

private:
    SDL_Texture* currentImage;
    int health;
    int speed;
    //type

    //position
     //collider
};

