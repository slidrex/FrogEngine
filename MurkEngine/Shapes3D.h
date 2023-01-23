#pragma once
#include "Vertex.h"

namespace Murk 
{
	struct Shape3D
	{
		unsigned int* indeces;
		unsigned int indexCount;
		Vertex3f* verteces;
		unsigned int vertexCount;
	};
	Shape3D* CreateCube(float x, float y);
}