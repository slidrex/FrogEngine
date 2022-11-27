#pragma once
#include "glm/glm.hpp"
#include <array>

struct Vertex2f
{
	glm::vec2 position;
	glm::vec2 textureCoord;

	Vertex2f()
	{
		position = glm::vec2(0.0f, 0.0f);
		textureCoord = glm::vec2();
	}
	Vertex2f(float x, float y, glm::vec2 texCoord = glm::vec2())
	{
		position.x = x;
		position.y = y;
		textureCoord = texCoord;
	}
};