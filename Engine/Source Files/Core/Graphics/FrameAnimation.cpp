#include "../Headers/FrameAnimation.h"
#include <iostream>
#include "xmllite.h"

FrameAnimation::FrameAnimation(std::string file, SDL_Rect* objectTransform) : m_objectTransform(objectTransform)
{

}

FrameAnimation::~FrameAnimation()
{
	m_currentSequence->TextureIDs.clear();
	m_currentSequence->TextureIDs.shrink_to_fit();
	m_sequenceMap.clear();
}

void FrameAnimation::Draw()
{
//	TextureManager::GetInstance()->Draw(*m_objectTransform);
}

void FrameAnimation::Update()
{
	if (m_currentSequence->FrameCount > 1)
		m_currentFrame = (SDL_GetTicks() / m_currentSequence->Speed) % m_currentSequence->FrameCount;
	else
		m_currentFrame = 0;

//	m_objectTransform->textureID = m_currentSequence->TextureIDs[m_currentFrame];

}

//bool FrameAnimation::Parse(std::string source)
//{
////	 xml;
//
//}

bool FrameAnimation::SetCurrentSequence(std::string sequenceID)
{
	if (m_sequenceMap.count(sequenceID) > 0)
	{
		m_currentSequence = m_sequenceMap[sequenceID];
		m_objectTransform->w = m_currentSequence->Width;
		m_objectTransform->h = m_currentSequence->Height;
		return true;
	}
	std::cout << "Failed to find sequence id: " << sequenceID << std::endl;
	return false;
}
