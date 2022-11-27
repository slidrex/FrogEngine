#pragma once
#include <vector>
#include "VertexBuffer.h"
#include "BufferLayout.h"

namespace FrogEngine
{
	class VertexArray
	{
	private:
		unsigned int ID;
	public:
		VertexArray(VertexBuffer buffer, BufferLayout layout);
		~VertexArray();
		void Bind() const;
		void Unbind() const;
	};
}