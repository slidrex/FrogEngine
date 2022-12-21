#include "SpriteSheetAnimation.h"

void FrogEngine::SpriteSheetAnimation::UpdateAnimation(float timeStep)
{
	if(timeSinceUpdate < 1)
	{
		timeSinceUpdate += timeStep * AnimationSpeed;
	}
	else
	{
		if (currentFrame >= m_frameCount - 1)
		{
			currentFrame = 0;
			currentOffset = 0;
		}
		else
		{
			currentFrame++;
			currentOffset += (float)1 / (float)m_frameCount;
		}
		timeSinceUpdate = 0;

	}
}