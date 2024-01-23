#pragma once
#include "Projectile.h"
class Missile :
    public Projectile
{

public:
    void Draw();
    void Update(float deltaTime);
    void Clean();

private:
    int power;
    const int lightPower = 10;
    const int mediumPower = 20;
    const int highPower = 40;

    //type (light, mid, heavy)
    //sprite
    //power (10, 20, 40)
    //speed
    //explosion sprite
    //position
    //collider
};

