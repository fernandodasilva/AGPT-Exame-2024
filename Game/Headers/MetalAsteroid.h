#pragma once
#include "../Engine/Source Files/Headers/Entities/GameObject.h"

class MetalAsteroid :
    public GameObject
{
public:
    void Draw();
    void Update(float deltaTime);
    void Clean();

    void RotateAndTranslate(b2Vec2& vector, b2Vec2& center, float angle);


private:
    glm::vec2 position;
    //collider
    int size;
    b2Body body;
};

