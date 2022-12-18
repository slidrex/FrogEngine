#pragma once
#include "glm/glm.hpp"

namespace FrogEngine
{
	class Events
	{
	public:
		static bool IsMousePressed(int mouse);
		static glm::vec2 GetMousePos();
		static bool IsKeyPressed(int key);
		static float GetAspectRatio();
	};
}
