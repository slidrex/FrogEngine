#pragma once
#include "glew.h"
#include "VertexArray.h"
#include "VertexBuffer.h"


Murk::VertexArray::VertexArray(Murk::VertexBuffer& buffer, BufferLayout layout)
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
Murk::VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &ID);
}
void Murk::VertexArray::Bind() const
{
	glBindVertexArray(ID);
}
void Murk::VertexArray::Unbind() const
{
	glBindVertexArray(0);
}