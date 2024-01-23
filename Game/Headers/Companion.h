#pragma once
#include "../Engine/Source Files/Headers/Entities/Pawn.h"
#include "../Engine/Source Files/Headers/TextureManager.h"
#include "../include/SDL2/SDL.h"

class Companion : public Pawn
{
public:
    //constructor
    Companion();
    ~Companion();
    // destructor
    //method to fire
    void Shoot();
    void UpdateHealth();

    void Draw();
    void Update(float deltaTime);
    void Clean();

private:
    //position
    //sprite "clone.bmp" use first 4 rows and 4 columns for first animation, use last row for death animation
    SDL_Texture* currentImage;
    //collider
    //animation
    int currentHealth;
    const int maxHealth = 100;
    //missile
    //Rigidbody
};

