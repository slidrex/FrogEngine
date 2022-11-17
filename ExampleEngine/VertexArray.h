#pragma once
#include <vector>
#include "VertexBuffer.h"

namespace FrogEngine
{
	class VertexArray
	{
	private:
		unsigned int ID;
	public:
		VertexArray(VertexBuffer buffer, unsigned int stride);
		~VertexArray();
		void Bind() const;
		void Unbind() const;
	};
}