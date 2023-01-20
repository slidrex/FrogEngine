#pragma once
#include "glm/glm.hpp"

namespace Murk
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
