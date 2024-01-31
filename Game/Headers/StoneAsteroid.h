#pragma once
#include "../Engine/Source Files/Headers/Entities/GameObject.h"
#include "../include/glm/glm.hpp"

class StoneAsteroid :
    public GameObject
{
    //constructor
    //split
    void Split();
    //destructor
    //on collision
    ~StoneAsteroid();
    virtual void Draw();
    virtual void Clean();
    virtual void Update(float deltaTime);

private:
    SDL_Texture* currentImage;
    int size;
    int speed;
    //type

    glm::vec2 position;
     //collider
    //on collision enter
};

