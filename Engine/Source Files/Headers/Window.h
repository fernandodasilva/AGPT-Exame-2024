#pragma once
#include "../include/SDL2/SDL.h"
#include <string>
#include "../include/glad/include/glad/glad.h"

struct Properties
{
public:
	Properties(
		std::string title, int x, int y, int width, int height, Uint32 flags)
	{
		Title = title;
		X = x;
		Y = y;
		Width = width;
		Height = height;
		Flags = flags;
	}

public:
	std::string Title;
	int X; int Y; int Width; int Height; Uint32 Flags;
	
};

class Window

{
public:
	Window(std::string title, int windowWidth, int windowHeight);
	Window(Properties* windowProperties) :
		m_title(windowProperties->Title), m_positionX(windowProperties->X),
		m_positionY(windowProperties->Y), m_windowWidth(windowProperties->Width),
		m_windowHeight(windowProperties->Height), m_flags(windowProperties->Flags)
	{}

	void CreateContext(SDL_Window* window);
	void GetContext(SDL_Window* window);
	void DeleteContext(SDL_Window* window);

	SDL_Surface* getSurface();


	void updateSurface();

//	static Window* GetWindowInstance()
//	{
//		//return windowInstance = (windowInstance != nullptr) ? windowInstance : new Window("Test window", 640, 480);
//	} //SINGLETON
//
//
//	static SDL_Window* Get_Window_Instance()
//	{
///*		{ return window_instance = (window_instance != nullptr) ?
//			window_instance : SDL_CreateWindow(title, positionX, positionY, windowWidth, windowHeight, flags);
//		}*/
//		//SINGLETON
//	}


	~Window();
private:
	SDL_Window* window;
	static Window* windowInstance;
	static SDL_Window* window_instance;

	SDL_GLContext context;

protected:
	std::string m_title; int m_positionX; int m_positionY; int m_windowWidth; int m_windowHeight; Uint32 m_flags;
};