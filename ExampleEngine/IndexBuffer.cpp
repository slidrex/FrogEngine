#include "glew.h"
#include "IndexBuffer.h"

using namespace FrogEngine;

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}
void IndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
IndexBuffer::~IndexBuffer()
{
	Unbind();
	glDeleteBuffers(1, &m_ID);
}
IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count)
{
	glGenBuffers(1, &m_ID);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * count, data, GL_STATIC_DRAW);
	Unbind();
	m_Count = count;
}
