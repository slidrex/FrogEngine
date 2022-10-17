#pragma once
namespace FrogEngine
{
	class VertexBuffer
	{
	private:
		unsigned int m_ID;
	public:
		VertexBuffer(const void* positions, unsigned int size);
		~VertexBuffer();
		void Bind() const;
		void Unbind() const;
	};
}