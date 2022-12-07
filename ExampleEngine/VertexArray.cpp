#pragma once
#include "glew.h"
#include "VertexArray.h"
#include "VertexBuffer.h"


FrogEngine::VertexArray::VertexArray(FrogEngine::VertexBuffer& buffer, BufferLayout layout)
{
	buffer.Bind();
	glGenVertexArrays(1, &ID);
	glBindVertexArray(ID);
	unsigned int offset = 0;
	for(int i = 0; i < layout.Elements.size(); i++)
	{
		glEnableVertexArrayAttrib(ID, i);

		glVertexAttribPointer(i, layout.Elements[i].m_count, layout.Elements[i].m_type, layout.Elements[i].m_normalized, layout.GetStride(), (const void*)offset);
		offset += layout.Elements[i].m_count * GetSize(layout.Elements[i].m_type);

	}

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