#pragma once
#include "glm/glm.hpp"

struct Vertex2f
{
	float position[2];
	float texCoords[2];
	
	Vertex2f()
	{
		position[0] = 0;
		position[1] = 0;
		texCoords[0] = 0;
		texCoords[1] = 0;
	}
	Vertex2f(float x, float y, float textureX, float textureY)
	{
		position[0] = x;
		position[1] = y;
		texCoords[0] = textureX;
		texCoords[1] = textureY;
	}
};