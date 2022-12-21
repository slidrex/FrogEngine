#pragma once
#include "glm/glm.hpp"

namespace FrogEngine
{
	class SpriteSheetAnimation
	{
	private:
		unsigned int m_frameCount;
		unsigned int currentFrame;
		float currentOffset;
		float timeSinceUpdate;
	public:
		float AnimationSpeed;
		/// <summary>
		/// Horizontal only.
		/// </summary>
		SpriteSheetAnimation(unsigned int frameCount, float animationSpeed)
		{
			m_frameCount = frameCount;
			currentFrame = 0;
			AnimationSpeed = animationSpeed;
			timeSinceUpdate = 0.0f;
			currentOffset = 0.0f;
		}
		void UpdateAnimation(float timeStep);
		inline float GetUVOffset() const { return currentOffset; };
	};
}