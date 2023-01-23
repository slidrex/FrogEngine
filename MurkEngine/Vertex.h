#pragma once
#include "glm/glm.hpp"
namespace Murk
{
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
	struct Vertex3f
	{
		float position[3];
		float color[4];
		Vertex3f()
		{
			position[0] = 0.0f;
			position[1] = 0.0f;
			position[2] = 0.0f;

			color[0] = 0.0f;
			color[1] = 0.0f;
			color[2] = 0.0f;
			color[3] = 1.0f;
		}
		Vertex3f(float x, float y, float z, glm::vec3 col)
		{
			position[0] = x;
			position[1] = y;
			position[2] = z;
			color[0] = col.x;
			color[1] = col.y;
			color[2] = col.z;
			color[3] = 1.0f;
		}
	};
}