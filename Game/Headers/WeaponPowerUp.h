#pragma once
#include "../Headers/Powerup.h"
class WeaponPowerUp :
    public Powerup
{
public:
    void Draw();
    void Update(float deltaTime);
    void Clean();
    void OnCollect();

private:
    SDL_Texture* currentImage;
    int speed;

};

