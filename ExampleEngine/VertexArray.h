#pragma once
#include <vector>
#include "VertexBuffer.h"

namespace FrogEngine
{
	static std::vector<unsigned int> locations;
	class VertexArray
	{
	private:
		unsigned int ID;
	public:
		VertexArray(FrogEngine::VertexBuffer buffer, unsigned int stride);
		~VertexArray();
		void Bind() const;
		void Unbind() const;
	};
}