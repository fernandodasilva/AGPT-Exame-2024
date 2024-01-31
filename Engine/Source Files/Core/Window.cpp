#include "../Headers/Window.h"
#include "../Headers/InitError.h"

Window* Window::windowInstance = nullptr;

Window::Window(std::string title, int windowWidth, int windowHeight)
{
	
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_OPENGL);
	if (window == nullptr)
	{
		throw InitError();
		SDL_Quit();
	}

	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		throw InitError();
		SDL_Quit();
	}
}


 

void Window::CreateContext(SDL_Window* window)
{
	context = SDL_GL_CreateContext(window);
	//this might be important because of the Get Context function
	SDL_GL_MakeCurrent(window, context);
}

void Window::GetContext(SDL_Window* window)
{
	SDL_GL_GetCurrentContext();
}

void Window::DeleteContext(SDL_Window* window)
{
	SDL_GL_DeleteContext(window);
}

SDL_Surface* Window::getSurface()
{
	return SDL_GetWindowSurface(window);
}



void Window::updateSurface()
{
	SDL_UpdateWindowSurface(window);
}

Window::~Window()
{
	SDL_DestroyWindow(window);
}
