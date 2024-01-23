#pragma once

#include <map>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "../Headers/TextureManager.h"

struct Sequence
{
	int Speed;
	int FrameCount;
	int Width, Height;
	std::vector<std::string> TextureIDs;
};

class FrameAnimation
{
public:
	FrameAnimation(std::string file, SDL_Rect* objectTransform);
	~FrameAnimation();

	void Draw();
	void Update();
	bool Parse(std::string source);
	bool SetCurrentSequence(std::string sequenceID);

private:
	Uint8 m_currentFrame;
	Sequence* m_currentSequence;
	SDL_Rect* m_objectTransform;
	std::map<std::string, Sequence*> m_sequenceMap;

};

