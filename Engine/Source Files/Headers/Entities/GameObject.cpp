#include "GameObject.h"
#include "GameState.h"

b2Body* GameObject::AddRigidbody(int x, int y, int width, int height, bool isDynamic)
{
	b2BodyDef bodyDef;
	bodyDef.position.Set(x, y);
	if (isDynamic)
	{
		bodyDef.type = b2_dynamicBody;
	}
	b2Body* body = GameState::GetWorldInstance()->CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox(width / 2, height / 2);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;

	body->CreateFixture(&fixtureDef);
}