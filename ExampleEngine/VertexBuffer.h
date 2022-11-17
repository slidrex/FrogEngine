#pragma once
#include "Vertex.h"

namespace FrogEngine
{
	class VertexBuffer
	{
	private:
		unsigned int m_ID;
	public:
		VertexBuffer(const void* positions, unsigned int size);
		VertexBuffer(Vertex2f *verteces, GLuint vertexCount);
		~VertexBuffer();
		void Bind() const;
		void Unbind() const;
	};
}