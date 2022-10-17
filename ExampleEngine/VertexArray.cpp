#include "glew.h"
#include "VertexArray.h"

FrogEngine::VertexArray::VertexArray(FrogEngine::VertexBuffer buffer, unsigned int stride)
{
	buffer.Bind();
	glGenVertexArrays(1, &ID);
	glBindVertexArray(ID);
	unsigned int currentLocation = locations.size();
	locations.push_back(currentLocation);
	glEnableVertexArrayAttrib(ID, currentLocation);

	glVertexAttribPointer(currentLocation, stride, GL_FLOAT, GL_FALSE, stride * sizeof(float), NULL);

	Unbind();
}
FrogEngine::VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &ID);
}
void FrogEngine::VertexArray::Bind() const
{
	glBindVertexArray(ID);
}
void FrogEngine::VertexArray::Unbind() const
{
	glBindVertexArray(0);
}