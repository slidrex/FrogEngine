#pragma once
#include "Vertex.h"

namespace FrogEngine
{
	class VertexBuffer
	{
	private:
		unsigned int m_ID;
	public:
		VertexBuffer(Vertex2f *verteces, GLuint vertexCount);
		VertexBuffer(GLuint size);
		VertexBuffer(const void* positions, unsigned int size);
		~VertexBuffer();
		void Bind() const;
		void Unbind() const;
	};
}