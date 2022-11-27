#pragma once
#include <iostream>

namespace FrogEngine
{
	class Texture
	{
	private:
		unsigned int m_ID;
		unsigned char* m_localBuffer;
		std::string m_TexturePath;
		int m_BB;
		int height, width;
	public:
		Texture(std::string path);
		~Texture();
		void Bind(unsigned int slot = 0) const;
		void Unbind() const;
	};
}