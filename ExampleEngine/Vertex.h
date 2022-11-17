#pragma once
#include "glm/glm.hpp"
#include <array>

struct Vertex2f
{
	glm::vec2 positions;

	Vertex2f()
	{
		positions = glm::vec2(0.0f, 0.0f);
	}
	Vertex2f(float x, float y)
	{
		positions.x = x;
		positions.y = y;
	}
};