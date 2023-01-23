#include "Shapes2D.h"

Murk::Shape2D* Murk::CreateSquare(float x, float y, float xSize, float ySize)
{
	Shape2D* shape = new Shape2D();
	shape->vertexCount = 4;
	shape->verteces = new Vertex2f[4]
	{
		Vertex2f(x - xSize / 2, y - ySize / 2, 0.0f, 0.0f),
		Vertex2f(x - xSize / 2, y + ySize / 2, 0.0f, 1.0f),
		Vertex2f(x + xSize / 2, y + ySize / 2, 1.0f, 1.0f),
		Vertex2f(x + xSize / 2, y - ySize / 2, 1.0f, 0.0f)
	};
	shape->indexCount = 6;
	shape->indeces = new unsigned int[6]
	{
		0, 1, 2,
		0, 2, 3
	};
	return shape;
}
