#include "../Engine/Source Files/Headers/Entities/Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	delete m_PhysicsWorld;
}

void Scene::OnPhysicsStart()
{

}

void Scene::setScene(Scene* scene)
{
	currentScene = scene;

}
