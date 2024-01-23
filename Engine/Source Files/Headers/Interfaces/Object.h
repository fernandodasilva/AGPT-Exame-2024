#pragma once

class Object 
{
public:

	Object() {};

	virtual void Draw() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Clean() = 0;

protected:
	virtual ~Object() {}
};