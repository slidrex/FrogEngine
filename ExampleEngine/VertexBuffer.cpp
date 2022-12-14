#include "Renderer.h"

using namespace FrogEngine;

VertexBuffer::VertexBuffer(GLuint size)
{
	glGenBuffers(1, &m_ID);
	Bind();

	glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
}

VertexBuffer::VertexBuffer(Vertex2f* verteces, GLuint vertexCount)
{
	glGenBuffers(1, &m_ID);
	Bind();
	float *positions = new float[vertexCount * 2];

	for(int i = 0; i < vertexCount; i++)
	{
		//*(positions + i * 2) = (verteces + i)->position.x;
		//*(positions + i * 2 + 1) = (verteces + i)->position.y;
	}
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex2f) * vertexCount, positions, GL_STATIC_DRAW);
}

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