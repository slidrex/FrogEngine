#pragma once
#include "glfw3.h"
#include <vector>

namespace Murk
{
		static unsigned int GetSize(GLenum type)
		{
			switch (type)
			{
			case GL_FLOAT:
				return 4;
			case GL_INT:
				return 4;
			}
		}
	struct LayoutElement
	{
		int m_count;
		GLenum m_type;
		bool m_normalized;
		LayoutElement(int count, GLenum type, bool normalized)
		{
			m_count = count;
			m_type = type;
			m_normalized = normalized;
		}
	};
	class BufferLayout
	{
	private:
		unsigned int m_stride;
	public:
		inline unsigned int GetStride() const { return m_stride; }
		std::vector<LayoutElement> Elements;
		template<typename T>
		void Push(unsigned int count);
		template<>
		void Push<float>(unsigned int count)
		{
			Elements.push_back(LayoutElement(count, GL_FLOAT, false));
			m_stride += sizeof(float) * count;
		}
		template<>
		void Push<double>(unsigned int count)
		{
			Elements.push_back(LayoutElement(count, GL_DOUBLE, false));
			m_stride += sizeof(double) * count;
		}
	};
}