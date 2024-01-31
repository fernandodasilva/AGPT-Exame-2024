#include "../Game/Headers/MetalAsteroid.h"

void MetalAsteroid::Update(float deltaTime)
{

}

void MetalAsteroid::RotateAndTranslate(b2Vec2& vector, b2Vec2& center, float angle)
{
	b2Vec2 temp;
	temp.x = vector.x * cos(angle) - vector.y * sin(angle);
	temp.y = vector.x * sin(angle) + vector.y * cos(angle);

	vector = temp + center;
}
