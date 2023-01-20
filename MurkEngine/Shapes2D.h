#pragma once
#include "Vertex.h"

namespace Murk
{
	struct Shape2D
	{
		unsigned int vertexCount;
		Vertex2f* verteces;
		unsigned int indexCount;
		unsigned int* indeces;
	};
	Shape2D* CreateSquare(float x, float y, float xSize, float ySize);
}