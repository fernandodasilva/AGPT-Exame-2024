#pragma once


#include <glm/glm.hpp>

//physics
#include <box2d/b2_world.h>
#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_polygon_shape.h>


class Scene
{
public:
	Scene();
	~Scene();

	void OnPhysicsStart();

	bool GetIsRunning() const { return m_IsRunning; }

	void setScene(Scene* scene);

private:



private:
	bool m_IsRunning = false;
	b2World* m_PhysicsWorld = nullptr;
	Scene* currentScene = nullptr;
};