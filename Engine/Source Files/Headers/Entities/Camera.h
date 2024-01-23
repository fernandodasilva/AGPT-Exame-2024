#pragma once
#include "../include/SDL2/SDL.h"
class Camera
{
public:
	inline static Camera* GetInstance() { return (s_instance != nullptr) ? s_instance : new Camera(); }

	void Draw();



private:
	Camera();

	static Camera* s_instance;

	Uint32 m_levelWidth;
	Uint32 m_levelHeight;
};


