#pragma once
#include "../Headers/Powerup.h"
class ShieldPowerUp :
    public Powerup
{
public:
    void Draw();
    void Update(float deltaTime);
    void Clean();
    void OnCollect();

private:
    //position
    int speed;
    SDL_Texture* currentImage;

};

