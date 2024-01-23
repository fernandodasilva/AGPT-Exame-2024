#pragma once
#include "Projectile.h"
class LonerProjectile :
    public Projectile
{
public:
    LonerProjectile();
    ~LonerProjectile();

    void Draw();
    void Update(float deltaTime);
    void Clean();

private:
    int speed;
    SDL_Texture* currentImage;


    //position
    //collider
    //sprite "EnWeap6.bmp"
    //Explosion sprite "explode16.bmp"
};

