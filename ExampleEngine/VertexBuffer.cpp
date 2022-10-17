#include "glew.h"
#include "glfw3.h"
#include "VertexBuffer.h"

using namespace FrogEngine;

VertexBuffer::VertexBuffer(const void *positions, unsigned int size)
{
	glGenBuffers(1, &m_ID);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, size, positions, GL_STATIC_DRAW);
}
void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}
void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
VertexBuffer::~VertexBuffer()
{
	Unbind();
	glDeleteBuffers(1, &m_ID);
}