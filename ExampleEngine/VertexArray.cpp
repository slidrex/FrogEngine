#pragma once
#include "glew.h"
#include "VertexArray.h"
#include "VertexBuffer.h"


FrogEngine::VertexArray::VertexArray(FrogEngine::VertexBuffer buffer, unsigned int stride)
{
	buffer.Bind();
	glGenVertexArrays(1, &ID);
	glBindVertexArray(ID);
	glEnableVertexArrayAttrib(ID, 0);

	glVertexAttribPointer(0, stride, GL_FLOAT, GL_FALSE, stride * sizeof(float), NULL);

	buffer.Unbind();
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