#include "glew.h"
#include "image.h"
#include "Texture.h"

Murk::Texture::Texture(std::string path)
{
	stbi_set_flip_vertically_on_load(1);

	m_localBuffer = stbi_load(path.c_str(), &width, &height, &m_BB, 4);
	

	glGenTextures(1, &m_ID);
	glBindTexture(GL_TEXTURE_2D, m_ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer);
	Unbind();
	
	if(m_localBuffer)
	{
		stbi_image_free(m_localBuffer);
	}

}
Murk::Texture::~Texture()
{

}
void Murk::Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_ID);
}
void Murk::Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
