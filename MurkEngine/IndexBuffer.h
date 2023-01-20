#pragma once
namespace Murk
{
	class IndexBuffer
	{
	private:
		unsigned int m_Count;
		unsigned int m_ID;
	public:
		IndexBuffer(const unsigned int* data, unsigned int count);
		~IndexBuffer();
		void Bind() const;
		void Unbind() const;
		unsigned int GetCount() const { return m_Count; }
	};
}